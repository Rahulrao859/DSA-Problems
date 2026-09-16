class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;

        // Store all indices for each integer
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = 0;

        for (auto& [x, indices] : pos) {
            // Must appear at least 3 times
            if (indices.size() < 3)
                continue;

            // Check whether all consecutive differences are equal
            int diff = indices[1] - indices[0];
            bool special = true;

            for (int i = 2; i < indices.size(); i++) {
                if (indices[i] - indices[i - 1] != diff) {
                    special = false;
                    break;
                }
            }

            if (special)
                ans++;
        }

        return ans;
    }

}
;