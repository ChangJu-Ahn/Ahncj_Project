////#include <math.h>
////#include <stdio.h>
////#include <string.h>
////#include <stdlib.h>
////#include <assert.h>
////#include <limits.h>
////#include <stdbool.h>
////
////
////int main() {
////	int n;
////	scanf("%i", &n);
////	int *ar = malloc(sizeof(int) * n);
////	int area[100] = { 0 };
////	int pair = 0;
////	for (int ar_i = 0; ar_i < n; ar_i++){
////		scanf("%i", &ar[ar_i]);
////		area[ar[ar_i] - 1]++;
////	}
////
////	for (int area_i = 0; area_i < 100; area_i++){
////		pair += area[area_i] / 2;
////	}
////
////	printf("%d\n", pair);
////	return 0;
////}
//
//#include <stdio.h>
//
//int LSearch(int ar[], int len, int target){
//	int i = 0;
//	for (; i < len; i++){
//		if (ar[i] == target){
//			return i;
//		}
//	}
//	return -1;
//}
//
//int main(int arc, char** argv){
//	int arr[] = { 3, 1, 8, 5, 6, 7, 2, 9, 4 };
//	int idx = 0;
//
//	idx = LSearch(arr, sizeof(arr) / sizeof(int), 10);
//	if (idx == -1){
//		printf("Fail!!\n");
//	}
//	else{
//		printf("Target Index : %d\n", idx);
//	}
//
//	idx = LSearch(arr, sizeof(arr) / sizeof(int), 1);
//	if (idx == -1){
//		printf("Fail!!\n");
//	}
//	else{
//		printf("Target Index : %d\n", idx);
//	}
//
//	return 0;
//}

//
//#include <math.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <limits.h>
//#include <stdbool.h>
//
//int solve(int totalPage, int searchPage){
//	totalPage = (totalPage / 2);
//	searchPage = (searchPage / 2);
//	if (searchPage <= totalPage - searchPage) return searchPage;
//	else return totalPage - searchPage;
//}
//
//int main() {
//	int n;
//	scanf("%d", &n); 
//	int p;
//	scanf("%d", &p);
//	int result = solve(n, p);
//	printf("%d\n", result);
//	return 0;
//}
//


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int steps = 0;
	int high = 0;
	int present = 0;
	scanf("%i", &steps);
	char *valley = (char*)malloc(sizeof(char) * steps);
	for (int i = 0; i < steps + 1; i++)
		scanf("%c", &valley[i]);

	for (int i = 0; i < steps + 1; i++){
		if (i != 0){
			if (valley[i] == 'U'){
				present++;
				if (high < present)
					high++;
			}
			else{
				present--;
			}
		}
	}

	printf("%i", high);	
	return 0;
}
