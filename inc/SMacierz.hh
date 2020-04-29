#ifndef SMACIERZ_HH
#define SMACIERZ_HH
#include <iostream>
#include "SWektor.hh"
#include "rozmiar.h"
#include "LZespolona.hh"
#include <cmath>




template <typename STyp, int SWymiar>
class SMacierz {

    SWektor<STyp,SWymiar>  kolumna[SWymiar];
  public:
    SMacierz();
    SWektor<STyp,SWymiar>  operator [] (unsigned int Ind) const { return kolumna[Ind]; }
    SWektor<STyp,SWymiar> &operator [] (unsigned int Ind)       { return kolumna[Ind]; }
    SWektor<STyp,SWymiar> operator - (const SMacierz<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator*(SWektor<STyp,SWymiar> B)const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
    SMacierz PodstawKolumne(SWektor <STyp,SWymiar> B, int n)const;
    STyp wyznacznik () const;
    SMacierz transpozycja();
};
template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar>::SMacierz()
{
    SWektor<STyp,SWymiar> z[ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j=0;j<ROZMIAR;j++)
        {
            z[i][j]=0;
        }
        kolumna[i]=z[i];
    }
}
template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::PodstawKolumne (SWektor<STyp,SWymiar> B, int n) const
{
    SMacierz<STyp,SWymiar> C;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
           C[i][j]=this->kolumna[i][j];
        }
    }
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
           if(j==n)
           {
               C[i][j]=B[i]; 
           }
        }
    }
    return C;
}
template <typename STyp, int SWymiar>
  STyp SMacierz<STyp,SWymiar>::wyznacznik () const
  {
    STyp det;
    SMacierz A;
    for (int i = 0; i < ROZMIAR ; i++)

        for (int j = 0; j < ROZMIAR; j++)
        {
            A[i][j]=this->kolumna[i][j];
        }
    for (int i = 0; i < ROZMIAR - 1; i++)

        for (int j = i + 1; j < ROZMIAR; j++)

            for (int k = i + 1; k < ROZMIAR; k++)

                A[j][k] = A[j][i] / A[i][i] * A[i][k] -A[j][k];
    
    det=A[1][1];
    for (int i = 0; i < ROZMIAR-1; i++)
        det = A[i+1][i+1]* det;
    if (det ==0)
    {
    std::cerr<<"Wyznacznik macierzy równy 0. Brak rozwiązań rzeczywistych.";
       exit(0);
    }
    return det; 
  }
  
/*template <>
  double SMacierz<double,SWymiar>::wyznacznik () const
  {
    double det;
    SMacierz A;
    for (int i = 0; i < ROZMIAR ; i++)

        for (int j = 0; j < ROZMIAR; j++)
        {
            A[i][j]=this->kolumna[i][j];
        }
    for (int i = 0; i < ROZMIAR - 1; i++)

        for (int j = i + 1; j < ROZMIAR; j++)

            for (int k = i + 1; k < ROZMIAR; k++)

                A[j][k] = A[j][i] / A[i][i] * A[i][k] -A[j][k];
    
    for (int i = 0; i < ROZMIAR; i++)
        det = A[i][i]* det;
    if (det ==0)
    {
    std::cerr<<"Wyznacznik macierzy równy 0. Brak rozwiązań rzeczywistych.";
       exit(0);
    }
    return det; 
  }
*/
  
template <typename STyp, int SWymiar>

SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::transpozycja() 
{
    SMacierz<STyp,SWymiar> B;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            B[i][j]=this->kolumna[j][i];

        }
    }
    return B;
}
template <typename STyp, int SWymiar>

 SWektor<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator*(SWektor<STyp,SWymiar> B) const
{
    SWektor<STyp,SWymiar> C;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
           C[i]=C[i]+B[j]*this->kolumna[i][j];
        }
    }
    return C;
}
template <typename STyp, int SWymiar>
std::istream &operator>>(std::istream &StrWe, SMacierz<STyp,SWymiar> &A)
{
    SWektor<STyp,SWymiar> z;
    for (int i = 0; i < SWymiar; ++i)
    {
            StrWe>>z;
            A[i]=z;

    }
    return StrWe;
}
template <typename STyp, int SWymiar>
std::ostream &operator<<(std::ostream &StrWy, const SMacierz<STyp,SWymiar> &Mac)
{
     for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            StrWy << Mac[i][j] << " ";
        }
        StrWy << std::endl;
    }
    return StrWy;
}


















#endif
