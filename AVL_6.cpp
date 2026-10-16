#include<bits/stdc++.h>
#include <list>
#include <map>
#include <vector>
#include <iostream>
using namespace::std;

template<typename data_type>
struct AVL {
    struct TreeNode {
        int height;
        data_type data;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
        int size;

        TreeNode( data_type _data, int height = 0,TreeNode* parent = nullptr, int _size=1,
                    TreeNode* left = nullptr,
                    TreeNode* right = nullptr) :
                    data(_data), size(_size), height(height), left(left), right(right), parent(parent) {}
    };

    TreeNode* root;

    AVL() {
        root = nullptr;
    }

    int sz(TreeNode* u) {
        if (u == nullptr) return 0;
        return u->size;

    }
    void update(TreeNode* u) {
        u -> height = 1 + max(h(u -> left) , h(u -> right));
        u->size = 1 + sz(u -> left) + sz(u -> right);
    }

    int h(TreeNode* u) {
        return u == nullptr ? -1 : u -> height;
    }

    int FB(TreeNode* u) {
        return h(u -> left) - h(u -> right);
    }


    int search(data_type key) {
        int contador=0;
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->data == key) {
                 return contador+=sz(current->left);

            }
            if (current -> data > key) {
                current = current -> left;
            }
            else if (current -> data < key) {
                contador+=1+sz(current->left);
                current=current-> right;
            }

        }
        return contador;

    }

    TreeNode* min_element(TreeNode* u) {
        if (u == nullptr) return nullptr;
        TreeNode* current = u;
        while (current -> left != nullptr) {
            current = current -> left;
        }
        return current;
    }

    TreeNode* max_element(TreeNode* u) {
        if (u == nullptr) return nullptr;
        TreeNode* current = u;
        while (current -> right != nullptr) {
            current = current -> right;
        }
        return current;
    }

    TreeNode* min_element() {
        return min_element(root);
    }

    TreeNode* max_element() {
        return max_element(root);
    }

    TreeNode* rotate_left(TreeNode* u) {
        TreeNode* v = u -> right;
        v->parent = u -> parent;
        u -> right = v -> left;
        if (u->right != nullptr) u->right->parent = u;
        v -> left = u;
        u-> parent = v;
        update(u);
        update(v);
        return v;
    }

    TreeNode* rotate_right(TreeNode* u) {
        TreeNode* v = u -> left;
        v->parent = u -> parent;
        u -> left = v -> right;
        if (u->left != nullptr) u->left->parent = u;
        v -> right = u;
        u -> parent = v;
        update(u);
        update(v);
        return v;
    }

    TreeNode* rebalance(TreeNode* u) {
        update(u);
        if (FB(u) > 1) {
            // L
            if (FB(u -> left) < 0) {
                // LR
                u -> left = rotate_left(u -> left);


            }
            return rotate_right(u);
        }
        if (FB(u) < -1) {
            // R

            if (FB(u -> right) > 0) {
                // RL
                u -> right = rotate_right(u -> right);

            }
            return rotate_left(u);
        }
        return u;
    }


    void insert(data_type value) {
        root = insert(root, value, nullptr);
    }
    void insert_2(pair<data_type, data_type> value) {
        root = insert(root, value);
    }


    void print_inorder() {
        print_subtree_inorder(root);
        cout << endl;
    }

    void print_subtree_inorder(TreeNode* u) {
        if (u == nullptr) return;
        print_subtree_inorder(u -> left);
        cout << u -> data << " ";
        print_subtree_inorder(u -> right);
    }

    void print_preorder() {
        print_subtree_preorder(root);
        cout << endl;
    }

    void print_subtree_preorder(TreeNode* u) {
        if (u == nullptr) return;
        cout << u -> data << " ";
        print_subtree_preorder(u -> left);
        print_subtree_preorder(u -> right);
    }

    void print_postorder() {
        print_subtree_postorder(root);
        cout << endl;
    }

    void print_subtree_postorder(TreeNode* u) {
        if (u == nullptr) return;
        print_subtree_postorder(u -> left);
        print_subtree_postorder(u -> right);
        cout << u -> data << " ";
    }

    TreeNode* successor(TreeNode* x) {
        if (x -> right != nullptr) {
            return min_element(x -> right);
        }
        TreeNode* y = x -> parent;
        while (y != nullptr and y -> right == x) {
            x = y;
            y = y -> parent;
        }
        return y;
    }

    TreeNode* predecessor(TreeNode* x) {
        if (x -> left != nullptr) {
            return max_element(x -> left);
        }
        TreeNode* y = x -> parent;
        while (y != nullptr and y -> left == x) {
            x = y;
            y = y -> parent;
        }
        return y;
    }

    TreeNode* transplant(TreeNode* u, TreeNode* v) {
        if (u -> parent == nullptr) {
            root = v;
        }
        else if (u -> parent -> right == u) {
            u -> parent -> right = v;
        }
        else {
            u -> parent -> left = v;
        }
        if (v != nullptr) {
            v -> parent = u -> parent;
        }
        delete u;
    }

    TreeNode* erase(TreeNode* u, int value) {
        if (u==nullptr) {
            return nullptr;
        }
        if (value < u -> data) {
            u -> left = erase(u -> left, value);
        }
        else if (value > u -> data) {
            u -> right = erase(u -> right, value);
        }
        else {
            if (u->left == nullptr) {
                if (u->right != nullptr) u->right->parent = u->parent;
                return u->right;

            }
            else if ( u->right == nullptr) {
                u->left->parent=u->parent;
                return u->left;
            }
            TreeNode* s = min_element(u -> right);
            u->data= s->data;
            u->right= erase(u->right, s->data);
        }
        return rebalance(u);
    }
    void erase( int x) {
        root = erase(root, x);

    }
    bool find(data_type x) {
        TreeNode* u = root;
        while (u != nullptr) {
            if (x<u->data) u = u->left;
            else if (x > u->data) u = u->right;
            else return true;
        }
        return false;
    }

    TreeNode* insert(TreeNode* u, data_type value, TreeNode* parent) {
        if (u == nullptr) {
            return new TreeNode(value, 0,parent);
        }
        if (value<u->data) {
            u -> left = insert(u -> left, value, u );
        }
        else if (value> u->data) {
            u -> right = insert(u -> right, value, u );
        }
        return rebalance(u);
    }
    void k_minimo(int k) {
        int numero=0;
        TreeNode* u = root;
        while (u != nullptr) {
            int x= sz(u->left);
            if (k== x + 1 ) {
                numero=u->data;
                break;
            }
            else if (k<=x) {
                u= u->left;
            }
            else {
                k-=x+1;
                u= u->right;
            }
        }
        cout << numero << "\n";
    }




};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int operacion;
    int x;
    AVL<int> root;
    int contador=0;
    bool is=true;
    while (n>0) {
        cin>>operacion;
        if (operacion == 1) {
            cin>>x;
            root.insert(x);

        }
        else if (operacion == 2) {
            cin>>x;
            root.erase(x);
        }
        else if (operacion == 3) {
            cin>>x;
            root.k_minimo(x);
        }

        n--;
    }
    return 0;
}
