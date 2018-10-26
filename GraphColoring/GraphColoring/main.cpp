//
//  main.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 19/10/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include <iostream>
#include "Graph.hpp"

int main(int argc, const char * argv[]) {
    int first[] = {0,0,0,1,2,2,2,3,4};
    int second[] = {1,3,5,6,3,4,6,4,5};
    Graph* graf = new Graph(7,9,first,second);
    graf->zachlanny();
    graf->printKolory();
    delete graf;
    return 0;
}
