#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<ListNode*> splitListToParts1(ListNode* root, int k) {
    ListNode *p1 = root;
    vector<ListNode*> ans;
    for(int i=0;i<=k;i++)
   		ans.push_back(root);
   	bool flag = true;
    while(1){
    	ListNode *ptemp = ans[k];
    	for(int j=0;j<k;j++){
			ans[k]=ans[k]->next;
			if(ans[k]==NULL){
				ans[k] = ptemp;
				flag = false;
				break;
			}
		}
		if(!flag)
			break;
    	for(int i=k-1;i>0;i--){
    		for(int j=0;j<i;j++){
    			ans[i]=ans[i]->next;
    		}
    	}
    }
    // ans.pop_back();
    for(auto l:ans){
    	cout<<l->val<<" ";
    }
    cout<<endl;
    return ans;
}

vector<ListNode*> splitListToParts(ListNode* root, int k) {
	ListNode *p = root;
	int cnt = 0;
	while(p!=NULL){
		cnt++;
		p=p->next;
	}
	vector<ListNode*> ans;
	int size = cnt/k;
	int mod = cnt%k;
	ans.push_back(root);
	for(int i=0;i<mod;i++){
		p = ans[i];
		for(int j=1;j<=size;j++){
			p = p->next;
		}
		ans.push_back(p->next);
		p->next = NULL;
	}
	if(size==0){
		for(int i=mod;i<k-1;i++)
			ans.push_back(NULL);
	}
	else{
		for(int i=mod;i<k-1;i++){
			p = ans[i];
			for(int j=1;j<size;j++){
				p = p->next;
			}
			ans.push_back(p->next);
			p->next = NULL;
		}
	}
	// return ans;
	cout<<ans.size()<<endl;
	for(auto l:ans){
		p = l;
		while(p){
    		cout<<p->val<<" ";
    		p=p->next;
		}
		cout<<endl;
    }
}

int main(){
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	ListNode *p6 = new ListNode(6);
	ListNode *p7 = new ListNode(7);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	splitListToParts(p1,3);
	return 0;
}