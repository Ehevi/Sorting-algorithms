#include <iostream>
#include <iomanip>
#include <time.h.>
#include <cstdlib>
using namespace std;

char ConversionIntToChar(int b)
{
    char a;
    a=(b%10)+48;
    return a;
}

int digit(char* number, int position)
{//wyluskanie cyfry znajdujacej sie na danej pozycji
  return (int)(number[position]-'0');
}

void countingSortByPos(char **arr, int n, int pos)
{//sortowanie wg kolejnych cyfr liczby
    int k=10; //zakres kluczy: cyfry
    char **b=new char*[n];
    int *c=new int[k];
    int i, j;
    for(i=0; i<k; i++) c[i]=0; //przygotowanie tablicy c
    for(i=0; i<n; i++) c[digit(arr[i], pos)]++; //zliczanie, ile jest elementow o i-tym kluczu
    for(i=1; i<k; i++) c[i]+=c[i-1]; //ile jest elementow mniejszych od danego
    for(i=n-1; i>=0; i--) //odliczanie indeksow od konca, aby algorytm pozostal stabilny
    b[--c[digit(arr[i], pos)]]=arr[i]; //umiejscowienie na wlasciwym miejscu w tablicy b
    //na poczatku zmniejszam wartosci tablicy c, bo indeksowanie zaczyna sie od 0
    //tzn. pierwszy element ma indeks 0 itd.
    for(i=0; i<n; i++) arr[i]=b[i]; //przepisanie wyniku do tablicy arr
    delete [] b;
    delete [] c;
}

void radixSort(char** arr, int n, int length)
{
  int i;
  for(i=length-1; i>=0; i--)//sortowanie stabilne wedlug najmniej znaczacej cyfry
  {
    countingSortByPos(arr, n, i);
  }
}

int main() //Program g³ówny//
{
  int i, j, n, length, temp;
  cout<<"RADIXSORT"<<endl;
  cout<<"Rozmiar tablicy (ile liczb do posortowania): ";
  cin>>n;
  char **arr=new char*[n]; //calosc danych w dwuwymiarowej tablicy znakow
  cout<<"Dlugosc liczb do posortowania: ";
  cin>>length; //d³ugoœc liczb do posortowania
  for(i=0; i<n; i++) arr[i]=new char[length]; //pojedyncza liczba to tablica znakow(cyfr)

  cout<<"Tablica przed posortowaniem:\n";

// Wype³niam tablicê arr[][] liczbami pseudolosowymi i wyœwietlam jej zawartoœæ

  srand((unsigned)time(NULL));

  for(i=0; i<n; i++)
  {
    temp=rand()%9+1; //zeby pierwsza cyfra nie byla zerem
    arr[i][0]=ConversionIntToChar(temp);
    for(j=1; j<length; j++)
    {
        temp=rand()%10; //cyfra na pozycje 'j' i-tej liczby
        arr[i][j]=ConversionIntToChar(temp);
    }
  }

    //Wyœwietlenie zawartosci tablicy
    for(i=0; i<n; i++)
    {
        for(j=0; j<length; j++) cout<<arr[i][j];
        cout<<"     ";
    }

    //Sortowanie

    radixSort(arr, n, length);

    //Wyswietlenie zawartosci tablicy po posortowaniu
    cout<<endl<<"Tablica po posortowaniu:\n";
    for(i=0; i<n; i++)
    {
        for(j=0; j<length; j++) cout<<arr[i][j];
        cout<<"     ";
    }

  for(i=0; i<n; i++) delete [] arr[i];
  delete [] arr; //zwolnienie pamiêci
  return 0;
}
