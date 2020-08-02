/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // // 1.遍历：
        // ListNode* pHead = new ListNode; // 未初始化，头结点值为0，最后返回头结点的next
        // ListNode* pTemp = pHead;
        // while (l1 != NULL && l2 != NULL)
        // {
        //     if (l1->val > l2->val)
        //     {
        //         pTemp->next = l2;
        //         l2 = l2->next;
        //     }
        //     else                        // 包含等于的情况：l1->val == l2->val
        //     {
        //         pTemp->next = l1;
        //         l1 = l1->next;
        //     }
        //     pTemp = pTemp->next;
        // }
        // pTemp->next = (l1 == NULL) ? l2 : l1;
        // return pHead->next;            // 返回头结点的next

    
        // 2.递归
        if (l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        else if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// @lc code=end

