//
//  Populacja.hpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 09/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once

#include <iostream>
#include <vector>
//#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <algorithm>
#include "Osobnik.hpp"
#include "Graph.hpp"

class Populacja {
private:
    Graph* graf;
    Osobnik* rodz1;
    Osobnik* rodz2;
//    Osobnik dziecko;
    int wielkoscPopulacji;
    std::vector<Osobnik> osobnikiPopulacji;
    
public:
    Populacja(int,Graph*);
    void rodzice1();
    void rodzice2();
    void laczenie();
    void sortuj();
    void selekcja();
    void mutacja();
    void printPopulacje();
};
