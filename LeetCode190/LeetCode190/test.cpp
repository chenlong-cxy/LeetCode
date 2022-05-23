#include <iostream>
#include <stdint.h>

using namespace std;

/*
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t ans = 0;
		//逐位颠倒
		for (int i = 0; i < 32 && n > 0; i++)
		{
			ans |= (n & 1) << (31 - i); //低位往高位放
			n >>= 1; //准备取下一个比特位
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
		n = ((n >> 1) & M1) | ((n & M1) << 1); //一个为一组进行交换 -> 每两个比特位已经被颠倒
		n = ((n >> 2) & M2) | ((n & M2) << 2); //两个为一组进行交换 -> 每四个比特位已经被颠倒
		n = ((n >> 4) & M4) | ((n & M4) << 4); //四个为一组进行交换 -> 每八个比特位已经被颠倒
		n = ((n >> 8) & M8) | ((n & M8) << 8); //八个为一组进行交换 -> 每十六个比特位已经被颠倒
		return n >> 16 | n << 16; //十六个为一组进行交换 -> 32个比特位已经被颠倒
	}
};

int main()
{
	cout << Solution().reverseBits(43261596) << endl;
	return 0;
}