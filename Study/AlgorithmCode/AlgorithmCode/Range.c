#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define MAX 20
#define MIN 1

void RandValueCreate(int *);
void PrintArray(int *);
void SequenceSort(int *);						//���� ���� O(n^2)
void BubbleSort(int *);							//���� ���� O(n^2)
void SelectSort(int *);							//���� ���� O(n^2)
void InsertSort(int *);							//���� ���� O(n^2)

void MergeSort(int *);								//�պ� ���� (���� ��)
void MergeSortRecursive(int *, int, int);			//�պ� ���� (��͹ݺ�)
void Merge(int *, int, int, int);

void ShellSort(int *);							//�� ����
void ShellOfExclusiveIntertSort(int *, int);	//�� �˰��� ���� ��������
void gap_insertion_sort(int*, int, int, int);

void QuickSort(int *, int, int);							//�� ���� 
void HeapSort(int *);							//�� ���� 

////������
//int main() {
//	int tempAr[MAX];
//
//	RandValueCreate(tempAr);
//	printf("=========���� �� �迭=========");
//	PrintArray(tempAr);
//	printf("=========���� �� �迭=========\n\n");
//
//	//SequenceSort(tempAr);
//	//BubbleSort(tempAr);
//	//SelectSort(tempAr);
//	//InsertSort(tempAr);
//	//MergeSort(tempAr);
//	/*ShellSort(tempAr);*/
//	QuickSort(tempAr, 0, MAX - 1);
//
//	printf("=========���� �� �迭=========");
//	PrintArray(tempAr);
//	printf("=========���� �� �迭=========\n\n");
//	return 0;
//}

//�⺻ ����Լ�
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

//��������
void SequenceSort(int *arr){
	printf("=========���� �� �迭=========\n\n");
	PrintArray(arr);

	for (int arr_i = 0; arr_i < MAX; arr_i++){
		printf("=========ù��° �ݺ��� ����=========\n\n");
		for (int arr_j = arr_i; arr_j < MAX; arr_j++){
			if (arr[arr_i] > arr[arr_j]){
				Swap(&arr[arr_i], &arr[arr_j]);
				PrintArray(arr);
			}
		}
		printf("=========ù��° �ݺ��� ����=========\n\n");
	}

	printf("=========���� ���� �迭=========\n\n");
	PrintArray(arr);
}

//��������
void BubbleSort(int *arr){
	printf("=========���� �� �迭=========\n\n");
	PrintArray(arr);
	
	for (int arr_i = MAX; arr_i > 1; arr_i--){
		printf("=========ù��° �ݺ��� ����=========\n\n");
		for (int arr_j = 0; arr_j < arr_i - 1; arr_j++){
			if (arr[arr_j] > arr[arr_j + 1]){
				Swap(&arr[arr_j], &arr[arr_j + 1]);
				PrintArray(arr);
			}
		}
		printf("=========ù��° �ݺ��� ����=========\n\n");	
	}

	printf("=========���� ���� �迭=========\n\n");
	PrintArray(arr);
}

//��������
void SelectSort(int *arr){
	printf("=========���� �� �迭=========\n\n");
	PrintArray(arr);

	for (int arr_i = 0; arr_i < MAX; arr_i++){
		printf("=========ù��° �ݺ��� ����=========\n\n");
		int minIndex = arr_i;

		for (int arr_j = arr_i + 1; arr_j < MAX; arr_j++){
			if (arr[minIndex] > arr[arr_j])
				minIndex = arr_j;
		}

		Swap(&arr[arr_i], &arr[minIndex]);
		PrintArray(arr);
		printf("=========ù��° �ݺ��� ����=========\n\n");
	}

	printf("=========���� ���� �迭=========\n\n");
	PrintArray(arr);
}

//��������
void InsertSort(int *arr){
	printf("=========���� �� �迭=========\n\n");
	PrintArray(arr);

	for (int arr_i = MAX - 1; arr_i > 1; arr_i--){
		printf("=========ù��° �ݺ��� ����=========\n\n");

		for (int arr_j = 0; arr_j < arr_i; arr_j++){
			if (arr[arr_i] < arr[arr_j])
				Swap(&arr[arr_i], &arr[arr_j]);
		}

		PrintArray(arr);
		printf("=========ù��° �ݺ��� ����=========\n\n");
	}

	printf("=========���� ���� �迭=========\n\n");
	PrintArray(arr);
}

