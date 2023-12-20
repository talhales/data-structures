/**
* @file kromozom.hpp
* @description kromozom sınıfının başlık dosyası
* @course Bilgisayar Mühendisliği(İÖ) B Grubu
* @assignment 1
* @date 17/11/2024
* @author Talha Biçer talha.bicer@ogr.sakarya.edu.tr
*/
#ifndef kromozom_hpp
#define kromozom_hpp
#include "baglilist.hpp"
#include <fstream>
#include <iostream>
using namespace std;

class kromozom{
    public:
        void txtyazdir();
        void mutasyon(int satir,int sira);
        void caprazlama(int satir1,int satir2);
        void otoislem();
        void ekranayaz();
};


#endif