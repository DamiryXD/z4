#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>



template <typename STyp, int SWymiar>
class SWektor {
    STyp  _Wsp[SWymiar];
  public:
    SWektor() { for (STyp &Wsp: _Wsp) Wsp = 0; }
  
    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }

    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
};




template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}


template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << " " << W[Ind];
  }  
  return StrmWyj;
}
template <typename STyp, int SWymiar>
std::istream &operator>>(std::istream &StrWe, SWektor<STyp,SWymiar> &Arg1)
{
    for (int i = 0; i < SWymiar; i++)
    {
        StrWe >> Arg1[i];

    }
    return StrWe;
}


#endif
