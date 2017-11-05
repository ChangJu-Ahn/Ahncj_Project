#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define MAX 20
#define MIN 1

void RandValueCreate(int *);
void PrintArray(int *);
void SequenceSort(int *);						//순차 정렬 O(n^2)
void BubbleSort(int *);							//버블 정렬 O(n^2)
void SelectSort(int *);							//선택 정렬 O(n^2)
void InsertSort(int *);							//삽입 정렬 O(n^2)

void MergeSort(int *);								//합병 정렬 (시작 점)
void MergeSortRecursive(int *, int, int);			//합병 정렬 (재귀반복)
void Merge(int *, int, int, int);

void ShellSort(int *);							//쉘 정렬
void ShellOfExclusiveIntertSort(int *, int);	//쉘 알고리즘 전용 삽입정렬
void gap_insertion_sort(int*, int, int, int);

void QuickSort(int *, int, int);							//퀵 정렬 
void HeapSort(int *);							//힙 정렬 

////시작점
//int main() {
//	int tempAr[MAX];
//
//	RandValueCreate(tempAr);
//	printf("=========정렬 전 배열=========");
//	PrintArray(tempAr);
//	printf("=========정렬 전 배열=========\n\n");
//
//	//SequenceSort(tempAr);
//	//BubbleSort(tempAr);
//	//SelectSort(tempAr);
//	//InsertSort(tempAr);
//	//MergeSort(tempAr);
//	/*ShellSort(tempAr);*/
//	QuickSort(tempAr, 0, MAX - 1);
//
//	printf("=========정렬 후 배열=========");
//	PrintArray(tempAr);
//	printf("=========정렬 후 배열=========\n\n");
//	return 0;
//}

//기본 사용함수
void Swap(int *first, int *second){
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}
void RandValueCreate(int *arr){
	int i = 0;
	for (; i < MAX; i++)
		arr[i] = rand() % MAX;
}
void PrintArray(int *arr){
	int i = 0;
	for (; i < MAX; i++)
		printf("%2d, ", arr[i]);
	printf("\n");
}

//순차정렬
void SequenceSort(int *arr){
	printf("=========정렬 전 배열=========\n\n");
	PrintArray(arr);

	for (int arr_i = 0; arr_i < MAX; arr_i++){
		printf("=========첫번째 반복문 시작=========\n\n");
		for (int arr_j = arr_i; arr_j < MAX; arr_j++){
			if (arr[arr_i] > arr[arr_j]){
				Swap(&arr[arr_i], &arr[arr_j]);
				PrintArray(arr);
			}
		}
		printf("=========첫번째 반복문 종료=========\n\n");
	}

	printf("=========최종 정렬 배열=========\n\n");
	PrintArray(arr);
}

//버블정렬
void BubbleSort(int *arr){
	printf("=========정렬 전 배열=========\n\n");
	PrintArray(arr);
	
	for (int arr_i = MAX; arr_i > 1; arr_i--){
		printf("=========첫번째 반복문 시작=========\n\n");
		for (int arr_j = 0; arr_j < arr_i - 1; arr_j++){
			if (arr[arr_j] > arr[arr_j + 1]){
				Swap(&arr[arr_j], &arr[arr_j + 1]);
				PrintArray(arr);
			}
		}
		printf("=========첫번째 반복문 종료=========\n\n");	
	}

	printf("=========최종 정렬 배열=========\n\n");
	PrintArray(arr);
}

//선택정렬
void SelectSort(int *arr){
	printf("=========정렬 전 배열=========\n\n");
	PrintArray(arr);

	for (int arr_i = 0; arr_i < MAX; arr_i++){
		printf("=========첫번째 반복문 시작=========\n\n");
		int minIndex = arr_i;

		for (int arr_j = arr_i + 1; arr_j < MAX; arr_j++){
			if (arr[minIndex] > arr[arr_j])
				minIndex = arr_j;
		}

		Swap(&arr[arr_i], &arr[minIndex]);
		PrintArray(arr);
		printf("=========첫번째 반복문 종료=========\n\n");
	}

	printf("=========최종 정렬 배열=========\n\n");
	PrintArray(arr);
}

//삽입정렬
void InsertSort(int *arr){
	printf("=========정렬 전 배열=========\n\n");
	PrintArray(arr);

	for (int arr_i = MAX - 1; arr_i > 1; arr_i--){
		printf("=========첫번째 반복문 시작=========\n\n");

		for (int arr_j = 0; arr_j < arr_i; arr_j++){
			if (arr[arr_i] < arr[arr_j])
				Swap(&arr[arr_i], &arr[arr_j]);
		}

		PrintArray(arr);
		printf("=========첫번째 반복문 종료=========\n\n");
	}

	printf("=========최종 정렬 배열=========\n\n");
	PrintArray(arr);
}

//합병정렬
void MergeSort(int *arr){
	printf("=========정렬 전 배열=========\n\n");
	PrintArray(arr);
	printf("=========정렬 전 배열=========\n\n");

	MergeSortRecursive(arr, 0, MAX-1);

	printf("=========최종 정렬 배열=========\n\n");
	PrintArray(arr);
}
void MergeSortRecursive(int * arr, int fromIdx, int toIdx){
	int mid = 0;
	if (fromIdx < toIdx){
		mid = (fromIdx + toIdx) / 2;
		MergeSortRecursive(arr, fromIdx, mid);					//배열의 앞쪽부분 재귀
		MergeSortRecursive(arr, mid + 1, toIdx);				//배열의 앞쪽부분 재귀
		Merge(arr, fromIdx, mid, toIdx);
	}
}
void Merge(int * arr, int first, int mid, int end){
	int *tempArr = (int *)malloc(sizeof(int) * MAX);

	int start = first;
	int midBase = mid + 1;
	int index = first;

	while (start <= mid && midBase <= end){
		if (arr[start] <= arr[midBase])
			tempArr[index++] = arr[start++];
		else
			tempArr[index++] = arr[midBase++];
	}

	while (start <= mid)	
		tempArr[index++] = arr[start++];
	while (midBase <= end)
		tempArr[index++] = arr[midBase++];

	for (int i = first; i <= end; i++)
		arr[i] = tempArr[i];

	free(tempArr);
	PrintArray(arr);
}

