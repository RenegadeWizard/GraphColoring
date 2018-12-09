//
//  Populacja.hpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 09/12/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#pragma once

#include <iostream>
#include "Osobnik.hpp"

class Populacja {
private:
    Osobnik *osobniki; //dynamiczna tablica
    int macierz_sasiedztwa;
    Osobnik rodz1, rodz2, dziecko;
public:
    Populacja();
    void rodzice1();
    void rodzice2();
    void laczenie();
//    void popraw_losowo(Osobnik this->dziecko);
//    void popraw_dokladnie(Osobnik this->dziecko);
    void sortuj();
};
