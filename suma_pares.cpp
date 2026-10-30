#include <iostream>
#include <vector>
using namespace std;
#include<bits/stdc++.h>
using namespace::std;

template<typename data_type>
struct AVL {
    struct TreeNode {
        int height;
        data_type data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(data_type data = data_type(), int height = 0,
                    TreeNode* left = nullptr,
                    TreeNode* right = nullptr) :
                    data(data), height(height), left(left), right(right) {}
    };

    TreeNode* root;

    AVL() {
        root = nullptr;
    }

    void update(TreeNode* u) {
        u -> height = 1 + max(h(u -> left) , h(u -> right));
    }

    int h(TreeNode* u) {
        return u == nullptr ? -1 : u -> height;
    }

    int FB(TreeNode* u) {
        return h(u -> left) - h(u -> right);
    }

    bool search(data_type key) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            if (current -> data > key) {
                current = current -> left;
            }
            else {
                current = current -> right;
            }
        }
        return false;
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
        u -> right = v -> left;
        v -> left = u;
        update(u);
        update(v);
        return v;
    }

    TreeNode* rotate_right(TreeNode* u) {
        TreeNode* v = u -> left;
        u -> left = v -> right;
        v -> right = u;
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
        root = insert(root, value);
        update(root);

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

    TreeNode* erase(TreeNode* u, data_type value) {
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
                return u->right;
            }
            else if ( u->right == nullptr) {
                return u->left;
            }
            TreeNode* s = min_element(u -> right);
            u->data= s->data;
            u->right= erase(u->right, s->data);
        }
        return rebalance(u);
    }
    void erase( data_type x){
        root = erase(root, x);
    }

    TreeNode* insert(TreeNode* u, data_type value) {
        if (u == nullptr) {
            return new TreeNode(value, 0);
        }
        if (value < u -> data) {
            u -> left = insert(u -> left, value);
        }
        else {
            u -> right = insert(u -> right, value);
        }
        return rebalance(u);
    }
};
int main() {

    int n;
    cin>>n;
    int k;
    cin>>k;
    AVL<pair<long long int, int>> sumas;
    vector<long long int> v;
    long long int x;
    long long int y;
    long long int suma=0;

    for(int i=0;i<n;i++) {
        cin>>x;
        v.push_back(x);
    }

    vector<int> ant, sig;
    vector<bool> vivo(n, true);
    for (int i=0;i<n;i++) {
        ant.push_back(i-1);
        sig.push_back(i+1);
    }
    sig[n-1]=-1;

    x=v[0];
    for (int i = 1; i < v.size(); i++) {
        y=v[i];
        suma= 1LL*x+1LL*y;
        sumas.insert(make_pair(suma,i-1));
        x=y;
    }
    int quedan=n;
    while (quedan>k) {
        int indice=sumas.min_element()->data.second;
        long long int borrar=sumas.min_element()->data.first;
        sumas.erase(sumas.min_element()->data);

        int derecha=sig[indice];
        if (ant[indice] != -1)
            sumas.erase(make_pair(v[ant[indice]]+v[indice], ant[indice]));
        if (sig[derecha] != -1)
            sumas.erase(make_pair(v[derecha]+v[sig[derecha]], derecha));

        v[indice]=borrar;
        vivo[derecha]=false;
        sig[indice]=sig[derecha];
        if (sig[derecha] != -1) ant[sig[derecha]]=indice;
        quedan--;

        if (ant[indice] != -1)
            sumas.insert(make_pair(v[ant[indice]]+v[indice], ant[indice]));
        if (sig[indice] != -1)
            sumas.insert(make_pair(v[indice]+v[sig[indice]], indice));
    }

    for (int i=0;i<v.size();i++) {
        if (vivo[i])
        cout<<v[i]<<" ";
    }

    return 0;
}
