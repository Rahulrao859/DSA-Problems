class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pos, digit;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // powers of 10
        vector<long long> p10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            p10[i] = (p10[i - 1] * 10) % MOD;

        // prefNum[i] = number formed by first i non-zero digits
        vector<long long> prefNum(m + 1, 0);
        vector<long long> prefSum(m + 1, 0);

        for (int i = 1; i <= m; i++) {
            prefNum[i] = (prefNum[i - 1] * 10 + digit[i - 1]) % MOD;
            prefSum[i] = prefSum[i - 1] + digit[i - 1];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x = (prefNum[R + 1] -
                           prefNum[L] * p10[len] % MOD +
                           MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};