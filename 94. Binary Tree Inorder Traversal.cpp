#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <queue>
#include <stack>

using namespace std;

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ans;
	if(root == NULL)	return ans;
    stack<TreeNode*> stk;
    TreeNode *temp = root;
    while(temp!=NULL || !stk.empty()){
    	while(temp){
    		stk.push(temp);
    		temp=temp->left;
    	}
    	ans.push_back(stk.top()->val);
        temp = stk.top()->right;
    	stk.pop();
    }
    return ans;
}

int main(){

	return 0;
}