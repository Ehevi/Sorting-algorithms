#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j], arr[j+1]);
        }
    }
}

int main() //Program g³ówny//
{
  int i;
  int size;
  cout<<"BUBBLE SORT (zamiana)\n"; 
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

  bubbleSort(t, size);
  
// Wynik sortowania

  cout<<"Po sortowaniu:\n\n";
  for(i=0; i<size; i++) cout<<setw(4)<<t[i];
  cout<<endl;
  return 0;
}
