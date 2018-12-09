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

class Osobnik {
private:
    int static wierzcholki;
    int kolory;
    int *tab_kolorow;
public:
    Osobnik(int);
    void policz_kolory();
    int* getTab(){return tab_kolorow;}
    int getKolory(){return kolory;}
    int static getWierzcholki(){return wierzcholki;}
};
