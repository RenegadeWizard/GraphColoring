//
//  Graph.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 19/10/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph(int n,int m,int* first,int* second){
    rozmiar = n;
    macierz = new int * [rozmiar];
    kolory = new int[rozmiar];
    for(int i=0;i<rozmiar;i++)
        macierz[i] = new int [rozmiar];
    for(int i=0;i<rozmiar;i++)
        for(int j=0;j<rozmiar;j++)
            macierz[i][j] = 0;
    for(int i=0;i<m;i++){
        macierz[first[i]][second[i]] = 1;
        macierz[second[i]][first[i]] = 1;
    }
}

Graph::Graph(int n,std::vector<int> first,std::vector<int> second){
    rozmiar = n;
    macierz = new int * [rozmiar];
    kolory = new int [rozmiar];
    for(int i=0;i<rozmiar;i++)
        macierz[i] = new int [rozmiar];
    for(int i=0;i<rozmiar;i++)
        for(int j=0;j<rozmiar;j++)
            macierz[i][j] = 0;
    for(int i=0;i<first.size();i++){
        macierz[first[i]-1][second[i]-1] = 1;
        macierz[second[i]-1][first[i]-1] = 1;
    }
}

Graph::~Graph(){
    for(int i=0;i<rozmiar;i++)
        delete[] macierz[i];
    delete[] macierz;
    delete[] kolory;
}


void Graph::printMacierz(){
    std::cout << "Macierz: \n";
    for(int i=0;i<rozmiar;i++){
        for(int j=0;j<rozmiar;j++)
            std::cout << macierz[i][j] << " ";
        std::cout << "\n";
    }
}

void Graph::printKolory(){
    std::cout << "Kolory:\n";
    for(int i=0;i<rozmiar;i++)
        std::cout << kolory[i] << " ";
    std::cout << "\n";
}

void Graph::printIleKolorow(){
    std::cout<<"Ile kolorow:\n";
    int ile = 0;
    for(int i=0;i<rozmiar;i++)
        if(kolory[i] > ile)
            ile = kolory[i];
    std::cout<<ile+1<<"\n";
}
