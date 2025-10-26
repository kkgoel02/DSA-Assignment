
#include <iostream>
using namespace std;

int main(){

    int num;
    int arr[]={78,363,323,5,343,54};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Enter the number";
    cin>>num;

    int low=0,high=size-1,mid=0;
    bool found=false;

    while(low<high){
        mid=(high+low)/2;
        if(arr[mid]==num){
            cout<<"The desired number at position:"<<mid;
            found=true;
            break;
        }
        else if(arr[mid]>=num){
            high=mid-1;
        }
        else if(arr[mid]<=num){
            low=mid+1;
        }
    }
    if(found!=true){
        cout<<"Number not found";
    }

    return 0;
}