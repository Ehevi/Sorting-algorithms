#include <iostream>
#include <iomanip>
#include <time.h.>
#include <cstdlib>
using namespace std;

void countingSort(int a[], int n, int k)
{
    int b[n]; int c[k]; int i;
    for(i=0; i<k; i++) c[i]=0; //przygotowanie tablicy c
    for(i=0; i<n; i++) c[a[i]]++; //zliczanie, ile jest elementow o i-tym kluczu
    for(i=1; i<k; i++) c[i]+=c[i-1]; //ile jest elementow mniejszych od danego
    for(i=n-1; i>=0; i--) b[--c[a[i]]]=a[i]; //umiejscowienie na wlasciwym miejscu w tablicy b
    for(i=0; i<n; i++) a[i]=b[i]; //przepisanie wyniku do tablicy a
}

int main() //Program glowny//
{
  int i, n, k;
  cout<<"COUNTINGSORT\n"; 
  cout<<"Rozmiar tablicy: ";
  cin>>n;
  int t[n];
  cout<<"Zakres kluczy: ";
  cin>>k;
  cout<<"(od 0 do "<<k-1<<")"<<endl;
    cout<<"Tablica przed sortowaniem:\n\n";

// Wypelniam tablice t[] liczbami pseudolosowymi i wyswietlam jej zawartosc

  srand((unsigned)time(NULL));

  for(i=0; i<n; i++) t[i]=rand()%k; //liczba pseudolosowa z zakresu 0-k//
  for(i=0; i<n; i++) cout<<setw(4)<<t[i];
  cout<<endl;

// Sortowanie

  countingSort(t, n, k);
  
// Wynik sortowania

  cout<<"Po sortowaniu:\n\n";
  for(i=0; i<n; i++) cout<<setw(4)<<t[i];
  cout<<endl;
  return 0;
}
