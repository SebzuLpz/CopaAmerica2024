#ifndef SimulacionCopa_HPP
#define SimulacionCopa_HPP



#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <random>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

class Jugador3 {
public:
    int id;
    string nombre;
    int agresividad;

    Jugador3(int id, string nombre, int agresividad)
        : id(id), nombre(nombre), agresividad(agresividad) {}
};

struct Equipo3 {
    string separdor;
    int id;
    string nombre;
    double defensa;
    double ataque;
    int grupo;
    string grupoNombre;
    vector<Jugador3> jugadores;
    unsigned int partidosJugados;
    int puntos;
    int golesMarcados;
    int golesRecibidos;

    Equipo3(int id, string nombre, double defensa, double ataque, int grupo, string grupoNombre)
        :id(id), nombre(nombre), defensa(defensa), ataque(ataque), grupo(grupo), grupoNombre(grupoNombre), 
        partidosJugados(0), puntos(0), golesMarcados(0), golesRecibidos(0) {}
};


struct Nodo3 {
    Equipo3 equipo;
    Nodo3* izquierda;
    Nodo3* derecha;
};

vector<Equipo3> equipos3;

void cargarEquipos3() {
    ifstream archivo("InfoEquiJug.txt");
    if (!archivo) {
        cerr << "No se ha podido abrir el archivo..." << endl;
        exit(1);
    }

    string linea;
    while (getline(archivo, linea, ' ') && linea!= "+" ) {

        int id;
        string nombre;
        double defensa;
        double ataque;
        int grupo;
        string grupoNombre;


        istringstream iss(linea);
        iss >> id >> nombre >> defensa >> ataque >> grupo >> grupoNombre  ;

        Equipo3 equipo(id, nombre, defensa, ataque, grupo, grupoNombre);

        while (getline(archivo, linea) && linea!= "-") {
            int idJugador;
            string nombreJugador;
            int agresividad;
            string separador;

            istringstream issJugador(linea);
            issJugador >> idJugador >> nombreJugador >> agresividad;

            Jugador3 jugador(idJugador, nombreJugador, agresividad);
            equipo.jugadores.push_back(jugador);
        }

        equipos3.push_back(equipo);
    }
}

class Estadio3 {
    public:
    int idEstadio;
    string nombreEstadio;
    string nombreCiudad;
    string estadios;

    int getId() const { return id_; } // Agregar este método
private:
    int id_; // Asumo que tienes un miembro de datos llamado id_
    

};


list<Estadio3> cargarEstadios3() {
    list<Estadio3> estadios3;
    ifstream archivo("Estadios.txt");

    if (!archivo) {
        cerr << "Error al abrir el archivo Estadios.txt" << std::endl;
        return estadios3; // Devuelve una lista vacía si no se puede abrir el archivo
    }

    Estadio3 estadio;
string linea;

    while (std::getline(archivo, linea)) {
        if (linea == "+") {
            // Ignora la línea de separador
            continue;
        }

        if (estadio.idEstadio == 0) {
            // Lee el id del estadio
            estadio.idEstadio = std::stoi(linea);
        } else {
            // Lee el nombre y ciudad del estadio
            size_t comaPos = linea.find(',');
            estadio.nombreEstadio = linea.substr(0, comaPos);
            estadio.nombreCiudad = linea.substr(comaPos + 1);

            // Agrega el estadio a la lista
            estadios3.push_back(estadio);
            estadio.idEstadio = 0; // Reinicia el id para el próximo estadio
        }
    }

    archivo.close();
    return estadios3;
}


random_device rd3;
mt19937 gen3(rd3());

int generarNumero3(int min, int max) {
    uniform_int_distribution<int> dis(min, max);
    return dis(gen3);
}

bool partidoJugado3(int equipo1, int equipo2) {
    if (equipo1 < equipo2) {
        for (auto it = equipos3.begin(); it!= equipos3.end(); ++it) {
            if (it->id == equipo1 && it->partidosJugados & (1 << equipo2)) {
                return true;
            }
        }
    } else {
        for (auto it = equipos3.begin(); it!= equipos3.end(); ++it) {
            if (it->id == equipo2 && it->partidosJugados & (1 << equipo1)) {
                return true;
            }
        }
    }
    return false;
}



