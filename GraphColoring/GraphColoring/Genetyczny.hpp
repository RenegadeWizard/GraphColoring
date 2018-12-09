//
//  Genetyczny.hpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 08/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include "Graph.hpp"

class Genetyczny{
private:
    int wielkoscPopulacji;
    int liczbaPokolen;
    int liczbaOperacjiKrzyzowania;
    int liczbaOperacjiMutacji;
    std::vector<int*> pokolenie;
public:
    Genetyczny(int,int,int,int);
    void operator()(Graph*);
    void krzyzuj();
    void mutuj();
    void sortuj();
    void napraw(Graph*);
    void tworzPokolenie();
    void printPokolenia();
};
