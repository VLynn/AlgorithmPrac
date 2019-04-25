#include <stdio.h>

int getMajority(int p[], int size);

int main(void) {
    int testCase[7] = {-2, 5, 7, 7, 9, 7, 7};
    int majority = getMajority(testCase, 7);
    printf("The majority is %d\n", majority);
}

/*
 * 长度为N的数组，有一个数重复出现了N/2+1次，用最小的代价找出这个数
 * 多数投票法，时间复杂度度O(N)
 *
 * 思路：在数组中找到两个不相同的元素并删除它们，不断重复此过程，直到数组中元素都相同，那么剩下的元素就是主要元素。
 * 数组中去掉任意多对不同元素，剩下的子数组任然满足多数规则。
 * 其它算法：hash计数法；排序法，排序后最多数一定是中位数；
 */
int getMajority(int p[], int size) {
    if (p == NULL || size < 1) {
        printf("ERROR, invalid args.");
        return -1;
    }

    int candidate, count, i;
    count = 0;

    for (i = 0; i < size; i++) {
        if (count == 0) 
            candidate = p[i];
        if (p[i] == candidate)
            count++;
        else
            count--;
    }

    return candidate;
}