Equipo3 simularPenales3(Equipo3& equipo1, Equipo3& equipo2) {
    int golesEquipo1 = 0;
    int golesEquipo2 = 0;
    int agresividadTotalEquipo1 = 0;
    int agresividadTotalEquipo2 = 0;

    // Calcular la agresividad total de cada equipo
    for (auto& jugador : equipo1.jugadores) {
        agresividadTotalEquipo1 += equipo1.ataque;
    }
    for (auto& jugador : equipo2.jugadores) {
        agresividadTotalEquipo2 += equipo2.ataque;
    }

    // Simulación de penales
    while (golesEquipo1 == golesEquipo2) {
        int agresividadEquipo1 = generarNumero3(1, agresividadTotalEquipo1);
        int agresividadEquipo2 = generarNumero3(1, agresividadTotalEquipo2);

        if (agresividadEquipo1 > agresividadEquipo2) {
            golesEquipo1++;
        } else if (agresividadEquipo1 < agresividadEquipo2) {
            golesEquipo2++;
        }
    }

    // Actualizar el número de partidos jugados
    equipo1.partidosJugados++;
    equipo2.partidosJugados++;

    // Actualizar los goles marcados y recibidos
    equipo1.golesMarcados += golesEquipo1;
    equipo1.golesRecibidos += golesEquipo2;
    equipo2.golesMarcados += golesEquipo2;
    equipo2.golesRecibidos += golesEquipo1;
    if (golesEquipo1==golesEquipo2){
        equipo1.puntos += 1;
        equipo2.puntos += 1;
    }
    // Devolver el ganador del partido
    if (golesEquipo1 > golesEquipo2) {
        
        //cout << "Ganador del empate anterior en penaltis: \n" << equipo1.nombre << endl;
        //cout << "Pasa a la siguiente ronda." << endl;
        return equipo1;
    } else if (golesEquipo2> golesEquipo1){
        
        //cout << "Ganador del empate anterior en penaltis: \n" << equipo2.nombre << endl;
        //cout << "Pasa a la siguiente ronda. \n" << endl;
        return equipo2;
    }

}

void imprimirEstadio3(const list<Estadio3>& estadios, int idest) {
    for (const auto& estadio : estadios) {
        if (estadio.idEstadio == idest) {
            //cout << "Estadio: " << estadio.nombreEstadio << "   |    Ciudad: " << estadio.nombreCiudad << endl;
            //cout << "-------------------------------------------------------------------" << endl;
            return;
        }
    }
    //cout << "Estadio: Desconocido, Ciudad: Desconocida" << endl;
}




string getJugadorNombre3(const Equipo3& equipo1, const Equipo3& equipo2, int id) {
    for (const auto& jugador : equipo1.jugadores) {
        if (jugador.id == id) {
            return jugador.nombre;
        }
    }
    for (const auto& jugador : equipo2.jugadores) {
        if (jugador.id == id) {
            return jugador.nombre;
        }
    }
    return ""; 
    }
    // or throw an exception if not found
    string getEquipoNombre3(const Equipo3& equipo1, const Equipo3& equipo2, int id) {
    for (const auto& jugador : equipo1.jugadores) {
        if (jugador.id == id) {
            return equipo1.nombre;
        }
    }
    for (const auto& jugador : equipo2.jugadores) {
        if (jugador.id == id) {
            return equipo2.nombre;
        }
    }
    return ""; // or throw an exception if not found
}



