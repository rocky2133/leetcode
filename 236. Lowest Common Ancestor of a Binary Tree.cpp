#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <queue>
#include <stack>

using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(root == NULL || root == p || root == q)	return root;
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	TreeNode *right = lowestCommonAncestor(root->right, p, q);
	return (left==p && right==q || left==q && right==p)?root:NULL;   
}