class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();

        // Number of equal adjacent pairs in the cyclic string.
        int total = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == s[(i + 1) % n])
                ++total;
        }

        // For a rotation:
        // score = total - 1 if first == last
        // score = total otherwise.
        if (k != total && k != total - 1)
            return 0;

        int equalEnds = 0;

        // Rotation starting at i:
        // first = s[i]
        // last  = s[(i - 1 + n) % n]
        for (int i = 0; i < n; ++i) {
            if (s[i] == s[(i - 1 + n) % n])
                ++equalEnds;
        }

        if (k == total - 1)
            return equalEnds;

        return n - equalEnds;
    }
};