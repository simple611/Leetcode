class Solution {
public:
    bool matches(int s1map[], int s2map[]){
        for(int i=0; i < 26; i++){
            if(s1map[i] != s2map[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion_map_slidingWindow(string s1, string s2) {
        int lenS1=s1.length();
        if(lenS1 > s2.length())
            return false;
        unordered_map<char, int> mp;
        
        for(int i=0;i<s1.length();i++){
            mp[s1[i]]++;   
        }
        
        int start=0,end=0;
        
       
        int count=mp.size();
        int k = lenS1;
        
        while(end < s2.length()){
            if(mp.find(s2[end]) != mp.end()){
                mp[s2[end]]--;
            }
            
            if(mp[s2[end]] == 0)
                count--;
            
            if(end-start+1 <k){
                end++;
            } else if(end - start + 1 == k){
                 if(count == 0)
                     return true;
                
                if(mp.find(s2[start]) != mp.end()){
                    mp[s2[start]]++;
                    
                    if(mp[s2[start]] == 1){
                        count++;
                    }
                }
                start++;
                end++;
            } 
            
        }
        return false;
        
    }
    
    // TC - O(L1 + 26L1(L2 - L1))   SC - O(1)
    bool checkInclusion_array(string s1, string s2) {
        
        // array approach
        
        if(s1.length() > s2.length()){
            return false;
        }
        
        int s1map[26];
        //int s2map[26];
        
        for(int i=0;i<s1.length();i++){
            s1map[s1[i]-'a']++;
            // s2map[s2[i]-'a']++;
        }
        for(int i = 0; i <= s2.length() - s1.length(); i++){
            int s2map[26];
            for(int j=0;j<s1.length();j++){
                s2map[s2[i+j]-'a']++;
            }
            if (matches(s1map,s2map))
                return true;
        }
        return false;
        
    }
      
    //TC - O(26 * l2)  SC- O(1)
    bool checkInclusion(string s1, string s2) {
        // sliding window
        
        int l1 = s1.length();
        int l2 = s2.length();
        
        if(l1>l2)
            return false;
        
        vector<int> s1h(26,0);
        vector<int> s2h(26,0);
        
        int start = 0, end = 0;
        
        while(end < l1){
            s1h[s1[end]-'a']++;
            s2h[s2[end]-'a']++;
            end++;
        }
        end = end-1;
        
        while(end < l2){
            if(s1h == s2h){
                return true;
            }
            end++;
            if(end != l2){
                s2h[s2[end]-'a']++;
            }
            s2h[s2[start]-'a']--;
            start=start+1;
        }
        return false;
    }
};