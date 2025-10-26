

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int num;
    cout<<"Enter the no. of elements of array: ";
    cin>>num;
    vector <int> arr;

    cout<<"\nEnter elements of the array\n";
    for (int i=0;i<num;i++){
        cout<<": ";
        cin>>arr[i];
    }

    int inversion_count=0;
    for (int i=0;i<num;i++){
        for (int j=i+1;j<num;j++){
            if(arr[i]>arr[j]){
                inversion_count+=1;
            }
        }
    }
    cout<<"Inversion count: "<<inversion_count;

    return 0;
}