//
// Created by maydelithzuniga on 31/08/2026.
//
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
    ListNode* sortList(ListNode* head) {
        ListNode* sorted=nullptr;
        ListNode* nodo=head;
        while(head!=nullptr){
            ListNode* puntero=sorted;
            nodo=head;
            if(sorted==nullptr || nodo->val<sorted->val){
                head=nodo->next;
                nodo->next=sorted;
                sorted=nodo;
            }
            else {
                while(puntero->next!=nullptr && puntero->next->val < nodo->val){
                    puntero=puntero->next;
                }
                head=nodo->next;
                nodo->next=puntero->next;
                puntero->next=nodo;
            }
        }
        return sorted;
    }
};