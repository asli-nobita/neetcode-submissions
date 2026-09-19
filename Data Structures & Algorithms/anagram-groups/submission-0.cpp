class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        for (auto str : strs) {
            auto sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto [k, v] : anagramGroups) {
            ans.push_back(v);
        }
        return ans;
    }
};
