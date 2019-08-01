#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, j, value;
    for(i=1; i<n; i++)
    {
        value=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>value)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=value;
    }
}

int main() //Program g³ówny//
{
  int i;
  int size;
  cout<<"INSERTION SORT (wstawianie)\n"; 
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

  insertionSort(t, size);
  
// Wynik sortowania

  cout<<"Po sortowaniu:\n\n";
  for(i=0; i<size; i++) cout<<setw(4)<<t[i];
  cout<<endl;
  return 0;
}
