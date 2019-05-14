#include <stdio.h>

int binarySearch(const int s[], int length, int goal);

int main(void) {
    int testCase[] = {2, 5, 9, 14, 45, 60, 80, 123};
    int goal = 300;
    int index = binarySearch(testCase, 8, goal);
    printf("The index of %d is %d\n", goal, index);
}

/*
 * 二分查找
 * 在给定的已排序数组s[]中查找数goal的下标，找不到返回-1
 * 二分法，时间复杂度O(logN)
 */
int binarySearch(const int s[], int length, int goal) {
    int left, middle, right;
    left = 0;
    right = length - 1;

    while (left <= right) {
        middle = (left + right) / 2;

        if (s[middle] < goal)
            left = middle + 1;
        else if (s[middle] > goal)
            right = middle - 1;
        else
            return middle;
    }

    return -1;
}