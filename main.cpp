#include <iostream>
#include<fstream>
#include<string.h>
#include<ctime>
using namespace std;

ifstream f("date.in");
int v[100], n, t;

void RandomVector()
{
    int maxi,i;
    //cout<<" numar teste : "; cin>>t;
    //cout<<endl;
    cout<<" lungime vector : "; f>>n; cout <<n;
    cout<<endl;
    cout<<" valoare maxima : "; f>>maxi;cout<< maxi;
    cout<<endl;

    for (i = 1; i<= n; i++)
        v[i] = rand()% maxi;
}

/*void citire_vector(int v[], int &n)
{
    int i;
    f>>n;
        f>>v[i];
}*/

void AfisareVector(int v[], int n)
{
    int i;
    for(i=1; i<=n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void BubbleSort (int v[],int n)
{
    int i, sortat = 0, aux;
    while(sortat == 0)
    {
        sortat = 1;
        for (i = 1;i < n ;i++)
            if(v[i] > v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                sortat = 0;
            }
    }
}

void CountSort (int v[], int n)
{
    int maxi, i;
    maxi = 0;

    for (i = 1; i<=n; i++)
        if(v[i] > maxi)
        maxi = v[i];

    int ap[maxi + 1] = {0};

    for(i=1; i<=n ;i++)
        ap[v[i]] ++;

    for(i=0; i <= maxi; i++)
        while(ap[i]--)
            cout<<i<<" ";
    cout<<endl;


    //for(i =1;i<=n;i++)
      //  v[i] = afisare[i];
}

void Sortare (int x[20],int st, int dr)
{
    int aux;
    if (x[st] > x[dr])
    {
        aux = x[st];
        x[st] = x[dr];
        x[dr] = aux;
    }
}
void Merge(int v[], int st, int mij, int dr)
{
    int a[dr - st +1];
    int i = st, j = mij + 1, k = 1;

    while(i <= mij && j <= dr)
        if (v[i] <= v[j])
        {
            a[k] = v[i] ;i++;k++;
        }
        else
        {
            a[k] = v[j];j++;k++;
        }

    if(i <= mij)
        for(j=i; j <= mij; j++)
        {
            a[k] = v[j]; k++;
        }
    else
        for(i=j; i<= dr; i++)
        {
            a[k] = v[i];k++;
        }

    k = 1;

    for(i = st; i<=dr;i++)
    {
        v[i] = a[k];k++;
    }
}


void MergeSort(int v[], int st, int dr)
{
    int mij;
    if((dr-st) <= 1)
        Sortare(v,st,dr);
    else
    {
        mij = (st+dr)/2;
        MergeSort(v,st,mij);
        MergeSort(v,mij+1,dr);
        Merge(v,st,mij,dr);
    }
}

int QuickSort (int v[], int st, int dr)
{
    if (st < dr)
    {
        int mij = (st + dr) /2;
        int aux = v[st];
        v[st] = v[mij];
        v[mij] = aux;

        int i = st, j = dr, d = 0;

        while(i < j)
        {
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        QuickSort(v, st, i -1);
        QuickSort(v, i+1, dr);
    }
}

int Maxim (int v[], int n)
{
    int maxim = v[0],i;
    for(i=1;i<=n;i++)
        if(v[i] > maxim)
        maxim = v[i];
    return maxim;
}

void Count(int v[], int n, int e)
{
    int o[n], i, c[10] = {0};

    for(i=1;i<=n;i++)
        c[(v[i] / e) % 10] ++;

    for(i = 1; i< 10; i++)
        c[i] += c[i - 1];

    for(i = n; i >= 0; i--)
    {
        o[c[(v[i] / e) % 10]] = v[i];
        c[(v[i] / e) % 10]--;
    }

    for(i = 1; i <= n; i++)
        v[i] = o[i];
}

void RadixSort (int v[], int n)
{
    int e;
    int maxi = Maxim(v,n);
    for(e=1; maxi / e > 0; e *= 10)
        Count(v,n,e);
}


int main()
{
    int i,t;
    clock_t start, stop;
    cout<<" numar teste : "; f>>t;
    cout<<endl;
    for(i =1; i <= t;i++)
    {
        RandomVector();
        AfisareVector(v,n);
        cout<<endl;
        start = clock();
        //BubbleSort(v,n);
        //CountSort(v,n);
        //RadixSort(v,n);
        //MergeSort(v,1,n);
        QuickSort(v,1,n);
        stop = clock();
        AfisareVector(v,n);
        cout<<endl;
        cout<<" timpul de exectutie : "<<double(stop - start)/CLOCKS_PER_SEC;
        cout<<endl;
}
    return 0;
}

