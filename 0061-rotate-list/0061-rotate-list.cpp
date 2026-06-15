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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp=head;
        int len=1;
        while(temp->next!=NULL){
            temp=temp->next;
            len++;
        }
        k=k%len;
        if(k==0) return head;
        temp->next=head;
        int steps=len-k;
        ListNode* newNode=head;
        for(int i=1;i<steps;i++){
            newNode=newNode->next;
        }
        head=newNode->next;
        newNode->next=NULL;
        return head;
    }
};