Equipo3 simularPartido3(Equipo3& equipo1, Equipo3& equipo2, const list<Estadio3>& estadios2, int idEstadio) {
    int golesEquipo1 = 0;
    int golesEquipo2 = 0;
    //Simulacion de goles
    int ultimoGol = -1;
    for (int i = 0; i < 9; i++) { 
        // Aumentar el número de iteraciones a 16
        int probabilidadGol= generarNumero3(1, 10);
        if (probabilidadGol <= equipo1.ataque && probabilidadGol > equipo2.defensa) {golesEquipo1++;
            ultimoGol = 1;
        }
        if (probabilidadGol <= equipo2.ataque && probabilidadGol > equipo1.defensa) {
            golesEquipo2++;
            ultimoGol = 2;
        }
    }
    // Simulación de tarjetas
    map<int, string> tarjetas;
    for (const auto& jugador : equipo1.jugadores) {
        int probabilidadTarjeta = generarNumero3(1, 7);
        if (probabilidadTarjeta >= jugador.agresividad) {
            if (probabilidadTarjeta >= 7) {
                tarjetas[jugador.id] = "roja";
            } else {
                tarjetas[jugador.id] = "amarilla";
            }
        }
    }
    for (const auto& jugador : equipo2.jugadores) {
        int probabilidadTarjeta = generarNumero3(1, 7);
        if (probabilidadTarjeta >= jugador.agresividad) {
            if (probabilidadTarjeta >= 7) {
                tarjetas[jugador.id] = "roja";
            } else {
                tarjetas[jugador.id] = "amarilla";
            }
        }
    }
    
    //Imprimir resultado
    //cout << "-------------------------------------------------------------------" << endl;
    //cout << equipo1.grupoNombre << endl;
    //cout << "-------------------------------------------------------------------" << endl;
    //cout << equipo1.nombre << " [" << golesEquipo1 << "]-[" << golesEquipo2 << "] " << equipo2.nombre << endl;
    //cout << "-------------------------------------------------------------------" << endl;
    //cout << "Tarjetas en el partido:" << endl;
    //cout << "--------------------------" << endl;
    //cout << "Tarjetas amarillas:" << endl;
    //for (const auto& tarjeta : tarjetas) {
    //    if (tarjeta.second == "amarilla") {
    //        cout << "          " << getJugadorNombre3(equipo1, equipo2, tarjeta.first) << " (" << getEquipoNombre3(equipo1, equipo2, tarjeta.first) << ")" << endl;
    //    }
    //}
    //cout << "------------------------------------------------------------------" << endl;
    //cout << "Tarjetas rojas:" << endl;
    //for (const auto& tarjeta : tarjetas) {
    //    if (tarjeta.second == "roja") {
    //        cout << "          " << getJugadorNombre3(equipo1, equipo2, tarjeta.first) << " (" << getEquipoNombre3(equipo1, equipo2, tarjeta.first) << ")" << endl;
    //    }
    //}
    //cout << "------------------------------------------------------------------" << endl;
    imprimirEstadio3(estadios2, idEstadio);

    // Actualizar el número de partidos jugados
    equipo1.partidosJugados++;
    equipo2.partidosJugados++;

    // Actualizar los goles marcados y recibidos
    equipo1.golesMarcados += golesEquipo1;
    equipo1.golesRecibidos += golesEquipo2;
    equipo2.golesMarcados += golesEquipo2;
    equipo2.golesRecibidos += golesEquipo1;

    // Devolver el ganador del partido
    if (golesEquipo1 > golesEquipo2) {
        equipo1.puntos += 3;
        return equipo1;
    } else if (golesEquipo1 < golesEquipo2) {
        equipo2.puntos += 3;
        return equipo2;

    } 
    //if (golesEquipo1==golesEquipo2){
    //    equipo1.puntos += 1;
    //    equipo2.puntos += 1;
    //} 
    else { // Empate, simular penales
        equipo1.puntos += 1;
        equipo2.puntos += 1;
        return simularPenales3(equipo1, equipo2);


    }
    
}




void mostrarTablaPosiciones3(vector<Equipo3>& equipos,  const string& grupoNombre) {
    system ("cls");
    sort(equipos.begin(), equipos.end(), [](const Equipo3& e1, const Equipo3& e2 ) {
        return e1.puntos > e2.puntos;
    });
    //cout << "+--------------------------------------+" << endl;
    //cout << "|               " << setw(20) << left << grupoNombre << "   |" << endl;
    //cout << "|                 GRUPO                |" << endl;
    //cout << "+--------------------------------------+" << endl;
    //cout << "|      EQUIPOS       |       PUNTOS    |" << endl;
    //cout << "+--------------------------------------+" << endl;

    int grupo = equipos[0].grupo;
    int contador = 1;

    for (auto& equipo : equipos) {
        if (equipo.grupo != grupo) {
            grupo = equipo.grupo;
            contador = 1;
        }

        //cout << "|  " << setw(15) << left << equipo.nombre << "   |    " << setw(6) << right << equipo.puntos << "       |" << endl;
        contador++;
    }

    //cout << "+--------------------------------------+" << endl;

}


