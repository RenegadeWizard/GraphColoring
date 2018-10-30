//
//  main.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 19/10/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include <iostream>
#include "Graph.hpp"
#include <fstream>
#include <vector>

int main(int argc, const char * argv[]) {
    int ile,in,out;
    std::fstream file;
    file.open("myciel4.txt",std::ios::in);
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
    graf->zachlanny();
    graf->printKolory();
    graf->printIleKolorow();
    delete graf;
    return 0;
}
