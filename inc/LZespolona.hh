#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>


struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  public:
  LZespolona(){
    this->re=0; this->im=0;
  }
  LZespolona &operator = (double  Liczba);  
  
};

bool operator == (LZespolona Arg1,int i);
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Mnozna,  double  Mnoznik_Liczba);
LZespolona operator/(LZespolona Skl1, LZespolona Skl2);
LZespolona operator*(LZespolona Skl1, LZespolona Skl2);


std::ostream &operator << (std::ostream &StrmWyj, LZespolona  Zesp);
std::istream &operator>>(std::istream &StrWe, LZespolona &Lz);

#endif
