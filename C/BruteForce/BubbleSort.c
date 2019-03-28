/*
BubbleSort.c
*/
#include <stdio.h>

#define ARR_LEN 10    //数组长度

void bubble_sort(int *arr, int arr_len);

int main(void) {
	int input[ARR_LEN] = {2, 34, -6, 67, 12, 44, 12, 56, 90, 14};
	
	bubble_sort(input, ARR_LEN);
	//输出排序后的结果
	for (int i = 0; i < ARR_LEN; i++) {
		printf("%d ", input[i]);
	}
	
	return 0;
}

//冒泡排序
void bubble_sort(int *arr, int n) {
	for (int end = n-1; end > 0; end--) {
		for (int i = 0; i < end; i++) {
			if (arr[i] > arr[i+1]) {
				arr[i] ^= arr[i+1] ^= arr[i] ^= arr[i+1];
			}
		}
	}
}

//交换a, b的值
void swap() {
	//todo
}