//
//  Zachlanny.hpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 08/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once

#include <iostream>
#include "Graph.hpp"

class Zachlanny{
private:
    std::vector<int> tab_kolorow;
    Graph* graf;
public:
    Zachlanny(Graph*);
    void operator()();
    void zachlanny(int);
    std::vector<int> getTabKolorow() {return tab_kolorow;}
};
