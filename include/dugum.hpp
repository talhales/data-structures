/**
* @file dugum.hpp
* @description düğüm sınıfı
* @course Bilgisayar Mühendisliği(İÖ) B Grubu
* @assignment 1
* @date 16/11/2024
* @author Talha Biçer talha.bicer@ogr.sakarya.edu.tr
*/
#ifndef dugum_hpp
#define dugum_hpp
using namespace std;

struct Node {
    char data;
    Node* next;

    Node(char data) : data(data), next(nullptr) {}
};
#endif