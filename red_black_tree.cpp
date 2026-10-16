// CS2023 - Algoritmos y Estructuras de Datos - Semana 9
// Implementación de Red-Black Tree (según las diapositivas)
// Compilar: g++ -std=c++17 -O2 -Wall red_black_tree.cpp -o rbt

#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <set>
#include <stdexcept>
#include <vector>

using namespace std;

enum class Color { ROJO, NEGRO };

template <typename T>
class RedBlackTree {
    struct Nodo {
        T clave;
        Color color;
        Nodo *izq, *der, *padre;
    };

    Nodo* nil;   // centinela T.nil (siempre NEGRO)
    Nodo* raiz;  // T.raiz
    size_t cantidad;

    // ---------------- Rotaciones (con padre) ----------------
    void rotarIzquierda(Nodo* x) {
        Nodo* y = x->der;
        x->der = y->izq;
        if (y->izq != nil) y->izq->padre = x;
        y->padre = x->padre;
        if (x->padre == nil)
            raiz = y;
        else if (x == x->padre->izq)
            x->padre->izq = y;
        else
            x->padre->der = y;
        y->izq = x;
        x->padre = y;
    }

    void rotarDerecha(Nodo* x) {  // espejo de rotarIzquierda
        Nodo* y = x->izq;
        x->izq = y->der;
        if (y->der != nil) y->der->padre = x;
        y->padre = x->padre;
        if (x->padre == nil)
            raiz = y;
        else if (x == x->padre->der)
            x->padre->der = y;
        else
            x->padre->izq = y;
        y->der = x;
        x->padre = y;
    }

    // ---------------- Insertar ----------------
    void insertarArreglar(Nodo* z) {
        while (z->padre->color == Color::ROJO) {
            if (z->padre == z->padre->padre->izq) {
                Nodo* t = z->padre->padre->der;  // el tío
                if (t->color == Color::ROJO) {   // caso 1
                    z->padre->color = Color::NEGRO;
                    t->color = Color::NEGRO;
                    z->padre->padre->color = Color::ROJO;
                    z = z->padre->padre;
                } else {
                    if (z == z->padre->der) {  // caso 2
                        z = z->padre;
                        rotarIzquierda(z);
                    }
                    // caso 3
                    z->padre->color = Color::NEGRO;
                    z->padre->padre->color = Color::ROJO;
                    rotarDerecha(z->padre->padre);
                }
            } else {  // lo mismo, intercambiando izq y der
                Nodo* t = z->padre->padre->izq;
                if (t->color == Color::ROJO) {
                    z->padre->color = Color::NEGRO;
                    t->color = Color::NEGRO;
                    z->padre->padre->color = Color::ROJO;
                    z = z->padre->padre;
                } else {
                    if (z == z->padre->izq) {
                        z = z->padre;
                        rotarDerecha(z);
                    }
                    z->padre->color = Color::NEGRO;
                    z->padre->padre->color = Color::ROJO;
                    rotarIzquierda(z->padre->padre);
                }
            }
        }
        raiz->color = Color::NEGRO;
    }

    // ---------------- Eliminar ----------------
    void transplantar(Nodo* u, Nodo* v) {
        if (u->padre == nil)
            raiz = v;
        else if (u == u->padre->izq)
            u->padre->izq = v;
        else
            u->padre->der = v;
        v->padre = u->padre;  // siempre, aunque v sea nil
    }

    Nodo* minimo(Nodo* x) const {
        while (x->izq != nil) x = x->izq;
        return x;
    }

