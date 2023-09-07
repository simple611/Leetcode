class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        
        unordered_map<string, int> mp;
        
        if(s.size() < 10)
            return ans;
        
        int i = 0, j = 9;
        
        while(j< s.size()){
            
            string str = s.substr(i, j-i+1);
            mp[str]++;
            i++;
            j++;
        }
        
        for(auto m: mp){
            if(m.second > 1)
                ans.push_back(m.first);
        }
        
        return ans;
    }
};