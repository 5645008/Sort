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

//��������(��¿�)
void selection_sort(int list[], int n)
{
	printf("Selection Sort\n");
	move = 0;
	compare = 0;
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++)
	{
		least = i;
		for (j = i + 1; j < n; j++) {		// �ּڰ� Ž��
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


//��������(��պ񱳿�)
void selection_sort1(int list[], int n)
{
	move = 0;
	compare = 0;
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {			// �ּڰ� Ž��
			if (list[j] < list[least]) least = j;
			compare++;
		}
		SWAP(list[i], list[least], temp);
		move++;
	}
	allmove = allmove + move;
	allcompare = allcompare + compare;
}

//��������(��¿�)
void insertion_sort(int list[], int n)
{
	printf("Insert Sort\n");
	move = 0;
	compare = 0;
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j]; 		// ���ڵ��� ������ �̵�
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

//��������(��պ񱳿�)
void insertion_sort1(int list[], int n)
{
	move = 0;
	compare = 0;
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j]; 		// ���ڵ��� ������ �̵�
			compare++;
			move++;
		}
		list[j + 1] = key;
	}
	allmove = allmove + move;
	allcompare = allcompare + compare;
}




//��������(��¿�)
void bubble_sort(int list[], int n)
{
	printf("Bubble Sort\n");
	move = 0;
	compare = 0;
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) { 	// �յ��� ���ڵ带 ���� �� ��ü
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

//��������(��պ񱳿�)
void bubble_sort1(int list[], int n)
{
	move = 0;
	compare = 0;
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {	// �յ��� ���ڵ带 ���� �� ��ü
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
	

	//��������
	srand(time(NULL));
	for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 100; // ���� �߻� ���� 0~99
	printf("Original List\n");
	for (int k = 0; k < n; k++)
		printf("%d ", list[k]);
	printf("\n\n");


	selection_sort(list, n); // �������� ȣ�� 
	for (int s = 0; s < 20; s++) {
		for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
			list[i] = rand() % 100; // ���� �߻� ���� 0~99
		selection_sort1(list, n);
	}
	printf("move���: %d\n", allmove / 20);
	printf("compare���: %d\n", allcompare / 20);



	printf("\n\n");

	
	//��������
	allmove = 0;
	allcompare = 0;
	for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 100; // ���� �߻� ���� 0~99
	printf("Original List\n");
	for (int k = 0; k < n; k++)
		printf("%d ", list[k]);
	printf("\n\n");

	insertion_sort(list, n);
	for (int s = 0; s < 20; s++) {
		for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
			list[i] = rand() % 100; // ���� �߻� ���� 0~99
		insertion_sort1(list, n);
	}
	printf("move���: %d\n", allmove / 20);
	printf("compare���: %d\n", allcompare / 20);
	printf("\n\n");


	//��������
	allmove = 0;
	allcompare = 0;
	for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 100; // ���� �߻� ���� 0~99
	printf("Original List\n");
	for (int k = 0; k < n; k++)
		printf("%d ", list[k]);
	printf("\n\n");

	bubble_sort(list, n);
	for (int s = 0; s < 20; s++) {
		for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
			list[i] = rand() % 100; // ���� �߻� ���� 0~99
		bubble_sort1(list, n);
	}
	printf("move���: %d\n", allmove / 20);
	printf("compare���: %d\n", allcompare / 20);


	return 0;
}