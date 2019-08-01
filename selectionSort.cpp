#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;

int findLargest(int arr[], int end)
{
    int start=0;
    int largest=arr[start];
    int lIndex=start;
    while(start<=end)
    {
        if(arr[start]>largest)
        {
            largest=arr[start];
            lIndex=start;
        }
        start++;
    }
    return lIndex;
}

void selectionSort(int arr[], int n)
{
    int i=n-1;
    while(i>0)
    {
        swap(arr[i], arr[findLargest(arr, i)]);
        i--;
    }
}

int main() //Program g³ówny//
{
  int i;
  int size;
  cout<<"SELECTION SORT (wybor)\n"; 
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

  selectionSort(t, size);
  
// Wynik sortowania

  cout<<"Po sortowaniu:\n\n";
  for(i=0; i<size; i++) cout<<setw(4)<<t[i];
  cout<<endl;
  return 0;
}
