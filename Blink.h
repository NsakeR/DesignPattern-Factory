//----------------------------------------------------------------------------------------------------------------------------------
// Klasa pochodna Blink. Klasa powoduje zmian� koloru konsoli pod kolejnymi znakami zdania przekonwertowanego na kod Morse'a. 
// 
//
// Wersja: 1.0		Autor: Jakub Lefik		
// Data: 23.01.2021
//
// Historia zmian: 
//
// Do poprawy: 
// Zrobi� �eby dzia�o si� to na jednym polu 
//----------------------------------------------------------------------------------------------------------------------------------

#ifndef BLINK_H
#define BLINK_H
#include "morse2.h"
#include <windows.h>                    // �eby u�y� funkcji manipuluj�cymi konsol�
class Blink :
    public morse2
{
protected:
    enum Colors {						// Enumerator przechowuj�cy nazwy kolor�w 
        Black,
        Blue,
        Green,
        Aqua,
        Red,
        Purple,
        Yellow,
        White,
        Gray,
        Light_Blue,
        Light_Green,
        Light_Aqua,
        Light_Red,
        Light_Purple,
        Light_Yellow,
        Bright_White
    };

    inline void convert(std::string tekst_blink) { morse2::convert(tekst_blink); blink_console(); };        // Przeci��ona virtualna funkcja convert 

private:
    
    void blink_console() {                                                                                  // Funkcja migaj�ca konsol�
        std::string Stronk = translate;
        COORD pos;
        pos.X = 0;
        pos.Y = 7;
        std::cout << "Niebieskie dla -, Czerwone dla . ";
        for (int i = 0; i < Stronk.length(); i++)
        {
            if (Stronk[i] == '-')
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((Colors::Light_Aqua) << 4));
                std::cout << " ";
                Sleep(500);
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((Colors::Black) << 4));
                std::cout << " ";
                Sleep(200);
            }
            else if (Stronk[i] == '.')
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((Colors::Light_Red) << 4));
                std::cout << " ";           
                Sleep(300);      

                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((Colors::Black) << 4));
                std::cout << " ";
                Sleep(200);
            }
            else if (Stronk[i] == ' ')
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((Colors::Black)));
                Sleep(600);
                std::cout << " ";
                
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
    }

};
#endif

