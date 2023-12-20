/**
* @file baglilist.cpp
* @description bağlı liste sınıfının kodları
* @course Bilgisayar Mühendisliği(İÖ) B Grubu
* @assignment 1
* @date 16/11/2024
* @author Talha Biçer talha.bicer@ogr.sakarya.edu.tr
*/
#include "baglilist.hpp"
#include <iostream>
using namespace std;

baglilist::baglilist()
{
    head = nullptr;
    tail = nullptr; 
    boyut = 0;
}

baglilist::~baglilist()
{
    temizle();
}

void baglilist::veriekle(char data)
{
    if (data == ' ') { // txt dosyasındaki boşlukların linkedliste eklenmesini önleyen blok.
        return;
    }

    Node* newNode = new Node(data);
    if (!head) { // Liste boşsa, yeni düğümü başa ekle
        head = tail = newNode;
    }
    else {
        tail->next = newNode; // Son düğümün next işaretçisini yeni düğüme yönlendir
        tail = newNode; // Tail'i güncelle
    }
    boyut++;
}

void baglilist::print() const //Bağlı liste elemanlarını sırayla ekrana yaz.
{
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void baglilist::veridegistir(int sira, char yeni) //Bağlı listedeki spesifik elemanı değiştirme.
{
    Node* current = head;
    for (int i = 0; i < sira && current; ++i) {
        current = current->next;
    }
    if (current) {
        current->data = yeni;
    }
    else {
        cout << "Gecersiz Sira" << endl;
    }
}

void baglilist::temizle()
{
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp; // Belleği serbest bırak
    }
    tail = nullptr; // Tail'i sıfırla
    boyut = 0;
}

int baglilist::boyutu() const
{
    return boyut;
}

Node* baglilist::getHead() const
{
    return head;
}

Node* baglilist::getLast()
{
    return tail; 
}

void baglilist::removeAt(int index)
{
    if (index < 0 || index >= boyut) throw "Index out of range"; // Geçersiz indeks kontrolü
    
    Node* del;
    if (index == 0) { // İlk düğümü sil
        del = head;
        head = head->next;
        if (!head) { // Liste artık boşsa, tail'i de sıfırla
            tail = nullptr;
        }
    }
    else {
        Node* prev = FindPrevByPosition(index);
        del = prev->next;
        prev->next = prev->next->next;
        if (prev->next == nullptr) { // Eğer son düğüm silindiyse, tail'i güncelle
            tail = prev;
        }
    }
    delete del;
    boyut--;
}

bool baglilist::isEmpty()
{
    return head == nullptr;
}

Node* baglilist::FindPrevByPosition(int position)
{
    if (position < 0 || position >= boyut) throw "Index out of range";

    int index = 0;
    Node* itr = head;
    while (itr && index < position - 1) { // Önceki düğümü bul
        itr = itr->next;
        index++;
    }
    return itr;
}








