#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <omp.h>
#include "SpinLock.h"
#include <mutex>
#include <ctime>
#include <random>

using std::cout;
using std::endl;
using std::vector;

#define VEC_SIZE 1000

struct DemoStruct
{
	DemoStruct():
		mString("Demo Struct"),
		mIntVec(VEC_SIZE)
	{}
	std::string mString;
	std::vector<int> mIntVec;
};

class SafeContainerSpinLock
{
public:
	SafeContainerSpinLock() {};
	~SafeContainerSpinLock() {};

	void put(DemoStruct * pDS) {
		mLock.lock();
		mVec.push_back(pDS);
		mLock.unlock();
		return;
	}

private:
	std::vector<DemoStruct*> mVec;
	std::mutex mLock;
};

class UnsafeContainer
{
public:
	UnsafeContainer() {};
	~UnsafeContainer() {};

	void put(DemoStruct * pDS) {
		mVec.push_back(pDS);
		return;
	}

private:
	std::vector<DemoStruct*> mVec;
};

class SafeContainerMutex
{
public:
	SafeContainerMutex() {};
	~SafeContainerMutex() {};

	void put(DemoStruct * pDS) {
		mLock.lock();
		mVec.push_back(pDS);
		mLock.unlock();
		return;
	}

private:
	std::vector<DemoStruct*> mVec;
	SpinLock mLock;
};


int main(int argc, char** argv) {

	std::default_random_engine generator(time(NULL));

	std::uniform_int_distribution<int> randInt(1, 1000);
	randInt(generator);
	int size = 100000;

	SafeContainerSpinLock safeContainerSL;
	clock_t time1 = clock();
//#pragma omp parallel for
	for (int i = 0; i < size; i++)
	{
		DemoStruct * pDS = new DemoStruct;
		for (int i = 0; i < VEC_SIZE; ++i) {
			pDS->mIntVec[i] = randInt(generator);
		}

		safeContainerSL.put(pDS);

	}
	time1 = clock() - time1;
	printf("Time consumed in spinLock: %d\n", time1);

	SafeContainerSpinLock safeContainerMtx;
	clock_t time2 = clock();
	//#pragma omp parallel for
	for (int i = 0; i < size; i++)
	{
		DemoStruct * pDS = new DemoStruct;
		for (int i = 0; i < VEC_SIZE; ++i) {
			pDS->mIntVec[i] = randInt(generator);
		}

		safeContainerMtx.put(pDS);
	}
	time2 = clock() - time2;
	printf("Time consumed in mutex: %d\n", time2);

	UnsafeContainer unsafeContainer;
	clock_t time3 = clock();
	for (int i = 0; i < size; i++)
	{
		DemoStruct * pDS = new DemoStruct;
		for (int i = 0; i < VEC_SIZE; ++i) {
			pDS->mIntVec[i] = randInt(generator);
		}

		unsafeContainer.put(pDS);
	}
	time3 = clock() - time3;
	printf("Time consumed in unsafeContainer: %d\n", time3);

	getchar();
}