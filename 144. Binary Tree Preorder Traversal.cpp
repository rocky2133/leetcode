#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <queue>
#include <stack>

using namespace std;

vector<int> preorderTraversal1(TreeNode* root) {
	vector<int> ans;
    if(root==NULL)	return ans;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
    	TreeNode *temp = stk.top();
    	ans.push_back(temp->val);
    	stk.pop();
    	while(temp!=NULL){
    		if(temp->left!=NULL)
    			ans.push_back(temp->left->val);
    		if(temp->right!=NULL)
    			stk.push(temp->right);
    		temp=temp->left;
    	}
    }
    return ans;
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> ans;
	if(root==NULL) return ans;
	stack<TreeNode*> stk;
	stk.push(root);
	while(!stk.empty()){
		TreeNode* temp = stk.top();
		stk.pop();
		if(temp==NULL) continue;
		ans.push_back(temp->val);
		stk.push(temp->right);
		stk.push(temp->left);
	}
	return ans;
}

int main(){

	return 0;
}