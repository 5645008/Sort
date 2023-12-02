#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20

int sorted[MAX_SIZE];
int list[MAX_SIZE];
int n;
int move;
int compare;
int allmove;
int allcompare;


//합병정렬(출력용)
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// 분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
		move++;
		compare++;
	}
	if (i > mid) 	// 남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++) {
			sorted[k++] = list[l];
			move++;
		}
	else 	// 남아 있는 레코드의 일괄 복사
		for (l = i; l <= mid; l++) {
			sorted[k++] = list[l];
			move++;
		}
	// 배열 sorted[]의 리스트를 배열 list[]로 복사
	for (l = left; l <= right; l++) 
		list[l] = sorted[l];
	for (int o = 0; o < n; o++)
		printf("%d ", list[o]);
	printf("\n");
}

void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;              // 리스트의 균등분할
		merge_sort(list, left, mid);     // 부분리스트 정렬
		merge_sort(list, mid + 1, right);//부분리스트 정렬
		merge(list, left, mid, right);    // 합병
	}
}


//합병정렬(평균용)
void merge1(int list[], int left, int mid, int right)
{
	move = 0;
	compare = 0;
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// 분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
		move++;
		compare++;
	}
	if (i > mid) 	// 남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++) {
			sorted[k++] = list[l];
			move++;
		}
	else 	// 남아 있는 레코드의 일괄 복사
		for (l = i; l <= mid; l++) {
			sorted[k++] = list[l];
			move++;
		}
	// 배열 sorted[]의 리스트를 배열 list[]로 복사
	for (l = left; l <= right; l++)
		list[l] = sorted[l];

	allmove = allmove + move;
	allcompare = allcompare + compare;
}

void merge_sort1(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;              // 리스트의 균등분할
		merge_sort1(list, left, mid);     // 부분리스트 정렬
		merge_sort1(list, mid + 1, right);//부분리스트 정렬
		merge1(list, left, mid, right);    // 합병
	}
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	allmove = 0;
	allcompare = 0;

	//합병정렬
	srand(time(NULL));
	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99
	printf("Original List\n");
	for (int k = 0; k < n; k++)
		printf("%d ", list[k]);
	printf("\n\n");

	merge_sort(list,0, n-1);

	//합병정렬의 20회 평균 구하기
	for (int s = 0; s < 20; s++) {
		for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
			list[i] = rand() % 100; // 난수 발생 범위 0~99
		merge_sort1(list,0, n-1);
	}
	//20회 평균 출력
	printf("Average Move Count: %d\n", allmove / 20);
	printf("Average Compare Count: %d\n", allcompare / 20);


	return 0;
}