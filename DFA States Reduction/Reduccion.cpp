#include "Reduccion.h"
#include <iostream>

map<string, bool> Reduccion::MarcarPares(map<string, bool>& parejas, const DFA& dfa) {
    for (auto& par : parejas) {
        //char p = par.first.substr(0, 1)[0];
        //char q = par.first.substr(1, 0)[0];
        set<int> F = dfa.getEstadosAceptacion();
        int p = stoi(par.first.substr(0, 1));
        int q = stoi(par.first.substr(2, 3));
        if (F.count(p) and not F.count(q)) {
            par.second = true;
        }
        else if (not F.count(p) and F.count(q)) {
            par.second = true;
        }
    }
    return parejas; 
}


map<string, bool> Reduccion::MarcarParesNoMarcados(map<string, bool>& parejas, const DFA& dfa) {
        const set<char>& alfabeto = dfa.getAlfabeto();
        const map<pair<int, char>, int> transiciones = dfa.getTransiciones();
        char a = *alfabeto.begin();
        int count = 0;
        

        for (auto& par :parejas){
            if(par.second = false){ 

            int p = stoi(par.first.substr(0, 1));
            int q = stoi(par.first.substr(2, 3));

            auto pair1 = make_pair(p, a);
            auto it1 = transiciones.find(pair1);
            auto pair2 = make_pair(q, a);
            auto it2 = transiciones.find(pair2);
            

            if (it1 != transiciones.end() and it2 != transiciones.end()) {
                int estadoDestino = it1->second;
                int estadoDestino2 = it2->second;
                string clave = to_string(estadoDestino) + "," + to_string(estadoDestino2);
                auto pareja = parejas.find(clave);
                if (pareja != parejas.end()) {
                    if (pareja->second = true) {
                        par.second = true;
                        count++;
                        }
                    }
                }
            }


            
        }
        
    return parejas;
}


