#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;

#define for_int(index, begin, end) for (int index = begin; index < end; ++index)

#define ARRAY_LEN 100000
#define ITER_NUM 1000000

void showArr(int * begin, int len) {
	printf("Array is: ");
	for_int(i, 0, len) {
		printf("%d ", begin[i]);
	}
	printf("\n");
}

int main(int argc, char** argv) {
	int arr1[] = { 1 ,2, 3, 4 };
	int* arr2 = new int[4];
	std::move(arr1, arr1 + 4, arr2);

	showArr(arr1, 4);
	showArr(arr2, 4);



	int testArr1[ARRAY_LEN];
	int testArr2[ARRAY_LEN];

	for_int(i, 0, ARRAY_LEN) {
		testArr1[i] = i;
	}

	//std::move vs memcpy
	clock_t time1 = clock();
	for_int(i, 0, ITER_NUM) {
		std::move(testArr1, testArr1 + ARRAY_LEN, testArr2);
	}
	time1 = clock() - time1;
	printf("Time consumed in std::move: %d\n", time1);

	//std::move vs memcpy
	clock_t time2 = clock();
	for_int(i, 0, ITER_NUM) {
		memcpy(testArr1, testArr1, ARRAY_LEN * sizeof(int));
	}
	time2 = clock() - time2;
	printf("Time consumed in memcpy: %d\n", time2);

	getchar();
}