void simularFaseGrupos3() {
    list<Estadio3> estadios = cargarEstadios3();
    int idEstadio = 1; // Variable para llevar la cuenta del estadio
    
    for (int grupo = 1; grupo <= 4; grupo++) { 
        // Asumo que hay 4 grupos
        list<Equipo3*> equiposGrupo;
        for (auto& equipo : equipos3) {
            if (equipo.grupo == grupo) {
                equiposGrupo.push_back(&equipo);
            }
        }

        // Generar combinaciones de partidos
        list<pair<int, int>> partidos;
        for (auto it1 = equiposGrupo.begin(); it1!= equiposGrupo.end(); ++it1) {
            for (auto it2 = std::next(it1); it2!= equiposGrupo.end(); ++it2) {
                partidos.push_back({(*it1)->id, (*it2)->id});
            }
        }

        // Simular partidos
        for (auto& partido : partidos) {
            int idEquipo1 = partido.first;
            int idEquipo2 = partido.second;
            Equipo3* equipo1 = nullptr;
            Equipo3* equipo2 = nullptr;
            for (auto& equipo : equipos3) {
                if (equipo.id == idEquipo1) {
                    equipo1 = &equipo;
                } else if (equipo.id == idEquipo2) {
                    equipo2 = &equipo;
                }
                if (equipo1 && equipo2) {
                    break;
                }
            }
            

        string grupoNombre = to_string(grupo);
        if (grupoNombre=="1"){
            grupoNombre="GRUPO A";
        }
        if (grupoNombre=="2"){
            grupoNombre="GRUPO B";
        }
        if (grupoNombre=="3"){
            grupoNombre="GRUPO C";
        }
        if (grupoNombre=="4"){
            grupoNombre="GRUPO D";
        }
            
            //cout << "------------------------------------------------------------------" << endl;
            //cout << "Fase de grupos: "<<grupoNombre<<endl;
            simularPartido3(*equipo1, *equipo2, estadios, idEstadio);
            idEstadio++; // Aumentar el id del estadio en 1

            // Actualizar el número de partidos jugados
            equipo1->partidosJugados++;
            equipo2->partidosJugados++;
        }
    }

    // Mostrar tabla de posiciones de cada grupo
for (int grupo = 1; grupo <= 4; grupo++) {
        vector<Equipo3> equiposGrupo;
        for (auto& equipo : equipos3) {
            if (equipo.grupo == grupo) {
                equiposGrupo.push_back(equipo);
            }
        }
        string grupoNombre = to_string(grupo);
        if (grupoNombre=="1"){
            grupoNombre="GRUPO A";
        }
        if (grupoNombre=="2"){
            grupoNombre="GRUPO B";
        }
        if (grupoNombre=="3"){
            grupoNombre="GRUPO C";
        }
        if (grupoNombre=="4"){
            grupoNombre="GRUPO D";
        }


        mostrarTablaPosiciones3(equiposGrupo, grupoNombre);
    }
}

