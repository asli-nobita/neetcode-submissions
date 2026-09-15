class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        // int replacements = 0;
        char mostFreqChar;
        int maxFreq = 0;
        unordered_map<char, int> freqMap;
        int maxlen = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            freqMap[s[r]]++;
            if (freqMap[s[r]] > maxFreq) {
                maxFreq = freqMap[s[r]];
                mostFreqChar = s[r];
            }
            while (l < r && r - l + 1 - maxFreq > k) {
                freqMap[s[l]]--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};
