#include <iostream>
using namespace std;

typedef struct Fechas {
    char estadio [50];
    char equiposE [50];
}Fechas;

typedef struct NodoA {
    struct Fechas *Partidos;
    struct NodoA *enlace;
}NodoA;

void leerPartArchi (struct Fechas*, FILE *);
void leerArchivo (char *, struct NodoA **, struct NodoA **);
struct Fechas *crearPartido();
struct NodoA *crearNodo (struct Fechas*);
void agregarLista (struct NodoA **anterior, struct NodoA **siguiente, struct NodoA *nuevoN);
void imprimirLis (struct NodoA *);
void imprimirPartido (struct Fechas *);
void liberarMemoria (struct NodoA *r, struct Nodo *s);
void fechaYhora ();

void leerPartArchi (struct Fechas *r, FILE *archivo_p) {
    fgetc(archivo_p);
    fgets(r->estadio, 50, archivo_p);
    fgets(r->equiposE, 50, archivo_p);
}
void leerArchivo (char *ruta_a, struct NodoA **anterior, struct NodoA **siguiente) {
    int j;
    struct Fechas *nuevaF;
    struct NodoA *nuevoNo;
    FILE *archivo_p;
    archivo_p = fopen(ruta_a, "r");
    fscanf(archivo_p, "%d", &j);

    for (int i = 0; i < j; i++) {
        nuevaF = crearPartido();
        leerPartArchi(nuevaF, archivo_p);

        nuevoNo = crearNodo(nuevaF);
        agregarLista(anterior,siguiente,nuevoNo);
    }
}
struct Fechas *crearPartido() {
    struct Fechas *nuevaF;
    nuevaF = new (struct Fechas);
    return nuevaF;
}
struct NodoA *crearNodo (struct Fechas *r) {
    struct NodoA *nuevoNo;
    nuevoNo = new (struct NodoA);
    nuevoNo->Partidos = r;
    nuevoNo->enlace = nullptr;
    return nuevoNo;
}
void agregarLista (struct NodoA **anterior, struct NodoA **siguiente, struct NodoA *nuevoN) {
    if (*anterior == nullptr) {
        *anterior = nuevoN;
        *siguiente = nuevoN;
    } else {
        (*siguiente)->enlace = nuevoN;
        *siguiente = nuevoN;
    }
}

void imprimirLis (struct NodoA *anterior) {
    int i = 0;
    struct NodoA *actual;
    actual = anterior;
    while (actual != nullptr) {
        imprimirPartido(actual->Partidos);
        actual = actual->enlace;
        i++;
    }
}
void imprimirPartido (struct Fechas *r) {
    cout << "---------------------------------------\n";
    fechaYhora();
    cout << "\nEstadio: " << r->estadio;
    cout << r->equiposE << endl;
}

void liberarMemoria (struct NodoA *r, struct NodoA *s) {
    r = s;
    while (r != nullptr) {
        s = r->enlace;
        delete r;
        r = s;
    }
}


void fechaYhora () {
    int anio;
    time_t  nueva = time(0);
    tm *time = localtime(&nueva);

    vector<string> dia_delPartido;
    dia_delPartido.push_back("Domingo");
    dia_delPartido.push_back("Lunes");
    dia_delPartido.push_back("Martes");
    dia_delPartido.push_back("Miercoles");
    dia_delPartido.push_back("Jueves");
    dia_delPartido.push_back("Viernes");
    dia_delPartido.push_back("Sabado");

    vector<string> mes_delPartido;
    mes_delPartido.push_back("Enero");
    mes_delPartido.push_back("Febrero");
    mes_delPartido.push_back("Marzo");
    mes_delPartido.push_back("Abril");
    mes_delPartido.push_back("Mayo");
    mes_delPartido.push_back("Junio");
    mes_delPartido.push_back("Julio");
    mes_delPartido.push_back("Agosto");
    mes_delPartido.push_back("Septiembre");
    mes_delPartido.push_back("Octubre");
    mes_delPartido.push_back("Noviembre");
    mes_delPartido.push_back("Diciembre");

    anio = 1900 + time->tm_year;
    cout << "\t"<<dia_delPartido[time->tm_wday] << ", ";
    cout << time->tm_mday << " de " << mes_delPartido[time->tm_mon] << " del " << anio << endl;
    cout << "\t\t\t\t"<<time->tm_hour << ":" << time->tm_min;
}