#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "matrix.hh"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.


TEST_CASE("Test konstruktora bezparametrycznego dla Vector'a") {
    
    Vector wektor_bezparam;
    wektor_bezparam = Vector();

   CHECK(wektor_bezparam[0]==0);
}

TEST_CASE("Test konstruktora parametrycznego dla Vector'a") {
    
    Vector wektor_param;
    double tmp[SIZE];
    tmp[0]={21};
    tmp[1]={37};
    wektor_param = Vector(tmp);
   CHECK(wektor_param[1]==37);
}

TEST_CASE("Test dodawania dwoch wektorow") {
    
    Vector wynik, wektor, wektor2;
    wektor[0]=2; wektor[1]=1;
    wektor2[0]=3; wektor2[1]=7;
    wynik=wektor+wektor2;
   CHECK(wynik[0]==(5));
   CHECK(wynik[1]==(8));
}
TEST_CASE("Test odejmowania dwoch wektorow") {
    
    Vector wynik, wektor, wektor2;
    wektor[0]=2; wektor[1]=1;
    wektor2[0]=3; wektor2[1]=7;
    wynik=wektor-wektor2;
   CHECK(wynik[0]==(-1));
   CHECK(wynik[1]==(-6));
}
TEST_CASE("Test konstruktora bezparametrycznego dla Macierzy") {
    
    Matrix macierz_bezparam;
    macierz_bezparam = Matrix();

   CHECK(macierz_bezparam(0,0)==0);
}

TEST_CASE("Test konstruktora parametrycznego dla Macierzy") {
    
    Matrix macierz_param;
    double tmp[SIZE][SIZE];
    tmp[0][0]=37;
    tmp[0][1]={37};
    tmp[1][0]={37};
    tmp[1][1]={37};

    macierz_param = Matrix(tmp);
   CHECK(macierz_param(0,0)==37);
}

TEST_CASE("Test mnozenia macierzy przez wektor") {
    Vector wektor, wynik;
    wektor[0]=0;
    wektor[1]=0;
    Matrix macierz;
    macierz(0,0) = 2;
    macierz(0,1) = 1;
    macierz(1,0) = 3;
    macierz(1,1) = 7;

    wynik=macierz*wektor;
   CHECK(wynik[1]==0);
}