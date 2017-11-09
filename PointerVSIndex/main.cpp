#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;
typedef std::vector<int> MyVec;

#define NUM 100000000
#define LOOP 1000

struct WithPointer
{
	int * p;
};

struct WithIndex
{
	int index;
};

int main(int argc, char** argv) {
	MyVec vec(NUM);

	int a = 0;
	for (int & i : vec) {
		i = ++a;
	}

	vector<WithIndex> indexVec(NUM);
	for (size_t i = 0; i < NUM; i++)
	{
		indexVec[i].index = i;
	}

	vector<WithPointer> pointerVec(NUM);
	for (size_t i = 0; i < NUM; i++)
	{
		pointerVec[i].p = &vec[i];
	}

	int sum = 0;
	clock_t time1;
	clock_t startTime = clock();
	for (size_t k = 0; k < LOOP; k++)
	{

		for (size_t i = 0; i < NUM; i++)
		{
			sum += vec[indexVec[i].index];
		}

	}
	clock_t endTime = clock();
	time1 = endTime - startTime;

	cout << "Time comsumed using index: " << time1 << endl;

	cout << sum << endl;

	sum = 0;
	clock_t time2;
	startTime = clock();
	for (size_t k = 0; k < LOOP; k++)
	{
		for (size_t i = 0; i < NUM; i++)
		{
			sum += *pointerVec[i].p;
		}
	}
	endTime = clock();
	time2 = endTime - startTime;

	cout << "Time comsumed using pointer: " << time2 << endl;
	cout << sum << endl;

	getchar();
}