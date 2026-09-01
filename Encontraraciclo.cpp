//
// Created by maydelithzuniga on 01/09/2026.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <vector>
 using namespace std;
class Solution {
public:


    bool hasCycle(ListNode *head) {
        ListNode*puntero=head;
        vector<ListNode*> recorridos;
        while(puntero!=nullptr){

            for(ListNode*nodo:recorridos){
                if(nodo==puntero){
                    return true;
                    break;
                }
            }
            recorridos.push_back(puntero);
            puntero=puntero->next;

        }
        return false;}

};