    void eliminarArreglar(Nodo* x) {
        while (x != raiz && x->color == Color::NEGRO) {
            if (x == x->padre->izq) {
                Nodo* w = x->padre->der;  // el hermano
                if (w->color == Color::ROJO) {  // caso 1
                    w->color = Color::NEGRO;
                    x->padre->color = Color::ROJO;
                    rotarIzquierda(x->padre);
                    w = x->padre->der;
                }
                if (w->izq->color == Color::NEGRO && w->der->color == Color::NEGRO) {
                    // caso 2
                    w->color = Color::ROJO;
                    x = x->padre;
                } else {
                    if (w->der->color == Color::NEGRO) {  // caso 3
                        w->izq->color = Color::NEGRO;
                        w->color = Color::ROJO;
                        rotarDerecha(w);
                        w = x->padre->der;
                    }
                    // caso 4
                    w->color = x->padre->color;
                    x->padre->color = Color::NEGRO;
                    w->der->color = Color::NEGRO;
                    rotarIzquierda(x->padre);
                    x = raiz;
                }
            } else {  // lo mismo, intercambiando izq y der
                Nodo* w = x->padre->izq;
                if (w->color == Color::ROJO) {
                    w->color = Color::NEGRO;
                    x->padre->color = Color::ROJO;
                    rotarDerecha(x->padre);
                    w = x->padre->izq;
                }
                if (w->der->color == Color::NEGRO && w->izq->color == Color::NEGRO) {
                    w->color = Color::ROJO;
                    x = x->padre;
                } else {
                    if (w->izq->color == Color::NEGRO) {
                        w->der->color = Color::NEGRO;
                        w->color = Color::ROJO;
                        rotarIzquierda(w);
                        w = x->padre->izq;
                    }
                    w->color = x->padre->color;
                    x->padre->color = Color::NEGRO;
                    w->izq->color = Color::NEGRO;
                    rotarDerecha(x->padre);
                    x = raiz;
                }
            }
        }
        x->color = Color::NEGRO;
    }

    void eliminarNodo(Nodo* z) {
        Nodo* y = z;
        Color c = y->color;  // color original de y
        Nodo* x;
        if (z->izq == nil) {
            x = z->der;
            transplantar(z, z->der);
        } else if (z->der == nil) {
            x = z->izq;
            transplantar(z, z->izq);
        } else {
            y = minimo(z->der);
            c = y->color;
            x = y->der;
            if (y->padre == z) {
                x->padre = y;  // x puede ser nil: guardamos su padre
            } else {
                transplantar(y, y->der);
                y->der = z->der;
                y->der->padre = y;
            }
            transplantar(z, y);
            y->izq = z->izq;
            y->izq->padre = y;
            y->color = z->color;
        }
        delete z;
        --cantidad;
        if (c == Color::NEGRO) eliminarArreglar(x);
    }

    // ---------------- Auxiliares ----------------
    Nodo* buscarNodo(const T& clave) const {
        Nodo* x = raiz;
        while (x != nil && x->clave != clave)
            x = (clave < x->clave) ? x->izq : x->der;
        return x;
    }

    void destruir(Nodo* x) {
        if (x == nil) return;
        destruir(x->izq);
        destruir(x->der);
        delete x;
    }

    void enOrden(Nodo* x, const function<void(const T&)>& f) const {
        if (x == nil) return;
        enOrden(x->izq, f);
        f(x->clave);
        enOrden(x->der, f);
    }

    // Devuelve la altura negra de x; -1 si se viola alguna propiedad
    int validar(Nodo* x, const T* lo, const T* hi) const {
        if (x == nil) return 1;
        if (lo && !(*lo < x->clave)) return -1;
        if (hi && !(x->clave < *hi)) return -1;
        if (x->izq != nil && x->izq->padre != x) return -1;
        if (x->der != nil && x->der->padre != x) return -1;
        if (x->color == Color::ROJO &&
            (x->izq->color == Color::ROJO || x->der->color == Color::ROJO))
            return -1;  // dos rojos seguidos
        int a = validar(x->izq, lo, &x->clave);
        int b = validar(x->der, &x->clave, hi);
        if (a < 0 || b < 0 || a != b) return -1;
        return a + (x->color == Color::NEGRO ? 1 : 0);
    }

    void imprimir(Nodo* x, int nivel) const {
        if (x == nil) return;
        imprimir(x->der, nivel + 1);
        cout << string(nivel * 4, ' ') << x->clave
             << (x->color == Color::ROJO ? "(R)" : "(N)") << "\n";
        imprimir(x->izq, nivel + 1);
    }

public:
    RedBlackTree() : cantidad(0) {
        nil = new Nodo{T(), Color::NEGRO, nullptr, nullptr, nullptr};
        nil->izq = nil->der = nil->padre = nil;
        raiz = nil;
    }

    ~RedBlackTree() {
        destruir(raiz);
        delete nil;
    }

