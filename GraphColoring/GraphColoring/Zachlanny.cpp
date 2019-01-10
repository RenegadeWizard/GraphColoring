//
//  Zachlanny.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 08/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Zachlanny.hpp"

Zachlanny::Zachlanny(Graph* g){
    graf = g;
    for(int i=0;i<graf->getRozmiar();i++)
        tab_kolorow.push_back(0);
}

void Zachlanny::operator()(){
    for(int i=0;i<graf->getRozmiar();i++)
        zachlanny(i);
}

void Zachlanny::zachlanny(int wierzcholek){
    int k,j;
    for(int i=0;i<graf->getRozmiar();i++){
        k = 0;
        j = 0;
        while(j < (i+wierzcholek)%graf->getRozmiar()){
            if(graf->getMacierz()[(i+wierzcholek)%graf->getRozmiar()][j])
                if(tab_kolorow[j] == k){
                    k++;
                    j = 0;
                    continue;
                }
            j++;
        }
        tab_kolorow[(i+wierzcholek)%graf->getRozmiar()] = k;
    }
}
