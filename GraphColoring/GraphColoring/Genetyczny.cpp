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
    pop->printPopulacje();
    for(int i=0;i<liczbaPokolen;i++){
        for(int j=0;j<liczbaOperacjiKrzyzowania;j++){
            pop->rodzice1();
            pop->laczenie();
            pop->printPopulacje();
        }
        for(int j=0;j<liczbaOperacjiMutacji;j++){
            pop->mutacja();
            pop->printPopulacje();
        }
        pop->sortuj();
        pop->printPopulacje();
        pop->selekcja();
        pop->printPopulacje();
    }
    delete pop;
}

//void Genetyczny::tworzPokolenie(){
//    std::vector<Osobnik> populacja;
//    srand(time(NULL));
//
//    for(int i=0;i<wielkoscPopulacji;i++)
//        populacja.push_back(rand()%((wielkoscPopulacji+4)/3));
//    pokolenie.push_back(populacja);
//
////    for(int i=0;i<wielkoscPopulacji;i++)
////        std::cout << populacja[i] << " ";
////    std::cout << "\n";
//}


//void Genetyczny::printPokolenia(){
//    for(auto populacja : pokolenie){
//        for(int i=0;i<wielkoscPopulacji;i++){
//            std::cout << populacja[i] << " ";
//        }
//        std::cout << "\n";
//    }
//}
