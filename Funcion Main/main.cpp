#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <fstream>
#include <ctime>
#include <vector>
#include "jugador.hpp"
#include "partidosOctavos.hpp"
#include "ABB.hpp"
#include "Estadistica.hpp"
using namespace std;

int main() {
    int opc;
    char opn;
    MATCH arbol;
    arbol = nullptr;
    do {
        cout << "\t*************************\n";
        cout << "\t*      BIENVENIDO       *\n";
        cout << "\t* UEFA CHAMPIONS LEAGUE *\n";
        cout << "\t*************************\n";
        cout << "\n";
        cout << "\t[1] Equipos.\n";
        cout << "\t[2] Fechas Octavos.\n";
        cout << "\t[3] Partidos.\n";
        cout << "\t[4] Estadisticas. \n";
        cout << "\t[0] Salir. \n";
        cout << "\tDigite numero: ";
        cin >> opc;
        system("cls");

        switch (opc) {
            case 1: {
                char grp;

                cout << "[A] Grupo. \n";
                cout << "[B] Grupo. \n";
                cout << "[C] Grupo. \n";
                cout << "[D] Grupo. \n";
                cout << "Digite letra (Mayuscula): ";
                cin >> grp;
                system("cls");

                switch (grp) {
                    case 'A': {
                        int eqpA;
                        string grupoA;
                        ifstream archivo;

                        archivo.open("grupoA.txt", ios::in);
                        if (archivo.fail()) {
                            cout << "Error";
                            exit(1);
                        }

                        while (!archivo.eof()) {
                            getline(archivo, grupoA);
                            cout << "\t" << grupoA << "\n";
                        }
                        archivo.close();

                        cout << "\n\t\tJugadores 'A'\n";
                        cout << "\t[1] Villareal (ESP)\n";
                        cout << "\t[2] Sevilla (ESP)\n";
                        cout << "\t[3] Milan (ITA)\n";
                        cout << "\t[4] Manchester United (ENG)\n";
                        cout << "\tDigite numero: ";
                        cin >> eqpA;
                        system("cls");

                        switch (eqpA) {
                            case 1: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tVillareal.\n";
                                leerArch("VillaReal.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            case 2: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tSevilla\n";
                                leerArch("Sevilla.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            case 3: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tMilan\n";
                                leerArch("Milan.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            case 4: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tManchester United\n";
                                leerArch("ManchesterUnited.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            default:
                                break;
                        }
                        break;
                    }
                    case 'B': {
                        int eqpB;
                        string grupoA;
                        ifstream archivo;

                        archivo.open("grupoB.txt", ios::in);
                        if (archivo.fail()) {
                            cout << "Error";
                            exit(1);
                        }

                        while (!archivo.eof()) {
                            getline(archivo, grupoA);
                            cout << "\t" << grupoA << "\n";
                        }
                        archivo.close();

                        cout << "\n\t\tJugadores 'B'\n";
                        cout << "\t[1] Ajax (NED)\n";
                        cout << "\t[2] Porto (POR)\n";
                        cout << "\t[3] Tottenham Hotspor (ENG)\n";
                        cout << "\t[4] Barcelona (ESP))\n";
                        cout << "\tDigite numero: ";
                        cin >> eqpB;
                        system("cls");

                        switch (eqpB) {
                            case 1: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tAjax\n";
                                leerArch("Ajax.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            case 2: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tPorto\n";
                                leerArch("Porto.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            case 3: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tTottenham Hotspor\n";
                                leerArch("TottenhamHotspor.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            case 4: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tBarcelona\n";
                                leerArch("Barcelona.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            default:
                                break;
                        }
                        break;
                    }
                    case 'C': {
                        int eqpC;
                        string grupoA;
                        ifstream archivo;

                        archivo.open("grupoC.txt", ios::in);
                        if (archivo.fail()) {
                            cout << "Error";
                            exit(1);
                        }

                        while (!archivo.eof()) {
                            getline(archivo, grupoA);
                            cout << "\t" << grupoA << "\n";
                        }
                        archivo.close();

                        cout << "\n\t\tJugadores 'C'\n";
                        cout << "\t[1] Bayern de Munich (GER)\n";
                        cout << "\t[2] Real Madrid (ESP)\n";
                        cout << "\t[3] Liverpool (ENG)\n";
                        cout << "\t[4] Roma (ITA)\n";
                        cout << "\tDigite numero: ";
                        cin >> eqpC;
                        system("cls");

                        switch (eqpC) {
                            case 1: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tBayern de Munich\n";
                                leerArch("BayernMunich.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            case 2: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tReal Madrid\n";
                                leerArch("RealMadrid.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            case 3: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tLiverpool\n";
                                leerArch("Liverpool.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            case 4: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tRoma\n";
                                leerArch("Roma.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            default:
                                break;
                        }
                        break;
                    }
                    case 'D': {
                        int eqpD;
                        string grupoA;
                        ifstream archivo;

                        archivo.open("grupoD.txt", ios::in);
                        if (archivo.fail()) {
                            cout << "Error";
                            exit(1);
                        }

                        while (!archivo.eof()) {
                            getline(archivo, grupoA);
                            cout << "\t" << grupoA << "\n";
                        }
                        archivo.close();

                        cout << "\n\t\tJugadores 'D'\n";
                        cout << "\t[1] Juventus (ITA)\n";
                        cout << "\t[2] Paris Saint-Germain (FRA)\n";
                        cout << "\t[3] Atletico de Madrid (ESP)\n";
                        cout << "\t[4] Monaco (FRA)\n";
                        cout << "\tDigite numero: ";
                        cin >> eqpD;
                        system("cls");

                        switch (eqpD) {
                            case 1: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tJuventus\n";
                                leerArch("Juventus.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            case 2: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tParis Saint-Germain\n";
                                leerArch("ParisSaint.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            case 3: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tAtletico de Madrid (ESP)\n";
                                leerArch("AtleticoMadrid.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            case 4: {
                                struct Nodo *p, *q;
                                p = nullptr;
                                q = nullptr;
                                cout << "\tMonaco\n";
                                leerArch("Monaco.txt", &p, &q);
                                imprimirLista(p);
                                libMem(p, q);
                                break;
                            }
                            default:;
                                break;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 2: {
                struct NodoA *r, *s;
                r = nullptr;
                s = nullptr;
                cout << "\tPartidos Octavos\n";
                leerArchivo("Partidos.txt", &r, &s);
                imprimirLis(r);
                liberarMemoria(r,s);
                break;
            }
            case 3: {
                string nomE;
                int pMax, pts = 0, totN, pMen;
                pMen = 15;
                pMax = 45;
                totN = 5;
                for (int i = 0; i < totN; i++) {
                    cout << "Nombre equipo: ";
                    cin >> nomE;
                    cout << "Puntos Equipo: ";
                    cin >> pts;
                    insertalEyP(arbol,nomE,pts);
                }
                cout << "Orden.\n";
                PostOrden(arbol);
                break;
            }
            case 4: {
                fstream archivoE ("Estadisticas.txt");
                ingresarD();
                promedio();
                impresion();
                break;
            }
            default:
                break;
        }
        cout << "\nAtras (Presione 'X'): ";
        cin >> opn;
    } while (opn == 'x' || opn == 'X');
    system("pause");
    return 0;
}