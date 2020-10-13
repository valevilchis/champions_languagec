#include <iostream>
#define a 16
#define b 1
using namespace std;

struct estadisticas {
    string equipo;
    int parJ;
    int parG;
    int parE;
    int parP;
    int promedio;
}estadisticas[a][b];

void ingresarD ();
void promedio ();
void impresion ();
void ingresarD () {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << "Nombre Equipo: ";
            cin >> estadisticas[i][j].equipo;
            cout << "Partidos Jugados: ";
            cin >> estadisticas[i][j].parJ;
            cout << "Partidos Ganados: ";
            cin >> estadisticas[i][j].parG;
            cout << "Partidos Empatados: ";
            cin >> estadisticas[i][j].parE;
            cout << "Partidos Perdidos: ";
            cin >> estadisticas[i][j].parP;
        }
    }
}

void promedio () {
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 1; j++) {
            estadisticas[i][j].promedio = (estadisticas[i][j].parG * 3 + estadisticas[i][j].parE);
        }
    }
}

void impresion () {
    cout<< "\t" << "Equipo" << "\t" << "PJ" << "\t" << "PG" << "\t" << "PP" << "\t" << "PE" << "\t" << "PROM" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            cout << "\t"<< estadisticas[i][j].equipo << "\t" << estadisticas[i][j].parJ << "\t" << estadisticas[i][j].parG << "\t" << estadisticas[i][j].parP << "\t" << estadisticas[i][j].parE << "\t" << estadisticas[i][j].promedio << endl;
        }
    }
}