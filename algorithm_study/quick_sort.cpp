// Quick sort
#if 0
#include<stdio.h>
#include<stdlib.h>
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void quick_sort(int list[], int left, int right);
int partition(int list[], int left, int right);

int main() {
	int i;
	int mylist[9] = { 5,3,8,4,9,1,6,2,7 };

	printf("Before sorting, \n");

	for (int i = 0; i < 9; i++) {
		printf("%d   ", mylist[i]);
	}

	quick_sort(mylist, 0, 8);

	printf("\nAfter sorting, \n");

	for (int i = 0; i < 9; i++) {
		printf("%d   ", mylist[i]);
	}

	return 0;
}

void quick_sort(int list[], int left, int right) {
	int q;
	if (left < right) {
		q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}

}

int partition(int list[], int left, int right) {
	int tmp;
	int low = left + 1;
	int high = right;
	int pivot = list[left]; //pivot setup

	while (low < high) {
		for (; low <= right && list[low] < pivot; low++);
		for (; high >= left && list[high] > pivot; high--);

		if (low < high) {
			swap(list[low], list[high], tmp);
		}
	}

	swap(list[left], list[high], tmp); //replace high value with pivot value

	return high;
}
#endif