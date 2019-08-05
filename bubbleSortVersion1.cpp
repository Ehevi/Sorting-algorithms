#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i;
    while(n>0)
    {
        for(i=0; i<n-1; i++)
        {
            if(arr[i]>arr[i+1])
            swap(arr[i], arr[i+1]);
        }
        n--;
    }
}

int main() //Program główny//
{
  int i;
  int size;
  cout<<"BUBBLE SORT (zamiana)\n"; 
  cout<<"Rozmiar tablicy: ";
  cin>>size;
  int t[size];
cout<<"Tablica przed sortowaniem:\n\n";

// Wypełniam tablicę t[] liczbami pseudolosowymi i wyświetlam jej zawartość

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
