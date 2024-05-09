#ifndef Main_CPP
#define Main_CPP

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <random>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include "SimulacionPartidos.hpp"
#include "SimulacionFases.hpp"
#include "SimulacionCopa.hpp"

using namespace std;

//struct Jugador {
//    int id;
//    string nombre;
//    int agresividad;
//};
//
//struct Equipo {
//    int id;
//    string nombre;
//    int defensa;
//    int ataque;
//    vector<Jugador> jugadores;
//    int puntos;
//    int golesAFavor;
//    int diferenciaGoles;
//    int golesEnContra;
//    int posicion;
//    string grupo;
//};


//struct Partido {
//    int id;
//    int fecha;
//    Equipo equipo1;
//    Equipo equipo2;
//    int golesEquipo1;
//    int golesEquipo2;
//};




//Ver Jugadores de los equipos
int equiposs() {
    system ("cls");
    int opcionequipos;
    string equipos1;
    string equipos; 
    while (true) {
        system ("cls");
        cout << "--- EQUIPOS CLASIFICADOS ---" << endl;
        cout << "Seleccione el equipo que desea ver: " << endl;
        equipos1.clear(); 
        ifstream archivo("Equipos.txt");
        while (getline(archivo, equipos)) {
            equipos1 = equipos1 + equipos + "\n";
        }
        cout<<endl;
        archivo.close();
        cout << equipos1 << endl;
        cout << "Digite el equipo que desea ver: " << endl;
        cin >> opcionequipos;
        cout<<endl;
        if (opcionequipos == 17) {
            return 0; 
        }
        if (opcionequipos == 1) {
            string jugador1, jugador; 
            ifstream archivo("Argentina.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 2) {
            string jugador1, jugador; 
            ifstream archivo("Chile.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 3) {
            string jugador1, jugador; 
            ifstream archivo("Peru.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 4) {
            string jugador1, jugador; 
            ifstream archivo("Canada.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 5) {
            string jugador1, jugador; 
            ifstream archivo("Mexico.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 6) {
            string jugador1, jugador; 
            ifstream archivo("Ecuador.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 7) {
            string jugador1, jugador;
            ifstream archivo("Venezuela.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 8) {
            string jugador1, jugador; 
            ifstream archivo("Jamaica.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;}
        if (opcionequipos == 9) {
            string jugador1, jugador; 
            ifstream archivo("EstadosUnidos.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 10) {
            string jugador1, jugador; 
            ifstream archivo("Uruguay.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 11) {
            string jugador1, jugador;
            ifstream archivo("Panama.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 12) {
            string jugador1, jugador; 
            ifstream archivo("Bolivia.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 13) {
            string jugador1, jugador;
            ifstream archivo("Brasil.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 14) {
            string jugador1, jugador;
            ifstream archivo("Colombia.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 15) {
            string jugador1, jugador; 
            ifstream archivo("Paraguay.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos == 16) {
            string jugador1, jugador; 
            ifstream archivo("CostaRica.txt");
            while (getline(archivo, jugador1)) {
                jugador = jugador + jugador1 + "\n";
            }
            archivo.close();
            cout << jugador << endl;
        }
        if (opcionequipos==17){
            cout<<"Volviendo al menu principal..."<<endl;
        }
        if (opcionequipos >= 18) {
            cout << "Opcion no valida, volviendo al menu..." << endl;
        }
        system("pause");
        system ("cls");
    }
    system("pause");
}
int grupos() {
    system ("cls");
    int opciongrupos;
    string grupo_1;
    string grupo1; 
    while (true) {
        
        grupo_1.clear(); 
        cout << "--- GRUPOS ---\n" << endl;
        cout << "1. Grupo A " << endl;
        cout << "2. Grupo B " << endl;
        cout << "3. Grupo C " << endl;
        cout << "4. Grupo D " << endl;
        cout << "5. Ver todos los grupos" << endl;
        cout << "6. Volver al menu principal" << endl;
        cout << "\nSeleccione el grupo que desea ver: " << endl;
        cin >> opciongrupos;
        cout<<endl;
        if (opciongrupos == 1) {
            ifstream archivo("GrupoA.txt");
            while (getline(archivo, grupo1)) {
                grupo_1 = grupo_1 + grupo1 + "\n";
            }
            archivo.close();
            cout << grupo_1 << endl;
        }
        if (opciongrupos == 2) {
            ifstream archivo("GrupoB.txt");
            while (getline(archivo, grupo1)) {
                grupo_1 = grupo_1 + grupo1 + "\n";
            }
            archivo.close();
            cout << grupo_1 << endl;
        }
        if (opciongrupos == 3) {
            ifstream archivo("GrupoC.txt");
            while (getline(archivo, grupo1)) {
                grupo_1 = grupo_1 + grupo1 + "\n";
            }
            archivo.close();
            cout << grupo_1 << endl;
        }
        if (opciongrupos == 4) {
            ifstream archivo("GrupoD.txt");
            while (getline(archivo, grupo1)) {
                grupo_1 = grupo_1 + grupo1 + "\n";
            }
            archivo.close();
            cout << grupo_1 << endl;
        }
        if (opciongrupos == 5) {
            ifstream archivo("Grupos.txt");
            while (getline(archivo, grupo1)) {
                grupo_1 = grupo_1 + grupo1 + "\n";
            }
            archivo.close();
            cout << grupo_1 << endl;
        }
        if (opciongrupos == 6) {
            return 0; // Volver al menú principal
        }
        if (opciongrupos >= 6) {
            cout << "Opcion no valida volviendo al menu..." << endl;
        }
        system("pause");
        system ("cls");
    }

}





int Estadios() {

    
    string linea;
    string est;
    string est2;


    cout << "--- ESTADIOS ---\n" << endl;

    ifstream archivo("NombreEstadios.txt");
    while (getline(archivo, est)) {
        est2 = est2 + est + "\n";
    }
    archivo.close();
    cout << est2 << endl;
    int opcionestadio;
    cout << "\nDesea ver los estadios por partido?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "Seleccione una opcion: " << endl;

    cin >> opcionestadio;
    if (opcionestadio == 1){
        system ("cls");
        ifstream archivo("Estadios_copa_america_ks.txt");
    while (getline(archivo, est)) {
        est2 = est2 + est + "\n";
    }
    archivo.close();
    cout << est2 << endl;
    }
    if (opcionestadio == 2){
        return 0;
    }
    system("pause");
    system ("cls");
}





//vector<Equipo> leerEquipos() {
//    vector<Equipo> equipos;
//    ifstream archivo("Info_Equipos_Jugadores.txt");
//    string linea;
//    Equipo equipoActual;
//    Jugador jugadorActual;
//    while (getline(archivo, linea)) {
//        if (linea[0] == '-') {
//            // Nuevo equipo
//            if (!equipoActual.nombre.empty()) {
//                equipos.push_back(equipoActual);
//                equipoActual = Equipo();
//            }
//            if (linea.size() > 2) { 
//                istringstream iss(linea.substr(2));
//                iss >> equipoActual.id;
//                getline(iss, equipoActual.nombre);
//                getline(iss, linea);
//                iss.str(linea);
//                iss.clear();
//                iss >> equipoActual.defensa;
//                iss >> equipoActual.ataque;
//            } 
//        } else if (linea[0] == '+') {
//            // Nuevo jugador
//            if (linea.size() > 2) {
//                istringstream iss(linea.substr(2));
//                iss >> jugadorActual.id;
//                getline(iss, jugadorActual.nombre);
//                iss >> jugadorActual.agresividad;
//                equipoActual.jugadores.push_back(jugadorActual);
//                jugadorActual = Jugador();
//            } 
//        }
//    }
//    if (!equipoActual.nombre.empty()) {
//        equipos.push_back(equipoActual);
//    }
//    return equipos;
//}
//vector<Partido> leerPartidos() {
//    vector<Partido> partidos;
//    ifstream archivo("Partidos.txt");
//    if (!archivo.is_open()) {
//        cerr << "Error al abrir el archivo 'Partidos.txt'" << endl;
//        exit(1);
//    }
//    string linea;
//    while (getline(archivo, linea)) {
//        if (linea.empty() || linea.size() < 4) {
//            cerr << "Formato de línea inválido: " << linea << endl;
//            continue;
//        }
//        if (linea[0] == '*') {
//
//        } else if (linea[0] == '-') {
//            istringstream iss(linea.substr(2));
//            Partido partido;
//            iss >> partido.fecha;
//        } else if (linea[0] == '+') {
//            istringstream iss(linea.substr(2));
//            Partido partido;
//            
//            iss >> partido.equipo1.nombre;
//            iss >> partido.equipo2.nombre;
//            partidos.push_back(partido);
//        }
//    }
//    archivo.close();
//    return partidos;
//}
//
//int generarResultado(int defensaEquipo1, int ataqueEquipo1, int defensaEquipo2, int ataqueEquipo2) {
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> dis(0, 10);
//
//    int golesEquipo1 = dis(gen) * (ataqueEquipo1 / (defensaEquipo2 + 1));
//    int golesEquipo2 = dis(gen) * (ataqueEquipo2 / (defensaEquipo1 + 1));
//
//    return golesEquipo1 - golesEquipo2;
//}
//void simularGrupo(vector<Equipo>& equipos, vector<Partido>& partidos) {
//    for (Partido& partido : partidos) {
//        int resultado = generarResultado(partido.equipo1.defensa, partido.equipo1.ataque, partido.equipo2.defensa, partido.equipo2.ataque);
//        partido.golesEquipo1 = resultado > 0 ? resultado : 0;
//        partido.golesEquipo2 = -resultado > 0 ? -resultado : 0;
//
//        if (partido.golesEquipo1 > partido.golesEquipo2) {
//            partido.equipo1.puntos += 3;
//        } else if (partido.golesEquipo1 < partido.golesEquipo2) {
//            partido.equipo2.puntos += 3;
//        } else {
//            partido.equipo1.puntos += 1;
//            partido.equipo2.puntos += 1;
//        }
//
//        if (partido.golesEquipo1 > partido.golesEquipo2) {
//            partido.equipo1.golesAFavor += abs(resultado);
//            partido.equipo1.diferenciaGoles += abs(resultado);
//            partido.equipo2.golesEnContra += abs(resultado);
//        } else if (partido.golesEquipo1 < partido.golesEquipo2) {
//            partido.equipo2.golesAFavor += abs(resultado);
//            partido.equipo2.diferenciaGoles += abs(resultado);
//            partido.equipo1.golesEnContra += abs(resultado);
//        } else {
//            partido.equipo1.golesAFavor += abs(resultado);
//            partido.equipo2.golesAFavor += abs(resultado);
//            partido.equipo1.golesEnContra += abs(resultado);
//            partido.equipo2.golesEnContra += abs(resultado);
//        }
//    }
//
//    sort(equipos.begin(), equipos.end(), [](const Equipo& e1, const Equipo& e2) {
//        return e1.puntos > e2.puntos;
//    });
//
//    for (size_t i = 0; i < equipos.size(); ++i) {
//        equipos[i].posicion = i + 1;
//    }
//}
//void simularPartidoPorPartido(vector<Equipo>& equipos) {
//    vector<Partido> partidos = leerPartidos();
//
//    while (true) {
//        cout << "Ingrese el grupo que desea simular: ";
//        string grupo;
//        cin >> grupo;
//
//        vector<Equipo>* equiposGrupo = nullptr;
//        for (Equipo& equipo : equipos) {
//            if (equipo.grupo == grupo) {
//                if (!equiposGrupo) {
//                    equiposGrupo = new vector<Equipo>();
//                }
//                equiposGrupo->push_back(equipo);
//            }
//        }
//
//        if (!equiposGrupo) {
//            cout << "Grupo no valido. Intente nuevamente." << endl;
//            continue;
//        }
//
//        cout << "Grupo " << grupo << ":" << endl;
//        for (Partido& partido : partidos) {
//            if (partido.equipo1.grupo == grupo || partido.equipo2.grupo == grupo) {
//                cout << "Simular partido (" << partido.equipo1.nombre << " vs " << partido.equipo2.nombre << "): ";
//                string linea;
//                getline(cin, linea);
//
//                int resultado = generarResultado(partido.equipo1.defensa, partido.equipo1.ataque, partido.equipo2.defensa, partido.equipo2.ataque);
//                partido.golesEquipo1 = resultado > 0 ? resultado : 0;
//                partido.golesEquipo2 = -resultado > 0 ? -resultado : 0;
//
//                if (partido.golesEquipo1 > partido.golesEquipo2) {
//                    partido.equipo1.puntos += 3;
//                } else if (partido.golesEquipo1 < partido.golesEquipo2) {
//                    partido.equipo2.puntos += 3;
//                } else {
//                    partido.equipo1.puntos += 1;
//                    partido.equipo2.puntos += 1;
//                }
//
//                if (partido.golesEquipo1 > partido.golesEquipo2) {
//                    partido.equipo1.golesAFavor += abs(resultado);
//                    partido.equipo1.diferenciaGoles += abs(resultado);
//                    partido.equipo2.golesEnContra += abs(resultado);
//                } else if (partido.golesEquipo1 < partido.golesEquipo2) {
//                    partido.equipo2.golesAFavor += abs(resultado);
//                    partido.equipo2.diferenciaGoles += abs(resultado);
//                    partido.equipo1.golesEnContra += abs(resultado);
//                } else {
//                    partido.equipo1.golesAFavor += abs(resultado);
//                    partido.equipo2.golesAFavor += abs(resultado);
//                    partido.equipo1.golesEnContra += abs(resultado);
//                    partido.equipo2.golesEnContra += abs(resultado);
//                }
//
//                sort(equiposGrupo->begin(), equiposGrupo->end(), [](const Equipo& e1, const Equipo& e2) {
//                    return e1.puntos > e2.puntos;
//                });
//
//                cout << "Tabla de posiciones:" << endl;
//                for (size_t i = 0; i < equiposGrupo->size(); ++i) {
//                    Equipo& equipo = (*equiposGrupo)[i];
//                    cout << (i + 1) << ". " << equipo.nombre << " - " << equipo.puntos << " puntos" << endl;
//                }
//            }
//        }
//    }
//}
//
//void simularTorneoPorFechas(vector<Equipo>& equipos) {
//    vector<Partido> partidos = leerPartidos();
//
//    for (size_t i = 0; i < equipos.size(); ++i) {
//        cout << "Fecha " << i + 1 << ":" << endl;
//        for (Partido& partido : partidos) {
//            if (partido.fecha == i + 1) {
//                cout << "Simular partido (" << partido.equipo1.nombre << " vs " << partido.equipo2.nombre << "): ";
//                string linea;
//                getline(cin, linea);
//
//                int resultado = generarResultado(partido.equipo1.defensa, partido.equipo1.ataque, partido.equipo2.defensa, partido.equipo2.ataque);
//                partido.golesEquipo1 = resultado > 0 ? resultado : 0;
//                partido.golesEquipo2 = -resultado > 0 ? -resultado : 0;
//
//                if (partido.golesEquipo1 > partido.golesEquipo2) {
//                    partido.equipo1.puntos += 3;
//                } else if (partido.golesEquipo1 < partido.golesEquipo2) {
//                    partido.equipo2.puntos += 3;
//                } else {
//                    partido.equipo1.puntos += 1;
//                    partido.equipo2.puntos += 1;
//                }
//
//                if (partido.golesEquipo1 > partido.golesEquipo2) {
//                    partido.equipo1.golesAFavor += abs(resultado);
//                    partido.equipo1.diferenciaGoles += abs(resultado);
//                    partido.equipo2.golesEnContra += abs(resultado);
//                } else if (partido.golesEquipo1 < partido.golesEquipo2) {
//                    partido.equipo2.golesAFavor += abs(resultado);
//                    partido.equipo2.diferenciaGoles += abs(resultado);
//                    partido.equipo1.golesEnContra += abs(resultado);
//                } else {
//                    partido.equipo1.golesAFavor += abs(resultado);
//                    partido.equipo2.golesAFavor += abs(resultado);
//                    partido.equipo1.golesEnContra += abs(resultado);
//                    partido.equipo2.golesEnContra += abs(resultado);
//                }
//            }
//        }
//
//        sort(equipos.begin(), equipos.end(), [](const Equipo& e1, const Equipo& e2) {
//            return e1.puntos > e2.puntos;
//        });
//
//        cout << "Tabla de posiciones:" << endl;
//        for (size_t j = 0; j < equipos.size(); ++j) {
//            Equipo& equipo = equipos[j];
//            cout << j + 1 << ". " << equipo.nombre << " - Puntos: " << equipo.puntos << ", Diferencia de goles: " << equipo.diferenciaGoles << endl;
//        }
//
//        cout << "Presione Enter para continuar..." << endl;
//        string linea;
//        getline(cin, linea);
//    }
//}
//
//void simularTorneoPorEtapas (){
//
//}
//
//void simularGrupos(){}
//void simularCuartosDeFinal(){}
//void simularSemifinales(){}
//void simularTercerPuesto(){}
//void simularFinal(){}
//void simularCopaAmerica() {
//    cout << "--- Fase de grupos ---" << endl;
//    simularGrupos();
//    cout << "--- Cuartos de final ---" << endl;
//    simularCuartosDeFinal();
//    cout << "--- Semifinales ---" << endl;
//    simularSemifinales();
//    cout << "--- Tercer puesto ---" << endl;
//    simularTercerPuesto();
//    cout << "--- Final ---" << endl;
//    simularFinal();
//}
void simular() {
    int opcionsimular;
    //vector<Equipo> equipos = leerEquipos(); // Leer los equipos desde un archivo o base de datos
    while (true) {
        cout << "--- SIMULACION ---" << endl;
        cout << "1. Simular partido por partido" << endl;
        cout << "2. Simular torneo por etapas" << endl;
        cout << "3. Simular copa america" << endl;
        cout << "4. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: " << endl;
        cin >> opcionsimular;
        cout<<endl;
        if (opcionsimular == 1) {
            partidoXpartido();
        }
        if (opcionsimular == 2) {
            PorFases();
        }
        if (opcionsimular == 3) {
            Copa();
        }
        if (opcionsimular == 4){
            cout << "Volviendo al menu principal..." <<  endl;
            return;
        }
        if (opcionsimular >=5) {
            cout << "Opcion no valida volviendo al menu principal..." << endl;
            return;
        }
    }
    system ("cls");
}
int main() {
    system("cls");
    while (true) {
        cout << "---- COPA AMERICA 2024 ----" << endl;
        cout << "---- (ESTADOS UNIDOS) ---- \n" << endl;
        cout << "1. Equipos" << endl;
        cout << "2. Grupos" << endl;
        cout << "3. Estadios" << endl;
        cout << "4. Simular" << endl;
        cout << "5. Salir" << endl;
        cout<<"\nSeleccione una opcion: "<<endl;
        int opcionmenu1;
        cin >> opcionmenu1;
        cout<<endl;
        switch (opcionmenu1) {
            case 1:
                equiposs();
                system ("cls");
                break;
            case 2:
                grupos();
                system ("cls");
                break;
            case 3:
                system ("cls");
                Estadios();
                system ("cls");
                break;
            case 4:
                simular();
                system ("cls");
                break;
            case 5:
            cout<<"Saliendo del programa..."<<endl;
            cout<<"Nos vemos pronto :)"<<endl;
                return 0; // Salir del programa
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
    
    return 0;
}
#endif