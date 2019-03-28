#include <stdio.h>

int removeDuplicate(int[], int);

int main(void) {
	int arr[6] = {2, 5, 5, 7, 7, 12};
	int length = removeDuplicate(arr, 6);
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
}  

/**
 * 移除有序数组中的重复元素
 * @param  arr    有序数组
 * @param  length 数组长度
 * @return        移除重复元素后的数组长度
 */
int removeDuplicate(int arr[], int length) {
	int i = 0;	//指向不重复数组已处理好的最后一个元素
	int j = 1;	//指向待处理的下一个元素

	for (; j < length; j++) {
		if (arr[i] != arr[j]) {
			arr[++i] = arr[j];
		}
	}

	return i + 1;	// 返回不重复数组的长度
}