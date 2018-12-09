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

void Genetyczny::napraw(Graph* graf){
    int j,k;
    for(auto populacja : pokolenie){
        for(int i=0;i<graf->getRozmiar();i++){
            k = j = 0;
            while(j<i){
                if(graf->getMacierz()[i][j])
                    if(populacja[i] == populacja[j]){
                        populacja[i] = k++;
                        j = 0;
                        continue;
                    }
                j++;
            }
        }
    }
}

void Genetyczny::tworzPokolenie(){
    int* populacja = new int[wielkoscPopulacji];
    srand(time(NULL));
    for(int j=0;j<liczbaPokolen;j++){
        for(int i=0;i<wielkoscPopulacji;i++)
            populacja[i] = rand()%((wielkoscPopulacji+4)/3);
        pokolenie.push_back(populacja);
    }
//    for(int i=0;i<wielkoscPopulacji;i++)
//        std::cout << populacja[i] << " ";
//    std::cout << "\n";
}


void Genetyczny::printPokolenia(){
    for(auto populacja : pokolenie){
        for(int i=0;i<wielkoscPopulacji;i++){
            std::cout << populacja[i] << " ";
        }
        std::cout << "\n";
    }
}
