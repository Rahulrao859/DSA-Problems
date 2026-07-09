class Solution {
public:
    static const int MOD = 1e9 + 7;

    int divisibleGame(vector<int>& nums) {
        unordered_set<int> divisors;

        // Collect all possible k (>1)
        for (int x : nums) {
            for (int d = 1; 1LL * d * d <= x; d++) {
                if (x % d == 0) {
                    if (d > 1) divisors.insert(d);
                    if (x / d > 1) divisors.insert(x / d);
                }
            }
        }

        long long bestDiff = LLONG_MIN;
        int bestK = 2;

        if (divisors.empty()) {
            // All numbers are 1
            long long cur = -nums[0], mx = cur;
            for (int i = 1; i < nums.size(); i++) {
                long long val = -1LL * nums[i];
                cur = max(val, cur + val);
                mx = max(mx, cur);
            }
            return (int)(((mx % MOD + MOD) % MOD) * 2 % MOD);
        }

        for (int k : divisors) {
            long long cur = LLONG_MIN, mx = LLONG_MIN;

            for (int x : nums) {
                long long val = (x % k == 0) ? x : -1LL * x;

                if (cur == LLONG_MIN)
                    cur = val;
                else
                    cur = max(val, cur + val);

                mx = max(mx, cur);
            }

            if (mx > bestDiff || (mx == bestDiff && k < bestK)) {
                bestDiff = mx;
                bestK = k;
            }
        }

        long long ans = ((bestDiff % MOD + MOD) % MOD);
        ans = ans * bestK % MOD;
        return (int)ans;
    }
};
