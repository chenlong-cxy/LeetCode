#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Solution {
//public:
//	//�ַ������
//	string multiply(string num1, string num2) {
//		if (num1 == "0" || num2 == "0")
//			return "0";
//		string retArr; //��˺���ַ���
//		int flag = 0; //��ʶ��Ҫ��ӵ�0�ĸ���
//		for (int i = num2.size() - 1; i >= 0; i--) //����ȡ�����ĵ�����һλ�������ڶ�λ��...
//		{
//			int count = num2[i] - '0'; //�������д��뱻������˵���һλ������
//			string tmp; //�洢������λ�뱻������˺�Ľ������ʱΪ�գ�
//			//��count�뱻������ˣ��൱�ڽ���������count�ε�tmp����
//			for (int j = 0; j < count; j++)
//			{
//				tmp = addStrings(tmp, num1);
//			}
//			//���ַ���tmp������flag��0
//			for (int k = 0; k < flag; k++)
//				tmp.push_back('0');
//			retArr = addStrings(retArr, tmp); //���ַ���tmp�ӵ�����ַ���retArr����
//			flag++; //��һ��tmp�ַ���������Ҫ��ӵ�0�ĸ�������
//		}
//		return retArr; //������˺���ַ���
//	}
//	//�ַ������
//	string addStrings(string s1, string s2) {
//		int next = 0; //��ʶ��λ
//		int end1 = s1.size() - 1, end2 = s2.size() - 1;
//		string retArr; //��Ӻ���ַ���
//		while (end1 >= 0 || end2 >= 0) //ֻҪ��һ���ַ���δ������Ͼͼ���
//		{
//			int num1 = 0; //��һ���ַ�������ӵ�����
//			if (end1 >= 0)
//			{
//				num1 = s1[end1] - '0';
//				end1--;
//			}
//			int num2 = 0; //�ڶ����ַ�������ӵ�����
//			if (end2 >= 0)
//			{
//				num2 = s2[end2] - '0';
//				end2--;
//			}
//			int sum = num1 + num2 + next; //���������������Ӻ�Ľ����ע����Ͻ�λnext��
//			if (sum > 9) //��Ҫ��λ
//			{
//				next = 1; //��ʶ��λ
//				sum -= 10; //��λ���λ�õ�����
//			}
//			else //�����λ
//				next = 0;
//			retArr.push_back(sum + '0'); //β�嵽����ַ���retArr����
//		}
//		if (next == 1) //�����λ
//			retArr.push_back('1'); //���ַ�1β�嵽����ַ���retArr����
//		reverse(retArr.begin(), retArr.end()); //�����ַ���retArr
//		return retArr; //������Ӻ���ַ���
//	}
//};


class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		int m = num1.size(), n = num2.size();
		vector<int> arr(m + n, 0);
		for (int i = n - 1; i >= 0; i--) //ȡ������ÿһλ
		{
			int a = num2[i] - '0';
			for (int j = m - 1; j >= 0; j--) //ȡ��������ÿһλ
			{
				int b = num1[j] - '0';
				arr[i + j + 1] += a*b; //�����
			}
		}
		int end = m + n - 1;
		while (end > 0)
		{
			arr[end - 1] += arr[end] / 10;
			arr[end] %= 10;
			end--;
		}
		int flag = 1;
		if (arr[0] != 0)
			flag = 0;
		string retArr;
		for (int i = flag; i < m + n; i++)
		{
			retArr += arr[i] + '0';
		}
		return retArr;
	}
};

int main()
{
	cout << Solution().multiply("2", "3") << endl;
	return 0;
}