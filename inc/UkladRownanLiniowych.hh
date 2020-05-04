#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include "SWektor.hh"
#include "SMacierz.hh"
#include "rozmiar.h"
#include <iomanip>


template <typename STyp, int SWymiar>
class SUkladRownanLiniowych 
{ 
  SWektor<STyp,SWymiar>  Rozwiazanie;
  SMacierz<STyp,SWymiar>  A;
  SWektor<STyp,SWymiar>  B;
  public:
  void RozwiazUkladRownan();
  void WyliczBladRozwiazania();
  SWektor<STyp,SWymiar> &Get_wektor()
  {
    return B;
  }
  SWektor<STyp,SWymiar> Get_wektor()const{
    return B;
  }
  SMacierz<STyp,SWymiar> &Get_macierz()
  {
    return A;
  }
  SMacierz<STyp,SWymiar> Get_macierz()const{
    return A;
  }
};


/*
* Metoda rozwiazujaca uklad rownan liniowych, rozwiazanie jest wyswietlane przy pomocy przeciazonego strumienia wyjscia
* Prerekwizyty: Wczytana poprawnie Macierz oraz Wektor Wyrazow Wolnych
*              - Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWymiar - Wymiar operowanej macierzy typu liczba całkowita 
* Argumenty: 
*  ----
* Zwraca:
*   ---
*/

template <typename STyp, int SWymiar>
  void SUkladRownanLiniowych<STyp,SWymiar>:: RozwiazUkladRownan ()
  {
    std::cout<<"Rozwiązanie x= (x1,x2,x3,x4,x5):"<<std::endl;
    STyp det=A.wyznacznik();
    for (int i=0;i<ROZMIAR;i++)
    {
        SMacierz<STyp,SWymiar> C= A.PodstawKolumne(B,i);
        this->Rozwiazanie[i]=C.wyznacznik() /det;
        std::cout<<this->Rozwiazanie[i] << " ";
    }
    std::cout<<std::endl;
  }

  /*
* Metoda obliczajaca blad rozwiazania ukladu rownan liniowych, rozwiazanie jest wyswietlane przy pomocy przeciazonego strumienia wyjscia
* Prerekwizyty: Wczytana poprawnie Macierz, Wektor Wyrazow Wolnych oraz obliczone rozwiązanie ukladu rownan.
*              - Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWymiar - Wymiar operowanej macierzy typu liczba całkowita 
* Argumenty: 
* -----
* Zwraca:
*   ---
*/

template <typename STyp, int SWymiar>
  void SUkladRownanLiniowych<STyp,SWymiar>::WyliczBladRozwiazania ()
  {
        std::cout<<"Wektor bledu:"<<std::endl;
        SWektor<STyp,SWymiar> blad= A*this->Rozwiazanie - B;
        std::cout.setf(std::ios::showpoint);
        std::cout<<std::scientific<<std::setprecision(2)<< blad;
        std::cout.setf(std::ios::showpoint);
  }
    /*
* Przeciążenie operatora wejscia dla Ukladu rownanLiniowych
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWyciar - Wymiar operowanej macierzy typu liczba całkowita 
* Argumenty:
*   Strm- strumien wejscia
*   UklRown - Uklad rownan skladajacy sie z macierzy,wektora wyrazow wolnych oraz wektora rozwiazania
* Zwraca:
*   Strumien wejscia
*/

template <typename STyp, int SWymiar>
std::istream &operator>>(std::istream &Strm, SUkladRownanLiniowych<STyp,SWymiar> &UklRown)
{
  Strm>>UklRown.Get_macierz();
  Strm>>UklRown.Get_wektor();
  return Strm;
}
/*
* Przeciążenie operatora wyjscia dla Ukladu rownanLiniowych
* Prerekwizyty: Poprawne zainicjowanie szablonu <typename STyp, int SWymiar> z argumentami:
*              - Styp - Rodzaj operowanej zmiennej. Dopuszczalne typy to liczba zmienno przecinkowa typu double lub liczba zespolona
*              - SWyciar - Wymiar operowanej macierzy typu liczba całkowita 
* Argumenty:
*   Strm- strumien wyjscia
*   UklRown - Uklad rownan skladajacy sie z macierzy,wektora wyrazow wolnych oraz wektora rozwiazania
* Zwraca:
*   Strumien wyjscia
*/
template <typename STyp, int SWymiar>
std::ostream &operator<<(std::ostream &Strm, const SUkladRownanLiniowych<STyp,SWymiar> &UklRown)
{
  Strm<<UklRown.Get_macierz();
  Strm<<UklRown.Get_wektor();
  return Strm;
}
#endif
