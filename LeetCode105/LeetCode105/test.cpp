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
	TreeNode* _buildTree(vector<int>& preorder, int& pi, vector<int>& inorder, int inStart, int inEnd)
	{
		if (inStart > inEnd) //中序序列不存在，该子树是空树
			return nullptr;
		//1、构建该子树的根结点
		TreeNode* root = new TreeNode(preorder[pi]); 
		pi++;
		//2、将该子树的中序遍历序列划分为其左子树和右子树的中序遍历序列
		int rooti = inStart;
		while (inorder[rooti] != root->val)
		{
			rooti++;
		}
		//3、递归构建该子树的左右子树
		root->left = _buildTree(preorder, pi, inorder, inStart, rooti - 1);
		root->right = _buildTree(preorder, pi, inorder, rooti + 1, inEnd);
		//4、返回所构建子树的根
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int i = 0; //标识当前构建子树的根结点在preorder当中的下标
		return _buildTree(preorder, i, inorder, 0, inorder.size() - 1);
	}
};
int main()
{

	return 0;
}

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//
//class Solution {
//public:
//	TreeNode* _buildTree(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int istart, int iend)
//	{
//		if (pstart > pend)
//			return nullptr;
//		TreeNode* root = new TreeNode(preorder[pstart]);
//		int count = 0;
//		while (inorder[istart + count] != preorder[pstart])
//		{
//			count++;
//		}
//		root->left = _buildTree(preorder, pstart + 1, pstart + count, inorder, istart, istart + count - 1);
//		root->right = _buildTree(preorder, pstart + count + 1, pend, inorder, istart + count + 1, iend);
//		return root;
//	}
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//		return _buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
//	}
//};