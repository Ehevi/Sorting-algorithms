#include <iostream>
#include <iomanip>
#include <time.h.>
#include <cstdlib>
using namespace std;

struct point
{
    int x;
    int y;
};

void printPoints(point** array, int n)
{
    int i, j, k;
    bool found;
    for(i=0; i<15; i++)
    {
        for(j=14; j>=0; j--)
        {
            k=0;
            found=false;
            while(k<n && !found)
            {
                if((array[k]->x)==14-j && (array[k]->y)==14-i) found=true;
                k++;
            }
            if(found) cout<<setw(3)<<k-1;
            else cout<<setw(3)<<".";
        }
        cout<<endl;
    }
}

void findDominant(point** array, bool* dominatingPoints, int n)
{
    bool isDominated;
    int j;
    for(int i=0; i<n; i++)
    {
        isDominated=false;
        j=0;
        while(j<n && !isDominated)
        {
            if(i!=j && (array[i]->x)<(array[j]->x) && (array[i]->y)<(array[j]->y))
            {isDominated=true;}
            j++;
        }
        if(isDominated) dominatingPoints[i]=false;
        else dominatingPoints[i]=true;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int n, value;
    cout<<"Liczba punktow: ";
    cin>>n;
    cout<<endl;
    point** array=new point*[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Punkt "<<setw(2)<<i<<": x=";
        array[i]=new point;
        value=rand()%15;
        array[i]->x=value;
        cout<<setw(2)<<array[i]->x<<",    ";
        value=rand()%15;
        array[i]->y=value;
        cout<<"y="<<setw(2)<<array[i]->y<<endl;
    }
    cout<<endl<<"Dane punkty: "<<endl;
    printPoints(array, n);
    bool* dominatingPoints=new bool[n];
    findDominant(array, dominatingPoints, n);
    cout<<endl<<"Punkty dominujace zbior: ";
    for(int i=0; i<n; i++)
    {
        if(dominatingPoints[i]) cout<<setw(3)<<i;
    }
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        delete [] array[i];
    }
    delete array;
    delete dominatingPoints;
    return 0;
}
