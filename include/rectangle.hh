#pragma once

#include "matrix.hh"
#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>

class Rectangle {

private:
    Vector wspolrzedna[SIZE*2];
public:
    Rectangle();               /*konstruktor klasy*/
    Rectangle(Vector tmp[SIZE*2]);
    friend std::ostream & operator << (std::ostream & strm, const Rectangle &prostokat);
    void rotacja(Matrix mamcierz);
    void translacja(Vector tmp);
    void sprawdz_dlugosc();
};

/******************************************************************************
 |  Konstruktor klasy Rectangle.                                              |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
Rectangle::Rectangle()
{
    for(int i=0; i<4; i++)
    {
        wspolrzedna[i]=0;
    }
}
/******************************************************************************
 |  Konstruktor klasy Rectangle.                                              |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */

Rectangle::Rectangle(Vector tmp[SIZE*2])
{
    for(int i=0; i<4; i++)
    {
        wspolrzedna[i]=tmp[i];
    }
}
std::ostream & operator << (std::ostream & strm, const Rectangle &prostokat)           
{
    strm << prostokat.wspolrzedna[0][0] << " " << prostokat.wspolrzedna[0][1] << std::endl;      /*poprawne zczytywanie wspolrzednych z macierzy*/
    strm << prostokat.wspolrzedna[1][0] << " " << prostokat.wspolrzedna[1][1] << std::endl;
    strm << prostokat.wspolrzedna[2][0] << " " << prostokat.wspolrzedna[2][1] << std::endl;
    strm << prostokat.wspolrzedna[3][0] << " " << prostokat.wspolrzedna[3][1] << std::endl;
    strm << prostokat.wspolrzedna[0][0] << " " << prostokat.wspolrzedna[0][1] << std::endl;
    return strm;
}
/**********************************************************************************************************************************************************/
void Rectangle::rotacja(Matrix mamcierz)
{
    
    for(int i=0; i<SIZE*2; i++)
        {
           wspolrzedna[i]=mamcierz*wspolrzedna[i];
        }
    
}
/*********************************************************************************************************************************************************/
void Rectangle::translacja(Vector tmp)                             
{
    
    for(int i=0; i<SIZE*2; i++)
        {
           wspolrzedna[i]=tmp+wspolrzedna[i];
        }
}
/****************************************************************************************************************************************************************/
void Rectangle::sprawdz_dlugosc()         /*sprawdzanie dlugosci przeciwleglych bokow prostokata*/
{
        
        int i=0;
        if(sqrt((pow((wspolrzedna[i+1][0]-wspolrzedna[i][0]),2))+(pow((wspolrzedna[i+1][1]-wspolrzedna[i][1]),2)))==sqrt((pow((wspolrzedna[i+3][0]-wspolrzedna[i+2][0]),2))+(pow((wspolrzedna[i+3][1]-wspolrzedna[i+2][1]),2)))&&sqrt((pow((wspolrzedna[i+2][0]-wspolrzedna[i+1][0]),2))+(pow((wspolrzedna[i+2][1]-wspolrzedna[i+1][1]),2)))==sqrt((pow((wspolrzedna[i+3][0]-wspolrzedna[i][0]),2))+(pow((wspolrzedna[i+3][1]-wspolrzedna[i][1]),2))))
        {
            std::cout << "Dlugosci bokow sa zgodne" << std::endl;
        }
        else
        {
            std::cerr << "To nie jest poprawny prostokat" << std::endl;
        }
}


