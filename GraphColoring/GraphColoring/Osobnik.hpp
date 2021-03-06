//
//  Osobnik.hpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 09/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once

#include <iostream>
#include <set>
#include <vector>
#include <map>
//#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include "Graph.hpp"
#include "Zachlanny.hpp"


class Osobnik {
private:
    int wierzcholki;
    int kolory;
    std::vector<int> tab_kolorow;
    int numerKolejny;
    int fitness;
    Graph* graf;
public:
    Osobnik(Graph*,int);
    Osobnik(Graph*);
    Osobnik(int,int);
    Osobnik(std::vector<int>,Graph*);
    Osobnik(Graph*,bool);
    
    void normalizujKolory();
    void napraw();
    void policz_kolory();
    std::vector<int> getTab(){return tab_kolorow;}
    int getKolory(){return kolory;}
    int getWierzcholki(){return wierzcholki;}
    void setWierzcholki(int w) {wierzcholki = w;}
    void mutacja();
    void mutacja1();
    void mutacja2();
    int bledneKrawedzie();
    int getNumerKolejny(){return numerKolejny;}
    void updateFitness();
    int getFitness() {return fitness;}
    void randomowaMutacja();
    void randomowaMutacja2();
    void randomowaMutacja3();
    void randomowaMutacja4();
    void randomowaMutacja5();
};
