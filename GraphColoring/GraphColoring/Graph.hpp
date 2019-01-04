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
#include <vector>

class Graph{
private:
    int rozmiar;
    int** macierz;
    int* kolory;
    int maxWierzcholek;
public:
    void setRozmiar();
    void setMacierz();
    void setKolory();
    int getRozmiar(){return rozmiar;}
    int** getMacierz(){return macierz;}
    int* getKolory(){return kolory;}
    int getMaxWierzcholek() {return maxWierzcholek;}
    
    void printMacierz();
    void printKolory();
    void printIleKolorow();
    Graph(int,int,int*,int*);   // ilość wierzchołków, ilość połączeń, tablica 1, tablica 2
    Graph(int,std::vector<int>,std::vector<int>);   // ilość wierzchołków, vector 1, vector 2
    ~Graph();
};
