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
            pop->laczenie(liczbaOperacjiMutacji);
        }
//        pop->sortujFitness();
//        pop->randomowaMutacja();
        pop->sortuj();
        pop->selekcja();
//        if(!pop->getOsobnikiPopulacji()[0].getFitness())
//            std::cout << i << ": "<<pop->getOsobnikiPopulacji()[0].getKolory()<<"\n";
        
        
        std::cout << i << ": ";
        pop->printMax();
    }
    delete pop;
}
