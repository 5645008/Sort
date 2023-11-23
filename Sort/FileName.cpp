#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20

int list[MAX_SIZE];
int n;
int move;
int compare;
int allmove;
int allcompare;

//�� ���� ���α׷�

//��������
void insertion_sort(int list[], int first, int last, int gap)
{	
	int i, j, key,count;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
			list[j + gap] = list[j];
			compare++;
			move++;
		}
		if (list[i] != list[j + gap]) {
			move++;
		}
		list[j + gap] = key;
	}
}
//������(��¿�)
void shell_sort(int list[], int n)   // n = size
{
	printf("Shell Sort\n");
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++) 		// �κ� ����Ʈ�� ������ gap
			insertion_sort(list, i, n - 1, gap);
		for (int k = 0; k < n; k++)
			printf("%d ", list[k]);
		printf("\n");
	}
}

//������(��տ�)
void shell_sort1(int list[], int n)   // n = size
{
	move = 0;
	compare = 0;
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++) 		// �κ� ����Ʈ�� ������ gap
			insertion_sort(list, i, n - 1, gap);
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
	
	//������
	srand(time(NULL));
	for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 100; // ���� �߻� ���� 0~99
	printf("Original List\n");
	for (int k = 0; k < n; k++)
		printf("%d ", list[k]);
	printf("\n\n");

	shell_sort(list, n);

	//�������� 20ȸ ��� ���ϱ�
	for (int s = 0; s < 20; s++) {
		for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
			list[i] = rand() % 100; // ���� �߻� ���� 0~99
		shell_sort1(list, n);
	}
	//20ȸ ��� ���
	printf("Average Move Count: %d\n", allmove / 20);
	printf("Average Compare Count: %d\n", allcompare / 20);


	return 0;
}