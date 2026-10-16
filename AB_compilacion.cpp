//
// Created by maydelithzuniga on 15/09/2026.
//
#include <iostream>
using namespace std;

template<typename t>
struct BST {
    struct TreeNode {
        t data;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
        TreeNode(t data= t(), TreeNode* left=nullptr, TreeNode* right=nullptr, TreeNode* parent=nullptr): data(data), left(left), right(right), parent(parent) {}
    };
    TreeNode* root;
    BST() {
        root= new TreeNode();

    }
    bool search( t key) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            if (current->data>key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }
    t min_element(TreeNode* u) {
        if (u->data == nullptr) {
            return t();
        }
        TreeNode* current = u;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->data;

    }
t max_element(TreeNode* u) {
    if (u->data == nullptr) {
        return t();
    }
    TreeNode* current = u;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;

}
    t min_element() {
        min_element(root);
    }
    t max_element() {
        max_element(root);
    }

    void insertar(t value) {
        if (root == nullptr) {
            root= new TreeNode(value);
            return;
        }
        TreeNode* current = root;

        while (current !=nullptr) {
            if (current->data == value) {
                return;
            }
            if (current->data<value) {
                if (current->right != nullptr) {
                    current= current->right;
                }
                else {
                    current->right = new TreeNode(value,nullptr,nullptr, current) ;
                }
            }
            else {
                if (current->left != nullptr) {
                    current= current->left;
                }
                else {
                    current->left = new TreeNode(value,nullptr,nullptr, current);
                    break;
                }
            }
        }
    }
    void print_inorder() {
        print_subtree_inorder(root);
    }
    void print_subtree_inorder(TreeNode* _root) {
        if (_root == nullptr) {
            return;
        }
        print_subtree_inorder(_root->left);
        cout << _root->data << " ";
        print_subtree_inorder(_root->right);
    }
     t sucessor(TreeNode* x) {
        if (x ->right1=nullptr) {
            return min_element(x->right);

        }
        TreeNode* y=x->parent;
        while (y!=nullptr and y->right==x) {
            x=y;
            y=y->parent;
        }
        return y ? y->data : t();
    }
    t predecessor(TreeNode* x) {
        if (x->left != nullptr) {
            return max_element(x->left);

        }
        TreeNode* y=x->parent;
        while (y!=nullptr and y->left==x   ) {
            x=y;
            y=y->parent;
        }
        return y ? y->data : t();
    }
    void transplant(TreeNode* u, TreeNode* v) {
        if (u->parent==nullptr) {
            root=v;
        }
        else if (u->parent->right==u) {
            u->parent->right=v;
        }
        else {
            u->parent->left=v;

        }
        if (v!=nullptr) {
            v->parent=u->parent;
        }
        delete u;
    }
    void erase(TreeNode* u) {
        if (u->left!=nullptr and u->right==nullptr) {
            if (u->parent!=nullptr) {

            }
        }
    }
};

int main() {




    return 0;
}
