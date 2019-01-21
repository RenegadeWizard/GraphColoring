//
//  Genetyczny.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 08/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Genetyczny.hpp"

Genetyczny::Genetyczny(int wP,int lP,int lOK,int lOM){
    wielkoscPopulacji = wP;
    liczbaPokolen = lP;
    liczbaOperacjiKrzyzowania = lOK;
    liczbaOperacjiMutacji = lOM;
}

void Genetyczny::operator() (Graph* graf){
    bool saNowe = false;
    int poczatek=0;
    pop = new Populacja(wielkoscPopulacji,graf);
    int licznik = 0;
    int tmpMin = pop->getOsobnikiPopulacji()[0].getWierzcholki();
//    pop->printPopulacje();
    for(int i=0;i<liczbaPokolen;i++){
        //if (saNowe)
        //    poczatek = wielkoscPopulacji;
        //else poczatek = 0;
        for(int j=0;j<liczbaOperacjiKrzyzowania;j++){
            //pop->rodzice1(poczatek);
            pop->rodzice1a();
            pop->laczenie(liczbaOperacjiMutacji);
        }
//        pop->sortujFitness();
//        pop->randomowaMutacja();
        pop->sortuj();
        pop->selekcja();
//        if(!pop->getOsobnikiPopulacji()[0].getFitness())
//            std::cout << i << ": "<<pop->getOsobnikiPopulacji()[0].getKolory()<<"\n";
        
        if(tmpMin == pop->bestKolor()){
            licznik++;
        }else if(tmpMin > pop->bestKolor()){
            licznik = 0;
            tmpMin = pop->bestKolor();
        }
        if(licznik > 10){
            licznik=0;
            pop->mutujj();
            saNowe = true;
        }
        else saNowe = false;
        
        std::cout << i << ": "<<tmpMin<<"\n";
        
        
//        std::cout << pop->getOsobnikiPopulacji()[0].bledneKrawedzie() <<"\n";
    }
    delete pop;
}
