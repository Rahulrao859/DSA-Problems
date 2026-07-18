class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string ans;

        // Add all characters except x and y
        for (char c = 'a'; c <= 'z'; c++) {
            if (c == x || c == y)
                continue;
            ans.append(freq[c - 'a'], c);
        }

        // Add all y's before x's
        ans.append(freq[y - 'a'], y);
        ans.append(freq[x - 'a'], x);

        return ans;
    }
};