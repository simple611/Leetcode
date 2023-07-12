class Solution {
public:
    
    //TC - O(m*nlogn), where m is the size of strs and n is the average size of string in strs
    // SC - O(m*n)
    vector<vector<string>> groupAnagrams_sort_map(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
    
    // Using countin sort 
    // TC - O(m*n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        string tmp_sorted;
        
        for (auto word : strs) {
            tmp_sorted = countSort(word);
            m[tmp_sorted].push_back(word);
        }
        
        vector<vector<string>> res;
        for (auto [word, list] : m) {
            res.push_back(list);
        }
        
        return res;
    }
    
    string countSort(string word) {
        vector<int> count(26);
        string res;
        
        for (auto ch : word) count[ch - 'a']++;
        for (int i = 0; i < 26; i++) res += string(count[i], i+'a');
        return res;
    }
};