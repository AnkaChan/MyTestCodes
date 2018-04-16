#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <map>
#include <omp.h>

#define REPEAT_TIMES 10000000
#define NUM_THREADS 4

#include <ctime>
#include <mutex>
#include <random>

using std::cout;
using std::endl;
using std::vector;

int count = 0;

#include <ctime>
#include <random>

int main(int argc, char** argv) {
<<<<<<< HEAD
	std::vector<int> vec(REPEAT_TIMES);


	std::default_random_engine generator(time(NULL));
	std::uniform_int_distribution<int> randInt(1, 100);
	
	// omp lock
	#pragma omp parallel for num_threads(4)
	for (int i = 0; i < REPEAT_TIMES; ++i) {
		vec[i] = randInt(generator);
	}

	clock_t time1 = clock();

//	int g90Count = 0;
//	#pragma omp parallel for num_threads(4)
//	for (int i = 0; i < REPEAT_TIMES; ++i) {
//		if (vec[i] > 98)
//		{
//		#pragma omp critical
//			{
//				++g90Count;
//			}
//		}
//	}

	//printf("");

	std::vector<int> vec1(REPEAT_TIMES);
	std::vector<int> vec2(REPEAT_TIMES);
	std::vector<int> vec3(REPEAT_TIMES);
	std::vector<int> vec4(REPEAT_TIMES);

//#pragma omp parallel sections num_threads(2)
//	{
//#pragma omp section
//		{
//			printf("Thread %d.\n", omp_get_thread_num());
//			for (int i = 0; i < REPEAT_TIMES; ++i) {
//				vec1[i] = randInt(generator);
//			}
//		}
//#pragma omp section
//		{
//			printf("Thread %d.\n", omp_get_thread_num());
//			for (int i = 0; i < REPEAT_TIMES; ++i) {
//				vec2[i] = randInt(generator);
//			}
//		}
//#pragma omp section
//		{
//			printf("Thread %d.\n", omp_get_thread_num());
//			for (int i = 0; i < REPEAT_TIMES; ++i) {
//				vec3[i] = randInt(generator);
//			}
//		}
//#pragma omp section
//		{
//			printf("Thread %d.\n", omp_get_thread_num());
//			for (int i = 0; i < REPEAT_TIMES; ++i) {
//				vec4[i] = randInt(generator);
//			}
//		}
//	}
//
#pragma omp parallel num_threads(4)
	{
		printf("Thread %d.\n", omp_get_thread_num());
	}

	// Map reduce

	int numThreads = 4;
	double sum[NUM_THREADS] = {0.0, 0.0, 0.0, 0.0 };

#pragma omp parallel for num_threads(NUM_THREADS)
	for (int i = 0; i < REPEAT_TIMES; ++i) {
		int tId = omp_get_thread_num();
		sum[tId] += sqrt(vec[i]);
	}

	double allSum1 = 0;
	for (int i = 0; i < NUM_THREADS; ++i) {
		allSum1 += sum[i];
	}
	printf("All sum: %f\n", allSum1);

	double allSum2 = 0;
#pragma omp parallel for
	for (int i = 0; i < REPEAT_TIMES; ++i) {
#pragma omp critical
		{
			allSum2 += sqrt(vec[i]);
		}
	}
	printf("All sum: %f\n", allSum2);


	time1 = clock() - time1;
	printf("Time consumption£º%d ms \n", time1);
	
=======

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



>>>>>>> 5582c4aa59a09e0731440fa01082256404c71493
	getchar();
}