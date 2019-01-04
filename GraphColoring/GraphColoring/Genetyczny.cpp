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
    pop = new Populacja(wielkoscPopulacji,graf);
//    pop->printPopulacje();
    for(int i=0;i<liczbaPokolen;i++){
        for(int j=0;j<liczbaOperacjiKrzyzowania;j++){
            pop->rodzice1();
//            pop->rodzice2();
//            pop->rodzice3();
//            pop->rodzice4();
//            pop->rodzice5();
            pop->laczenie(liczbaOperacjiMutacji);
//            pop->printPopulacje();
        }
//        for(int j=0;j<liczbaOperacjiMutacji;j++){
//            pop->mutacja();
//            pop->printPopulacje();
//        }
        pop->sortuj();
//        pop->printPopulacje();
        pop->selekcja();
//        pop->printPopulacje();
        std::cout << i << ": ";
        pop->printMax();
    }
//    pop->printPopulacje();
    delete pop;
}
