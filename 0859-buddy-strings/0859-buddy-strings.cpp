class Solution {
public:
    
    // TC - O(n) SC - O(1)
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        
        
        if( s == goal){
            map<char, int> mp;
            for(char c: s){
                mp[c]++;
                if(mp[c] == 2)
                    return true;
            }
            
            return false;
        }
        
        int firstIdx = -1, secondIdx = -1;
        for(int i=0;i<s.length();i++){
            if(s[i] != goal[i]){
                if(firstIdx == -1){
                    firstIdx = i;
                } else if ( secondIdx == -1){
                    secondIdx = i;
                } else {
                    return false;
                }
                    
            }
        }
        
        if(secondIdx == -1)
            return false;
        
        return s[firstIdx] == goal[secondIdx] && s[secondIdx] == goal[firstIdx];        
    }
};