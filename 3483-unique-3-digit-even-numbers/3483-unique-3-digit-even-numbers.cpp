class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {};

        for (int d : digits)
            cnt[d]++;

        int ans = 0;

        for (int i = 1; i <= 9; i++) { // hundreds digit (not 0)
            if (cnt[i] == 0)
                continue;

            cnt[i]--;

            for (int j = 0; j <= 9; j++) { // tens digit
                if (cnt[j] == 0)
                    continue;

                cnt[j]--;

                for (int k = 0; k <= 8; k += 2) { // units digit must be even
                    if (cnt[k] > 0)
                        ans++;
                }

                cnt[j]++;
            }

            cnt[i]++;
        }

        return ans;
    }
};