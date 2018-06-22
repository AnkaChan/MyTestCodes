#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <random>
#include "BinaryTree.h"

using std::cout;
using std::endl;
using std::vector;

class ShowNode {
public:
	void operator()(TreeNode * pNode) {
		printf("%f\n", pNode -> val);
		

	}
};

int main(int argc, char** argv) {
	std::default_random_engine generator(time(NULL));
	std::uniform_real_distribution<double> randReal(0.0, 1.0);
	randReal(generator);

	CBinaryTree tree;

	for (int i = 0; i < 20; i++)
	{
		tree.insert(randReal(generator));
	}
	/*tree.inOrderTraverse(ShowNode());
	printf("---------------------------------------------------\n");
	tree.changeToList();*/
	tree.invertTree();
	tree.inOrderTraverse(ShowNode());
}