#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>


struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  LZespolona(){
    this->re=0; this->im=0;
  }
  LZespolona &operator = (double  Liczba); 
};

LZespolona Sprzezenie(LZespolona Skl1);
double Modul2(LZespolona Skl1);
LZespolona operator / (LZespolona  Skl1,  double Liczba);
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Mnozna,  double  Mnoznik_Liczba);
LZespolona operator/(LZespolona Skl1, LZespolona Skl2);
LZespolona operator*(LZespolona Skl1, LZespolona Skl2);
bool operator == (LZespolona Arg1,int i);

std::ostream &operator << (std::ostream &StrmWyj, LZespolona  Zesp);
std::istream &operator>>(std::istream &StrWe, LZespolona &Lz);

#endif
