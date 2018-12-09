//
//  Populacja.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 09/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Populacja.hpp"

Populacja::Populacja(){
    osobniki = new Osobnik[Osobnik::getWierzcholki()];
}

void Populacja::rodzice1(){
    int punkt;
    //losuj punkt
    rodz1 = osobniki[punkt];
    //losuj punkt
    rodz2 = osobniki[punkt];
}

void Populacja::rodzice2(){
    rodz1 = (osobniki)[0];
    rodz2 = (osobniki)[1];
}

void Populacja::laczenie(){
    int punkt;
    //losowanie punktu;
    for (int i = 0; i < punkt; i++){
        osobniki[i] = (rodz1).getTab()[i];
    }
    for (int i = punkt; i < Osobnik::getWierzcholki(); i++){
        osobniki[i] = (rodz2).getTab()[i];
    }
}
