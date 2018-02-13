#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <map>
#include <omp.h>

using std::cout;
using std::endl;
using std::vector;

int count = 0;
std::map<int, int> intMap;
template<typename T>
void add() {
	#pragma omp critical
	{
		++count;
		intMap.insert(std::pair<int, T>(count, count));
	}
}

int main(int argc, char** argv) {
	

	#pragma omp parallel for
	for (int i = 0; i < 100000; ++i) {

		add<int>();
	}
	
	printf("count = %d\n", count);
	printf("intMap.size() = %d\n", intMap.size());
	getchar();
}