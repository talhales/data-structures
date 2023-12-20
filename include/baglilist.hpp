/**
* @file baglilist.hpp
* @description bağlı liste sınıfının başlıkdosyası
* @course Bilgisayar Mühendisliği(İÖ) B Grubu
* @assignment 1
* @date 16/11/2024
* @author Talha Biçer talha.bicer@ogr.sakarya.edu.tr
*/
#ifndef baglilist_hpp
#define baglilist_hpp
#include "dugum.hpp"
using namespace std;
class baglilist{
    public:
        baglilist();
        ~baglilist();
        void veriekle(char yeni);
        void print() const;
        void veridegistir(int sira, char yeni);
        void temizle();
        int boyutu() const;
        Node* getHead() const;
        Node* getLast();
        void removeAt(int index);
        bool isEmpty();

    private:
        int boyut;
        Node* head;
        Node* tail;
        Node* FindPrevByPosition(int position);
        

};


#endif 