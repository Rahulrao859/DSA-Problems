#include<iostream>
using namespace std;

int findduplicate(int arr[],int size){
    int ans = 0;

    for(int i=0;i<size;i++){
      ans = ans^arr[i];
    }

    for(int i = 1;i<size;i++){
        ans = ans^i;
    }
    
}

int main(){
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
   // take the input in the array
    int array[9];
    for(int i= 0;i<size;i++){
        cin>>array[i];
    }

    findduplicate(array,9);
   cout<<"The duplicate number in the array is:"<< findduplicate;

   return 0;
}
//hello world