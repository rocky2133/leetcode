#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int pathSum1(TreeNode* root, int sum){
	if(root==NULL)
		return 0;
	int ans = 0;
	if(root->val == sum)
		ans++;
	ans += (pathSum1(root->left, sum-root->val) + pathSum1(root->right, sum-root->val));
	return ans;
}

int pathSum(TreeNode* root, int sum) {
	if(root==NULL)
		return 0;
    int ans = 0;
    ans+=pathSum1(root, sum);
    ans+=pathSum(root->left, sum);
    ans+=pathSum(root->right, sum);
    return ans;
}

int main(){

	return 0;
}