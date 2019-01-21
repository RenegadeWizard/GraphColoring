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
    for(int i=0;i<1;i++){
        Osobnik* temp;
//        if(i==0){
//            temp = new Osobnik(graf,true);
//            temp->napraw();
//            osobnikiPopulacji.push_back(*temp);
//        }else{
            temp = new Osobnik(graf,rand()%graf->getRozmiar());
            temp->napraw();
            osobnikiPopulacji.push_back(*temp);
//        }
        
        delete temp;
    }
    for(int i=1;i<wielkoscPopulacji;i++){
        Osobnik* temp;
        temp = new Osobnik(graf);
        temp->napraw();
        osobnikiPopulacji.push_back(*temp);
        
        delete temp;
    }
}

int Populacja::bestFitness(){
    int bestFitness = osobnikiPopulacji[0].getFitness();
    for(auto a : osobnikiPopulacji){
        if(a.getFitness()<bestFitness)
            bestFitness = a.getFitness();
    }
    return bestFitness;
}

void Populacja::rodzice(){
//    if(bestFitness() > 4){
//        rodzice6();
//        mutacja = true;
//    }else{
//        rodzice2();
//        mutacja = false;
//    }
}

void Populacja::rodzice1(int poczatek){
    int punkt1,punkt2;
//    srand(unsigned(time(NULL))*licznik1++);
    //losuj punkty
    punkt1 = rand()%30;
    punkt2 = rand()%30;
    
    while(punkt1==punkt2 || punkt1-punkt2 > 20 || punkt2-punkt1 > 20){
        punkt1 = rand()%30;
        punkt2 = rand()%30;
    }
    
    rodz1 = &osobnikiPopulacji[poczatek+punkt1];
    rodz2 = &osobnikiPopulacji[poczatek+punkt2];
//    std::cout << punkt << "\n";
}
void Populacja::rodzice1a(){
    int punkt1,punkt2;
    //    srand(unsigned(time(NULL))*licznik1++);
    //losuj punkty
    punkt1 = rand()%wielkoscPopulacji;
    punkt2 = rand()%wielkoscPopulacji;
    
    while(punkt1==punkt2){
        punkt1 = rand()%wielkoscPopulacji;
        punkt2 = rand()%wielkoscPopulacji;
    }
    
    rodz1 = &osobnikiPopulacji[punkt1];
    rodz2 = &osobnikiPopulacji[punkt2];
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
    rodz2 = &osobnikiPopulacji[wielkoscPopulacji-1];
}

void Populacja::rodzice5(){
    rodz1 = &osobnikiPopulacji[wielkoscPopulacji-1];
    rodz2 = &osobnikiPopulacji[wielkoscPopulacji-2];
}

void Populacja::rodzice6(){
    int punkt1 = rand()%wielkoscPopulacji;
    int punkt2 = rand()%wielkoscPopulacji;
    int punkt3 = rand()%wielkoscPopulacji;
    int punkt4 = rand()%wielkoscPopulacji;
    
    int pierwszy,drugi;
//    if(osobnikiPopulacji[punkt1].getFitness()<osobnikiPopulacji[punkt2].getFitness())
//        pierwszy = punkt1;
//    else
//        pierwszy = punkt2;
//    if(osobnikiPopulacji[punkt3].getFitness()<osobnikiPopulacji[punkt4].getFitness())
//        drugi = punkt3;
//    else
//        drugi = punkt4;
    pierwszy = std::min(punkt1,punkt2);
    drugi = std::min(punkt3, punkt4);
    
//    while(pierwszy-drugi < 10 && drugi-pierwszy < 10)
//        drugi = rand()%wielkoscPopulacji;
    rodz1 = &osobnikiPopulacji[pierwszy];
    rodz2 = &osobnikiPopulacji[drugi];
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
    
    Osobnik* firstParent = new Osobnik(kolory,graf);
    for(int i=0;i<ileMutacji;i++){
//        if(mutacja){
//            firstParent->mutacja1();
//        }else{
//            firstParent->mutacja2();
//        }
        firstParent = mutacja(firstParent);
    }
//    firstParent->updateFitness();
    
//        firstParent->mutacja1();
    
    firstParent->napraw();
    osobnikiPopulacji.push_back(*firstParent);
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

void Populacja::sortujFitness(){
    int min,minWhere;
    for(int i=0;i<osobnikiPopulacji.size()-1;i++){
        min = osobnikiPopulacji[i].getFitness();
        minWhere = i;
        for(int j=i+1;j<osobnikiPopulacji.size();j++){
            if(osobnikiPopulacji[j].getFitness() < min){
                min = osobnikiPopulacji[j].getFitness();
                minWhere = j;
            }else if(osobnikiPopulacji[j].getFitness() == min && osobnikiPopulacji[j].getKolory() < osobnikiPopulacji[minWhere].getKolory()){
                min = osobnikiPopulacji[j].getFitness();
                minWhere = j;
            }
        }
        std::swap(osobnikiPopulacji[i], osobnikiPopulacji[minWhere]);
    }
}

void Populacja::selekcja(){
    osobnikiPopulacji.erase(osobnikiPopulacji.begin()+wielkoscPopulacji, osobnikiPopulacji.end());
}


Osobnik* Populacja::mutacja(Osobnik* child){
//    child->mutacja2(graf);
//    if(int i = rand()%3 == 0)
//        child->randomowaMutacja2();
//    else if(i == 1)
//        child->randomowaMutacja();
//    else
        child->mutacja();
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

void Populacja::naprawPopulacje(){
    for(int i=0;i<wielkoscPopulacji;i++){
        osobnikiPopulacji[i].napraw();
    }
}

void Populacja::randomowaMutacja(){
    int punkt = rand()%wielkoscPopulacji;
    osobnikiPopulacji[punkt].randomowaMutacja();
    osobnikiPopulacji[punkt].napraw();
}

int Populacja::bestKolor(){
    return osobnikiPopulacji[0].getKolory();
}

void Populacja::mutujj(){
    for(auto a:osobnikiPopulacji){
//        if(rand()%2)
//            a.randomowaMutacja();
//        else
//        a.randomowaMutacja();
//        a.randomowaMutacja2();
//        a.randomowaMutacja3();
//            a.randomowaMutacja4();
        a.randomowaMutacja5();
        a.napraw();
    }
//    dodaj();
}

void Populacja::dodaj(){
    for(int i=0;i<100;i++){
        Osobnik* temp = new Osobnik(graf);
        temp->napraw();
        osobnikiPopulacji.push_back(*temp);
        delete temp;
    }
}
