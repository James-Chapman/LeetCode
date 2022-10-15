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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        auto iter1 = l1;
        auto iter2 = l2;

        auto zero = new ListNode(0);
        auto retlist = new ListNode();
        auto iter3 = retlist;

        auto carry{false};
        auto combined{0};

        for (;;)
        {
            combined = iter1->val + iter2->val;
            if (carry)
            {
                combined += 1;
            }
            carry = false;
            if (combined > 9)
            {
                carry = true;
                combined = combined % 10;
            }

            iter3->val = combined;

            if (iter1->next || iter2->next || carry)
            {
                iter3->next = new ListNode();
                iter3 = iter3->next;

                if (iter1->next)
                {
                    iter1 = iter1->next;
                }
                else if (iter1->next == nullptr && iter1 != zero)
                {
                    iter1 = zero;
                }

                if (iter2->next)
                {
                    iter2 = iter2->next;
                }
                else if (iter2->next == nullptr && iter2 != zero)
                {
                    iter2 = zero;
                }
            }
            else
            {
                break;
            }
        }

        return retlist;
    }
};