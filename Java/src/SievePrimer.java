public class SievePrimer {

	/**
	 * ������ʵ�֡�����ɸѡ�㷨��
	 * ���룺һ�������� n > 1
	 * ������������� <= n ������������primers
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for (int value: sieve(100)) {
			System.out.print(value + " ");
		}
	}
	
	public static int[] sieve(int n) {
		int[] arr = new int[n + 1];             //ԭʼ����
		int[] temp = new int[n];
		int[] primers;                          //���ؽ������
		int mid = (int) Math.sqrt(n);           //��Ҫ���������ٽ���
		
		for (int i = 2; i <= n; i++) {
			arr[i] = i;
		}
		
		for (int j = 2; j <= mid; j++) {
			//��������Ϊ0���������и�С������ m���ʶ��������б������� m �ı������ѱ���ȥ�����ؿ���
			if(arr[j] != 0) {
				//ÿһ�ֶ���j*j��ʼɸѡ����Ϊ2*j...(j-1)*j�Ѿ���ɸѡ����
				int sieved_num = j*j;
				
				while (sieved_num <= n) {
					arr[sieved_num] = 0;
					sieved_num += j;
				}
			}
		}
		
		int count = 0;               //ͳ����������
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