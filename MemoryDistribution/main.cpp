#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;

class CBuiltInMem
{
public:
	int & getInt(int i) { return _mem[i]; };

private:
	int _mem[500];
};


int main(int argc, char** argv) {
	int iterNum = 10000;
	int workNum = 1000;
	std::vector<int *> vecPInt(workNum);
	std::vector<vector<int>> vecVec(workNum);
	std::vector<CBuiltInMem> vecCBI;

	clock_t time1 = clock();
	for (int i = 0; i < iterNum; ++i) {
		for (int j = 0; j < workNum; j++)
		{
			std::vector<int> vec;
			vec.resize(500);
			vecVec[j] = vec;
		}
	}
	time1 = clock() - time1;

	printf("Time consumed in vector memory allocating: %d\n", time1);

	clock_t time2 = clock();
	for (int i = 0; i < iterNum; ++i) {
		for (int j = 0; j < workNum; j++)
		{
			vecPInt[j] = new int[500];
		}
		for (int j = 0; j < workNum; j++)
		{
			delete[] vecPInt[j];
		}
	}
	time2 = clock() - time2;
	printf("Time consumed in new memory allocating: %d\n", time2);

	clock_t time3 = clock();
	for (int i = 0; i < iterNum; ++i) {
		for (int j = 0; j < workNum; j++)
		{
			CBuiltInMem bIM;
			vecCBI.push_back(bIM);
		}
		vecCBI.clear();
	}
	time3 = clock() - time3;
	printf("Time consumed in built-in memory allocating: %d\n", time3);


	getchar();
}