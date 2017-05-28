/**
* Definition for a binary tree node.
*/

#include "iostream"
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* getRightLeafNode(TreeNode *root)
{
	if (root->right)
	{
		getRightLeafNode(root->right);
	}
	else
	{
		return root;
	}
}
void flatten(TreeNode* root) {
	if (!root)
	{
		return ;
	}
	if (root->left)
	{
		if (root->right)
		{
			flatten(root->right);
		}
		getRightLeafNode(root->left)->right = root->right;
		root->right = root->left;
		flatten(root->left);
		root->left = NULL;
	}
}

void travelTree(TreeNode *root){
	/*TreeNode *pnode, *lnode, *rnode;*/
	if (root)
	{
		std::cout << root->val << std::endl;
		travelTree(root->left);
		travelTree(root->right);
	}
}

void destoryTree(TreeNode *node){
	
	if (node)
	{
		destoryTree(node->left);
		destoryTree(node->right);
		delete node;
	}
}
int _main(char argc, char **argv)
{
	TreeNode *root = new TreeNode(0);
	TreeNode *pNode = root;
	const int length = 4;
	int acc = 0;
	for (size_t i = 0; i < length; i++)
	{
		acc++;
		TreeNode *ln = new TreeNode(acc);
		acc++;
		TreeNode *rn = new TreeNode(acc);
		pNode->left = ln;
		pNode->right = rn;

		pNode = ln;
	}
	travelTree(root);
	flatten(NULL);
	destoryTree(root);
	char c = getchar();
	return 0;
}