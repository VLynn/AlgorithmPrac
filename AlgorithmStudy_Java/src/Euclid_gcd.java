
public class Euclid_gcd {

	/**
	 * ������ʹ��ŷ������㷨����gcd(m, n)
	 * ���룺������ȫΪ0�ķǸ�����m, n
	 * �����m, n�����Լ��	 
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
