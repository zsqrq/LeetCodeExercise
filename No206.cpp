//
// Created by wz on 2021/3/23.
//
/*
输入一个链表，反转链表后，输出新链表的表头。
*/
#include <iostream>
#include <stdio.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* pHead) {
        ListNode *pre = nullptr;
        ListNode *cur = pHead;
        ListNode *nex = nullptr; // 这里可以指向nullptr，循环里面要重新指向
        while (cur) {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};
int main()
{
    Solution s;
    int length;
    ListNode *five_Ptr = new ListNode(5);
    ListNode *four_Ptr = new ListNode(4,five_Ptr);
    ListNode *three_Ptr = new ListNode(3,four_Ptr);
    ListNode *two_Ptr = new ListNode(2,three_Ptr);
    ListNode *head = new ListNode(1,two_Ptr);

    /*
    for (int i = length; i > 0 ; i--){
        if (i == length){
            ListNode *last = new ListNode(i);
            continue;
        }
        ListNode *
    }
     */

    ListNode* phead1 = head;
    while(phead1!=NULL)
    {
        cout<<phead1->val<<" ";
        phead1 = phead1->next;
    }
    cout << "\n" <<endl;
    ListNode* phead=s.reverseList(head);
    while(phead!=NULL)
    {
        cout<<phead->val<<" ";
        phead=phead->next;
    }
}