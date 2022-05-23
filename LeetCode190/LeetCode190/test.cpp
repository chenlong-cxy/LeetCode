#include <iostream>
#include <stdint.h>

using namespace std;

/*
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t ans = 0;
		//��λ�ߵ�
		for (int i = 0; i < 32 && n > 0; i++)
		{
			ans |= (n & 1) << (31 - i); //��λ����λ��
			n >>= 1; //׼��ȡ��һ������λ
		}
		return ans;
	}
};
*/

class Solution {
private:
	const uint32_t M1 = 0x55555555; //01010101010101010101010101010101
	const uint32_t M2 = 0x33333333; //00110011001100110011001100110011
	const uint32_t M4 = 0x0f0f0f0f; //00001111000011110000111100001111
	const uint32_t M8 = 0x00ff00ff; //00000000111111110000000011111111
public:
	uint32_t reverseBits(uint32_t n) {
		n = ((n >> 1) & M1) | ((n & M1) << 1); //һ��Ϊһ����н��� -> ÿ��������λ�Ѿ����ߵ�
		n = ((n >> 2) & M2) | ((n & M2) << 2); //����Ϊһ����н��� -> ÿ�ĸ�����λ�Ѿ����ߵ�
		n = ((n >> 4) & M4) | ((n & M4) << 4); //�ĸ�Ϊһ����н��� -> ÿ�˸�����λ�Ѿ����ߵ�
		n = ((n >> 8) & M8) | ((n & M8) << 8); //�˸�Ϊһ����н��� -> ÿʮ��������λ�Ѿ����ߵ�
		return n >> 16 | n << 16; //ʮ����Ϊһ����н��� -> 32������λ�Ѿ����ߵ�
	}
};

int main()
{
	cout << Solution().reverseBits(43261596) << endl;
	return 0;
}