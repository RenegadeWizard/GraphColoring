//
//  Graph.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 19/10/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph(int n,int* first,int* second){
    rozmiar = n;
    for(int i=0;i<rozmiar;i++)
        macierz[i] = new int [rozmiar];
    for(int i=0;i<rozmiar;i++)
        for(int j=0;j<rozmiar;j++)
            macierz[i][j] = 0;
    for(int i=0;i<rozmiar;i++){
        macierz[first[i]][second[i]] = 1;
        macierz[second[i]][first[i]] = 1;
    }
}

Graph::~Graph(){
    for(int i=0;i<rozmiar;i++)
        delete[] macierz[i];
    delete[] macierz;
}

void Graph::zachlanny(){
    
}
