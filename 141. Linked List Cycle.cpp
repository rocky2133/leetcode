#include <iostream>

using namespace std;

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

bool hasCycle(ListNode *head) {
	if(!head || !head->next)
		return false;
    ListNode* p1 = head;
    ListNode* p2 = head->next;
    while(p2 && p2->next){
    	if(p2 == p1)
    		return true;
    	p2 = p2->next->next;
    	p1 = p1->next;
    }
    return false;
}

int main(){

	return 0;
}