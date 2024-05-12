/*
2816. Double a Number Represented as a Linked List
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(head->val >= 5)
        {
            ListNode* newHead=new ListNode(0);
            newHead->next=head;
            head=newHead;
        }
        ListNode* cur=head;
        while(cur!=NULL)
        {
            cur->val=(cur->val*2)%10;
            if(cur->next!=NULL)
            {
                if(cur->next->val >= 5)
                {
                    cur->val+=1;
                }
            }
            cur=cur->next;
        }
        return head;
    }
};
