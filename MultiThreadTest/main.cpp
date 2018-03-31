#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <map>
#include <omp.h>
#include <ctime>
#include <mutex>
#include <random>
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

#pragma omp parallel for num_threads(4)
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", i);
	}
	getchar();
	double a;
	int iterNum = 100000;
	int workNum = 10000;
	
	clock_t time1 = clock();
	std::vector<double> vec(iterNum);
	std::vector<std::mutex> lockVec(iterNum); 
	//
	//omp_set_num_threads(4);
	////#pragma omp parallel for
	//for (int i = 0; i < iterNum; ++i) {
	//	std::default_random_engine generator(time(NULL));
	//	std::uniform_int_distribution<int> randInt(0, iterNum - 1);
	//	double aa = 0;
	//	for (int j = 0; j < workNum; ++j) {
	//
	//		int k = randInt(generator);
	//		lockVec[k].lock();
	//
	//		vec[k] += sqrt(j);
	//
	//		lockVec[k].unlock();
	//	}
	//	//vec[i] += aa;
	//}
	//printf("vec.front() = %lf\n", vec.front());
	//time1 = clock() - time1;
	//
	//printf("vec.front() = %lf\n", vec.front());
	//printf("Time consumed: %d\n", time1);
	//printf("intMap.size() = %d\n", intMap.size());

	//omp_set_num_threads(1);
	
	for (int i = 0; i < iterNum; ++i) {
		double aa = 0;
		#pragma omp parallel for
		for (int j = 0; j < workNum; ++j) {
			aa += sqrt(j);
		}
		vec[i] += aa;
	}
	printf("vec.front() = %lf\n", vec.front());
	time1 = clock() - time1;
	
	printf("vec.front() = %lf\n", vec.front());
	printf("Time consumed: %d\n", time1);
	printf("intMap.size() = %d\n", intMap.size());



	getchar();
}