#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTrees1(int s, int n) {
	vector<TreeNode*> ans;
	if(s>n){
		// cout<<"s: "<<s<<", n: "<<n<<endl;
		ans.push_back(NULL);
		return ans;
	}
    for(int i=s;i<=n;i++){
    	TreeNode *head = new TreeNode(i);
    	cout<<"i:"<<i<<", s:"<<s<<", n:"<<n<<endl;
    	vector<TreeNode*> left = generateTrees1(s,i-1);
    	vector<TreeNode*> right = generateTrees1(i+1,n);
    	cout<<head->val<<endl;
    	cout<<left.size()<<" "<<right.size()<<endl;
    	for(int j=0;j<left.size();j++){
    		for(int k=0;k<right.size();k++){
    			head->left = left[j];
    			head->right = right[k];
    			cout<<left[j]->val<<" "<<right[k]->val<<endl;
    			ans.push_back(head);
    		}
    	}
    }
    return ans;
}

vector<TreeNode*> generateTrees(int n){
	if(n==0)
		return vector<TreeNode*>();
	return generateTrees1(1, n);
}

int main(){
	generateTrees(0);
	return 0;
}