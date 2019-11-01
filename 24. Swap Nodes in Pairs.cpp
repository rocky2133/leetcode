#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL){
    	return head;
    }
    ListNode *pNext = head->next;
    head->next = swapPairs(pNext->next);
    pNext->next = head;
    return pNext;
}

int main(){

	return 0;
}