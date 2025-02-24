#pragma once
#ifndef REDUCCION_H
#define REDUCCION_H

#include "DFA.h"
#include <map>
#include <string>

using namespace std;

class Reduccion {
public:
    static map<string, bool> MarcarPares(map<string, bool>& parejas, const DFA& dfa);
    static map<string, bool> MarcarParesNoMarcados(map<string, bool>& parejas, const DFA& dfa);
};

#endif 
