class Solution {
public:
    int setbits(int num){

        int count = 0;

        while(num > 0){
            count += (num & 1);
            num >>= 1;
        }
        return count;
    }

    int calculateScore(int a, int b) {
        
        int s1 = setbits(a);
        int s2  = setbits(b);
        int answer = 0;

        if(s1 >= s2){
            answer = s1 * s2; 
        }
        else{
            answer = s2/s1;
        }
        return answer;
    }
};