//쉘 정렬
void ShellSort(int *arr){
	printf("=========정렬 전 배열=========");
	PrintArray(arr);
	printf("=========정렬 전 배열=========\n\n");

	int step, j;
	for (step = MAX / 2; step > 0; step /= 2){
		if (step % 2 == 0)
			step++;

		for (j = 0; j < step; j++)
			gap_insertion_sort(arr, j, MAX - 1, step);
	}
	
	printf("=========최종 정렬 배열=========\n\n");
	PrintArray(arr);
}
void gap_insertion_sort(int* list, int first, int last, int gap)
{
	int i, j, key;

	// 삽입 정렬에서도 첫 번째 원소는 정렬을 할 필요가 없으므로
	// 그 다음 인덱스 값을 key값으로 설정해줬기 때문에 초기값은
	// first + gap이다.
	for (i = first + gap; i <= last; i += gap)
	{
		// 각 반복별로 인덱스 i값에 gap을 더해줌으로써 부분 리스트 삽입 정렬을 구현
		key = list[i];

		// 키 값 이전의 배열의 값들을 조사하면서 key값이 들어갈 위치를 찾는다.
		for (j = i - gap; j >= first && list[j] > key; j -= gap)
		{
			// 마찬가지로 각 반복별로 1을 감소시키는 것이 아닌 gap을 감소시킴으로써
			// 부분리스트의 삽입 정렬을 구현한다.
			list[j + gap] = list[j];
		}
		list[j + gap] = key;
	}
}

//퀵 정렬
void QuickSort(int *arr, int first, int end){
	int left = first;
	int right = end;
	int pivot = arr[(first + end) / 2];

	do{
		while (arr[left] < pivot)	
			left++;
		while (arr[right] > pivot)	
			right--;

		if (left <= right){
			int temp = arr[left];
			arr[left++] = arr[right];
			arr[right--] = temp;
		}
	} while (left <= right);

	if (first < right) QuickSort(arr, first, right);
	if (end > left) QuickSort(arr, left, end);
}




















//
////병합 정렬(Merge Sort)
//#include <stdio.h>
//#include <stdlib.h>
//#include <memory.h>
//
//#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a와 b를 교환
//
//
//int *origin;
//int on;
//
//void MergeSort(int *base, int n);
//void ViewArr(int *arr, int n);
//int main(void)
//{
//	int arr[15] = { 9, 4, 3, 10, 5, 8, 7, 6, 2, 1 , 2, 45, 10, 4, 3};
//	origin = arr;
//	on = 15;
//	ViewArr(origin, on);
//	MergeSort(arr, 15);
//	ViewArr(origin, on);
//	return 0;
//}
//
//void PrintSpace(int n);
//void MergeSort(int *base, int n)
//{
//	int ahalf = n / 2; //배열의 앞쪽 개수
//	int bhalf = n - ahalf; //배열의 뒤쪽 개수
//	int ai = 0, bi = ahalf;
//	int i = 0;
//
//	int *tbase = 0;
//
//	if (n <= 1)//배열의 크기가 1보다 작거나 같을 때
//	{
//		return;
//	}
//
//	MergeSort(base, ahalf);//앞쪽 배열 재귀호출로 정렬
//	PrintSpace(base - origin);
//	ViewArr(base, ahalf);
//	MergeSort(base + ahalf, bhalf);//뒤쪽 배열 재귀호출로 정렬
//	PrintSpace(base + ahalf - origin);
//	ViewArr(base + ahalf, bhalf);
//	tbase = (int *)malloc(sizeof(int)*n);//배열 크기의 임시 공간을 할당
//	memcpy(tbase, base, sizeof(int)*n);//임시 공간에 배열 메모리 복사
//
//	while ((ai<ahalf) && (bi<n))
//	{
//		if (tbase[ai] <= tbase[bi])//뒤쪽이 크거나 같을 때
//		{
//			base[i] = tbase[ai];//앞쪽 배열의 원소를 대입
//			ai++;
//		}
//		else
//		{
//			base[i] = tbase[bi];//뒤쪽 배열의 원소를 대입
//			bi++;
//		}
//		i++;
//	}
//
//
//	while (ai<ahalf)//앞쪽 배열의 남은 것들을 대입
//	{
//		base[i] = tbase[ai];
//		i++;
//		ai++;
//	}
//
//	while (bi<n)//뒤쪽 배열의 남은 것들을 대입
//	{
//		base[i] = tbase[bi];
//		i++;
//		bi++;
//
//	}
//
//	free(tbase);//임시 버퍼에 할당한 메모리 해제       
//}
//void PrintSpace(int n)
//{
//	int i = 0;
//	for (i = 0; i<n; i++)
//	{
//		printf("   ");
//	}
//}
//void ViewArr(int *arr, int n)
//{
//	int i = 0;
//	for (i = 0; i<n; i++)
//	{
//		printf("%2d ", arr[i]);
//	}
//	printf("\n");
//}
