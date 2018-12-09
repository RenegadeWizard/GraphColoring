//
//  Osobnik.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 09/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Osobnik.hpp"

Osobnik::Osobnik(int w){
    wierzcholki = w;
    tab_kolorow = new int[wierzcholki];
}

void Osobnik::policz_kolory(){
    std::set<int> zbior;
    for (int i = 0; i < wierzcholki; i++){
        zbior.insert(tab_kolorow[i]);
    }
    kolory = zbior.size();
}
