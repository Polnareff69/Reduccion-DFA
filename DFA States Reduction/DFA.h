#pragma once
#ifndef DFA_H
#define DFA_H
using namespace std;
#include <set>
#include <map>
#include <string>

class DFA
{
public:
    DFA(set<int> estados,
        set<char> alfabeto,
        int estadoInicial,
        map<pair<int, char>, int> transiciones,
        set<int> estadosAceptacion);

    bool procesar(const string& cadena);
    map<string, bool> generarParejasEstados();

    const set<int>& getEstados() const;
    const set<char>& getAlfabeto() const;
    int getEstadoInicial() const;
    const map<pair<int, char>, int>& getTransiciones() const;
    const set<int>& getEstadosAceptacion() const;

private:
    set<int> estados;
    set<char> alfabeto;
    int estadoInicial;
    map<pair<int, char>, int> transiciones;
    set<int> estadosAceptacion;

};



#endif