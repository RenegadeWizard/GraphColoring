//
//  Graph.hpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 19/10/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once

#include <stdio.h>

class Graph{
private:
    int rozmiar;
    int** macierz = new int * [rozmiar];


public:
    void zachlanny();
    Graph(int,int*,int*);
    ~Graph();
};
