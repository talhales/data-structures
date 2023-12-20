/**
* @file kromozom.cpp
* @description kromozom sınıfının kodları
* @course Bilgisayar Mühendisliği(İÖ) B Grubu
* @assignment 1
* @date 17/11/2024
* @author Talha Biçer talha.bicer@ogr.sakarya.edu.tr
*/
#include "kromozom.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void kromozom::mutasyon(int satir, int sira)
{
    ifstream dna("Dna.txt");
    ofstream tmp("tmp.txt");
    if (!dna.is_open() || !tmp.is_open()) {
        cerr << "hata" << endl; // Dosya hata kontrolü
        return;
    }

    baglilist kro;
    string line;
    int anliksatir = 0;

    while (getline(dna, line)) {
        if (anliksatir == satir) {
            for (char gen : line) {
                kro.veriekle(gen); // İstenen satırdaki karakterleri bağlı listeye ekler
            }
            kro.veridegistir(sira, 'X'); // Mutasyon

            Node* current = kro.getHead();
            while (current) {
                tmp << current->data << ' ';
                current = current->next;
            }
            tmp << endl;
            kro.temizle(); // Bellek temizleme
        }
        else {
            tmp << line << endl; // İstenen satırda olmayan kromozomları olduğu gibi yaz
        }
        anliksatir++;
    }

    dna.close();
    tmp.close();

    remove("Dna.txt"); // Orijinal dosyayı silip geçici dosyayı orijinal dosya yapma
    rename("tmp.txt", "Dna.txt");
}

void kromozom::caprazlama(int satir1, int satir2)
{
    ifstream dna("Dna.txt");
    ofstream tmp("tmp.txt");
    if(!dna.is_open()&&!tmp.is_open()){
        cerr<<"hata"<<endl;//Dosya hata kontrolü
    }
    baglilist kro;
    baglilist crs;
    string line;
    int anliksatir=0;
    int kroboyut;
    
    while(getline(dna,line)){
        if(anliksatir==satir1){//Kross over işleminde yeni oluşacak kromozomun ilk yarısı
            
            for(char gen : line){
                kro.veriekle(gen);//İstenen satırdaki karakterleri bağlı listeye ekler.  
            }
            
            kroboyut=kro.boyutu();
            cout<<kroboyut;
            Node* current=kro.getHead();

            int islemsirasi=0;
            while(true){//Yeni oluşacak kromozomun ilk yarısında ikiye tam bölünme kontrolü yapılmıyor bunun sebebi int değişkeninin virgül sonraki kısmı olmaması.
                
                if(islemsirasi>=kroboyut/2){
                    break;
                }
                crs.veriekle(current->data);
                current=current->next;
                islemsirasi++;
            }
            kro.temizle();
            tmp << line << endl;
            
        }
        else if(anliksatir==satir2){//Kross over işleminde yeni oluşacak kromozomun son yarısı
            for(char gen : line){
                kro.veriekle(gen);//İstenen satırdaki karakterleri bağlı listeye ekler.  
            }
            
            kroboyut=kro.boyutu();
            cout<<kroboyut;
            if(kroboyut%2==0){//Seçilen kromozom ikiye tam bölünüyor mu kontrolü
                Node* current = kro.getHead();
                int islemsirasi=0;
                while(current){
                    
                    if(islemsirasi<kroboyut/2){
                        current=current->next;
                        islemsirasi++;
                        continue;
                    }
                    
                    crs.veriekle(current->data);
                    current=current->next;
                    
                    islemsirasi++;
                    
                    
            }
            }
            else{
                int islemsirasi=0;
                Node* current = kro.getHead();
                while(current){
                    if(islemsirasi<kroboyut/2+1){
                        current=current->next;
                        islemsirasi++;
                        continue;
                    }
                    
                    crs.veriekle(current->data);
                    current=current->next;
                    
                    islemsirasi++;
                }
            }
            tmp << line << endl;
            kro.temizle();
        }
        else{
            tmp << line << endl;//İstenen satırda olmayan kromozomları olduğı gibi yaz.
        }
        anliksatir++;
        
    }
    Node* current = crs.getHead();

        while(current){
            tmp << current->data << ' ';
            current=current->next;
        }
    tmp << endl;
    crs.temizle();

    dna.close();
    tmp.close();

    remove("Dna.txt");//Orijinal dosyayı silip geçici dosyayı orijinal dosya yapma.
    rename("tmp.txt","Dna.txt");
}
void kromozom::otoislem()
{
    ifstream oto("Islemler.txt");
    if (!oto.is_open()) {
        cerr << "hata" << endl; // Dosya hata kontrolü
        return;
    }

    string satir;
    while (getline(oto, satir)) {
        stringstream ss(satir);
        char islem;
        int x, y;

        ss >> islem >> x >> y; //Satırdan 'islem' , x ve y değerlerini al
        if (ss.fail()) {
            cout << "Satırda format hatası var: " << satir << endl;
            continue; // Hatalı satırı geç
        }

        if (islem == 'M') {
            mutasyon(x, y);  //Mutasyon işlemi yapılır
            cout << x << ".Satir " << y << ".Siradaki Kromozoma Mutasyon İslemi Yapildi." << endl;
        }
        else if (islem == 'C') {
            cout << x << ".Satir " << y << ".Satirdaki Kromozomlara Caprazlama İslemi Yapildi." << endl;
            caprazlama(x, y);  //Çaprazlama işlemi yapılır
            caprazlama(y, x);
        }
        else {
            cout << "Taninmayan islem!" << endl;
        }
    }

    oto.close(); //Dosyayı kapatma
}

void kromozom::ekranayaz()//Sağdan sola ilk genden küçük genleri ekrana yazan fonksiyon.
{
    ifstream dna("Dna.txt");
    if (!dna) {
        cout << "Dosya açılamadı!" << endl;
        return;
    }

    baglilist kro, son;
    string satir;

    while (getline(dna, satir)) {
        if (satir.empty()) continue; //Boş satırları atla

        for (char gen : satir) {
            kro.veriekle(gen); //Satırdaki karakterleri bağlı listeye ekler
        }

        Node* head = kro.getHead();
        Node* end = kro.getLast();

        if (head == nullptr) {
            kro.temizle(); //Boş listeyi temizle
            continue;
        }

        bool kucukmevcut = false;
        while (head != end && head->next != end) {
            if (end->data < head->data) {//End en sağdan başlayarak her adımda bir önceki düğüme gidip tüm listeyi gezer.
                son.veriekle(end->data);
                kucukmevcut = true;
                break;
            }
            Node* temp = head;
            while (temp->next != end) {//temp listenin en sonundaki end düğümünün bi öncesine yerleşerek end düğümünü bir önceki düğüme taşır.
                temp = temp->next;
            }
            end = temp;
        }

        if (!kucukmevcut) {
            son.veriekle(head->data);
        }

        kro.temizle(); // İşlem tamamlandı, listeyi temizle
    }

    son.print();
    son.temizle(); // Sonuç listesini temizle
    dna.close();   // Dosyayı kapat
}

void kromozom::txtyazdir()
{
    string line;//İşlem yapılacak txt dosyasına uygulama ekranından erişmek için fonksiyon.
    ifstream dna("Dna.txt");
    while (getline(dna, line)) {
        cout << line << endl;
    }
}
