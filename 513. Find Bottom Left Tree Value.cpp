#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <queue>

using namespace std;

int findBottomLeftValue(TreeNode* root) {
    int ans=0;
    if(root == NULL)	return ans;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        ans=que.front()->val;
        while(size){
            TreeNode *temp = que.front();
            que.pop();
            if(temp->left!=NULL)
                que.push(temp->left);
            if(temp->right!=NULL)
                que.push(temp->right);
            size--;
        }
    }
    return ans;
}

int main(){

	return 0;
}