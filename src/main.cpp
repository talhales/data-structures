/**
* @file main.cpp
* @description Main Dosyası
* @course Bilgisayar Mühendisliği(İÖ) B Grubu
* @assignment 1
* @date 20/11/2024
* @author Talha Biçer talha.bicer@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <cstdlib>
#include <windows.h> // Windows'a özgü
#include <locale.h>  // Türkçe karakterler için

#include "kromozom.hpp"
using namespace std;

int main() {
    // Türkçe karakterlerin doğru çalışabilmesi için locale ayarları
    setlocale(LC_ALL, "tr_TR");
    SetConsoleOutputCP(CP_UTF8);  // Konsol çıktısı için UTF-8 kodlama
    SetConsoleCP(CP_UTF8);        // Konsol girişi için UTF-8 kodlama

    int secenek;

    // Ana menu döngüsü
    while (true) {
        cout << "Yapmak istediğiniz işlemi seciniz" << endl
             << "1=DNA Listesini Yazdir." << endl
             << "2=Mutasyon" << endl
             << "3=Caprazlama" << endl
             << "4=Oto İslem" << endl
             << "5=Kucuk Yaz" << endl
             << "6=Cikis" << endl;

        cin >> secenek;
        system("cls");

        // Cikis koşulu
        if (secenek == 6) {
            cout << "Cikis yapiliyor..." << endl;
            break; // Döngüden çıkmak için break
        }

        switch (secenek) {
            case 1:
                {
                    kromozom a;
                    a.txtyazdir(); 
                    break;
                }
            case 2:
                {
                    kromozom a;  
                    int x, y;  
                    cout << "Mutasyona Uğramasini Istediğiniz Kromozomun Satir Sayisini Giriniz: ";
                    cin >> x;  
                    cout << "Mutasyona Uğramasini Istediğiniz Kromozomun Sira Sayisini Giriniz: ";
                    cin >> y;  

                    a.mutasyon(x, y);  // Mutasyon işlemi yapılırken x ve y değerleri kullanılıyor
                    break;
                }
            case 3:
                {
                    kromozom a;  
                    int satir1, satir2;  
                    cout << "Caprazlama işlemi için iki satir numarası giriniz:" << endl;
                    cout << "Satir 1: ";
                    cin >> satir1;
                    cout << "Satir 2: ";
                    cin >> satir2;

                    a.caprazlama(satir1, satir2);  
                    a.caprazlama(satir2, satir1);  
                    break;
                }
            case 4:
                {
                    kromozom a;  
                    a.otoislem();  
                    break;
                }
            case 5:
                {
                    kromozom a;  
                    a.ekranayaz();  
                    break;
                }
            default:
                cout << "Lutfen Gecerli Bir Sayi Giriniz!" << endl;
                break;
        }
    }

    return 0;
}
