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
		if (root == nullptr) //空树直接返回
		{
			return vector<vector<int>>();
		}
		queue<TreeNode*> q;
		//1、先将根入队列
		q.push(root); 

		int levelSize = 1; //初始levelSize为1（第一层只有根结点）
		vector<vector<int>> vv;
		while (!q.empty())
		{
			vector<int> v; //用于存储当前层的结点值
			//2、从队头取levelSize个结点放入容器v
			for (int i = 0; i < levelSize; i++)
			{
				//取结点放入容器v
				TreeNode* front = q.front();
				q.pop();
				v.push_back(front->val);

				//若取出结点左右孩子不为空，还需将不为空的孩子结点放入队列
				if (front->left) //
				{
					q.push(front->left);
				}
				if (front->right)
				{
					q.push(front->right);
				}
			}
			//3、将容器v放入容器vv当中，即第该层的结点值
			vv.push_back(v);

			//4、更新levelSize的值为当前队列当中的元素个数
			levelSize = q.size();
		}
		return vv; //返回层序遍历结果
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