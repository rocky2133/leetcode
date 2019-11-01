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

bool isPalindrome(ListNode* head) {
	if(head == NULL || head->next == NULL)
    	return true;
    if(head->next->next == NULL)
    	return head->val == head->next->val;
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *p1 = head;
    ListNode *p2 = head;
    ListNode *p3 = head;
    while(fast != NULL && fast->next != NULL){
    	slow = slow->next;
    	p3 = slow;
    	p2->next = p3->next;
    	p3->next = p1;
    	p1 = p3;
    	slow = p2;
    	fast = fast->next->next;
    }
    p2 = p2->next;
    if(fast == NULL){
    	p1 = p1->next;
    }
    while(p1 && p2){
    	if(p1->val != p2->val)
    		return false;
    	p1 = p1->next;
    	p2 = p2->next;
    }
    return true;
}

int main(){
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(1);
	// ListNode *p3 = new ListNode(1);
	// ListNode *p4 = new ListNode(1);
	// ListNode *p5 = new ListNode(3);
	// ListNode *p6 = new ListNode(2);
	// ListNode *p7 = new ListNode(1);
	p1->next = p2;
	// p2->next = p3;
	// p3->next = p4;
	// p4->next = p5;
	// p5->next = p6;
	// p6->next = p7;
	cout<<isPalindrome(p1)<<endl;
	return 0;
}