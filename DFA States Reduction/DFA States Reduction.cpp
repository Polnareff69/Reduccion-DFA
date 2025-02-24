#include "DFA.h"
#include <iostream>
#include <sstream>
#include "Reduccion.h"

using namespace std;

int main() {
    cout << "Ingrese el numero de casos: ";
    int test_cases;
    set<int> estadosDFA;
    int estados;
    set<char> alfabeto;
    string linea;
    set<int> estadosFinalesDFA;
    int estadosFinales;
    map<pair<int, char>, int> transiciones;

    cin >> test_cases;
   
    while (test_cases--) {

        cout << "Ingrese el numero de estados: ";
        cin >> estados;
        for (int i = 0; i <= estados; i++) {
            estadosDFA.insert(i);
        }

        cout << "Ingrese el alfabeto del DFA: ";
        cin.ignore();
        getline(cin, linea);
        stringstream ss(linea);
        char caracter;

        while (ss >> caracter) {
            alfabeto.insert(caracter);
        }

        /* 
        cout << "Alfabeto: ";
        for (char c : alfabeto) { 
            cout << c << " ";
        }
        cout << endl;
        */

        cout << "Ingrese los estados finales : "; 
        getline(cin, linea); 
        stringstream cc(linea);
        int estado;
        while (cc >> estado) {  
            estadosFinalesDFA.insert(estado);
        }

        /* 
        cout << "Estados de aceptación: ";
        for (int estado : estadosFinalesDFA) {  // Recorre todos los elementos del set
            cout << estado << " ";
        }
        */

        cout << "Ingrese la tabla de transiciones (una línea por estado, con " << alfabeto.size() << " valores por línea):\n";
        
        for (int i = 0; i <= estados; i++) {
            getline(cin, linea);
            stringstream ss(linea);

            int estado_destino;
            auto it = alfabeto.begin(); 

            while (ss >> estado_destino) {
                if (it == alfabeto.end()) break; 
                transiciones[{i, * it}] = estado_destino;
                ++it;
            }
           
        }

    }
    DFA M(estadosDFA, alfabeto, 0, transiciones, estadosFinalesDFA);

    map<string, bool> parejas = M.generarParejasEstados();

    cout << "Antes del cambio:\n";
    for (const auto& par : parejas) {
        cout << par.first << " -> " << (par.second ? "true" : "false") << endl;
    }

    map<string, bool> parejasMarcadas = Reduccion::MarcarPares(parejas, M);


    cout << "\nDespués del cambio:\n";
    for (const auto& par : parejasMarcadas) {
        cout << par.first << " -> " << (par.second ? "true" : "false") << endl;
    }

    Reduccion::MarcarParesNoMarcados(parejas, M);



    return 0;
}