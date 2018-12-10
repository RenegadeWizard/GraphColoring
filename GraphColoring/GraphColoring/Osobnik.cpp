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
    srand(time(NULL));
    int t;
    for (int i=0; i<wierzcholki; i++){
        t = rand()%wierzcholki;
        tab_kolorow.push_back(t);
//        modulo stopien wierzcholka + 1
    }
    policz_kolory();
}

Osobnik::Osobnik(std::vector<int> kolory,int w){
    wierzcholki = w;
    tab_kolorow=kolory;
    policz_kolory();
}

void Osobnik::policz_kolory(){
    std::set<int> zbior;
    for (int i = 0; i < wierzcholki; i++){
        zbior.insert(tab_kolorow[i]);
    }
    kolory = zbior.size();
}

void Osobnik::napraw(Graph* graf){
    int j,k;
    for(int i=0;i<graf->getRozmiar();i++){
        k = j = 0;
        while(j<i){
            if(graf->getMacierz()[i][j])
                if(tab_kolorow[i] == tab_kolorow[j]){
                    tab_kolorow[i] = k++;
                    j = 0;
                    continue;
                }
            j++;
        }
    }
    policz_kolory();
}

void Osobnik::mutacja(){
    srand(time(NULL));
    int t1,t2;
    t1 = rand()%wierzcholki;
    t2 = rand()%wierzcholki;
    while(t1==t2)
        t2 = rand()%wierzcholki;
    std::swap(tab_kolorow[t1], tab_kolorow[t2]);
}
