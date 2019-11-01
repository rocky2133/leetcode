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

ListNode* oddEvenList(ListNode* head) {
	if(head==NULL || head->next==NULL || head->next->next==NULL)
		return head;
    ListNode *p1 = head;
    ListNode *p2 = p1->next;
    ListNode *p2s = p2;
    ListNode *p3 = p2->next;
    while(p3){
    	p1->next=p3;
    	p2s->next=p3->next;
    	p3->next=p2;
    	p1 = p3;
    	p2s = p2s->next;
    	if(!p2s)
    		break;
    	p3 = p2s->next;
    }
    return head;
}

int main(){
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	ListNode *p6 = new ListNode(6);
	ListNode *p7 = new ListNode(7);
	// p1->next = p2;
	// p2->next = p3;
	// p3->next = p4;
	// p4->next = p5;
	// p5->next = p6;
	// p6->next = p7;
	ListNode*p = oddEvenList(p1);
	while(p){
		cout<<p->val<<" ";
		p = p->next;
	}
	return 0;
}