class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        // Try to make the answer greater at position i.
        // We process from right to left.
        for (int i = n - 1; i >= 0; i--) {
            
            // We need the prefix target[0..i-1].
            int freq[26];
            copy(cnt, cnt + 26, freq);

            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (freq[x] == 0) {
                    possible = false;
                    break;
                }

                freq[x]--;
            }

            if (!possible)
                continue;

            // At position i, choose the smallest character
            // strictly greater than target[i].
            int x = target[i] - 'a';
            int bigger = -1;

            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            string ans = target.substr(0, i);

            ans += char('a' + bigger);
            freq[bigger]--;

            // Put remaining characters in sorted order.
            for (int c = 0; c < 26; c++) {
                while (freq[c] > 0) {
                    ans += char('a' + c);
                    freq[c]--;
                }
            }

            return ans;
        }

        return "";
    }
};
