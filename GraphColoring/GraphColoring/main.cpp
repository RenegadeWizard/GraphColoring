//
//  main.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 19/10/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include <iostream>
#include "Graph.hpp"
#include "Generator.hpp"
#include "Zachlanny.hpp"
#include "Genetyczny.hpp"
#include "Osobnik.hpp"
#include <fstream>
#include <vector>
#include <ctime>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
//    Osobnik::licznik = 0;
    std::fstream file/*("out4.txt",std::ios::out)*/;
//    Generator generuj(20,70,file);
//    file.close();
    file.open("gc500.txt",std::ios::in);
    int ile,in,out;
    srand(time(NULL));
    file >> ile;
    std::vector<int> first;
    std::vector<int> second;
    while(!file.eof()){
        file >> in;
        file >> out;
        first.push_back(in);
        second.push_back(out);
    }
    Graph* graf = new Graph(ile,first,second);
    Genetyczny g(100,300000000,50,30);
//    Genetyczny g(100,300000000,50,30); // Wilekosc populacji, liczba pokolen, liczba operacji krzyzowania, liczba mutacji
//    Zachlanny z;
    g(graf);
//    z(graf);
//    graf->printIleKolorow();
    delete graf;
    file.close();
    return 0;
}
