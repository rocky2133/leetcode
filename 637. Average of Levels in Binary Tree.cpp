#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <queue>

using namespace std;

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ans;
    if(root == NULL)	return ans;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        ans.push_back(0.0);
        int num = ans.size()-1;
        int i=0;
        while(i<size){
            TreeNode *temp = que.front();
            ans[num]+=temp->val;
            que.pop();
            if(temp->left!=NULL)
                que.push(temp->left);
            if(temp->right!=NULL)
                que.push(temp->right);
            i++;
        }
        ans[num]/=(double)size;
    }
    return ans;
}

int main(){

	return 0;
}