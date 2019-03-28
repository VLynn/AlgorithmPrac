/* 
SelectionSort.c
*/
#include <stdio.h>

#define ARR_LEN 10    //数组长度

void selection_sort(int *arr, int arr_len);

int main(void) {
	int input[ARR_LEN] = {2, 34, -6, 67, 12, 44, 12, 56, 90, 14};
	
	selection_sort(input, ARR_LEN);
	//输出排序后的数组
	for (int i = 0; i < ARR_LEN; i++) {
		printf("%d ", input[i]);
	}
	
	return 0;
}

//选择排序
//输入：数组指针，数组长度
void selection_sort(int *arr, int n) {
	int min_index, temp;
	
	for (int i = 0; i < n-1; i++) {
		//初始化最小值索引
		min_index = i;
		for (int j = i; j < n; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		//交换最小值到起始位置
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
}