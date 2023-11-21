#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;
int move;
int compare;
int allmove;
int allcompare;

//선택정렬(출력용)
void selection_sort(int list[], int n)
{
	printf("Selection Sort\n");
	move = 0;
	compare = 0;
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++)
	{
		least = i;
		for (j = i + 1; j < n; j++) {		// 최솟값 탐색
			if (list[j] < list[least]) least = j;
			compare++;
		}
		SWAP(list[i], list[least], temp);
		move++;
		for (int k = 0; k < n; k++)
			printf("%d ", list[k]);
		printf("\n");
	}
	printf("Move Count: %d\n", move);
	printf("Compare Count: %d\n", compare);
}


//선택정렬(평균비교용)
void selection_sort1(int list[], int n)
{
	move = 0;
	compare = 0;
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {			// 최솟값 탐색
			if (list[j] < list[least]) least = j;
			compare++;
		}
		SWAP(list[i], list[least], temp);
		move++;
	}
	allmove = allmove + move;
	allcompare = allcompare + compare;
}

//삽입정렬(출력용)
void insertion_sort(int list[], int n)
{
	printf("Insert Sort\n");
	move = 0;
	compare = 0;
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j]; 		// 레코드의 오른쪽 이동
			compare++;
			move++;
		}
		list[j + 1] = key;
		for (int k = 0; k < n; k++)
			printf("%d ", list[k]);
		printf("\n");
	}
	printf("Move Count: %d\n", move);
	printf("Compare Count: %d\n", compare);
}

//삽입정렬(평균비교용)
void insertion_sort1(int list[], int n)
{
	move = 0;
	compare = 0;
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j]; 		// 레코드의 오른쪽 이동
			compare++;
			move++;
		}
		list[j + 1] = key;
	}
	allmove = allmove + move;
	allcompare = allcompare + compare;
}




//버블정렬(출력용)
void bubble_sort(int list[], int n)
{
	printf("Bubble Sort\n");
	move = 0;
	compare = 0;
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) { 	// 앞뒤의 레코드를 비교한 후 교체
			compare++;
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
				move++;
			}
		}
		for (int k = 0; k < n; k++)
			printf("%d ", list[k]);
		printf("\n");
	}
	printf("Move Count: %d\n", move);
	printf("Compare Count: %d\n", compare);
}

//버블정렬(평균비교용)
void bubble_sort1(int list[], int n)
{
	move = 0;
	compare = 0;
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {	// 앞뒤의 레코드를 비교한 후 교체
			compare++;
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
				move++;
			}
		}
	}
	allmove = allmove + move;
	allcompare = allcompare + compare;
}



int main(void)
{
	int i;
	n = MAX_SIZE;
	allmove = 0;
	allcompare = 0;
	

	//선택정렬
	srand(time(NULL));
	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99
	printf("Original List\n");
	for (int k = 0; k < n; k++)
		printf("%d ", list[k]);
	printf("\n\n");


	selection_sort(list, n); // 선택정렬 호출 
	for (int s = 0; s < 20; s++) {
		for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
			list[i] = rand() % 100; // 난수 발생 범위 0~99
		selection_sort1(list, n);
	}
	printf("move평균: %d\n", allmove / 20);
	printf("compare평균: %d\n", allcompare / 20);



	printf("\n\n");

	
	//삽입정렬
	allmove = 0;
	allcompare = 0;
	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99
	printf("Original List\n");
	for (int k = 0; k < n; k++)
		printf("%d ", list[k]);
	printf("\n\n");

	insertion_sort(list, n);
	for (int s = 0; s < 20; s++) {
		for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
			list[i] = rand() % 100; // 난수 발생 범위 0~99
		insertion_sort1(list, n);
	}
	printf("move평균: %d\n", allmove / 20);
	printf("compare평균: %d\n", allcompare / 20);
	printf("\n\n");


	//버블정렬
	allmove = 0;
	allcompare = 0;
	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99
	printf("Original List\n");
	for (int k = 0; k < n; k++)
		printf("%d ", list[k]);
	printf("\n\n");

	bubble_sort(list, n);
	for (int s = 0; s < 20; s++) {
		for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
			list[i] = rand() % 100; // 난수 발생 범위 0~99
		bubble_sort1(list, n);
	}
	printf("move평균: %d\n", allmove / 20);
	printf("compare평균: %d\n", allcompare / 20);


	return 0;
}