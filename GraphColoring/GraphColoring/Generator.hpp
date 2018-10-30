//
//  Generator.hpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 30/10/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <string>

class Generator{
private:
    std::string nazwaPliku;
public:
    Generator();
    ~Generator();
    void setNazwa() ;
    std::string getNazwa() {return nazwaPliku;};
};
