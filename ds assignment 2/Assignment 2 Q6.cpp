//tried using normal array. Doesn't work in vs code but works in some compliers.

#include <iostream>
using namespace std;

void transpose(int rows[],int cols[], int values[], int count){\

    int trows[100], tcols[100], tvalues[100];
    
    for (int i=0;i<count;i++){
        trows[i]=cols[i];
        tcols[i]=rows[i];
        tvalues[i]=values[i];
    }

    cout<<"\nTranspose of the matrix is: ";
    cout << "\nRows\tCol\tValue";
    for (int i=0;i<count;i++){
        cout<<"\n"<<trows[i]<<"\t"<<tcols[i]<<"\t"<<tvalues[i]<<"\t";
    }

}

void addition(int rows1[],int cols1[], int values1[], int count1,int rows2[],int cols2[], int values2[], int count2){
    
    int rows3[count1+count2],cols3[count1+count2],values3[count1+count2],count3=0;

    int i=0,j=0;
    while(i<count1 && j<count2){
        if(rows1[i]==rows2[j] && cols1[i]==cols2[j]){
            rows3[count3]=rows1[i];
            cols3[count3]=cols1[i];
            values3[count3]=values1[i]+values2[j];
            count3++;
            i++;
            j++;
        }
        else if(rows1[i]<rows2[j]||rows1[i]==rows2[j]&&cols1[i]<cols2[j]){
            rows3[count3]=rows1[i];
            cols3[count3]=cols1[i];
            values3[count3]=values1[i];
            count3++;
            i++;
        }   
        else if(rows1[i]>rows2[j]||rows1[i]==rows2[j]&&cols1[j]<cols1[i]){
            rows3[count3]=rows1[j];
            cols3[count3]=cols1[j];
            values3[count3]=values1[j];
            count3++;
            j++;
        }
    }
    while(i<count1){
        rows3[count3]=rows1[i];
        cols3[count3]=cols1[i];
        values3[count3]=values1[i];
        count3++;
        i++;
    }

    while(j<count2){
        rows3[count3]=rows2[j];
        cols3[count3]=cols2[j];
        values3[count3]=values2[j];
        count3++;
        j++;
    }

    cout<<"\nAdditon of both matrix is: \n";
    cout << "\nRows\tCol\tValue";
    for (int i=0;i<count3;i++){
        cout<<"\n"<<rows3[i]<<"\t"<<cols3[i]<<"\t"<<values3[i]<<"\t";
    }

}

void multiplication(int rows1[],int cols1[], int values1[], int count1,int rows2[],int cols2[], int values2[], int count2,int sizeMatrix){

    int rows3[sizeMatrix],cols3[sizeMatrix],values3[sizeMatrix],count3=0;    

    cout<<"\nMultiplication of both matrix is: \n";
    cout << "\nRows\tCol\tValue";
    for (int i=0;i<count3;i++){
        cout<<"\n"<<rows3[i]<<"\t"<<cols3[i]<<"\t"<<values3[i]<<"\t";
    }
}

int main(){

    int x,y;

    cout<<"Enter the size for the matrix";
    cout<<"\nx: ";
    cin>>x;

    cout<<"y: ";
    cin>>y;

    int arr[x][y];

    cout<<"Enter the values for the matrix: ";
    for (int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<": ";
            cin>>arr[i][j];
        }
    }

    int rows[x*y];
    int cols[x*y];
    int values[x*y];
    int count=0;

    for (int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(arr[i][j]!=0){
                rows[count]=i;
                cols[count]=j;
                values[count]=arr[i][j];
                count++;
            }
        }
    }
    cout << "Row\tCol\tValue";
    for (int i=0;i<count;i++){
        cout<<"\n"<<rows[i]<<"\t"<<cols[i]<<"\t"<<values[i]<<"\t";
    }

    transpose(rows,cols,values,count);
    addition(rows,cols,values,count,rows,cols,values,count);
    multiplication(rows,cols,values,count,rows,cols,values,count,x*y);

    return 0;
}