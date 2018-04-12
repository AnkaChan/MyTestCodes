#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;

template<typename T> 
class DemoClass {
public:
	static int id = 0;
	T val;

};

typedef DemoClass<int> C1;
typedef DemoClass<int> C2;

//int C1::id = 0;
//int C2::id = 0;

class SonClass : public C1 {
	float val;
};

int main(int argc, char** argv) {

	C1 c1;
	C2 c2;

	C2::id = 2;
	C1::id = 1;

	printf("c1: %d\n", C1::id);
	printf("c2: %d\n", C2::id);
	printf("Son: %d\n", SonClass::id);
	getchar();
}