#include <iostream>
#include <cmath>
#include "LZespolona.hh"

using namespace std;


/*!
 * Podstawia do liczby zespolonej liczbę rzeczywistą.
 * Powoduje to, że w części urojonej zostanie automatycznie podstawiona
 * wartość 0.
 */
LZespolona &LZespolona:: operator = (double  Liczba)
{

  this->re = Liczba; this->im = 0;
  return *this;
}


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}



/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Odjemna  - pierwszy argument operacji odejmownia,
 *    Odjemnik - drugi argument operacji odejmowania.
 * Zwraca:
 *    Różnica dwoch argumentów przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Odjemna,  LZespolona  Odjemnik)
{
  LZespolona  Wynik;

  Wynik.re = Odjemna.re - Odjemnik.re;
  Wynik.im = Odjemna.im - Odjemnik.im;
  return Wynik;
}

LZespolona Sprzezenie(LZespolona Skl1)
{
  LZespolona  Wynik;
  Wynik.re = Skl1.re;
  Wynik.im = Skl1.im*(-1);
  return Wynik;
}

double Modul2(LZespolona Skl1)
{
  double  Wynik;
  Wynik = pow (sqrt( pow(Skl1.re,2) + pow(Skl1.im,2) ),2);
  return Wynik;
 
}

LZespolona operator / (LZespolona  Skl1,  double Liczba)
{ 
  LZespolona  Wynik;
  Wynik.re = Skl1.re / Liczba;
  Wynik.im = Skl1.im / Liczba;
  return Wynik;
}



LZespolona operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  LZespolona  Licznik;
  double  Mianownik;
  Licznik = (operator * (Skl1,Sprzezenie(Skl2)));
  Mianownik =  Modul2(Skl2);
  Wynik = operator / (Licznik,Mianownik);
  return Wynik;
}
/*!
 * Realizuje wczytanie liczby zespolonej.
 * Argumenty:
 *    StrWe - strumien wejscia,
 *    &Lz - Struktura danych typi Liczba zespolona przechowująca część rzeczywistą i urojoną liczby zespolonej.
 * Zwraca:
 *  Strumien wejscia.
 */
std::istream &operator>>(std::istream &StrWe, LZespolona &Lz)
{
  char LewyNawias,PrawyNawias,CzescUrojona;
  StrWe >> LewyNawias;
  StrWe >> Lz.re;
  StrWe >> Lz.im;
  StrWe >> CzescUrojona;
  StrWe >> PrawyNawias;
  //printf("Lz.re: %f, Lz.im: %f, LewyNawias: %c,PrawyNawias: %c,Czesc Urojona:%c",Lz.re,Lz.im,LewyNawias,PrawyNawias,CzescUrojona);
  if (LewyNawias!='(' || PrawyNawias!=')' || CzescUrojona!='i')
  {
    StrWe.setstate(std::istream::badbit);
  }
  return StrWe;
}

/*!
 * Realizuje mnozenie liczby zespolonej przez liczbę rzeczywistą (typ double)
 * Argumenty:
 *    Mnozna         - pierwszy argument operacji mnozenia (liczba zespolona),
 *    Mnoznik_Liczba - drugi argument operacji mnozenia (liczba rzeczywista).
 * Zwraca:
 *    Iloczyn dwoch argumentów przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Mnozna,  double  Mnoznik_Liczba)
{
  LZespolona  Wynik;

  Wynik.re = Mnozna.re * Mnoznik_Liczba;
  Wynik.im = Mnozna.im * Mnoznik_Liczba;
  return Wynik;
}
/*!
 * Realizuje mnozenie liczby zespolonej przez liczbe zespolona
 * Argumenty:
 *    Skl1 - pierwszy argument operacji mnozenia (liczba zespolona),
 *    Skl2 - drugi argument operacji mnozenia (liczba zespolona).
 * Zwraca:
 *    Iloczyn dwoch argumentów przekazanych jako parametry.
 */
LZespolona operator*(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

/*!
 * Umożliwia wyświetlenie liczby zespolonej w formacie:
 *             (4.5+5.6i)
 * Parametry:
 *    StrmWyj - strumień wyjściowy, do którego ma być wpisany napis
 *              reprezentujący liczbę zespoloną,
 *       Zesp - liczba zespolona, której wartość ma być zapisana w postaci
 *              znakowej w danym strumieniu.
 * Zwraca: Strumień wyjściowy przekazany jako pierwszy parametr.
 */
ostream &operator << (ostream &StrmWyj, LZespolona  Zesp)
{
  return StrmWyj << '(' << Zesp.re << showpos << Zesp.im << "i)" << noshowpos;
}

bool operator == (LZespolona Arg1,int i)
{
  if (Arg1.re == i && Arg1.im == i) return true;
  else return false;
}
