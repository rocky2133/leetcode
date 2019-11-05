#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <queue>
#include <stack>

using namespace std;

TreeNode* convert(vector<int>& nums, int left, int right){
	if(left>right)	return NULL;
	if(left==right)	return new TreeNode(nums[left]);
	int med = (left+right)/2;
	TreeNode* root = new TreeNode(nums[med]);
	root-> left = convert(nums, left, med-1);
	root-> right = convert(nums, med+1, right);
	return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	int n = nums.size();
	if(n<=0)	return NULL;
    return convert(nums, 0, n-1);
}