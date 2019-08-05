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

void quickSort(int arr[], int left, int right)
{
    if(left<right)
    {
        int x=partition(arr, left, right);
        quickSort(arr, left, x);
        quickSort(arr, x+1, right);
    }
}

int main() //Program g³ówny//
{
  int i;
  int size;
  cout<<"QUICKSORT\n"; 
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

  quickSort(t, 0, size-1);
  
// Wynik sortowania

  cout<<"Po sortowaniu:\n\n";
  for(i=0; i<size; i++) cout<<setw(4)<<t[i];
  cout<<endl;
  return 0;
}
