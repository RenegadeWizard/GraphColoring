//
//  Zachlanny.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 08/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Zachlanny.hpp"

void Zachlanny::operator()(Graph* graf){
    int k,j;
    for(int i=0;i<graf->getRozmiar();i++){
        k = 0;
        j = 0;
        while(j < i){
            if(graf->getMacierz()[i][j])
                if(graf->getKolory()[j] == k){
                    k++;
                    j = 0;
                    continue;
                }
            j++;
        }
        graf->getKolory()[i] = k;
    }
}
