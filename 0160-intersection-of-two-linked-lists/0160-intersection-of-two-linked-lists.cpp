/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *head) {
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=getLength(headA);
        int lenB=getLength(headB);
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(lenA>lenB){
            tempA=tempA->next;
            lenA--;
        }
        while(lenA<lenB){
            tempB=tempB->next;
            lenB--;
        }
        while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};