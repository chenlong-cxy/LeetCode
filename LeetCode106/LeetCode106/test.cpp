#include <iostream>
#include <vector>
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
	TreeNode* _buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int& pi)
	{
		if (inStart > inEnd) //�������в����ڣ��������ǿ���
			return nullptr;
		//1�������������ĸ����
		TreeNode* root = new TreeNode(postorder[pi]);
		pi--;
		//2����������������������л���Ϊ�����������������������������
		int rooti = inStart;
		while (inorder[rooti] != root->val)
		{
			rooti++;
		}
		//3���ݹ鹹������������������
		root->right = _buildTree(inorder, rooti + 1, inEnd, postorder, pi);
		root->left = _buildTree(inorder, inStart, rooti - 1, postorder, pi);
		//4�����������������ĸ�
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int i = postorder.size() - 1; //��ʶ��ǰ���������ĸ������postorder���е��±�
		return _buildTree(inorder, 0, inorder.size() - 1, postorder, i);
	}
};
int main()
{

	return 0;
}

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
//class Solution {
//public:
//	TreeNode* _buildTree(vector<int>& inorder, int istart, int iend, vector<int>& postorder, int pstart, int pend)
//	{
//		if (istart > iend)
//			return nullptr;
//		TreeNode* root = new TreeNode(postorder[pend]);
//		int count = 0;
//		while (inorder[istart + count] != postorder[pend])
//		{
//			count++;
//		}
//		root->left = _buildTree(inorder, istart, istart + count - 1, postorder, pstart, pstart + count - 1);
//		root->right = _buildTree(inorder, istart + count + 1, iend, postorder, pstart + count, pend - 1);
//		return root;
//	}
//	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//		return _buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
//	}
//};