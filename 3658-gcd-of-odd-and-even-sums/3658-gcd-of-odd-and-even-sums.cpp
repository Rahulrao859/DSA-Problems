class Solution {
public:

    int CalculateGcd(int a,int b){

        while(b!=0){
            int temp = b;
            b = a%b;
            a = temp;
        }

        return a;
    }
    int gcdOfOddEvenSums(int n) {

        int EvenSum = n*(n+1);
        int OddSum = n*n;

       int Gcd = CalculateGcd(OddSum,EvenSum);

       return Gcd;
        
    }
};