//
//  Generator.cpp
//  GraphColoring
//
//  Created by Krzysztof Sychla on 30/10/2018.
//  Copyright © 2018 Krzysztof Sychla. All rights reserved.
//

#include "Generator.hpp"



using namespace std;

Generator::Generator(int il_w, int wypelnienie,std::ostream& out){
    srand((int)time(0));
    
    int il_krawedzi;
    il_krawedzi = int( (il_w * (il_w - 1) * wypelnienie) / (200));
    
    //tablica sasiedztwa
    int **tablica = new int *[il_w];
    for (int i = 0; i < il_w; i++)
    {
        tablica[i] = new int[il_w];
    }
    
    //zerowanie
    for (int i = 0; i < il_w; i++)
    {
        for (int j = 0; j < il_w; j++)
            tablica[i][j] = 0;
    }
    
    //generowanie petli (zapewnienie spojnosci)
    vector <int> petla;
    for (int i = 0; i < il_w; i++)
        petla.push_back(i);
    random_shuffle(petla.begin(), petla.end());
    
    //    for (int i = 0; i < il_w; i++)
    //        cout<<"petla ["<<i<<"] = " << petla[i] << endl;
    
    for (int i = 0; i < il_w - 1; i++)
    {
        tablica[petla[i]][petla[i + 1]] = 1;
        tablica[petla[i+1]][petla[i]] = 1;
    }
    tablica[petla[il_w - 1]][petla[0]] = 1;
    tablica[petla[0]][petla[il_w - 1]] = 1;
    
    
//    for (int i = 0; i < il_w; i++)
//    {
//        for (int j = 0; j < il_w; j++)
//            cout << tablica[i][j] << " ";
//        cout << endl;
//    }
    
    //uzupelnianie reszty tablicy
    
    int tmp = 0;
    int w1, w2;
    while (tmp < il_krawedzi - il_w)
    {
        w1 = (rand() % il_w);
        w2 = (rand() % il_w);
        
        if (!tablica[w1][w2] && w1!=w2)
        {
            tablica[w1][w2] = 1;
            tablica[w2][w1] = 1;
            tmp += 1;
        }
        
    }
    
    //tworzenie tablicy krawedzi
    
    int **krawedz = new int *[il_krawedzi];
    int ilosc = 0;
    for (int i = 0; i < il_w; i++)
    {
        for (int j = 0; j < il_w; j++)
        {
            if (tablica[i][j])
            {
                krawedz[ilosc] = new int[2];
                krawedz[ilosc][0] = i+1;    //numerowanie wierzcholkow
                krawedz[ilosc][1] = j+1;    //od jedynki
                ilosc += 1;
            }
        }
    }
    
    out << il_w << "\n";
    for (int i = 0; i < il_krawedzi; i++)
        out << krawedz[i][0] << " " << krawedz[i][1] << endl;
    
    //    for (int i = 0; i < il_w; i++)
    //    {
    //        delete[] tablica[i];
    //    }
    delete[] tablica;
}


Generator::~Generator(){
    
}
