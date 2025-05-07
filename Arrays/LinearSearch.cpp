#include<iostream>  // linear search
using namespace std;

bool linear_search(int array[],int size,int key){
  

    for(int i=0;i<size;i++){
       if(array[i]==key){
        return 1;
       }
    }
     return 0;
}

int main(){

    int size;
    cout<<"Enter the size of the array:";
    cin>>size;

    int array[8];
     
     // to take the input of the array
    for(int i =0;i<size;i++){
        cin>>array[i];
    }

    int key;
    cout<<"Enter the value of key to be found:";
    cin>>key;


      int found = linear_search(array,8,key);

     if(found){
        cout<<"Key is found:";
     }

     else{
        cout<<"Key not found";
     }
}