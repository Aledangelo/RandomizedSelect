#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

void swap(int *, int , int );
int Partition(int *, int , int);
int RandomizedPartition(int *, int , int);
int RandomizedSelect(int *, int , int , int );
int N;
int main() {

    clock_t inizio,fine;
    double tempo;

    N = 10;
    srand(time(NULL));

    //N = 1 + rand() % 100;

    int i;
    int A[N];
    cout<<"VETTORE A:                       ";
    for(i = 1; i <= N; i++){
        A[i] = rand() % 100;
        cout<<A[i]<<"|";
    }
    cout<<endl;

    int stat = rand() % N;
    cout<<"Cerca la statistica di ordine:   "<<stat<<endl;

    inizio = clock();
    int q = RandomizedSelect(A,1,N,stat);
    fine = clock();

    cout<<"STATISTICA CORRETTA:             "<<q<<endl;

    tempo = ((double)(fine-inizio))/CLOCKS_PER_SEC;
    cout<<"T(n):                            "<<tempo<<endl;
    cout<<"DIM:                             "<<N<<endl;

    return 0;
}


int RandomizedSelect(int *A, int p, int r, int i){
    if(p == r){         //qua avevamo scritto if(p = r) invece di if(p == r) ed entrava sempre nel for
        return A[p];    //quindi restituiva sempre l'elemento alla posizione p
    }


    int q = RandomizedPartition(A,p,r); //indice del pivot scelto

    int k = q - p + 1;  //ricalcoliamo l'indice del pivot

    if(k == i){
        return A[q];
    } else if(i<k){
        return RandomizedSelect(A,p,q-1,i);
    } else {
        return RandomizedSelect(A,q+1,r,i-k);
    }

}

int Partition(int *A, int p, int r){
    int pivot = A[r];
    //indice i di terminazione elementi <= pivot
    int i = p-1;
    //indice j = elemento da confrontare

    int j;

    for(j = p; j<r; j++){
        if(A[j] <= pivot) {
            i = i + 1;
            swap(A, i, j);
        }
    }

    swap(A,i+1,r); //scambio il pivot con il primo elemento più grande
    return i+1;
}

int RandomizedPartition(int *A, int p, int r){
    int q;
    int dif = r-p+1; //qua avevamo fatto r-p, ma è r-p+1 (immagina un vettore che parte da due e va a 6 e fatti i conti)
    int pivot = p + rand() % dif;
    swap(A,pivot,r);
    q = Partition(A,p,r);

    return q;

}

void swap(int *A, int p, int r){
    int temp;
    temp = A[p];
    A[p] = A[r];
    A[r] = temp;
}