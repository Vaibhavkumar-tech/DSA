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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* temp=head;
        int l=0;
        //total length
        while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        //which to be deleted
        int steps=l-n;
        ListNode* move=dummy;

        while(steps){
            move=move->next;
            steps--;
        }
        ListNode* m=move->next;
        move->next=move->next->next;
        delete(m);
        return dummy->next;
    }
};