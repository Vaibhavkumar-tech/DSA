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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newHead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        vector<int>ans;
        ListNode* fast=head;
        ListNode* slow=head;

        //even mein 2 hota mid then mid2 chahiye
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        //mid se reverse kr do means half-half kr diye then dono same hona chahiye
        ListNode* tail=reverse(slow->next);
        ListNode* temp=head;
        while(tail!=NULL){
            if(temp->val!=tail->val){
                return false;
            }
            temp=temp->next;
            tail=tail->next;
        }
        return true;
    }
};