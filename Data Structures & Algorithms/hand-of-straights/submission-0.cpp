class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        sort(hand.begin(), hand.end());
        unordered_map<int, int> freq; 
        for (auto num : hand) 
            freq[num]++; 
        int i = 0;
        while (i < n) {
            if (freq[hand[i]] > 0) {
                // starting point
                for (int j = hand[i]; j < hand[i] + groupSize; j++) {
                    if (freq[j] == 0) return false;
                    freq[j]--;
                }
            } else {
                i++;
            }
        }
        return true;
    }
};
