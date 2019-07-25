#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

void merge(int t[], int left, int middle, int right)
{
    int p[right+1]; //tablica pomocnicza//
    int i;
    int a=left; int b=middle;
    for(i=left; i<=right; i++)
    {
        if((a==middle)||((b<=right)&&(t[a]>t[b])))
        {
            p[i]=t[b]; b++;
        }
        else
        {
            p[i]=t[a]; a++;
        }
    }
    for(i=left; i<=right; i++)
    {
        t[i]=p[i];
    }
}

void mergeSort(int t[], int left, int right)
{
    int middle=(left+right+1)/2;
    if(middle-left>1) mergeSort(t, left, middle-1);
    if(right-middle>0) mergeSort(t, middle, right);
    merge(t, left, middle, right);
}

int main() //Program g³ówny//
{
  int i;
  int N;
  cout<<"Sortowanie przez scalanie\n"; 
  cout<<"Rozmiar tablicy: ";
  cin>>N;
  int t[N];
    cout<<"Tablica przed sortowaniem:\n\n";

// Wype³niam tablicê d[] liczbami pseudolosowymi i wyœwietlam jej zawartoœæ

  srand((unsigned)time(NULL));

  for(i=0; i<N; i++) t[i]=rand()%100; //liczba pseudolosowa z zakresu 0-100//
  for(i=0; i<N; i++) cout<<setw(4)<<t[i];
  cout<<endl;

// Sortowanie

  mergeSort(t, 0,N-1);
  
// Wynik sortowania

  cout<<"Po sortowaniu:\n\n";
  for(i=0; i<N; i++) cout<<setw(4)<<t[i];
  cout<<endl;
  return 0;
}
