#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;

void heapify (int arr[], int i, int size) //i: indeks zaburzonego elementu//
{
    int l=2*i; //left//
    int r=2*i+1; //right//
    int largest;
    if(l<size&&arr[l]>arr[i]) largest=l;
    else largest=i;
    if(r<size&&arr[r]>arr[largest]) largest=r;
    if(i!=largest)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, size);
    }
}

void buildHeap(int arr[], int size)
{
    for(int i=size/2; i>0; i--)
    {heapify(arr, i, size);}
}

void heapSort(int arr[], int size)
{
    buildHeap(arr, size);
    for(int i=size-1; i>1; i--)
    {
        swap(arr[i], arr[1]);
        size--;
        heapify(arr, 1, size);
    }
}

int main() //Program g³ówny//
{
  int i;
  int size;
  cout<<"HEAPSORT\n"; 
  cout<<"Rozmiar tablicy: ";
  cin>>size;
  int t[size+1];
cout<<"Tablica przed sortowaniem:\n\n";

// Wype³niam tablicê t[] liczbami pseudolosowymi i wyœwietlam jej zawartoœæ

  srand((unsigned)time(NULL));

  for(i=1; i<=size; i++) t[i]=rand()%100; //liczba pseudolosowa z zakresu 0-100//
  for(i=1; i<=size; i++) cout<<setw(4)<<t[i];
  cout<<endl;

// Sortowanie

  heapSort(t, size+1);
  
// Wynik sortowania

  cout<<"Po sortowaniu:\n\n";
  for(i=1; i<=size; i++) cout<<setw(4)<<t[i];
  cout<<endl;
  return 0;
}
