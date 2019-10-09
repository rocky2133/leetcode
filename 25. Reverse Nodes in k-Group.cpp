#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* last, ListNode *head, int length){
	if(length <= 1)
		return head;
	else if(length == 2){
		ListNode* p1 = head;
		ListNode* p2 = head->next;
		if(!p1 || !p2){
			last->next = head;
			return NULL;
		}
		p1->next = p2->next;
		p2->next = p1;
		last->next = p2;
		return head;
	}
	else{
		ListNode* detect = head;
		for(int i=0; i<length-1; i++){
			detect = detect->next;
			if(!detect)
				return NULL;
		}
		ListNode* p1 = head;
		ListNode* p2 = head->next;
		ListNode* p3 = head->next->next;
		
		p2->next = p1;
		for(int i=0; i<length-3;i++){
			p1 = p2;
			p2 = p3;
			p3 = p3->next;
			p2->next = p1;
		}
		head->next = p3->next;
		p3->next = p2;
		last->next = p3;
		return head;
	}
}

ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode* pst = head;
	ListNode* realHead = new ListNode(0);
	realHead->next = head;
	ListNode* last = realHead;

	while(pst){
 		last = reverse(last, pst, k);
		if(last)
			pst = last->next;
		else{

			break;
		}
	}
	return realHead->next;
}

int main(){
	int i = 0;
	ListNode* head = new ListNode(0);
	ListNode* pst = head;
	for(int i=1;i<6;i++){
		pst->next = new ListNode(i);
		pst = pst->next;
	}
	pst->next = NULL;
	pst = reverseKGroup(head->next, 4);

	// pst = reverse(head, head->next, 2);
	while(pst){
		cout<<pst->val<<" ";
		pst = pst->next;
	}
	return 0;
}
