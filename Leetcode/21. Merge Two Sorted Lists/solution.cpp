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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (!list1 && !list2) {
            return nullptr;
        }
        else if (list1 && !list2) {
            return list1;
        }
        else if (!list1 && list2) {
            return list2;
        }

        ListNode* head;
        if (list1->val > list2->val) {
            head = list2;
            list2 = list2->next;
        }
        else {
            head = list1;
            list1 = list1->next;
        }

        ListNode* current = head;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                current->next = list2;
                list2 = list2->next;
            }
            else {
                current->next = list1;
                list1 = list1->next;
            }
            current = current->next;
        }

        if (list1) {
            current->next = list1;
        }

        if (list2) {
            current->next = list2;
        }

        return head;
    }
};