#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 5; // Liczebnoœæ zbioru.
int d[N],p[N];

int merge(int left, int middle, int right) //inwersje podczas scalania dwóch posortowanych tablic//
{
	int inversions=0; int i;
	int i1=left; //indeks do przechodzenia po lewej czêœci tablicy
	int i2=middle; //indeks do przechodzenia po prawej czêœci tablicy
	for(i=left; i<=right; i++)
	{
		if(i1==middle)
		{
			p[i]=d[i2]; i2++;
		}
		if((i2<=right)&&(d[i1]>d[i2]))
		{
			p[i]=d[i2]; i2++; inversions++;
		}
		if((i1!=middle)&&(i2!=right)&&(d[i1]<d[i2]))
		{
			p[i]=d[i1]; i1++;
		}
	}
	for(i=left;i<=right; i++)
	{
	d[i]=p[i];
	}
	return inversions;
}

int MSnC(int left, int right)
{
  int counter=0;
  if(right>left)
  {
	int i;
  	int middle=(left+right+1)/2;
  	counter+=MSnC(left, middle-1);
  	counter+=MSnC(middle, right);
  	counter+=merge(left, middle, right);
  }
  return counter;
}
    
// Program g³ówny
//---------------

int main()
{
  int i;
  cout << "Tablica: ";

// Najpierw wype³niamy tablicê d[] liczbami pseudolosowymi
// a nastêpnie wyœwietlamy jej zawartoœæ

  srand((unsigned)time(NULL));

  for(i = 0; i < N; i++) d[i] = rand() % 100;
  for(i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;
  cout<<"inwersje: "<<MSnC(0, N-1);
  cout<<endl<<"Po posortowaniu: "<<endl;
  for(i=0;i<N;i++) cout<<setw(4)<<d[i];
  cout<<endl;
  return 0;
}
