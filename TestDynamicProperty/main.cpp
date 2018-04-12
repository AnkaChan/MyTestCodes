#include <iostream>
#include "Array.h"
using std::cout;
using std::endl;

template<typename T>
class Prop {
public:
	T val;
	static int index;
};

typedef Prop<std::string> MyProp;

int main(int argc, char** argv) {
	MyProp p;
	p.index = 0;

	MyProp mP;
	mP.index = 1;

	printf("Prop's static index: %d\n", p.index);
	printf("MyProp's static index: %d\n", mP.index);

}