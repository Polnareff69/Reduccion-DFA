#pragma once
#ifndef AFD_H
#define AFD_H
using namespace std;
#include <set>
#include <map>
#include <string>

class AFD
{
public:
    AFD(set<string> estados,
        set<char> alfabeto,
        string estadoInicial,
        map<pair<string, char>, string> transiciones,
        set<string> estadosAceptacion);

    bool procesar(const string& cadena);

private:
    set<string> estados;
    set<char> alfabeto;
    string estadoInicial;
    map<pair<string, char>, string> transiciones;
    set<string> estadosAceptacion;

};

#endif

class AFD
{
};
