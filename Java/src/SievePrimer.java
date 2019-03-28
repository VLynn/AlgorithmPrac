public class SievePrimer {

	/**
	 * 概述：实现“质数筛选算法”
	 * 输入：一个正整数 n > 1
	 * 输出：包含所有 <= n 的质数的数组primers
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for (int value: sieve(100)) {
			System.out.print(value + " ");
		}
	}
	
	public static int[] sieve(int n) {
		int[] arr = new int[n + 1];             //原始数组
		int[] temp = new int[n];
		int[] primers;                          //返回结果数组
		int mid = (int) Math.sqrt(n);           //需要处理的最大临界数
		
		for (int i = 2; i <= n; i++) {
			arr[i] = i;
		}
		
		for (int j = 2; j <= mid; j++) {
			//待处理数为0，代表它有更小的质数 m，故而它的所有倍数都是 m 的倍数，已被消去，不必考虑
			if(arr[j] != 0) {
				//每一轮都从j*j开始筛选，因为2*j...(j-1)*j已经被筛选过了
				int sieved_num = j*j;
				
				while (sieved_num <= n) {
					arr[sieved_num] = 0;
					sieved_num += j;
				}
			}
		}
		
		int count = 0;               //统计质数数量
		for (int value : arr) {
			if(value != 0) {
				temp[count++] = value;
			}
		}
		
		primers = new int[count];
		System.arraycopy(temp, 0, primers, 0, count);
		return primers;
	}
}