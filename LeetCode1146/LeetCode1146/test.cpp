#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//class SnapshotArray {
//public:
//	SnapshotArray(int length) {
//		nums.resize(length, 0); //��������ĳ��ȳ�ʼ��Ϊlength������ÿ��Ԫ�س�ʼ��Ϊ0
//		snap_count = 0; //���պų�ʼ��Ϊ0
//	}
//
//	void set(int index, int val) {
//		nums[index] = val; //����������index����Ԫ��ֵ����Ϊval
//	}
//
//	int snap() {
//		snaps.push_back(nums); //���浱ǰ�Ŀ�������
//		return snap_count++; //���ص�ǰ��������Ŀ��պţ��������պ�����
//	}
//
//	int get(int index, int snap_id) {
//		return snaps[snap_id][index]; //�����պ�Ϊsnap_id�Ŀ���������index����Ԫ��ֵ���з���
//	}
//private:
//	vector<int> nums; //��������
//	vector<vector<int>> snaps; //�洢ÿ�����պŶ�Ӧ�Ŀ�������
//	int snap_count; //���պ�
//};
//class SnapshotArray {
//public:
//	//������������
//	struct Num
//	{
//		int val;
//		int time;
//		Num(int t, int v) :val(v), time(t)
//		{}
//		bool operator < (const Num& other)
//		{
//			return time < other.time;
//		}
//	};
//	SnapshotArray(int length) {
//		time = 0;
//		size = length;
//		snap_size = 0;
//		nums.resize(size);
//		for (int i = 0; i < size; ++i)
//		{
//			nums[i].push_back(Num(time, 0));
//		}
//	}
//
//	void set(int index, int val) {
//		nums[index].push_back(Num(++time, val));
//	}
//
//	int snap() {
//		snaps.push_back(time);
//		return snap_size++;
//	}
//
//	int get(int index, int snap_id) {
//		Num n = Num(snaps[snap_id] + 1, 0);
//		//���ҵ�һ����С��n��ֵ
//		return (--lower_bound(nums[index].begin(), nums[index].end(), n))->val;
//	}
//private:
//	int time;
//	int size;
//	int snap_size;
//	vector<vector<Num> > nums;
//	vector<int> snaps;
//};
//class SnapshotArray {
//public:
//	SnapshotArray(int length) {
//		table.resize(length);
//		for (size_t i = 0; i < length; i++)
//		{
//			table[i].push_back(make_pair(0, 0));
//		}
//		snap_size = 0;
//		time = 0;
//	}
//
//	void set(int index, int val) {
//		table[index].push_back(make_pair(++time, val));
//	}
//
//	int snap() {
//		snapTable.push_back(time);
//		return snap_size++;
//	}
//
//	int get(int index, int snap_id) {
//		int left = 0, right = table[index].size() - 1;
//		while (left < right)
//		{
//			int mid = (left + right) / 2;
//			if (table[index][mid].first > snapTable[snap_id])
//				right = mid - 1;
//			else if (table[index][mid].first < snapTable[snap_id])
//				left = mid + 1;
//			else
//				return table[index][mid].second;
//		}
//		int pos = table[index][left].first > snapTable[snap_id] ? left - 1 : left;
//		return table[index][pos].second;
//	}
//private:
//	vector<vector<pair<int, int>>> table;
//	vector<int> snapTable;
//	int snap_size;
//	int time;
//};
class SnapshotArray {
public:
	//�������ͣ�<time, val>��ֵ��
	struct Num {
		int time;
		int val;
		//���캯��
		Num(int t, int v) :time(t), val(v)
		{}
		//��<���Ž������أ�Ϊ��ʹ��lower_bound������
		bool operator<(const Num& other)
		{
			return time < other.time;
		}
	};
	SnapshotArray(int length) {
		nums.resize(length); //��������Ϊlength�Ŀ�������
		for (int i = 0; i < length; i++) //�����������е�ÿ��Ԫ�ض���ʼ��Ϊ0����ʱtimeΪ0��
		{
			nums[i].push_back(Num(0, 0));
		}
		snap_size = 0; //��һ�ε���snap����ʱ���صĿ��պ�Ӧ��Ϊ0
		time = 0; //��ǰ��δ���ù�set���������time��ֵ��ʼ��Ϊ0
	}

	void set(int index, int val) {
		//��time+1�ε���set�����󣬿��������е�index��Ԫ�ص�ֵ������Ϊval
		nums[index].push_back(Num(++time, val));
	}

	int snap() {
		snaps.push_back(time); //�������պŵ�time֮���ӳ���ϵ�������±굽Ԫ�ص�ӳ�䣩
		return snap_size++; //���ؿ��պţ�����snap_size++����һ�ε���snap������ȡ���Ŀ��պ��ڴ˻�����+1��
	}

	int get(int index, int snap_id) {
		//��ȡ���պ�Ϊsnap_idʱ�����������е�index��Ԫ�ص�ֵ

		//1���ڵ�index��Ͱ�У��ҵ�һ��time��С��snap_id��Ӧ��timeֵ+1��<time, val>��ֵ��
		Num n(snaps[snap_id] + 1, 0);
		auto it = lower_bound(nums[index].begin(), nums[index].end(), n);

		//2���ü�ֵ�Ե�ǰһ����ֵ�Ծ���Ŀ���ֵ�ԣ����ü�ֵ�Ե��е�val���ؼ���
		return (--it)->val;
	}
private:
	vector<vector<Num>> nums; //��������
	vector<int> snaps; //ÿ�����պŶ�Ӧ��time
	int snap_size; //��һ�ε���snap����ʱ���صĿ��պ�
	int time; //��¼��ǰ�Ѿ�����set�����Ĵ���
};
int main()
{
	/*SnapshotArray* obj = new SnapshotArray(3);
	obj->set(0, 5);
	int snap_num = obj->snap();
	obj->set(0, 6);
	int val = obj->get(0, 0);*/

	SnapshotArray* obj = new SnapshotArray(2);
	obj->set(0, 12);
	int snap_num = obj->snap();
	snap_num = obj->snap();
	int val = obj->get(1, 0);
	cout << val << endl;
	val = obj->get(1, 0);
	cout << val << endl;
	snap_num = obj->snap();
	snap_num = obj->snap();

	return 0;
}