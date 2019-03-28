
public class Euclid_gcd {

	/**
	 * 概述：使用欧几里得算法计算gcd(m, n)
	 * 输入：两个不全为0的非负整数m, n
	 * 输出：m, n的最大公约数	 
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print(euclid(1, 17));
	}
	
	public static int euclid(int m, int n) {
		int temp = 0;
		while (n != 0) {
			temp = m%n;
			m = n;
			n = temp;
		}
		return m;
	}
}
