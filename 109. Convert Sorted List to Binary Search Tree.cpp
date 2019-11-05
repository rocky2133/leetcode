#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <queue>
#include <stack>

using namespace std;
ListNode* midLink(ListNode* head){
	ListNode* fast = head->next;
	ListNode* slow = head;
	ListNode* pre = head;
	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		pre = slow;
		slow = slow->next;
	}
	// pre->next = NULL;
	return pre;
}

TreeNode* sortedListToBST(ListNode* head) {
    if(head==NULL)	return NULL;
    if(head->next==NULL)	return new TreeNode(head->val);
    ListNode *pre = midLink(head);
    ListNode *mid = pre->next;
    pre->next = NULL;
    TreeNode *root = new TreeNode(mid->val);
    cout<<mid->val<<endl;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);
    return root;
}