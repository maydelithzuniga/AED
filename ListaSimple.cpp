//
// Created by maydelithzuniga on 31/08/2026.
//

#include <iostream>
using namespace std;
template <typename T>
struct LinkedNode {
    T data;
    LinkedNode* next;
    LinkedNode() {
        next = nullptr;
    }
    LinkedNode(T data, LinkedNode<T>* next = nullptr) : data(data),
    next(next) {}
};
template<typename data_type>
struct LinkedList {
    LinkedNode<data_type>* head;
    LinkedNode<data_type>* tail;
    LinkedList() {
        head = tail = nullptr;
    };
    void push_front(data_type value) {
        // Inserta un nodo con "value"
        // al inicio de la lista
        LinkedNode<data_type>* new_node = new LinkedNode<data_type>(value, head);
        if (head == nullptr) {
            tail = new_node;
        }
        head = new_node;
    }
    void push_back(data_type value) {
        if (tail == nullptr) {
            head = tail = new LinkedNode<data_type>(value);
        }
        else {
            tail -> next = new LinkedNode<data_type>(value);
            tail = tail -> next;
        }
    }
    void insert(LinkedNode<data_type>* node, data_type value) {
        // Inserta un nodo con "value"
        // Despues del nodo "node" que no es nulo
        LinkedNode<data_type>* new_node = new LinkedNode<data_type>(value, node ->
        next);
        if (node == tail) {
            tail = new_node;
        }
        node -> next = new_node;
    }
    void insert(int k, data_type value) {
        // Inserta "value" como el k-ésimo valor en la nueva secuencia
        // Es 0-indexed
        if (k == 0) push_front(value);
        else {
            LinkedNode<data_type>* current = head;
            for (int i = 1; i <= k - 1; ++i) {
                current = current -> next;
            }
            insert(current, value);
        }
    }
    void pop_front() {
        LinkedNode<data_type>* current = head;
        head = head -> next;
        if (head == nullptr) tail = nullptr;
        delete current;
    }
    void erase(LinkedNode<data_type>* node) {
        // Elimina el siguiente al nodo "node"
        if (node -> next) {
            LinkedNode<data_type>* current = node -> next;
            if (node -> next == tail) {
                tail = node;
            }
            node -> next = node -> next -> next;
            delete current;
        }
    }
    void erase(int k) {
        if (k == 0) pop_front();
        else {
            LinkedNode<data_type>* current = head;
            for (int i = 1; i <= k - 1; ++i) {
                current = current -> next;
            }
            erase(current);
        }
    }
    void print() {
        LinkedNode<data_type>* current = head;
        while (current != nullptr) {
            cout << current -> data << " ";
            current = current -> next;
        }
        cout << '\n';
    }
};