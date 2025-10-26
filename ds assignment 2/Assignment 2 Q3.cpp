
#include <iostream>
using namespace std;

int main(){

    int arr[]={1,2,3,4,6,7,8,9,10,11,12};
    int size=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;i++){
        if(arr[i]!=i+1){
            cout<<"The missing integer is: "<<i+1<<"(Linear search)";
            break;
        }
    }
    int low=0,high=size-1,mid=0;
    bool found=false;
    while(low<high){
        mid=(low+high)/2;
        if(arr[mid]==mid+1){
            low=mid+1;
        }
        else if(arr[mid]==mid+2 && arr[mid-1]==mid+1){
            high=mid-1;
        }
        else if(arr[mid]==mid+2 && arr[mid-1]==mid){
            cout<<"\nThe missing integer is: "<<mid+1<<"(Binary Search)";
            found=true;
            break;
        }
    }
    if(found!=true){
        cout<<"The series is absolutely correct.";
    }

    return 0;
}