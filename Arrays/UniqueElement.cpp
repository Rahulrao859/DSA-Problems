#include<iostream>  // find the unique element in the array
using namespace std;

int  findunique(int arr[],int size){
    int ans = 0;
    for(int i=0;i<size;i++){
        ans = ans^arr[i];   // we have to do X-OR as from XORing the duplicate variable cancel out and 
                            // unique variable is printed
    }
    return ans;
 
}

int main(){

    int size;
    cout<<"Enter the  size of the array:";
    cin>>size;   // we have to take size as odd given in ques

    int array[7];
    // take the input of the array
    for(int i=0;i<size;i++){
        cin>>array[i];
    }

    int ans =  findunique(array,size);

     cout<<"The element is: "<<ans<<endl;
}