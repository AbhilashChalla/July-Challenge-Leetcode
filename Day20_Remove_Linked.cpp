/*
Problem Statement:
---------------------------------------------------
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
---------------------------------------------------
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
	//Approach: Take care of cases like nodes with given val at the beginning and end, consecutive nodes with given val and nodes with given val between valid nodes.
	//Time Complexity: O(Nodes)
	//Space Complexity: O(1)
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val==val)
            head=head->next;
        ListNode* first=head;
        ListNode *prev=NULL;
        
        while(head!=NULL){
            if(head->next && head->next->val==val){
                ListNode* temp=head;
                while(temp->next && temp->next->val==val)
                    temp=temp->next;
                if(temp->val==val)
                    temp=temp->next;
                head->next=temp;
            }
            else
                head=head->next;
        }
        return first;
    }
};