//�պ�����
void MergeSort(int *arr){
	printf("=========���� �� �迭=========\n\n");
	PrintArray(arr);
	printf("=========���� �� �迭=========\n\n");

	MergeSortRecursive(arr, 0, MAX-1);

	printf("=========���� ���� �迭=========\n\n");
	PrintArray(arr);
}
void MergeSortRecursive(int * arr, int fromIdx, int toIdx){
	int mid = 0;
	if (fromIdx < toIdx){
		mid = (fromIdx + toIdx) / 2;
		MergeSortRecursive(arr, fromIdx, mid);					//�迭�� ���ʺκ� ���
		MergeSortRecursive(arr, mid + 1, toIdx);				//�迭�� ���ʺκ� ���
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

//�� ����
void ShellSort(int *arr){
	printf("=========���� �� �迭=========");
	PrintArray(arr);
	printf("=========���� �� �迭=========\n\n");

	int step, j;
	for (step = MAX / 2; step > 0; step /= 2){
		if (step % 2 == 0)
			step++;

		for (j = 0; j < step; j++)
			gap_insertion_sort(arr, j, MAX - 1, step);
	}
	
	printf("=========���� ���� �迭=========\n\n");
	PrintArray(arr);
}
void gap_insertion_sort(int* list, int first, int last, int gap)
{
	int i, j, key;

	// ���� ���Ŀ����� ù ��° ���Ҵ� ������ �� �ʿ䰡 �����Ƿ�
	// �� ���� �ε��� ���� key������ ��������� ������ �ʱⰪ��
	// first + gap�̴�.
	for (i = first + gap; i <= last; i += gap)
	{
		// �� �ݺ����� �ε��� i���� gap�� ���������ν� �κ� ����Ʈ ���� ������ ����
		key = list[i];

		// Ű �� ������ �迭�� ������ �����ϸ鼭 key���� �� ��ġ�� ã�´�.
		for (j = i - gap; j >= first && list[j] > key; j -= gap)
		{
			// ���������� �� �ݺ����� 1�� ���ҽ�Ű�� ���� �ƴ� gap�� ���ҽ�Ŵ���ν�
			// �κи���Ʈ�� ���� ������ �����Ѵ�.
			list[j + gap] = list[j];
		}
		list[j + gap] = key;
	}
}

//�� ����
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
////���� ����(Merge Sort)
//#include <stdio.h>
//#include <stdlib.h>
//#include <memory.h>
//
//#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a�� b�� ��ȯ
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
//	int ahalf = n / 2; //�迭�� ���� ����
//	int bhalf = n - ahalf; //�迭�� ���� ����
//	int ai = 0, bi = ahalf;
//	int i = 0;
//
//	int *tbase = 0;
//
//	if (n <= 1)//�迭�� ũ�Ⱑ 1���� �۰ų� ���� ��
//	{
//		return;
//	}
//
//	MergeSort(base, ahalf);//���� �迭 ���ȣ��� ����
//	PrintSpace(base - origin);
//	ViewArr(base, ahalf);
//	MergeSort(base + ahalf, bhalf);//���� �迭 ���ȣ��� ����
//	PrintSpace(base + ahalf - origin);
//	ViewArr(base + ahalf, bhalf);
//	tbase = (int *)malloc(sizeof(int)*n);//�迭 ũ���� �ӽ� ������ �Ҵ�
//	memcpy(tbase, base, sizeof(int)*n);//�ӽ� ������ �迭 �޸� ����
//
//	while ((ai<ahalf) && (bi<n))
//	{
//		if (tbase[ai] <= tbase[bi])//������ ũ�ų� ���� ��
//		{
//			base[i] = tbase[ai];//���� �迭�� ���Ҹ� ����
//			ai++;
//		}
//		else
//		{
//			base[i] = tbase[bi];//���� �迭�� ���Ҹ� ����
//			bi++;
//		}
//		i++;
//	}
//
//
//	while (ai<ahalf)//���� �迭�� ���� �͵��� ����
//	{
//		base[i] = tbase[ai];
//		i++;
//		ai++;
//	}
//
//	while (bi<n)//���� �迭�� ���� �͵��� ����
//	{
//		base[i] = tbase[bi];
//		i++;
//		bi++;
//
//	}
//
//	free(tbase);//�ӽ� ���ۿ� �Ҵ��� �޸� ����       
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
