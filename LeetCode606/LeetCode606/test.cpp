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
		if (root == nullptr) //����
		{
			return string(); //���ؿ��ַ���
		}
		string str;
		//1���ȸ�����ֵ�����ַ���
		str += to_string(root->val);

		//2������������Ϊ�գ�����������Ϊ�յ���������Ϊ�գ�����Ҫ����������ֵ�����ַ���
		if (root->left || root->right)
		{
			str += "(";
			str += tree2str(root->left); //�����������Ĺ�����ͬ
			str += ")";
		}

		//3������������Ϊ�գ�����Ҫ����������ֵ�����ַ���
		if (root->right)
		{
			str += "(";
			str += tree2str(root->right); //�����������Ĺ�����ͬ
			str += ")";
		}
		return str; //�����ַ���
	}
};

class Solution {
public:
	string tree2str(TreeNode* root){
		string str;
		_tree2str(root, str); //�����Ӻ������Ӻ����������ô���
		return str; //�����ַ���
	}
	void _tree2str(TreeNode* root, string& str) {
		if (root == nullptr) //����
		{
			return; //ֱ�ӷ���
		}
		//1���ȸ�����ֵ�����ַ���
		str += to_string(root->val);

		//2������������Ϊ�գ�����������Ϊ�յ���������Ϊ�գ�����Ҫ����������ֵ�����ַ���
		if (root->left || root->right)
		{
			str += "(";
			_tree2str(root->left, str); //�����������Ĺ�����ͬ
			str += ")";
		}

		//3������������Ϊ�գ�����Ҫ����������ֵ�����ַ���
		if (root->right)
		{
			str += "(";
			_tree2str(root->right, str); //�����������Ĺ�����ͬ
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