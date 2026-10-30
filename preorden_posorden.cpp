#include <iostream>
#include <vector>
using namespace std;

#include<bits/stdc++.h>
using namespace::std;

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
        long long suma;
        int cnt;
        int size;

        TreeNode( data_type _data, int height = 0,TreeNode* parent = nullptr, int cnt=1, int _size=1,
                    TreeNode* left = nullptr,
                    TreeNode* right = nullptr) :
                    data(_data), size(_size),cnt(cnt), height(height), left(left), right(right), parent(parent) {
            suma=data;
        }
    };

    TreeNode* root;

    AVL() {
        root = nullptr;
    }

    int sz(TreeNode* u) {
        if (u == nullptr) return 0;
        return u->size;

    }
    long long suma(TreeNode* u) {
        if (u == nullptr) return 0;
        return u -> suma;
    }

    int cnt(TreeNode* u) {
        if (u == nullptr) return 0;
        return u->cnt;
    }

    void update(TreeNode* u) {
        u -> height = 1 + max(h(u -> left) , h(u -> right));
        u->size = u->cnt + sz(u -> left) + sz(u -> right);
        u->suma=1LL*u->cnt*u->data + suma(u -> left) + suma(u -> right);
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
            if (u->cnt>1) {
                u->cnt-=1;
                update(u);
                return u;
            }
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
            u->cnt=s->cnt;
            s->cnt=1;
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
        if (value==u->data) {
            u->cnt+=1;
            update(u);
            return u;
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


    long long rango(int x, int y) {
        TreeNode* u = root;
        long long contador=0;
        while (u != nullptr) {
            if (u->data<=y  and u->data>=x) {
                contador+=1LL*u->cnt*u->data;
                if (u->left != nullptr) {
                    TreeNode* v=u->left;
                    while (v != nullptr) {
                        if (v->data>=x) {
                            contador+=1LL*v->cnt*v->data + suma(v->right);
                            v = v->left;
                        }
                        else {
                            v=v->right;
                        }
                    }
                }
                u = u -> right;
            }
            else if (y<u->data) {
                u=u->left;
            }
            else if (x>u->data) {
                u=u->right;
            }
        }
        return contador;
    }



};

int encontrar(vector<int> &v, int x, int ini, int fin) {
    while (ini <= fin) {
        if (v[ini]==x) {
            return ini;
        }
        if (v[fin]==x) {
            return fin;
        }
        ini++;
        fin--;
    }
    return -1;
}

void reconstruir(vector<int> &preorder, vector<int> &postorder, int l, int r, int pl, int pr, vector<int> &inorden, bool &is) {
    if (!is) {
        return;
    }
    int raiz=preorder[l];
    if (raiz!=postorder[pr]) {
        is=false;
        return;
    }
    if (l==r) {
        inorden.push_back(raiz);
        return;
    }
    int siguiente_preorden=preorder[l+1];
    int anterior_postorden=postorder[pr-1];
    if (siguiente_preorden!=anterior_postorden) {
        int indice_derecho=encontrar(preorder,anterior_postorden,l+2,r);
        if (indice_derecho==-1) {
            is=false;
            return;
        }
        int z=(indice_derecho-l)-2;
        int y=r-indice_derecho;
        if (z%2==0 and y%2==0) {
            int tam=indice_derecho-l-1;
            reconstruir(preorder,postorder,l+1,indice_derecho-1,pl,pl+tam-1,inorden, is);
            inorden.push_back(raiz);
            reconstruir(preorder,postorder,indice_derecho,r,pl+tam,pr-1,inorden,is);
        }
        else {
            is=false;
        }
    }
    else {
        is=false;
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> preorder;
    vector<int> postorder;
    vector<int> inorden;
    bool is=true;
    int x;
    for (int i = 0; i < n; i++) {
        cin>>x;
        preorder.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        cin>>x;
        postorder.push_back(x);
    }
    reconstruir(preorder,postorder,0,n-1,0,n-1, inorden, is);
    if (!is) {
        cout<<"IMPOSIBLE"<<"\n";
    }
    else {
        for (int i = 0; i < n; i++) {
            cout<<inorden[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}