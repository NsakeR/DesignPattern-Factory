//---------------------------------------------------------------------------------------------------------------------------------------------
// Klasa pochodna Dysk_tekst. Klasa powoduje zapisanie do pliku informacji przekazanej w convert, przemianowanej na kod Morse'a, do pliku.
//
//
// Wersja: 1.0		Autor: Jakub Lefik		
// Data: 23.01.2021
//
// Historia zmian: 
//---------------------------------------------------------------------------------------------------------------------------------------------

#ifndef DYSK_TEKST_H
#define DYSK_TEKST_H
#include "morse2.h"
#include <fstream>          // Dla obs�ugi plik�w
class Dysk_tekst :
    public morse2
{
public:                                                                                                 // Przeci��ona funkcja convert dla:  (r�wnie dobrze mo�na u�y� typu samo-definiuj�cego "auto" jednak postanowi�em przeci��y� jawnie)
    inline void convert(std::string tekst_dysk) { morse2::convert(tekst_dysk); Save_to_file(); };       // String�w
    inline void convert(int int_number) { morse2::convert(int_number); Save_to_file(); };               // Int�w
    inline void convert(double d_number) { morse2::convert(d_number); Save_to_file(); };                // Doubli
    inline void convert(float f_number) { morse2::convert(f_number); Save_to_file(); };                 // Float�w

    inline void setExternalInfo(std::string informations_disk) { morse2::setExternalInfo(informations_disk); };     // Przeci��ona funkcja setExternalInfo

private:
    void Save_to_file() {                                                             // Metoda do zapisywania w pliku
        std::fstream file;
        std::string fileName = externalInfo;                                          // Nazwa pliku przekazywana za pomoc� obecnego setExternalInfo

        file.open(fileName, std::ios::app | std::ios::out);                           //  Do��cz do pliku | Plik wyj�ciowy
        if (file.is_open()) {                                                         
            std::cout << "Plik otworzono. Nastepuje zapis tresci do pliku..." << std::endl;  // Przyjazny interfejs
            file << translate << std::endl;                                                  // Zapisywanie obecnej wiadomo�ci w postaci kodu morse'a do pliku
            std::cout<< "Zapisano " << std::endl;                                            // Przyjazny interfejs cz.2
            file.close();
        }
        else {std::cout<< "Plik nie zostal otworzony." << std::endl; }                       // Przyjazny interfejs cz.3
    }
};

#endif