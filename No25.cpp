//
// Created by wz on 2021/3/23.
//

/*给你一个链表，每k个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是k的整数倍，那么请将最后剩余的节点保持原有顺序。*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k <= 1) return head; //空指针及不需要翻转的情况直接返回head
        ListNode* dummyhead = head;
        ListNode* pre = nullptr; //记录前一个ListNode
        ListNode* cur = head; //记录当前ListNode
        ListNode* next = nullptr; //记录后一个ListNode
        for(int i = 0; i < k; i++) { //检测ListNode数量是否大于k
            if(!cur) return head; //若不大于直接返回头
            cur = cur->next; //指向下一个ListNode
        }
        cur = head; //检测完毕后cur复原成头
        for(int i = 0; i < k; i++) {
            next = cur->next; //记录后一个ListNode
            cur->next = pre; //cur指向前一个ListNode
            pre = cur; //pre右移
            cur = next; //cur右移
        }
        dummyhead->next = reverseKGroup(next, k); //此时k个ListNode翻转完毕，尾（原来的头）指向递归后返回的头
        //head = pre;
        return pre; //返回新的头
    };
    ListNode* CreatNode(int n){
        ListNode* head = NULL , *pnew = NULL, *ptail = NULL;
        int num, i = 1;
        while (i <= n){
            pnew = new ListNode(i);
            if (head == NULL){
                head = pnew;
            } else
            {
                ptail->next = pnew;
            }
            ptail = pnew;
            i++;
        }
        pnew = NULL;
        delete pnew;
        return head;
    }
    void PrintNode(ListNode *head){
        ListNode *phead = head;
        while (phead != NULL){
            cout << phead->val << endl;
            phead = phead->next;
        }
    }
};

int main()
{
    Solution s;
    ListNode* head = s.CreatNode(12);
    cout << "hello" << endl;
    ListNode* phead=s.reverseKGroup(head,3);
    s.PrintNode(phead);
}