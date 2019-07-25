#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 10; // Liczebnoœæ zbioru.
int d[N],p[N];

// Procedura sortuj¹ca
//--------------------

void MergeSort(int left, int right)
{
  int i;
  int middle=(left+right+1)/2;
  if(middle-left>1) MergeSort(left, middle-1);
  if(right-middle>0) MergeSort(middle, right);
  
  int i1=left; int i2=middle;
  for(i=left; i<=right; i++)
    {
    	if((i1==middle)||((i2<=right)&&(d[i1]>d[i2])))
    	{
			p[i]=d[i2];
			i2++;
		}
		else
		{
			p[i]=d[i1];
			i1++;
		}
	}
  for(i=left;i<=right; i++)
	{
  		d[i]=p[i];
	}
}

// Program g³ówny
//---------------

int main()
{
  int i;
  
  cout << " Sortowanie przez scalanie\n"
          "Przed sortowaniem:\n\n";

// Najpierw wype³niamy tablicê d[] liczbami pseudolosowymi
// a nastêpnie wyœwietlamy jej zawartoœæ

  srand((unsigned)time(NULL));

  for(i = 0; i < N; i++) d[i] = rand() % 100;
  for(i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;

// Sortujemy

  MergeSort(0,N-1);
  
// Wyœwietlamy wynik sortowania

  cout << "Po sortowaniu:\n\n";
  for(i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;
  return 0;
}
