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
    // Returns the kth node starting from temp
    ListNode* getKthNode(ListNode* temp, int k) {
        k--;

        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    // Reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1)
            return head;

        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL) {

            // Find kth node
            ListNode* kthNode = getKthNode(temp, k);

            // Less than k nodes left
            if (kthNode == NULL) {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }

            // Store next group's head
            ListNode* nextNode = kthNode->next;

            // Disconnect current group
            kthNode->next = NULL;

            // Reverse current group
            ListNode* newHead = reverseList(temp);

            // Connect with previous group
            if (temp == head)
                head = newHead;
            else
                prevLast->next = newHead;

            // temp becomes the last node after reversal
            prevLast = temp;

            // Connect last node to next group
            prevLast->next = nextNode;

            // Move to next group
            temp = nextNode;
        }

        return head;
    }
};