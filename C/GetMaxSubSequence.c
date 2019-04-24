#include <stdio.h>

int maxSubSeq1(const int[], int, int);
int maxSubSeq2(const int[], int);

int main(void) {
    const int arr[8] = {4, -3, 5, -2, -1, 2, 6, -2};
    // int max = maxSubSeq1(arr, 0, 7);
    int max = maxSubSeq2(arr, 8);
    printf("sum = %d\n", max);
}

/*
 * 返回指定序列的最大子序列之和
 * 分治法，时间复杂度O(NlogN)
 */
int maxSubSeq1(const int seq[], int left, int right) {
    // 递归结束点
    if (right <= left) {
        if (seq[left] > 0) {
            return seq[left];
        } else {
            return 0;
        }
    }

    int center, i;
    int leftMax, rightMax, middleMax;

    // 左右递归
    center = (left + right) / 2;
    leftMax = maxSubSeq1(seq, left, center);
    rightMax = maxSubSeq1(seq, center+1, right);

    // 中间子序列最大左值
    int middleLeftMax = 0;
    int middleLeftSum = 0;
    for (i = center; i >= left; i--) {
        middleLeftSum += seq[i];
        if (middleLeftSum > middleLeftMax) {
            middleLeftMax = middleLeftSum;
        }
    }
    // 中间子序列最大右值
    int middleRightMax = 0;
    int middleRightSum = 0;
    for (i = center+1; i <= right; i++) {
        middleRightSum += seq[i];
        if (middleRightSum > middleRightMax) {
            middleRightMax = middleRightSum;
        }
    }
    middleMax = middleLeftMax + middleRightMax;

    // 取三种情况中的最大值
    int max;
    max = (leftMax > rightMax) ? leftMax : rightMax;
    max = (middleMax > max) ? middleMax : max;
    return max;
}

/*
 * 返回指定序列的最大子序列之和
 * 时间复杂度O(N)
 * 
 * 假设Ai, A(i+1), ... Aj是从Ai起始的首个负值子序列， O(N)的算法证明包含两部分：
 * 1. 在i-j范围内，包含Aj的所有后缀子序列都不能作为最优子序列的前缀（包含Aj的所有后缀子序列都是负值）
 * 2. 包含Ai的最大子序列和就是i-j范围内的最大子序列和（包含Ai的所有前缀子序列和都是正值）
 */
int maxSubSeq2(const int seq[], int length) {
    int max, sum, i;
    max = sum = 0;

    for (i = 0; i < length; i++) {
        sum += seq[i];
        if (sum < 0) {
            sum = 0;
        } else if (sum > max) {
            max = sum;
        }
    }

    return max;
}