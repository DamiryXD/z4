#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include "SWektor.hh"
#include "SMacierz.hh"
#include "rozmiar.h"


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

template <typename STyp, int SWymiar>
  void SUkladRownanLiniowych<STyp,SWymiar>::WyliczBladRozwiazania ()
  {
        std::cout<<"Wektor bledu:"<<std::endl;
        SWektor<STyp,SWymiar> blad= A*this->Rozwiazanie - B;
        std::cout.setf(std::ios::showpoint);
        std::cout<< blad;
        std::cout.setf(std::ios::showpoint);
  }
template <typename STyp, int SWymiar>
std::istream &operator>>(std::istream &Strm, SUkladRownanLiniowych<STyp,SWymiar> &UklRown)
{
  Strm>>UklRown.Get_macierz();
  Strm>>UklRown.Get_wektor();
  return Strm;
}
template <typename STyp, int SWymiar>
std::ostream &operator<<(std::ostream &Strm, const SUkladRownanLiniowych<STyp,SWymiar> &UklRown)
{
  Strm<<UklRown.Get_macierz();
  Strm<<UklRown.Get_wektor();
  return Strm;
}
#endif
