#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr) //����ֱ�ӷ���
		{
			return vector<vector<int>>();
		}
		queue<TreeNode*> q;
		//1���Ƚ��������
		q.push(root); 

		int levelSize = 1; //��ʼlevelSizeΪ1����һ��ֻ�и���㣩
		vector<vector<int>> vv;
		while (!q.empty())
		{
			vector<int> v; //���ڴ洢��ǰ��Ľ��ֵ
			//2���Ӷ�ͷȡlevelSize������������v
			for (int i = 0; i < levelSize; i++)
			{
				//ȡ����������v
				TreeNode* front = q.front();
				q.pop();
				v.push_back(front->val);

				//��ȡ��������Һ��Ӳ�Ϊ�գ����轫��Ϊ�յĺ��ӽ��������
				if (front->left) //
				{
					q.push(front->left);
				}
				if (front->right)
				{
					q.push(front->right);
				}
			}
			//3��������v��������vv���У����ڸò�Ľ��ֵ
			vv.push_back(v);

			//4������levelSize��ֵΪ��ǰ���е��е�Ԫ�ظ���
			levelSize = q.size();
		}
		return vv; //���ز���������
	}
};

int main()
{
	TreeNode d1(3);
	TreeNode d2(9);
	TreeNode d3(20);
	TreeNode d4(15);
	TreeNode d5(7);
	d1.left = &d2;
	d1.right = &d3;
	d3.left = &d4;
	d3.right = &d5;
	vector<vector<int>> ret = Solution().levelOrder(&d1);
	cout << "[" << endl;
	for (size_t i = 0; i < ret.size(); i++)
	{
		cout << "    [";
		for (auto e : ret[i])
		{
			cout << e << " ";
		}
		cout << "]";
		cout << endl;
	}
	cout << "]" << endl;
	return 0;
}