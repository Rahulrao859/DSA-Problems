class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange = -1;
        int sum = 0;

        for (int num : nums) {
            int temp = num;
            int maxi = 0;
            int mini = 9;

            while (temp > 0) {
                int digit = temp % 10;
                maxi = max(maxi, digit);
                mini = min(mini, digit);
                temp /= 10;
            }

            int range = maxi - mini;

            if (range > maxRange) {
                maxRange = range;
                sum = num; // New maximum range
            } else if (range == maxRange) {
                sum += num; // Same maximum range
            }
        }

        return sum;
    }
};