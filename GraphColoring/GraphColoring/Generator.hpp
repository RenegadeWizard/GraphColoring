//
//  Generator.hpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 30/10/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <time.h>

class Generator{
private:
    std::string nazwaPliku;
public:
    Generator(int,int,std::ostream&);
    ~Generator();
    void setNazwa() ;
    std::string getNazwa() {return nazwaPliku;};
};
