#include <iostream>
#include <iomanip>
#include <time.h.>
#include <cstdlib>
using namespace std;

struct node
{
    float value;
    node* next;
};

void insert(float number, node* &first) //wstawianie do listy posortowanej
{
    if(first==NULL) //jezeli lista jest pusta
    {
        first=new node;
        first->value=number;
        first->next=NULL;
    }
    else //jezeli w kubelku juz cos jest
    {
        node* add=new node;
        add->value=number;
        if(first->value>number) //wstawianie na poczatek listy
        {
            add->next=first;
            first=add;
        }
        else //wstawianie do srodka listy
        {
            node* ptr=first;
            while(ptr->next!=NULL && ptr->next->value<number) ptr=ptr->next;
            add->next=ptr->next;
            ptr->next=add;
        }
    }
}

float getFromBuckets(node** buckets, int &whichBucket)
{
    while(buckets[whichBucket]==NULL) whichBucket++;
    node* ptr=buckets[whichBucket];
    float toReturn=ptr->value;
    buckets[whichBucket]=ptr->next;
    delete ptr;
    return toReturn;
}

void bucketSort(float* arr, int n)
{
    int i, j;
    node **buckets=new node*[n];//tablica list(kubelkow)
    for (i=0; i<n; i++) buckets[i]=NULL; //ustawienie poczatkowe list
    for(i=0; i<n; i++)
    {
        insert(arr[i], buckets[(int)(n*arr[i])]); //rozrzucenie po kubelkach
    }
    int whichBucket=0;
    for(i=0; i<n; i++)
    {
        arr[i]=getFromBuckets(buckets, whichBucket); //przepisanie z kubelkow do tablicy
    }

    delete [] buckets; //wyczyszczenie pamieci
}

int main() //Program g³ówny//
{
  int i, n;
  cout<<"BUCKETSORT"<<endl;
  cout<<"Rozmiar tablicy (ile liczb do posortowania): ";
  cin>>n;
  float *arr=new float[n]; //tablica do przechowywania danych
  cout<<"Tablica przed posortowaniem:\n";

// Wype³niam tablicê arr[] liczbami pseudolosowymi z zakresu [0; 1) i wyœwietlam jej zawartoœæ

  srand((unsigned)time(NULL));

  for(i=0; i<n; i++)
  {
    arr[i]=(rand())/(RAND_MAX+1.0);
  }

    //Wyœwietlenie zawartosci tablicy
    for(i=0; i<n; i++)
    {
        cout<<setprecision(5)<<arr[i];
        cout<<"     ";
    }

    //Sortowanie

    bucketSort(arr, n);

    //Wyswietlenie zawartosci tablicy po posortowaniu
    cout<<endl<<"Tablica po posortowaniu:\n";
    for(i=0; i<n; i++)
    {
        cout<<setprecision(5)<<arr[i];
        cout<<"     ";
    }

  delete [] arr; //zwolnienie pamiêci
  return 0;
}
