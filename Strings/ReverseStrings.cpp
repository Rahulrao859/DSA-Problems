#include <iostream>
#include <string>  // Required for using the string class
using namespace std;

void ReverseString(string &input){

    int start = 0;
    int end = input.length()-1;

    while(start<=end){
        swap(input[start],input[end]);
        start++;
        end--;
    }
}


int main() {
    string input;
    
    cout<<"Enter the input string";
    getline(std::cin, input);  // Reads the entire line, including spaces
    cout << "You entered: " << input <<endl;

    ReverseString(input);

    cout << "Reversed string: " << input << endl;

    return 0;
}
