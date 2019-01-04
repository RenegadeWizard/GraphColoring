//
//  Osobnik.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 09/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Osobnik.hpp"

int licznik = 0;

Osobnik::Osobnik(int w, int maxWierzcholek){
    wierzcholki = w;
    int t;
    for (int i=0; i<wierzcholki; i++){
//        t = rand()%(wierzcholki/125);
        t = rand()%(maxWierzcholek+1);
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
    int t1,t2;
    t1 = rand()%wierzcholki;
    t2 = rand()%wierzcholki;
    while(t1==t2)
        t2 = rand()%wierzcholki;
    std::swap(tab_kolorow[t1], tab_kolorow[t2]);
}

void Osobnik::mutacja1(Graph* graf){
    std::set<int> uzyteKolory;
    for(int i=0;i<graf->getRozmiar();i++){
        std::set<int> sasiednieKolory;
        for(int j=0;j<i;j++){
            if(graf->getMacierz()[i][j])
                sasiednieKolory.insert(tab_kolorow[j]);
        }
        std::set<int> mozliweKolory = uzyteKolory;
        for(auto a : sasiednieKolory){
            mozliweKolory.erase(a);
        }
        if(mozliweKolory.count(tab_kolorow[i])==0 && mozliweKolory.size() != 0){
            int los = rand() % mozliweKolory.size();
            auto a = mozliweKolory.begin();
            while(los-- > 0){
                a++;
                tab_kolorow[i] = *(a);
            }
//            tab_kolorow[i] = *(mozliweKolory.begin()+los);
        }
    }
}


void Osobnik::mutacja2(Graph* graf){
    std::set<int> uzyteKolory;
    for(int i=0;i<graf->getRozmiar();i++){
        uzyteKolory.insert(tab_kolorow[i]);
    }
    int los;
    for(int i=0;i<graf->getRozmiar();i++){
        for(int j=0;j<i;j++){
            if(graf->getMacierz()[i][j])
                if(tab_kolorow[i] == tab_kolorow[j]){
                    los = rand()%uzyteKolory.size();
                    auto a = uzyteKolory.begin();
                    while(los-- > 0){
                        a++;
                        tab_kolorow[i] = *(a);
                    }
                }
        }
    }
}

void Osobnik::bledneKrawedzie(Graph* graf){
    int k=0;
    for(int i=0;i<graf->getRozmiar();i++)
        for(int j=0;j<i;j++)
            if(graf->getMacierz()[i][j] && tab_kolorow[i] == tab_kolorow[j])
                k++;
}
