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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = l1;

        int overflow = 0;
        auto calculateSum = [&overflow](int value) {
            int res = value + overflow;
                
            if (res >= 10) {
                res = res - 10;
                overflow = 1;
            }
            else {
                overflow = 0;
            }
            return res;
        };

        ListNode* prev;

        // Calculate result to l1
        while (l1 && l2) {
            l1->val = calculateSum(l1->val + l2->val);

            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        // If l1 < l2, then link last l1 node with current l2 node
        // and calculate result to the l2.
        if (!l1) {
            prev->next = l2;
            l1 = l2;
        }

        while (l1) {
            l1->val = calculateSum(l1->val);
            prev = l1;
            l1 = l1->next;
        }

        // Add new node, if result should be longer than l1 and l2
        if (!l1 && overflow) {
            prev->next = new ListNode(overflow);
        }
        return head;
    }
};
