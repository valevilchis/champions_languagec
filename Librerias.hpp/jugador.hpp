#include <iostream>
using namespace std;
typedef struct Jugador {
    char nombre [30];
    char posicion [30];
    int numeroJ;
    int tarjetaA;
    int faltas;
    int goles;
}Jugador;

typedef struct Nodo {
    struct Jugador *futbolista;
    struct Nodo *siguiente;
}Nodo, Nodo;

void leerJugaArch (struct Jugador *p, FILE *archivo);
void leerArch (char *ruta, struct Nodo **inicio, struct Nodo **final);
struct Jugador *crearJug ();
struct Nodo *crearNod (struct Jugador *p);
void agregarList (struct Nodo **inicio, struct Nodo **final, struct Nodo *nuevo );
void imprimirLista(struct Nodo *inicio);
void imprimirJugador (struct Jugador *p);
void libMem (struct Nodo *p, struct Nodo *q);

void leerJugaArch (struct Jugador *p, FILE *archivo) {
    fscanf(archivo, "%d", &p->numeroJ);
    fscanf(archivo, "%d", &p->tarjetaA);
    fscanf(archivo, "%d", &p->faltas);
    fscanf(archivo, "%d", &p->goles);
    fgetc(archivo);
    fgets(p->nombre,30,archivo);
    fgets(p->posicion,30,archivo);
}

void leerArch (char *ruta, struct Nodo **inicio, struct Nodo **final) {
    struct Jugador *nuevoJ;
    struct Nodo *nuevoN;
    FILE *archivo;
    int n;
    archivo = fopen(ruta, "r");
    fscanf(archivo, "%d", &n);

    for (int i = 0; i < n; i++) {
        nuevoJ = crearJug();
        leerJugaArch(nuevoJ,archivo);

        nuevoN = crearNod(nuevoJ);
        agregarList(inicio, final, nuevoN);

    }
    fclose(archivo);
}

struct Jugador *crearJug () {
    struct Jugador *nuevoJ;
    nuevoJ = new (struct Jugador);
    return nuevoJ;
}

struct Nodo *crearNod (struct Jugador *p) {
    struct Nodo *nuevoN;

    nuevoN = new (struct Nodo);
    nuevoN->futbolista = p;
    nuevoN->siguiente = nullptr;
    return nuevoN;
}

void agregarList (struct Nodo **inicio, struct Nodo **final, struct Nodo *nuevo ) {
    if (*inicio == nullptr) {
        *inicio = nuevo;
        *final = nuevo;
    } else {
        (*final)->siguiente = nuevo;
        *final = nuevo;
    }
}

void imprimirLista(struct Nodo *inicio) {
    int i = 0;
    struct Nodo *actual;
    actual = inicio;
    while (actual != nullptr) {
        imprimirJugador(actual->futbolista);
        actual = actual->siguiente;
        i++;
    }
}

void imprimirJugador (struct Jugador *p) {
    cout << "\nNombre: " << p->nombre;
    cout << "Posicion: " << p->posicion;
    cout << "Tarjetas Amarillas: " << p->tarjetaA << endl;
    cout << "Faltas: " << p->faltas << endl;
    cout << "Goles Anotados: " << p->goles << endl;
    cout << "Numero Jugador: " << p->numeroJ << "\n";
}

void libMem (struct Nodo *p, struct Nodo *q) {
    p = q;
    while (p != nullptr) {
        q = p->siguiente;
        delete p;
        p = q;
    }
}
