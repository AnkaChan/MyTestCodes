#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char** argv) {
	
	int rVal = system("SayHello");
	printf("Return value is: %d\n", rVal);
	getchar();
}