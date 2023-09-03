class Solution {
public:
    
    //TC - O(l1+l2)  SC - O(m), m is size of map
    string minWindow(string s, string t) {
        int l1 = s.size(), l2 = t.size();
        
        if(l2 > l1) return "";
        
        unordered_map<char, int> t_mp;     
        for(char c: t)
            t_mp[c]++;
        
        int start = 0, end = 0;   
        int count = t_mp.size();
        int minL = INT_MAX;
        int minStart = 0;
        string ans = "";
        
        while(end < l1){
            
            // If char is present in map
            if(t_mp.find(s[end]) != t_mp.end()){
                t_mp[s[end]]--;
                
                if(t_mp[s[end]] == 0)
                    count--;       
            }
               
            while(count == 0){
                // cout<<"possible Substring = "<<s.substr(start, end+1)<<endl;
                if(minL > end-start+1){
                    minL = end-start+1; 
                    minStart = start;
                    // cout<<"Ans= "<< ans<<endl;
                }
                
                // Start removing elements from starting and updating the map accordingly
                if(t_mp.find(s[start]) != t_mp.end()){
                    t_mp[s[start]]++;
                    
                    if(t_mp[s[start]] == 1)
                        count++;
                }
                start++;
            } 
            end++; 
        }
        
        return minL == INT_MAX ? "" : s.substr(minStart, minL);
    }
};