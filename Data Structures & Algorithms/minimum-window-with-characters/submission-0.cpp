class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.length();
        int count = t.length();
        if (n < count) return "";
        unordered_map<char, int> freq;
        for (auto ch : t) freq[ch]++;
        int l = 0;
        int start = -1;
        int minlen = n + 1;
        for (int r = 0; r < n; r++) {
            if (freq.count(s[r])) {
                if (freq[s[r]] > 0) count--;
                freq[s[r]]--;
            }
            while (l <= r && count == 0) {
                if (r - l + 1 < minlen) {
                    start = l;
                    minlen = r - l + 1;
                }
                if (freq.count(s[l])) {
                    freq[s[l]]++;
                    if (freq[s[l]] > 0) {
                        count++;
                    }
                }
                l++;
            }
        }
        if (start == -1) return "";
        return s.substr(start, minlen);
    }
};
