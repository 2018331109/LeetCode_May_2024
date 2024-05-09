/*
2487. Remove Nodes From Linked List
You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.
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
class Solution
{
public:
    ListNode* reve(ListNode* head)
    {
        ListNode *prev=nullptr, *cur=head;
        while(cur!=nullptr)
        {
            ListNode *temp=cur->next;
            cur->next=prev;
            prev=cur, cur=temp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head)
    {
        head=reve(head);
        int mx=-1;
        ListNode *prev=NULL, *cur=head;
        while(cur!=NULL)
        {
            if(cur->val < mx)
            {
                prev->next=cur->next;
                ListNode *temp=cur; //to be deleted
                cur=cur->next, delete(temp);
            }
            else
            {
                mx=cur->val;
                prev=cur, cur=cur->next;
            }
        }
        return reve(head);
    }
};

