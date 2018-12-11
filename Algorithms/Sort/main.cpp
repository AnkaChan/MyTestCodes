#include <iostream>
#include "QuickSort.h"

int main() {
	int arr[12] = { 17, 22,6,8,1,5,5,23,12,57,12,3 };
	quickSort<int>(arr, 0, 11);

	for (int i = 0; i < 12; i++)
	{
		printf("%d ", arr[i]);
	}
}