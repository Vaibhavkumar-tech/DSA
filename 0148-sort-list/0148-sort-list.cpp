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
ListNode* MergeSorted(ListNode* head1,ListNode* head2){
    ListNode* t1=head1;
    ListNode* t2=head2;
    ListNode* dummy=new ListNode(-1);
    ListNode* temp=dummy;
    while(t1!=NULL && t2!=NULL){
        if(t1->val > t2->val){
            temp->next=t2;
            t2=t2->next;
        }
        else{
            temp->next=t1;
            t1=t1->next;
        }
        temp=temp->next;   // missing in your code
    }

    if(t1!=NULL){
        temp->next=t1;
    }
    else{
        temp->next=t2;
    }

    return dummy->next;
}

    ListNode* Middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* MergeSort(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* middle = Middle(head);
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;
        middle->next = NULL;
        lefthead = MergeSort(lefthead);
        righthead = MergeSort(righthead);
        return MergeSorted(lefthead, righthead);
    }

    ListNode* sortList(ListNode* head) {
        return MergeSort(head);
    }
};