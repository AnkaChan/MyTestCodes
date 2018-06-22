#ifndef BINARY_TREE
#define BINARY_TREE
#include <functional>

struct TreeNode
{
	double val;
	TreeNode * last = NULL;
	TreeNode * next = NULL;
};

class CBinaryTree {
public:
	CBinaryTree() {
		
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
	void changeToList() {
		auto changeNode = [this](TreeNode * pNode) mutable {
			static TreeNode * lastestAccessedNode = NULL;
			if (lastestAccessedNode == NULL)
			{
				lastestAccessedNode = pNode;
				rootNode = lastestAccessedNode;
				lastestAccessedNode->last = NULL;
				lastestAccessedNode->next = NULL;
			}
			else {
				lastestAccessedNode->next = pNode;
				pNode->last = lastestAccessedNode;
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
			if (pCurrentNode->next == NULL)
			{
				pLastNode = pCurrentNode;
			}
			pCurrentNode = pCurrentNode->next;
		}
		printf("---------------------------------------------------\n");
		pCurrentNode = pLastNode;
		while (pCurrentNode != NULL)
		{
			printf("%f\n", pCurrentNode->val);
			pCurrentNode = pCurrentNode->last;
		}
	}

	void invertTree() {
		auto swapNode = [](TreeNode * pNode) mutable {
			TreeNode * temp = pNode->last;
			pNode->last = pNode->next;
			pNode->next = temp;
		};
		preOrderTraverse(swapNode);
	}
private:
	void insertOnNode(TreeNode * pNewNode, TreeNode * pTargetNode) {
		if (pNewNode->val > pTargetNode->val)
		{
			if (pTargetNode->next == NULL) {
				pTargetNode->next = pNewNode;
				return;
			}
			else
			{
				insertOnNode(pNewNode, pTargetNode->next);
			}
		}
		else
		{
			if (pTargetNode->last == NULL) {
				pTargetNode->last = pNewNode;
				return;
			}
			else
			{
				insertOnNode(pNewNode, pTargetNode->last);
			}
		}
	}

	void inOrderTraverseNode(TreeNode * pTargetNode, std::function<void(TreeNode *)> & func) {
		if (pTargetNode->last != NULL)
		{
			inOrderTraverseNode(pTargetNode->last, func);
		}
		func(pTargetNode);
		if (pTargetNode->next != NULL)
		{
			inOrderTraverseNode(pTargetNode->next, func);
		}
		return;
	}

	void preOrderTraverseNode(TreeNode * pTargetNode, std::function<void(TreeNode *)> & func) {
		func(pTargetNode);
		if (pTargetNode->last != NULL)
		{
			preOrderTraverseNode(pTargetNode->last, func);
		}
		if (pTargetNode->next != NULL)
		{
			preOrderTraverseNode(pTargetNode->next, func);
		}
		return;
	}
	TreeNode * rootNode = NULL;
};

#endif // BINARY_TREE
