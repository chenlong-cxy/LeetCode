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
		if (root == nullptr)
		{
			return vector<vector<int>>();
		}
		int levelSize = 1;
		queue<TreeNode*> q;
		q.push(root);

		vector<vector<int>> vv;
		while (!q.empty())
		{
			vector<int> v;
			for (int i = 0; i < levelSize; i++)
			{
				TreeNode* front = q.front();
				q.pop();
				//cout<<front->val<<" ";
				v.push_back(front->val);
				if (front->left)
				{
					q.push(front->left);
				}
				if (front->right)
				{
					q.push(front->right);
				}
			}
			//cout<<endl;
			vv.push_back(v);
			levelSize = q.size();
		}
		return vv;
	}
};

int main()
{

	return 0;
}