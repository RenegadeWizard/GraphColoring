//
//  Populacja.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 09/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Populacja.hpp"

int licznik1 = 1;

Populacja::Populacja(int w,Graph* g){
    wielkoscPopulacji = w;
    graf = g;
//    Osobnik* temp;
    for(int i=0;i<wielkoscPopulacji;i++){
        Osobnik* temp = new Osobnik(graf->getRozmiar(),graf->getMaxWierzcholek());
        temp->napraw(graf);
        osobnikiPopulacji.push_back(*temp);
        delete temp;
    }
}

void Populacja::rodzice1(){
    int punkt;
//    srand(unsigned(time(NULL))*licznik1++);
    //losuj punkt
    punkt = rand()%wielkoscPopulacji;
    rodz1 = &osobnikiPopulacji[punkt];
//    std::cout << punkt << " ";
    //losuj punkt
    punkt = rand()%wielkoscPopulacji;
    rodz2 = &osobnikiPopulacji[punkt];
//    std::cout << punkt << "\n";
}

void Populacja::rodzice2(){
    rodz1 = &osobnikiPopulacji[0];
    rodz2 = &osobnikiPopulacji[1];
}

void Populacja::rodzice3(){
    rodz1 = &osobnikiPopulacji[0];
    int punkt = rand()%wielkoscPopulacji;
    while (punkt==0) {
        punkt = rand()%wielkoscPopulacji;
    }
    rodz2 = &osobnikiPopulacji[punkt];
}

void Populacja::rodzice4(){
    rodz1 = &osobnikiPopulacji[0];
    rodz2 = &*osobnikiPopulacji.end();
}

void Populacja::rodzice5(){
    rodz1 = &*osobnikiPopulacji.end();
    rodz2 = &*(osobnikiPopulacji.end()-1);
}

void Populacja::laczenie(int ileMutacji){
    int punkt;
//    srand(unsigned(time(NULL)));
    punkt = rand()%graf->getRozmiar();
//    punkt = graf->getRozmiar()/2;
    std::vector<int> kolory;
    for (int i = 0; i < punkt; i++){
        kolory.push_back(rodz1->getTab()[i]);
    }
    for (int i = punkt; i < graf->getRozmiar(); i++){
        kolory.push_back(rodz2->getTab()[i]);
    }
    Osobnik* temp = new Osobnik(kolory,graf->getRozmiar());
    for(int i=0;i<ileMutacji;i++)
        temp = mutacja(temp);
//    if(ileI < liczbaPokolen/3)
    temp->napraw(graf);
    osobnikiPopulacji.push_back(*temp);
}

void Populacja::sortuj(){
    int min,minWhere;
    for(int i=0;i<osobnikiPopulacji.size()-1;i++){
        min = osobnikiPopulacji[i].getKolory();
        minWhere = i;
        for(int j=i+1;j<osobnikiPopulacji.size();j++){
            if(osobnikiPopulacji[j].getKolory() < min){
                min = osobnikiPopulacji[j].getKolory();
                minWhere = j;
            }
        }
        std::swap(osobnikiPopulacji[i], osobnikiPopulacji[minWhere]);
    }
}

void Populacja::selekcja(){
    osobnikiPopulacji.erase(osobnikiPopulacji.begin()+wielkoscPopulacji, osobnikiPopulacji.end());
}

void Populacja::mutacja(){
//    srand(unsigned(time(NULL)));
    int ktory = rand()%wielkoscPopulacji;
    osobnikiPopulacji[ktory].mutacja2(graf);
    osobnikiPopulacji[ktory].napraw(graf);
}

Osobnik* Populacja::mutacja(Osobnik* child){
    child->mutacja1(graf);
    return child;
}

void Populacja::printPopulacje(){
    for(int i=0;i<osobnikiPopulacji.size();i++){
        std::cout << i <<". ";
        for(int j=0;j<graf->getRozmiar();j++){
            std::cout << osobnikiPopulacji[i].getTab()[j] << " ";
        }
        std::cout << "(" << osobnikiPopulacji[i].getKolory() << ")\n";
//        std::cout << " (" << osobnikiPopulacji[i].getKolory() <<")(" << osobnikiPopulacji[i].getNumerKolejny()<<")\n";
//        std::cout << "\n";
    }
    std::cout << "\n";
}


void Populacja::printMax(){
    std::cout << osobnikiPopulacji[0].getKolory() << "\n";
}
