//
// Created by maydelithzuniga on 01/09/2026.
//
#include <iostream>
#include <cmath>
#include <vector>
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
template <typename T>
struct Node_hijo {
    T data;
    Node_hijo* next;
    int next_index;
    int hijo;

    Node_hijo(T _data, int _next_index, int hijo): data(_data),next_index(_next_index),hijo(hijo) {
        next = nullptr;
    }
    ~Node_hijo()=default;
};
template<typename data_type>
struct LinkedListhijo {
    Node_hijo<data_type>* head;
    Node_hijo<data_type>* tail;

    LinkedListhijo() {
        head = tail = nullptr;
    };
    Node_hijo<data_type> * next;

    void push_back(data_type value, int index_next, int index_hijo) {
        if (tail == nullptr) {
            head = tail = new Node_hijo<data_type>(value, index_next, index_hijo);
        }
        else {
            tail -> next = new Node_hijo<data_type>(value, index_next, index_hijo);
            tail = tail -> next;
        }
    }

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

int main() {
    int tamano;
    cin >> tamano;
    int head_indice;
    cin >> head_indice;
    int indice=0;
    vector<int> valores;
    LinkedListhijo<int> hijos;
    int valor, indice_next, indice_hijo;
    while (indice<tamano) {
        cin >> valor;
        cin >> indice_next;
        cin >> indice_hijo;
        hijos.push_back(valor, indice_next, indice_hijo);
        indice++;
    }
    indice=0;
    Node_hijo<int> *puntero=hijos.head;
    while (indice<head_indice) {
        puntero=puntero -> next;
        indice++;
    }
    LinkedList<int> Lista_final;
    Lista_final.push_back(puntero -> data);
    for (int i = 1; i <= tamano; ++i) {
        Lista_final.push_back(0);
    }
    puntero = hijos.head;
    Node_hijo<int>* insertar=nullptr;
    while (puntero != nullptr) {
        int vueltas=puntero -> next_index;
        indice=0;
        insertar=hijos.head;
        int hijo_numero=puntero -> hijo;
        if (hijo_numero == 0) {
            while (indice<vueltas) {
                insertar=insertar -> next;
                indice++;
            }
            Lista_final.insert(vueltas-1, insertar->data);
        }
        else {
            while (indice<hijo_numero) {
                insertar=insertar -> next;
                indice++;
            }
            Lista_final.insert(vueltas-1, insertar->data);
            int ingreso=vueltas;
            int index_next=insertar -> next_index;
            Node_hijo<int> *puntero_2=insertar;
            while (puntero_2->next_index != 0) {
                int indice_2=0;
                Node_hijo<int>* insertar_2=hijos.head;
                    while (indice_2<index_next) {
                        insertar_2=insertar_2 -> next;
                        indice_2++;
                    }
                    Lista_final.insert(ingreso, insertar_2->data);
                ingreso++;
                puntero_2=puntero_2->next;
            }
            indice=0;
            insertar=hijos.head;
            while (indice<vueltas) {
                insertar=insertar -> next;
                indice++;
            }
            Lista_final.insert(ingreso+1, insertar->data);
        }
        
        puntero = puntero -> next;
    }
    return 0;
};