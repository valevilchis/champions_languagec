#include <iostream>
using namespace std;

typedef struct NodoUEFA {
    string equipo;
    int pts;
    NodoUEFA *izq;
    NodoUEFA *der;
}*MATCH;

MATCH crearNodo (string, int);
void insertalEyP (MATCH arbol, string, int);
void PostOrden (MATCH arbol);
void EliminarEquipo (MATCH &, int EE);
MATCH unirArbol (MATCH izq, MATCH der);
void impresion (MATCH &arbol, int j);


MATCH crearNodo (string equipo, int puntos) {
    MATCH nuevoNodo = new (struct NodoUEFA);
    nuevoNodo->equipo = equipo;
    nuevoNodo->pts = puntos;
    nuevoNodo->izq = nullptr;
    nuevoNodo->der = nullptr;
}

void insertalEyP (MATCH arbol, string equipo, int puntos){
    if (arbol == nullptr) {
        crearNodo(equipo,puntos);
    }
    else if (puntos < arbol->pts) {
        insertalEyP(arbol->izq, equipo,puntos);
    }
    else if (puntos > arbol->pts) {
        insertalEyP(arbol->der, equipo,puntos);
    }
}

void PostOrden (MATCH arbol){
    if (arbol == nullptr)
        return;
    PostOrden(arbol->izq);
    PostOrden(arbol->der);
    cout << arbol->pts << endl;
}

void EliminarEquipo (MATCH &arbol, int EE){
    if (arbol == nullptr)
        return;
    if (EE < arbol->pts)
        EliminarEquipo(arbol->izq, EE);
    else if (EE >arbol->pts)
        EliminarEquipo(arbol->der,EE);
    else {
        MATCH q = arbol;
        arbol = unirArbol(arbol->izq, arbol->der);
        delete q;
    }
}

MATCH unirArbol (MATCH izq, MATCH der){
    if (izq == nullptr)
        return der;
    if (der == nullptr)
        return izq;
    MATCH raiz = unirArbol(izq->der, der->izq);
    izq->der = raiz;
    der->izq = izq;
    return der;
}

void impresion (MATCH &arbol, int j) {
    if (arbol == nullptr) {
        return;
    } else {
        impresion(arbol->der, j + 2);
        for (int i = 0; i < j; i++) {
            cout << "   ";
        }
        cout << arbol->equipo << endl;
        impresion(arbol->izq, j + 2);
    }
}