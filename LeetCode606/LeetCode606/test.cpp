#include <iostream>
#include <string>
using namespace std;

//Definition for a binary tree node.
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
	string tree2str(TreeNode* root) {
		if (root == nullptr) //空树
		{
			return string(); //返回空字符串
		}
		string str;
		//1、先根结点的值放入字符串
		str += to_string(root->val);

		//2、若左子树不为空，或者左子树为空但右子树不为空，则需要将左子树的值放入字符串
		if (root->left || root->right)
		{
			str += "(";
			str += tree2str(root->left); //操作左子树的规则相同
			str += ")";
		}

		//3、若右子树不为空，则需要将右子树的值放入字符串
		if (root->right)
		{
			str += "(";
			str += tree2str(root->right); //操作右子树的规则相同
			str += ")";
		}
		return str; //返回字符串
	}
};

class Solution {
public:
	string tree2str(TreeNode* root){
		string str;
		_tree2str(root, str); //调用子函数，子函数采用引用传参
		return str; //返回字符串
	}
	void _tree2str(TreeNode* root, string& str) {
		if (root == nullptr) //空树
		{
			return; //直接返回
		}
		//1、先根结点的值放入字符串
		str += to_string(root->val);

		//2、若左子树不为空，或者左子树为空但右子树不为空，则需要将左子树的值放入字符串
		if (root->left || root->right)
		{
			str += "(";
			_tree2str(root->left, str); //操作左子树的规则相同
			str += ")";
		}

		//3、若右子树不为空，则需要将右子树的值放入字符串
		if (root->right)
		{
			str += "(";
			_tree2str(root->right, str); //操作右子树的规则相同
			str += ")";
		}
	}
};
int main()
{
	TreeNode d1(1);
	TreeNode d2(2);
	TreeNode d3(3);
	TreeNode d4(4);
	d1.left = &d2;
	d1.right = &d3;
	d2.right = &d4;
	cout << Solution().tree2str(&d1) << endl;
	return 0;
}