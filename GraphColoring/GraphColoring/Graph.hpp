//
//  Graph.hpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 19/10/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>

class Graph{
private:
    int rozmiar;
    int** macierz;
    int* kolory;
public:
    void zachlanny();
    void printMacierz();
    void printKolory();
    Graph(int,int,int*,int*);   // ilość wierzchołków, ilość połączeń, tablica 1, tablica 2
    ~Graph();
};
