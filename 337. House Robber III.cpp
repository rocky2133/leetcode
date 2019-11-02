#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

// int rob1(TreeNode* root){
// 	if(root == NULL)	return 0;
// 	int val = root->val;
// 	int ans1 = val;
// 	int ans2 = 0;
// 	bool lf = (root->left!=NULL);
// 	bool rt = (root->right!=NULL);
// 	int left = lf?root->left->val:0;
// 	int right = lf?root->right->val:0;
// 	if(lf)
// 		ans1+=rob(root->left->left)+rob(root->left->right);
// 	if(rt)
// 		ans1+=rob(root->right->left)+rob(root->right->right);
// 	ans2+=rob(root->left)+rob(root->right);
//     return max(ans1, ans2);
// }

int* doRob(TreeNode *root){
    int *res = new int[2];
    res[0]=0;
    res[1]=0;
    if(root == NULL)
        return res;
    int* left = doRob(root->left);
    int* right = doRob(root->right);
    res[0] = max(left[0],left[1])+max(right[0],right[1]);
    res[1] = left[0] + right[0] + root->val;
    return res;
}

int rob(TreeNode* root){
    int* res = doRob(root);
    return max(res[0],res[1]);
}

int main(){

	return 0;
}