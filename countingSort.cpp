#include <iostream>
#include <iomanip>
#include <time.h.>
#include <cstdlib>
using namespace std;

void countingSort(int *arr, int n, int k)
{
    int i;
    int *b=new int[n];
    int *c=new int[k];
    for(i=0; i<k; i++) c[i]=0; //przygotowanie tablicy c
    for(i=0; i<n; i++) c[arr[i]]++; //zliczanie, ile jest elementow o i-tym kluczu
    for(i=1; i<k; i++) c[i]+=c[i-1]; //ile jest elementow mniejszych od danego
    for(i=0; i<n; i++)
    b[--c[arr[i]]]=arr[i]; //umiejscowienie na wlasciwym miejscu w tablicy b
    //na poczatku zmniejszam wartosci tablicy c, bo indeksowanie zaczyna sie od 0
    //tzn. pierwszy element ma indeks 0 ind.
    for(i=0; i<n; i++) arr[i]=b[i]; //przepisanie wyniku do tablicy a
    delete [] b;
    delete [] c;
}

int main() //Program g³ówny//
{
  int i, n, k;
  cout<<"COUNTINGSORT\n"; 
  cout<<"Rozmiar tablicy: ";
  cin>>n;
  int *t=new int[n];
  cout<<"Zakres kluczy: ";
  cin>>k;
  cout<<"(od 0 do "<<k-1<<")"<<endl;
    cout<<"Tablica przed sortowaniem:\n\n";

// Wype³niam tablicê t[] liczbami pseudolosowymi i wyœwietlam jej zawartoœæ

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
  delete [] t;
  return 0;
}
