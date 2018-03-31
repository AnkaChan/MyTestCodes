#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Array.h"

#define _CRTDBG_MAP_ALLOC   //并非绝对需要该语句，但如果有该语句，打印出来的是文件名和行数等更加直观的信息
#define _CRTDBG_MAP_ALLOC_NEW
#include <stdlib.h>
#include <crtdbg.h> 

using std::cout;
using std::endl;
using std::vector;

typedef CArray<int, 8> IntArray;
#define for_int(index, begin, end) for (int index = begin; index < end; ++index)

void showArray(IntArray & arr) {
	return;
	printf("Array: capacity: %d, size: %d, content: ", (int)arr.capacity(), (int)arr.size());
	for (size_t i = 0; i < arr.size(); i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

int main(int argc, char** argv) {
	for_int(nn, 0, 100000) {
		IntArray arr;
		showArray(arr);

		for_int(i, 0, 8) {
			arr.push_back(i);
		}
		showArray(arr);

		for_int(i, 0, 8) {
			arr.push_back(i);
		}
		showArray(arr);

		arr.reserve(arr.size());
		showArray(arr);

		arr.clear();
		showArray(arr);

		for_int(i, 0, 8) {
			arr.push_back(i);
		}
		arr.erase(5);
		showArray(arr);
		arr.eraseN(3, 2);
		showArray(arr);
		arr.insert(2, 1);
		arr.insert(2, 3);
		arr.insert(2, 4);
		showArray(arr);
		arr.insertN(2, 2);
		showArray(arr);

		arr.insertN(3, 11);
		showArray(arr);
		arr.clear();
		showArray(arr);
		arr.reserve(8);
		arr.clear();
		showArray(arr);
		for_int(i, 0, 8) {
			arr.push_back(i);
		}for_int(i, 0, 8) {
			arr.push_back(i);
		}

		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	}
	getchar();
	int * pArr = new int[47];
	_CrtDumpMemoryLeaks();
}