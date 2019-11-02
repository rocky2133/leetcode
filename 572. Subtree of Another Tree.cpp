#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

bool isSubtree1(TreeNode* s, TreeNode* t) {
    if(s==NULL && t==NULL) return true;
    if(s==NULL || t==NULL) return false;
    if(s->val!=t->val) return false;
    return isSubtree1(s->left, t->left) && isSubtree1(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if(s==NULL) return false;
    return isSubtree1(s, t)||isSubtree(s->left, t)||isSubtree(s->right, t);
}

int main(){

	return 0;
}