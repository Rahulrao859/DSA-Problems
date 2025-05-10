#include<iostream>  // to reverse the given array
using namespace std;

void reversearray(int arr[],int n){

    int start = 0;
    int end = n-1;

    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void Printarray(int arr[],int n){
    for(int i= 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
   
   int First[5] = { 2,4,6,8,3};
   int Second[6] = {3,5,8,9,2,1};

   reversearray(First,5);
   reversearray(Second,6);

   // print the array
   
   Printarray(First,5);
   Printarray(Second,6);
}