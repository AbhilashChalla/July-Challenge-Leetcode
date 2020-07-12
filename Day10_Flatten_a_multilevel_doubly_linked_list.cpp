/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
	// Approach: Recursion can be used to traverse nodes in DLL as we do with trees using DFS.
	// How can we keep track of next node when there is a child for current node? 
	// Used a stack to keep track of next nodes. Maybe we can keep track of next nodes in recursive function itself.
	// Time Complexity: O(Nodes)
	// Space Complexity: O(Nodes)
public:
    stack<Node*> st;
    void helper(Node* head){
        if(head==NULL) return;
        if(head->next==NULL && head->child==NULL){
            if(st.empty()) return;
            else{
                Node* head_next=st.top();
                st.pop();
                head->next=head_next;
                head_next->prev=head;
                helper(head_next);
            }
        }
        if(head->child==NULL)
            helper(head->next);
        else
        {
            if(head->next!=NULL)
                st.push(head->next);
            head->child->prev=head;
            head->next=head->child;
            helper(head->child);
            head->child=NULL;
        }
    }
    Node* flatten(Node* head) {
        helper(head);
        return head;
    }
};
