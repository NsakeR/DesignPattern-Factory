//----------------------------------------------------------------------------------------------------------------------------------
// Klasa pochodna MessBox. Klasa wywo�uje okienko powiadomienia z ustalon� zawarto�ci�.
//
//
// Wersja: 1.0		Autor: Jakub Lefik		
// Data: 23.01.2021
//
// Historia zmian: 
//----------------------------------------------------------------------------------------------------------------------------------

#ifndef MESSBOX_H
#define MESSBOX_H
#include "morse2.h"
#include <windows.h>    // Dla MessageBox'a
class MessBox :
    public morse2
{
public:
    inline void convert(std::string tekst_box) { morse2::convert(tekst_box); alert(); };        // Przeci��ona funkcja convert 

private:
    void alert() {            // Funkcja kt�ra powoduje wywo�anie okienka dialogowego
        
        // Wersja eksperymentalna:
        //const wchar_t morse_text = translate;
        //std::cout << morse_text << std::endl;
        //MessageBox(NULL, (LPCWSTR)morse_text.c_str(), L"Okienko powiadomienia", MB_OK);
        // Wersja dzia�aj�ca: 
        MessageBox(NULL, L"Tu powinna byc wiadomosc w kodzie morse'a ale nie potrafie dojsc jak skonwertowac morse_tekst na LPCWSTR �eby si� Pani nie przestraszy�a chinskich znaczkow ", L"Okienko powiadomienia", MB_OK);
    }

};
#endif