    RedBlackTree(const RedBlackTree&) = delete;
    RedBlackTree& operator=(const RedBlackTree&) = delete;

    size_t tam() const { return cantidad; }
    bool vacio() const { return cantidad == 0; }
    bool buscar(const T& clave) const { return buscarNodo(clave) != nil; }

    // RB-Insertar: devuelve false si la clave ya existe
    bool insertar(const T& clave) {
        Nodo* y = nil;
        Nodo* x = raiz;
        while (x != nil) {
            y = x;
            if (clave == x->clave) return false;
            x = (clave < x->clave) ? x->izq : x->der;
        }
        Nodo* z = new Nodo{clave, Color::ROJO, nil, nil, y};
        if (y == nil)
            raiz = z;
        else if (clave < y->clave)
            y->izq = z;
        else
            y->der = z;
        ++cantidad;
        insertarArreglar(z);
        return true;
    }

    // RB-Eliminar: devuelve false si la clave no existe
    bool eliminar(const T& clave) {
        Nodo* z = buscarNodo(clave);
        if (z == nil) return false;
        eliminarNodo(z);
        return true;
    }

    T minimo() const {
        if (raiz == nil) throw runtime_error("arbol vacio");
        return minimo(raiz)->clave;
    }

    T maximo() const {
        if (raiz == nil) throw runtime_error("arbol vacio");
        Nodo* x = raiz;
        while (x->der != nil) x = x->der;
        return x->clave;
    }

    void recorrerEnOrden(const function<void(const T&)>& f) const { enOrden(raiz, f); }

    int altura() const {
        function<int(Nodo*)> h = [&](Nodo* x) -> int {
            return x == nil ? 0 : 1 + max(h(x->izq), h(x->der));
        };
        return h(raiz);
    }

    // Verifica: raíz negra, sin dos rojos seguidos, misma altura negra, orden BST, punteros padre
    bool esValido() const {
        if (raiz->color != Color::NEGRO || nil->color != Color::NEGRO) return false;
        return validar(raiz, nullptr, nullptr) >= 0;
    }

    void imprimir() const { imprimir(raiz, 0); }
};

// ---------------- Pruebas ----------------
int main() {
    // Ejemplo de la diapositiva 13: insertar 41, 38, 31, 12, 19, 8
    RedBlackTree<int> t;
    for (int k : {41, 38, 31, 12, 19, 8}) {
        t.insertar(k);
        cout << "+" << k << (t.esValido() ? "  [valido]" : "  [INVALIDO]") << "\n";
    }
    cout << "\nArbol (raiz a la izquierda, derecha arriba):\n";
    t.imprimir();

    cout << "\nEn orden: ";
    t.recorrerEnOrden([](const int& k) { cout << k << ' '; });
    cout << "\n";

    cout << "buscar(19)=" << t.buscar(19) << "  buscar(100)=" << t.buscar(100) << "\n";

    for (int k : {8, 41, 38}) {
        t.eliminar(k);
        cout << "-" << k << (t.esValido() ? "  [valido]" : "  [INVALIDO]") << "\n";
    }
    t.imprimir();

    // Prueba de estres contra std::set
    mt19937 rng(12345);
    RedBlackTree<int> r;
    set<int> ref;
    for (int i = 0; i < 200000; ++i) {
        int k = rng() % 5000;
        if (rng() % 2) {
            bool a = r.insertar(k), b = ref.insert(k).second;
            if (a != b) { cout << "ERROR insertar\n"; return 1; }
        } else {
            bool a = r.eliminar(k), b = ref.erase(k) > 0;
            if (a != b) { cout << "ERROR eliminar\n"; return 1; }
        }
        if (i % 1000 == 0 && !r.esValido()) { cout << "ERROR invariantes\n"; return 1; }
    }
    vector<int> v;
    r.recorrerEnOrden([&](const int& k) { v.push_back(k); });
    bool igual = v.size() == ref.size() && equal(v.begin(), v.end(), ref.begin());
    cout << "\nEstres: n=" << r.tam() << " altura=" << r.altura()
         << " valido=" << r.esValido() << " igual_a_set=" << igual << "\n";
    return igual && r.esValido() ? 0 : 1;
}
