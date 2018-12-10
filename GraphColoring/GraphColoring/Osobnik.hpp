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
#include <ctime>
#include <algorithm>
#include "Graph.hpp"

class Osobnik {
private:
    int wierzcholki;
    int kolory;
    std::vector<int> tab_kolorow;
public:
    Osobnik(int);
    Osobnik(std::vector<int>,int);
    void napraw(Graph*);
    void policz_kolory();
    std::vector<int> getTab(){return tab_kolorow;}
    int getKolory(){return kolory;}
    int getWierzcholki(){return wierzcholki;}
    void setWierzcholki(int w) {wierzcholki = w;}
    void mutacja();
};
