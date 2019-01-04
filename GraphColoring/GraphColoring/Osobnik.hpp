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
//#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include "Graph.hpp"


class Osobnik {
private:
    int wierzcholki;
    int kolory;
    std::vector<int> tab_kolorow;
    int numerKolejny;
public:
    Osobnik(int,int);
    Osobnik(std::vector<int>,int);
    void napraw(Graph*);
    void policz_kolory();
    std::vector<int> getTab(){return tab_kolorow;}
    int getKolory(){return kolory;}
    int getWierzcholki(){return wierzcholki;}
    void setWierzcholki(int w) {wierzcholki = w;}
    void mutacja();
    void mutacja1(Graph*);
    void mutacja2(Graph*);
    void bledneKrawedzie(Graph*);
    int getNumerKolejny(){return numerKolejny;}
};
