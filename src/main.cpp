#include "SWektor.hh"
#include "rozmiar.h"
#include "LZespolona.hh"
#include "SMacierz.hh"
#include "UkladRownanLiniowych.hh"
#include <iostream>
#include <limits>

using namespace std;

void Test_SzablonWektor_double()
{
     cout << endl
          << " --------- Test klasy Wektor<double," << ROZMIAR << "> ----------" << endl
          << endl;

     SWektor<double, ROZMIAR> W, W_wynik;

     for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind)
     {
          W[Ind] = Ind;
     }

     cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
          << "        " << W << endl
          << endl;

     W_wynik = W * 2;
     cout << "  Wyswietlenie wyniku: W*2" << endl
          << "        " << W_wynik << endl
          << endl;

     W_wynik = W * 2 - W;
     cout << "  Wyswietlenie wyniku: W-W*0.5" << endl
          << "        " << W_wynik << endl
          << endl;
}

void Test_SzablonWektor_LZespolona()
{
     cout << endl
          << " --------- Test klasy Wektor<LZespolona," << ROZMIAR << "> ----------" << endl
          << endl;

     SWektor<LZespolona, ROZMIAR> W, W_wynik;

     for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind)
     {
          W[Ind].re = Ind;
          W[Ind].im = Ind;
     }

     cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
          << "        " << W << endl
          << endl;

     W_wynik = W * 2;
     cout << "  Wyswietlenie wyniku: W*2" << endl
          << "        " << W_wynik << endl
          << endl;

     W_wynik = W * 2 - W;
     cout << "  Wyswietlenie wyniku: W-W*0.5" << endl
          << "        " << W_wynik << endl
          << endl;
}
void final_test()
{
     cout << endl
          << " Start programu " << endl
          << endl;
     char pom;
     cin >> pom;
          if (pom == 'r')
          {
               SUkladRownanLiniowych<double, ROZMIAR> Rozw;
               cin >> Rozw; // Wczytanie ze strumienia wejscia Macierzy oraz wektora wyrazow wolnych
               cout << "Macierz A:" << endl
                    << Rozw.Get_macierz(); 
               cout << "Macierz transponowana:" << endl
                    << Rozw.Get_macierz().transpozycja(); 
               cout << "Wektor wyrazow wolnych:" << endl
                    << Rozw.Get_wektor() << endl; // Wyswietlenie kolejno Macierzy A, A^T , oraz wektora wyrazow wolnych
               Rozw.RozwiazUkladRownan();    
               Rozw.WyliczBladRozwiazania(); // Rozwiazanie ukladu rownan
          }
          else if (pom == 'z')
          {
               SUkladRownanLiniowych<LZespolona, ROZMIAR> Rozw;
               cin >> Rozw; // Wczytanie ze strumienia wejscia Macierzy oraz wektora wyrazow wolnych
               cout << "Macierz A:" << endl
                    << Rozw.Get_macierz(); //
               cout << "Macierz transponowana:" << endl 
                    << Rozw.Get_macierz().transpozycja(); //
               cout << "Wektor wyrazow wolnych:" << endl
                    << Rozw.Get_wektor() << endl; // Wyswietlenie kolejno Macierzy A, A^T , oraz wektora wyrazow wolnych
               Rozw.RozwiazUkladRownan();         // Obliczenie ukladu
               Rozw.WyliczBladRozwiazania();      // wraz z jego bledem
          }
          else
          {
               cerr << "Wprowadzono niepoprawny format wejściowy. Dozwolone formaty to z lub r.";
          }
     
}

int main()
{
     final_test();
}
