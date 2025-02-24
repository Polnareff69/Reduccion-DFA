#include "DFA.h"
#include "DFA.h"
#include <iostream>


//Contructor
DFA::DFA(set<int> estados,
    set<char> alfabeto,
    int estadoInicial,
    map<pair<int, char>, int> transiciones,
    set<int> estadosAceptacion)
    : estados(estados), alfabeto(alfabeto), estadoInicial(estadoInicial),
    transiciones(transiciones), estadosAceptacion(estadosAceptacion) {}

const set<int>& DFA::getEstados() const { return estados; }
const set<char>& DFA::getAlfabeto() const { return alfabeto; }
int DFA::getEstadoInicial() const { return estadoInicial; }
const map<pair<int, char>, int>& DFA::getTransiciones() const { return transiciones; }
const set<int>& DFA::getEstadosAceptacion() const { return estadosAceptacion; }

//Procesamiento
bool DFA::procesar(const string& cadena) {
    int estadoActual = estadoInicial;
    for (char simbolo : cadena) {
        if (alfabeto.find(simbolo) == alfabeto.end()) {
            std::cerr << "Símbolo no válido: " << simbolo << std::endl;
            return false;
        }
        auto clave = std::make_pair(estadoActual, simbolo);
        if (transiciones.find(clave) == transiciones.end()) {
            std::cerr << "No hay transición definida para el par ("
                << estadoActual << ", " << simbolo << ")" << std::endl;
            return false;
        }
        estadoActual = transiciones[clave];
    }
    return true;
}

//Generar parejas 
map<string, bool> DFA::generarParejasEstados() {
    map<string, bool> parejas;
    for (auto it1 = estados.begin(); it1 != estados.end(); ++it1) {
        for (auto it2 = next(it1); it2 != estados.end(); ++it2) {
            string clave = to_string(*it1) + "," + to_string(*it2);
            parejas[clave] = false; // Se inicializa en false
        }
    }
    return parejas;
}