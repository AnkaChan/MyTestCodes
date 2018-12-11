#ifndef BINARY_TREE
#define BINARY_TREE
#include <functional>
#include <iterator>
#include <stack>

struct TreeNode
{
	double val;
	TreeNode * left = NULL;
	TreeNode * right = NULL;
	int maxLeftLen;
	int maxRightLen;
};


class CBinaryTree {
public:
	class CBinaryTreeIter : public std::iterator<std::forward_iterator_tag, TreeNode> {
	public:
		CBinaryTreeIter(CBinaryTree* tree, TreeNode * root) : mTree(tree), mRoot(root) {
			TreeNode * current = root;
			while (NULL != current)
			{
				traverseNodeStack.push(current);
				current = current->left;
			}
			if (!traverseNodeStack.empty())
			{
				currentNode = traverseNodeStack.top();
				traverseNodeStack.pop();
			}
			else
			{
				currentNode = NULL;
			}
		};
		CBinaryTreeIter  operator++() {
			if (traverseNodeStack.empty())
			{
				currentNode = NULL;
				mRoot = NULL;
				return *this;
			}
			currentNode = traverseNodeStack.top();
			traverseNodeStack.pop();
			TreeNode * current = currentNode->right;
			while (NULL != current)
			{
				traverseNodeStack.push(current);
				current = current->left;
			}

			return *this;
		};

		bool operator ==(const CBinaryTreeIter & iter1) {
			return currentNode == iter1.currentNode;

		}

		bool operator !=(const CBinaryTreeIter & iter1) {
			return currentNode != iter1.currentNode;
		}

		TreeNode & operator*() {
			return *currentNode;
		}

	private:
		CBinaryTree * mTree;
		TreeNode * mRoot;
		TreeNode * currentNode = NULL;
		std::stack<TreeNode *> traverseNodeStack;
	};


	CBinaryTree() {
		
	}

	int getMaxLen() {
		maxLen = 0;
		getMaxLenInSubTree(rootNode);
		return maxLen;
	}

	void getMaxLenInSubTree(TreeNode * pNode) {
		if (pNode->left == NULL)
		{
			pNode->maxLeftLen = 0;
		}
		else {
			getMaxLenInSubTree(pNode->left);
			pNode->maxLeftLen = pNode->left->maxLeftLen > pNode->left->maxRightLen ?
				pNode->left->maxLeftLen : pNode->left->maxRightLen;
			pNode->maxLeftLen += 1;
		}

		if (pNode->right == NULL)
		{
			pNode->maxRightLen = 0;
		}
		else {
			getMaxLenInSubTree(pNode->right);
			pNode->maxRightLen = pNode->right->maxLeftLen > pNode->right->maxRightLen ?
				pNode->right->maxLeftLen : pNode->right->maxRightLen;
			pNode->maxRightLen += 1;
		}

		int maxLenInSubTree = pNode->maxLeftLen > pNode->maxRightLen ? pNode->maxLeftLen : pNode->maxRightLen;

		if (maxLenInSubTree > maxLen) {
			maxLen = maxLenInSubTree;
		}
	}

	void insert(TreeNode * pNewNode) {
		if (rootNode == NULL)
		{
			rootNode = pNewNode;
			return;
		}
		insertOnNode(pNewNode, rootNode);
	};

	void insert(double newVal) {
		TreeNode * pNewNode = new TreeNode;
		pNewNode->val = newVal;
		if (rootNode == NULL)
		{
			rootNode = pNewNode;
			return;
		}
		insertOnNode(pNewNode, rootNode);
	};

	void inOrderTraverse(std::function<void(TreeNode *)>  func) {
		inOrderTraverseNode(rootNode, func);
	}

	void preOrderTraverse(std::function<void(TreeNode *)>  func) {
		preOrderTraverseNode(rootNode, func);
	}

	void preOrderTraverseNonrecursive(std::function<void(TreeNode *)>  func) {
		std::stack<TreeNode *> traverseStack;
		if (rootNode == NULL)
		{
			return;
		}

		TreeNode * currentPut = rootNode;

		func(rootNode);
		while (currentPut != NULL)
		{
			func(currentPut);
			traverseStack.push(currentPut);
			currentPut = currentPut->left;
		}

		while (!traverseStack.empty())
		{
			TreeNode * currentTraverse = traverseStack.top();
			traverseStack.pop();
			currentPut = currentTraverse->right;
			while (currentPut != NULL)
			{
				func(currentPut);
				traverseStack.push(currentPut);
				currentPut = currentPut->left;
			}

		}

	}

