// merge sort
#if 0
#include<stdio.h>
#include<stdlib.h>

void merge_sort(int list[], int left, int right);
void merge(int mylist[], int left, int mid, int right);

int main() {
	int i;
	int mylist[8] = { 27, 10, 12, 20, 25, 13, 15, 22 };

	printf("Before sorting, \n");

	for (int i = 0; i < 8; i++) {
		printf("%d ", mylist[i]);
	}
	merge_sort(mylist, 0, 7);

	printf("\n After sorting, \n");
	for (int i = 0; i < 8; i++) {
		printf("%d ", mylist[i]);
	}
	return 0;
}

void merge_sort(int list[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
void merge(int mylist[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	int sorted[8] = { 0 , }; //new array

	while (i <= mid && j <= right) {
		if (mylist[i] <= mylist[j]) {
			sorted[k++] = mylist[i++];
		}
		else sorted[k++] = mylist[j++];
	}
	while (i <= mid) {
		sorted[k++] = mylist[i++];
	}
	while (j <= right) {
		sorted[k++] = mylist[j++];
	}
	for (int a = left; a <= right; a++) {
		mylist[a] = sorted[a];
	}
}
#endif