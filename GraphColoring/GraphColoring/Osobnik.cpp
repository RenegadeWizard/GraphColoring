//
//  Osobnik.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 09/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Osobnik.hpp"

int licznik = 0;

Osobnik::Osobnik(int w){
    wierzcholki = w;
//    srand(unsigned(time(NULL)*licznik));
    int t;
    for (int i=0; i<wierzcholki; i++){
        t = rand()%(wierzcholki/6);
//        std::cout << t <<" ";
        tab_kolorow.push_back(t);
//        modulo stopien wierzcholka + 1
    }
//    std::cout << "\n";
    policz_kolory();
    numerKolejny = licznik++;
}

Osobnik::Osobnik(std::vector<int> kolory,int w){
    wierzcholki = w;
    tab_kolorow=kolory;
    policz_kolory();
    numerKolejny = licznik++;
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
//    srand(unsigned(time(NULL)));
    int t1,t2;
    t1 = rand()%wierzcholki;
    t2 = rand()%wierzcholki;
    while(t1==t2)
        t2 = rand()%wierzcholki;
    std::swap(tab_kolorow[t1], tab_kolorow[t2]);
}
