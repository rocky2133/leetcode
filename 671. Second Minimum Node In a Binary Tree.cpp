#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

int findSecondMinimumValue(TreeNode* root) {
    if(root==NULL)	return -1;
    bool lf = root->left!=NULL;
    bool rt = root->right!=NULL;
    int left = INT_MAX;
    int right = INT_MAX;
    if(!lf && !rt)	return -1;
    if(lf)
    	left = root->left->val>root->val?root->left->val:findSecondMinimumValue(root->left);
    if(rt)	
    	right = root->right->val>root->val?root->right->val:findSecondMinimumValue(root->right);
    if(left==-1)
    	return right;
    if(right==-1)
    	return left;
    return min(left, right);
}	

int main(){

	return 0;
}