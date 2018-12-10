//
//  Populacja.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 09/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Populacja.hpp"

Populacja::Populacja(int w,Graph* g){
    wielkoscPopulacji = w;
    graf = g;
//    Osobnik* temp = new Osobnik(graf->getRozmiar());
    for(int i=0;i<wielkoscPopulacji;i++){
        osobnikiPopulacji.push_back(new Osobnik(graf->getRozmiar()));
//        delete temp;
    }
}

void Populacja::rodzice1(){
    int punkt;
    srand(time(NULL));
    //losuj punkt
    punkt = rand()%wielkoscPopulacji;
    rodz1 = osobnikiPopulacji[punkt];
    //losuj punkt
    punkt = rand()%wielkoscPopulacji;
    rodz2 = osobnikiPopulacji[punkt];
}

void Populacja::rodzice2(){
    rodz1 = osobnikiPopulacji[0];
    rodz2 = osobnikiPopulacji[1];
}

void Populacja::laczenie(){
    int punkt;
    srand(time(NULL));
    punkt = rand()%graf->getRozmiar();
    std::vector<int> kolory;
    for (int i = 0; i < punkt; i++){
        kolory.push_back(rodz1->getTab()[i]);
    }
    for (int i = punkt; i < graf->getRozmiar(); i++){
        kolory.push_back(rodz2->getTab()[i]);
    }
    Osobnik* temp = new Osobnik(kolory,graf->getRozmiar());
    temp->napraw(graf);
    osobnikiPopulacji.push_back(temp);
}

void Populacja::sortuj(){
    int max,maxWhere;
    for(int i=0;i<wielkoscPopulacji-1;i++){
        max = osobnikiPopulacji[i]->getKolory();
        maxWhere = i;
        for(int j=i+1;j<wielkoscPopulacji;j++){
            if(osobnikiPopulacji[j]->getKolory() > max){
                max = osobnikiPopulacji[j]->getKolory();
                maxWhere = j;
            }
        }
        std::swap(osobnikiPopulacji[i], osobnikiPopulacji[maxWhere]);
    }
}

void Populacja::selekcja(){
    osobnikiPopulacji.erase(osobnikiPopulacji.begin()+wielkoscPopulacji, osobnikiPopulacji.end());
}

void Populacja::mutacja(){
    srand(time(NULL));
    int ktory = rand()%wielkoscPopulacji;
    osobnikiPopulacji[ktory]->mutacja();
}

void Populacja::printPopulacje(){
    for(int i=0;i<osobnikiPopulacji.size();i++){
        std::cout << i <<". ";
        for(int j=0;j<graf->getRozmiar();j++){
            std::cout << osobnikiPopulacji[i]->getTab()[j] << " ";
        }
        std::cout << " (" << osobnikiPopulacji[i]->getKolory() <<")\n";
    }
    std::cout << "\n";
}
