#include <iostream>
#include <iomanip>
#include <time.h.>
#include <cstdlib>
using namespace std;

int partition(int arr[], int left, int right)
{
    int x=arr[left]; //element dzielacy
    int i=left-1;
    int j=right+1;
    while(true)
    {
        do {i++;} while(arr[i]<x);
        do {j--;} while(arr[j]>x); //wyszukiwanie elementow do zamiany
        if(i<j) swap(arr[i], arr[j]);
        else return j; //zwraca indeks elementu dzielacego
    }
}

void qSort(int arr[], int left, int right)
{
    if(left<right)
    {
        int x=partition(arr, left, right);
        qSort(arr, left, x);
        qSort(arr, x+1, right);
    }
}

bool binSearch(int arr[], int value, int n)
{
    int left=0;
    int right=n-1;
    int m=(n-1)/2;
    while(left<right&&(arr[m]!=value))
    {
        m=(left+right)/2;
        if(arr[m]<value) left=m+1;
        else right=m;
    }
    return arr[m]==value;
}

int main() //Program g³ówny//
{
  int i;
  int size;
  cout<<"Rozmiar tablicy: ";
  cin>>size;
  int t[size];
cout<<"Tablica przed sortowaniem:\n\n";

// Wype³niam tablicê t[] liczbami pseudolosowymi i wyœwietlam jej zawartoœæ

  srand((unsigned)time(NULL));

  for(i=0; i<size; i++) t[i]=rand()%100; //liczba pseudolosowa z zakresu 0-100//
  for(i=0; i<size; i++) cout<<setw(4)<<t[i];
  cout<<endl;

// Sortowanie

  qSort(t, 0, size-1);
  
// Wynik sortowania

  cout<<"Po sortowaniu:\n\n";
  for(i=0; i<size; i++) cout<<setw(4)<<t[i];
  cout<<endl;

  cout<<"Szukana wartosc: ";
  int toBeFound;
  cin>>toBeFound;
  if(binSearch(t, toBeFound, size)) cout<<"TAK";
  else cout<<"NIE";
  return 0;
}
