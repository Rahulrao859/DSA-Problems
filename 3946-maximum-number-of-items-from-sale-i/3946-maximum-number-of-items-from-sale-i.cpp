#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> price(n), factor(n), freeCnt(n);
        int cheapest = INT_MAX;

        for (int i = 0; i < n; i++) {
            factor[i] = items[i][0];
            price[i] = items[i][1];
            cheapest = min(cheapest, price[i]);
        }

        // free copies obtained by buying the first copy of item i
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && factor[j] % factor[i] == 0)
                    cnt++;
            }
            freeCnt[i] = cnt;
        }

        const int NEG = -1e9;
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        // 0/1 knapsack on first purchases
        for (int i = 0; i < n; i++) {
            int c = price[i];
            int v = 1 + freeCnt[i];

            for (int b = budget; b >= c; b--) {
                dp[b] = max(dp[b], dp[b - c] + v);
            }
        }

        int ans = budget / cheapest;

        for (int spent = 0; spent <= budget; spent++) {
            if (dp[spent] < 0) continue;

            int remain = budget - spent;
            ans = max(ans, dp[spent] + remain / cheapest);
        }

        return ans;
    }
};