	void inOrderTraverseNonrecursive(std::function<void(TreeNode *)>  func) {
		std::stack<TreeNode *> traverseStack;
		if (rootNode == NULL)
		{
			return;
		}

		TreeNode * currentPut = rootNode;

		while (currentPut != NULL)
		{
			traverseStack.push(currentPut);
			currentPut = currentPut->left;
		}

		while (!traverseStack.empty())
		{
			TreeNode * currentTraverse = traverseStack.top();
			func(currentTraverse);
			traverseStack.pop();
			currentPut = currentTraverse->right;
			while (currentPut != NULL)
			{
				traverseStack.push(currentPut);
				currentPut = currentPut->left;
			}
			
		}

	}

	void changeToList() {
		auto changeNode = [this](TreeNode * pNode) mutable {
			static TreeNode * lastestAccessedNode = NULL;
			if (lastestAccessedNode == NULL)
			{
				lastestAccessedNode = pNode;
				rootNode = lastestAccessedNode;
				lastestAccessedNode->left = NULL;
				lastestAccessedNode->right = NULL;
			}
			else {
				lastestAccessedNode->right = pNode;
				pNode->left = lastestAccessedNode;
				//pNode->next = NULL;
				lastestAccessedNode = pNode;
			}
		};
		
		inOrderTraverse(changeNode);

		TreeNode * pCurrentNode = rootNode;
		TreeNode * pLastNode = NULL;
		while (pCurrentNode != NULL)
		{
			printf("%f\n", pCurrentNode->val);
			if (pCurrentNode->right == NULL)
			{
				pLastNode = pCurrentNode;
			}
			pCurrentNode = pCurrentNode->right;
		}
		printf("---------------------------------------------------\n");
		pCurrentNode = pLastNode;
		while (pCurrentNode != NULL)
		{
			printf("%f\n", pCurrentNode->val);
			pCurrentNode = pCurrentNode->left;
		}
	}

	void invertTree() {
		auto swapNode = [](TreeNode * pNode) mutable {
			TreeNode * temp = pNode->left;
			pNode->left = pNode->right;
			pNode->right = temp;
		};
		preOrderTraverse(swapNode);
	}

	CBinaryTreeIter begin() {
		return CBinaryTreeIter(this, rootNode);
	}

	CBinaryTreeIter end() {
		return CBinaryTreeIter(this, NULL);
	}
	
private:
	int maxLen;

	void insertOnNode(TreeNode * pNewNode, TreeNode * pTargetNode) {
		if (pNewNode->val > pTargetNode->val)
		{
			if (pTargetNode->right == NULL) {
				pTargetNode->right = pNewNode;
				return;
			}
			else
			{
				insertOnNode(pNewNode, pTargetNode->right);
			}
		}
		else
		{
			if (pTargetNode->left == NULL) {
				pTargetNode->left = pNewNode;
				return;
			}
			else
			{
				insertOnNode(pNewNode, pTargetNode->left);
			}
		}
	}

	void inOrderTraverseNode(TreeNode * pTargetNode, std::function<void(TreeNode *)> & func) {
		if (pTargetNode->left != NULL)
		{
			inOrderTraverseNode(pTargetNode->left, func);
		}
		func(pTargetNode);
		if (pTargetNode->right != NULL)
		{
			inOrderTraverseNode(pTargetNode->right, func);
		}
		return;
	}

	void preOrderTraverseNode(TreeNode * pTargetNode, std::function<void(TreeNode *)> & func) {
		func(pTargetNode);
		if (pTargetNode->left != NULL)
		{
			preOrderTraverseNode(pTargetNode->left, func);
		}
		if (pTargetNode->right != NULL)
		{
			preOrderTraverseNode(pTargetNode->right, func);
		}
		return;
	}
	TreeNode * rootNode = NULL;
};



#endif // BINARY_TREE
