//
//  Osobnik.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 09/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Osobnik.hpp"

int licznik = 0;

Osobnik::Osobnik(Graph* g,int k){
    graf = g;
    wierzcholki = graf->getRozmiar();
    Zachlanny z(graf);
    z.zachlanny(k);
    tab_kolorow = z.getTabKolorow();
    policz_kolory();
    updateFitness();
}

Osobnik::Osobnik(Graph* g){
    graf = g;
    wierzcholki = graf->getRozmiar();
    int t;
    for (int i=0; i<wierzcholki; i++){
        //        t = rand()%(wierzcholki/125);
        t = rand()%(graf->getMaxWierzcholek()+1);
//        t= rand()%(graf->getRozmiar());
        //        std::cout << t <<" ";
        tab_kolorow.push_back(t);
        //        modulo stopien wierzcholka + 1
    }
    //    std::cout << "\n";
    policz_kolory();
    numerKolejny = licznik++;
    updateFitness();
}

Osobnik::Osobnik(int w, int maxWierzcholek){
    wierzcholki = w;
    int t;
    for (int i=0; i<wierzcholki; i++){
//        t = rand()%(wierzcholki/125);
        t = rand()%(maxWierzcholek+1)/2;
//        std::cout << t <<" ";
        tab_kolorow.push_back(t);
//        modulo stopien wierzcholka + 1
    }
//    std::cout << "\n";
    policz_kolory();
    numerKolejny = licznik++;
    updateFitness();
}

Osobnik::Osobnik(std::vector<int> kolory,Graph* g){
    graf = g;
    wierzcholki = graf->getRozmiar();
    tab_kolorow=kolory;
    policz_kolory();
    numerKolejny = licznik++;
    updateFitness();
}

Osobnik::Osobnik(Graph* g,bool boo){
    graf = g;
    wierzcholki = graf->getRozmiar();
    for(int i=0;i<wierzcholki;i++){
        tab_kolorow.push_back(0);
    }
    policz_kolory();
    numerKolejny = 1;
    updateFitness();
}

void Osobnik::policz_kolory(){
    std::set<int> zbior;
    for (int i = 0; i < wierzcholki; i++){
        zbior.insert(tab_kolorow[i]);
    }
    kolory = zbior.size();
}

void Osobnik::napraw(){
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

void Osobnik::mutacja1(){
    std::set<int> uzyteKolory;
    for(int i=0;i<graf->getRozmiar();i++){
        uzyteKolory.insert(tab_kolorow[i]);
    }
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


void Osobnik::mutacja2(){
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

int Osobnik::bledneKrawedzie(){
    int k=0;
    for(int i=0;i<graf->getRozmiar();i++)
        for(int j=0;j<i;j++)
            if(graf->getMacierz()[i][j] && tab_kolorow[i] == tab_kolorow[j])
                k++;
    return k;
}


void Osobnik::updateFitness(){
    fitness = bledneKrawedzie();
}

void Osobnik::randomowaMutacja(){
    int i=0;
    while(i+1 < wierzcholki){
        std::swap(tab_kolorow[i], tab_kolorow[i+1]);
        i+=2;
    }
}

void Osobnik::randomowaMutacja2(){
    for(int i=0;i<wierzcholki/2;i++){
        std::swap(tab_kolorow[i], tab_kolorow[wierzcholki-i-1]);
    }
    
}

void Osobnik::randomowaMutacja3(){
    int punkt1,punkt2;
    for(int i=0;i<wierzcholki;i++){
        punkt1=rand()%wierzcholki;
        punkt2=rand()%wierzcholki;
        std::swap(tab_kolorow[punkt1], tab_kolorow[punkt2]);
    }
}
