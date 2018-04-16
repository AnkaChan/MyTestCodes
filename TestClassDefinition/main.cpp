#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "DemoClass.h"

using std::cout;
using std::endl;
using std::vector;

class Class2 {
public:
	int k;
	DemoClass c;
	int getI();
};


int main(int argc, char** argv) {
	Class2 c2;
	DemoClass c1;

	printf("%d, %d\n", c2.getI(), c1.getI());

}