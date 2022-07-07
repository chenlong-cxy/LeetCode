#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//class SnapshotArray {
//public:
//	SnapshotArray(int length) {
//		nums.resize(length, 0); //快照数组的长度初始化为length，并将每个元素初始化为0
//		snap_count = 0; //快照号初始化为0
//	}
//
//	void set(int index, int val) {
//		nums[index] = val; //将快照数组index处的元素值设置为val
//	}
//
//	int snap() {
//		snaps.push_back(nums); //保存当前的快照数组
//		return snap_count++; //返回当前快照数组的快照号，并将快照号自增
//	}
//
//	int get(int index, int snap_id) {
//		return snaps[snap_id][index]; //将快照号为snap_id的快照数组中index处的元素值进行返回
//	}
//private:
//	vector<int> nums; //快照数组
//	vector<vector<int>> snaps; //存储每个快照号对应的快照数组
//	int snap_count; //快照号
//};
//class SnapshotArray {
//public:
//	//构造数据类型
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
//		//查找第一个不小于n的值
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
	//数据类型，<time, val>键值对
	struct Num {
		int time;
		int val;
		//构造函数
		Num(int t, int v) :time(t), val(v)
		{}
		//对<符号进行重载（为了使用lower_bound函数）
		bool operator<(const Num& other)
		{
			return time < other.time;
		}
	};
	SnapshotArray(int length) {
		nums.resize(length); //创建长度为length的快照数组
		for (int i = 0; i < length; i++) //将快照数组中的每个元素都初始化为0（此时time为0）
		{
			nums[i].push_back(Num(0, 0));
		}
		snap_size = 0; //下一次调用snap函数时返回的快照号应该为0
		time = 0; //当前还未调用过set函数，因此time的值初始化为0
	}

	void set(int index, int val) {
		//在time+1次调用set函数后，快照数组中第index个元素的值被设置为val
		nums[index].push_back(Num(++time, val));
	}

	int snap() {
		snaps.push_back(time); //建立快照号到time之间的映射关系（数组下标到元素的映射）
		return snap_size++; //返回快照号，并将snap_size++（下一次调用snap函数获取到的快照号在此基础上+1）
	}

	int get(int index, int snap_id) {
		//获取快照号为snap_id时，快照数组中第index个元素的值

		//1、在第index号桶中，找到一个time不小于snap_id对应的time值+1的<time, val>键值对
		Num n(snaps[snap_id] + 1, 0);
		auto it = lower_bound(nums[index].begin(), nums[index].end(), n);

		//2、该键值对的前一个键值对就是目标键值对，将该键值对当中的val返回即可
		return (--it)->val;
	}
private:
	vector<vector<Num>> nums; //快照数组
	vector<int> snaps; //每个快照号对应的time
	int snap_size; //下一次调用snap函数时返回的快照号
	int time; //记录当前已经调用set函数的次数
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