Equipo3 simularFaseEliminacionDirecta3(vector<Equipo3> equipos) {
    list<Estadio3> estadios = cargarEstadios3(); // Declarar y inicializar estadios
    int idEstadio = 1; // Declarar y inicializar idEstadio
    // Identificar los 2 primeros equipos de cada grupo
    vector<Equipo3> equiposClasificados;
    for (int grupo = 1; grupo <= 4; grupo++) {
        vector<Equipo3> equiposGrupo;
        for (const auto& equipo : equipos) {
            if (equipo.grupo == grupo) {
                equiposGrupo.push_back(equipo);
            }
        }
        // Ordenar los equipos del grupo por puntos
        sort(equiposGrupo.begin(), equiposGrupo.end(), [](const Equipo3& e1, const Equipo3& e2) {
            return e1.puntos > e2.puntos;
        });
        // Agregar los 2 primeros equipos del grupo a la lista de equipos clasificados
        equiposClasificados.push_back(equiposGrupo[0]);
        equiposClasificados.push_back(equiposGrupo[1]);
    }

    // Crear árbol de eliminación directa
    Nodo3* raiz3 = new Nodo3{equiposClasificados[0], nullptr, nullptr};
    raiz3->izquierda = new Nodo3{equiposClasificados[7], nullptr, nullptr};
    raiz3->derecha = new Nodo3{equiposClasificados[1], nullptr, nullptr};
    raiz3->izquierda->izquierda = new Nodo3{equiposClasificados[4], nullptr, nullptr};
    raiz3->izquierda->derecha = new Nodo3{equiposClasificados[5], nullptr, nullptr};
    raiz3->derecha->izquierda = new Nodo3{equiposClasificados[6], nullptr, nullptr};
    raiz3->derecha->derecha = new Nodo3{equiposClasificados[2], nullptr, nullptr};
    raiz3->derecha->derecha->izquierda = new Nodo3 {equiposClasificados [3], nullptr, nullptr};


    idEstadio=25;

    // Simular partidos y avanzar a la siguiente ronda
    //cout << "------------------------------------------------------------------" << endl;
    //cout<<"Cuartos de final: "<<endl;
    Equipo3 equipoCuartos1 = simularPartido3(raiz3->equipo, raiz3->derecha->derecha->equipo, estadios, idEstadio);

    idEstadio++; // Aumentar el id del estadio en 1



    Nodo3* cuartos1 = new Nodo3{equipoCuartos1, nullptr, nullptr};
    //cout << "------------------------------------------------------------------" << endl;
    //cout<<"Cuartos de final: "<<endl;
    Equipo3 equipoCuartos2 = simularPartido3(raiz3->izquierda->izquierda->equipo, raiz3->izquierda->equipo, estadios, idEstadio);       
    idEstadio++; // Aumentar el id del estadio en 1



    Nodo3* cuartos2 = new Nodo3{equipoCuartos2, nullptr, nullptr};
    //cout << "------------------------------------------------------------------" << endl;
    //cout<<"Cuartos de final: "<<endl;
    Equipo3 equipoCuartos3 = simularPartido3(raiz3->izquierda->derecha->equipo, raiz3->derecha->izquierda->equipo, estadios, idEstadio);
    
    idEstadio++; // Aumentar el id del estadio en 1



    Nodo3* cuartos3 = new Nodo3{equipoCuartos3, nullptr, nullptr};
    //cout << "------------------------------------------------------------------" << endl;
    //cout<<"Cuartos de final: "<<endl;
    Equipo3 equipoCuartos4 = simularPartido3(raiz3->derecha->equipo, raiz3->derecha->derecha->izquierda->equipo, estadios, idEstadio);

    idEstadio++; // Aumentar el id del estadio en 1


    Nodo3* cuartos4 = new Nodo3{equipoCuartos4, nullptr, nullptr};

    // Simular semifinales

    //cout << "------------------------------------------------------------------" << endl;
    //cout<<"Semifinales: "<<endl;
    Equipo3 equipoSemifinal1 = simularPartido3(equipoCuartos1, equipoCuartos2, estadios, idEstadio);

    idEstadio++; // Aumentar el id del estadio en 1
    //Equipo perdedorSemifinal1 = equipoCuartos2; // Almacenar el perdedor de la semifinal 1

    //cout << "------------------------------------------------------------------" << endl;
    //cout<<"Semifinales: "<<endl;
    Equipo3 equipoSemifinal2 = simularPartido3(equipoCuartos3, equipoCuartos4, estadios, idEstadio);

    idEstadio++; // Aumentar el id del estadio en 1
    //Equipo perdedorSemifinal2 = equipoCuartos4; // Almacenar el perdedor de la semifinal 2

    // Simular tercer puesto
    //cout<<"Tercer puesto: "<<endl;
    //Equipo equipoTercerPuesto = simularPartido(perdedorSemifinal1, perdedorSemifinal2, estadios, idEstadio);
    idEstadio++; // Aumentar el id del estadio en 1

    // Simular final
    //cout << "------------------------------------------------------------------" << endl;
    //cout<<"Final: "<<endl;
    Equipo3 equipoFinal = simularPartido3(equipoSemifinal1, equipoSemifinal2, estadios, idEstadio);

    idEstadio++; // Aumentar el id del estadio en 1


    cout << "\n";
    cout << "El campeon es: " << equipoFinal.nombre << endl;
    cout << "\n";
    cout << equipoFinal.nombre << " es campeon de la Copa America 2024!" <<endl;
    cout << "\n";
    cout << "\n";
    ofstream archivout("ResultadoSimulacion.txt");
    archivout << "Simulación de la Copa América 2024" << endl << endl;
    archivout << "Ganador de cuartos 1: " << equipoCuartos1.nombre << endl;
    archivout << endl;
    archivout << "Ganador de cuartos 2: " << equipoCuartos2.nombre << endl;
    archivout << endl;
    archivout << "Ganador de cuartos 3: " << equipoCuartos3.nombre << endl;
    archivout << endl;
    archivout << "Ganador de cuartos 4: " << equipoCuartos4.nombre << endl;
    archivout << endl;
    archivout << "Ganador de semifinales 1: " << equipoSemifinal1.nombre << endl;
    archivout << endl;
    archivout << "Ganador de semifinales 2: " << equipoSemifinal2.nombre << endl;
    archivout << endl;
    archivout << "Campeón de la Copa América 2024: " << equipoFinal.nombre << endl;
    archivout << endl;
    archivout << equipoFinal.nombre << " es campeón de la Copa América 2024!" << endl;
    return equipoFinal;
}



int Copa() {
    cargarEquipos3();
    

    simularFaseGrupos3();  
    //cout << "Simulando Fase de eliminacion directa... \n" << endl;
    cout << "Simulando Copa America 2024... \n" << endl;
    Equipo3 equipoFinal = simularFaseEliminacionDirecta3(equipos3);

    ofstream archivo4 ("ResultadoSimulacion.txt");
    archivo4 << "";
    return 0;
}

namespace MyNamespace { 
    void Copa(); 
}
#endif
