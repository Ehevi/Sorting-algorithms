#include <iostream>
#include <iomanip>
#include <time.h.>
#include <cstdlib>
using namespace std;

int partitionHoare(int arr[], int left, int right, int chosenIndex)
{
	// wybor pivota: elementu o wczesniej wybranym indeksie
	int pivot = arr[chosenIndex];
	swap(arr[chosenIndex], arr[right]); //pivot na koniec

	// <=pivot: na lewo, >na prawo
	int pIndex = left;
	
	for (int i = left; i < right; i++)
	{
		if (arr[i] <= pivot)
		{
			swap(arr[i], arr[pIndex]);
			pIndex++; //licznik elementow <=pivot : czyli koncowy indeks pivota
		}
	}

	swap(arr[pIndex], arr[right]); //pivot wraca na swoje wlasciwe miejsce
	return pIndex; //zwracam indeks pivota w posortowanej tablicy
}

int hoare(int arr[], int left, int right, int k)
{
	if (left == right)
		return arr[left];

	// wybor pivota jako losowego indeksu z przedzialu [left, right]
	int pivotIndex = left + rand() % (right - left + 1);

  //funkcja partition, aktualizacja indeksu pivota na jego pozycje w posortowanej tablicy
	pivotIndex = partitionHoare(arr, left, right, pivotIndex);

	if (k == pivotIndex)
		return arr[k];

  if (k < pivotIndex)
		return hoare(arr, left, pivotIndex - 1, k);

		return hoare(arr, pivotIndex + 1, right, k);
}

int partition(int arr[], int left, int right)
{
    int i;
    int pivot=arr[right]; //element dzielacy
    int pIndex=left; //koncowy indeks pivota
    //podzial: mniejsze lub rowne pivotowi- przed pIndex
    for(i=left; i<right; i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
            //gdy znajde element <=pivot wrzucam go przed indeks pivota
        }
    }
    swap(arr[pIndex], arr[right]);
    //sprowadzam pivot z konca tablicy na wlasciwe miejsce
    return pIndex; //zwracam indeks pivota
}

void quickSort(int arr[], int left, int right)
{
    if(left<right)
    {
        int x=partition(arr, left, right);
        quickSort(arr, left, x-1);
        quickSort(arr, x+1, right);
    }
}

int main() //Program g³ówny//
{
  int i;
  int size;
  cout<<"HOARE (QUICKSELECT)\n"; 
  cout<<"Rozmiar tablicy: ";
  cin>>size;
  int t[size];
  int k;
  cout<<"k: ";
  cin>>k;
cout<<endl<<"Tablica przed sortowaniem:\n";

// Wypelniam tablice t[] liczbami pseudolosowymi i wyswietlam jej zawartosc

  srand((unsigned)time(NULL));

  for(i=0; i<size; i++) t[i]=rand()%100; //liczba pseudolosowa z zakresu 0-100//
  for(i=0; i<size; i++) cout<<setw(4)<<t[i];
  cout<<endl;

//hoare

cout<<"k-ty element: "<<hoare(t, 0, size-1, k-1)<<endl<<endl;

// Sortowanie

  quickSort(t, 0, size-1);
  
// Wynik sortowania

  cout<<"Po sortowaniu:\n";
  for(i=0; i<size; i++) cout<<setw(4)<<t[i];
  cout<<endl;
  cout<<"k-ty element: "<<t[k-1]<<endl;
  return 0;
}
