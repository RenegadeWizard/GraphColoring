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
#include <fstream>
#include <vector>

int main(int argc, const char * argv[]) {
    std::fstream file("out4.txt",std::ios::out);
    Generator generuj(20,70,file);
    file.close();
    file.open("out4.txt",std::ios::in);
    int ile,in,out;
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
    Genetyczny g(4,2,2,1);
    g(graf);
    delete graf;
    file.close();
    return 0;
}
