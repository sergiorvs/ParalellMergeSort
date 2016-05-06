#include <iostream>
#include <stdio.h>
#include <thread>
#include <stdlib.h>
#include <vector>
#include <time.h>
using  namespace std;

int a[10000];//= {10, 8, 5, 2, 3, 6, 7, 1, 4, 9,6, 7, 1, 4, 9.112,125,15984,45,45,4456,777777,45,68,78,4564,485987,78,7,7,778,544,4564,456,1,2,3,4,5,6,89,78,5,4,44,55,66,7,78,9,8,74,4,7,4,456,5655,123456789,10, 8, 5, 2, 3, 6, 7, 1, 4, 9,6, 7, 1, 4,10, 8, 5, 2, 3, 6, 7, 1, 4, 9,6, 7, 1, 4, 9.112,125,15984,45,45,4456,777777,45,68,78,4564,485987,78,7,7,778,544,4564,456,1,2,3,4,5,6,89,78,5,4,44,55,66,7,78,9,8,74,4,7,4,456,5655,123456789,10, 8, 5, 2, 3, 6, 7, 1, 4, 9,6, 7, 1, 4, 9.112,125,15984,45,45,4456,777777,45,68,78,4564,485987,78,7,7,778,544,4564,456,1,2,3,4,5,6,89,78,5,4,44,55,66,7,78,9,8,74,4,7,4,456,5655,123456789,78,789,45,4,5,6,8,7,5,8,12354,45,56,99999,789654785,789,45,4,5,6,8,7,5,8,12354,45,56,99999,789654785,456,45,45,45,78,555,5,45698,7879,45,45789,45,4,5,6,8,7,5,8,12354,45,56,99999,789654785,485,12,14,15,16,13,17,18,19,15,14,16,1,4,10, 8, 5, 2, 3, 6, 7, 1, 4, 9,6, 7, 1, 4, 9.112,125,15984,45,45,4456,777777,45,68,78,4564,485987,78,7,7,778,544,4564,456,1,2,3,4,5,6,10, 8, 5, 2, 3, 6, 7, 1, 4, 9,6, 7, 1, 4, 9.112,125,15984,45,45,4456,777777,45,68,78,4564,485987,78,7,7,778,544,4564,456,1,2,3,4,5,6,89,78,5,4,44,55,66,7,78,9,8,74,4,7,4,456,5655,123456789,10, 8, 5, 2, 3, 6, 7, 1, 4, 9,6, 7, 1, 4,10, 8, 5, 2, 3, 6, 7, 1, 4, 9,6, 7, 1, 4, 9.112,125,15984,45,45,4456,777777,45,68,78,4564,485987,78,7,7,778,544,4564,456,1,2,3,4,5,6,89,78,5,4,44,55,66,7,78,9,8,74,4,7,4,456,5655,123456789,10, 8, 5, 2, 3, 6, 7, 1, 4, 9,6, 7, 1, 4, 9.112,125,15984,45,45,4456,777777,45,68,78,4564,485987,78,7,7,778,544,4564,456,1,2,3,4,5,6,89,78,5,4,44,55,66,7,78,9,8,74,4,7,4,456,5655,123456789,78,789,45,4,5,6,8,7,5,8,12354,45,56,99999,789654785,789,45,4,5,6,8,7,5,8,12354,45,56,99999,789654785,456,45,45,45,78,555,5,45698,7879,45,45789,45,4,5,6,8,7,5,8,12354,45,56,99999,789654785,485,12,14,15,16,13,17,18,19,15,14,16,1,4,10, 8, 5, 2, 3, 6, 7, 1, 4, 9,6, 7, 1, 4, 9.112,125,15984,45,45,4456,777777,45,68,78,4564,485987,78,7,7,778,544,4564,456,1,2,3,4,5,6,89,78,5,4,44,55,66,7,78,9,8,74,4,7,4,456,5655,123456789,10, 8, 5, 2, 3, 6, 7, 1, 4, 9,6, 7, 1, 4, 9.112,125,15984,45,45,4456,777777,45,68,78,4564,485987,78,7,7,778,544,4564,456,1,2,3,4,5,6,89,78,5,4,44,55,66,7,78,9,8,74,4,7,4,456,5655,123456789,10, 8, 5, 2, 3, 6, 7, 1, 4, 9,6, 7, 1, 4, 9.112,125,15984,45,45,4456,777777,45,68,78,4564,485987,78,7,7,778,544,4564,456,1,2,3,4,5,6,89,78,5,4,44,55,66,7,78,9,8,74,4,7,4,456,5655,123456789,78,789,45,4,5,6,8,7,5,8,12354,45,56,99999};

typedef struct node {
int i;
int j;
} NODE;

void merge(int i, int j)
{
        int mid = (i+j)/2;//(inicio+fin)/2
        int ai = i;    //inicio
        int bi = mid+1;//inicio de mitad

        int newa[j-i+1], c = 0;//nuevo array

        while(ai <= mid && bi <= j) {
                if (a[ai] > a[bi])
                        newa[c++] = a[bi++];
                else
                        newa[c++] = a[ai++];
        }

        while(ai <= mid) {
                newa[c++] = a[ai++];
        }

        while(bi <= j) {
                newa[c++] = a[bi++];
        }

        for (ai = 0; ai < (j-i+1) ; ai++)
                a[i+ai] = newa[ai];

}

void * mergesort(void *a)
{
                NODE *p = (NODE *)a;//iguala nodos
                NODE n1, n2;
                int mid = (p->i+p->j)/2;//mitad
                thread A,B;
                n1.i = p->i;//inicio fin primera mitad
                n1.j = mid;
                n2.i = mid+1;//inicio fin segunda mitad
                n2.j = p->j;
                if (p->i >= p->j) return 0;
                A= thread(mergesort,&n1);
                B= thread(mergesort,&n2);
                A.join();
                B.join();
                merge(p->i, p->j);

}


int main()
{
    //int a[10000]; //= {5, 6, 1, 2, 0,45,4};
      for(int i=0;i<10000;i++)
        {
            a[i]=rand()%100;
            cout<<a[i]<<".";
        }

                int i = 0;
                NODE m;
                m.i = 0;
                thread M;
                m.j = (sizeof(a)/4)-1;
                cout<<"LONGITUD"<<sizeof(a)/4<<endl;
                float genera1,genera2;
                    genera1=clock();
                M = thread(mergesort,&m);
                M.join();
                    genera2=clock();
                for (i = 0; i < (sizeof(a)/4); i++) ///impresion
                               cout<<" "<<a[i];

                printf ("\n");
                cout<<"Tiempo : "<<(genera2-genera1)/CLK_TCK<<endl;
                return 0;
}
