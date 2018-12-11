template<typename T>
void quickSort(T * arr, int head, int tail){
	T pivot = arr[head];
	int i = head, j =tail;
	if (head >= tail) return ;
	while(i < j){
		while (i < j && arr[j] > pivot) --j;
		arr[i] = arr[j];
		while (i < j && arr[i] <= pivot) ++i;
		arr[j] = arr[i];
	}
	arr[i] = pivot;
	quickSort(arr, head, i-1);
	quickSort(arr, j+1, tail);
}