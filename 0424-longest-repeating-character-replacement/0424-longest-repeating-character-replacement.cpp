class Solution {
public:
    // bool isValid(string s, int len, int k){
    //     vector<int> vec(26,0);
    //     int start=0;
    //     int maxFreq = 0;
    //     for(int i=0;i<s.length();i++){
    //         vec[s[i]-'A']++;
            
    //         if(i-start + 1 > len){
    //             vec[s[i]-'A']--;
    //             start++;
    //         }
    //         maxFreq = max(maxFreq, vec[s[i]]-'A');
    //         if(len - maxFreq <=k)
    //             return true;
    //     }
    //     return false;
    // }
    int characterReplacement(string s, int k) {
        // int lo = 1;
        // int hi = s.length()+1;
        // int mid;
        // while(lo+1<hi){
        //     mid = lo+ (hi-lo)/2;
        //     if(isValid(s,mid,k)){
        //         lo = mid;
        //     } else {
        //         hi = mid;
        //     }
        // }
        // return lo;
        
        
        // if (s.size() == 0) return 0;
        // vector <int> arr(128);
        // int start = 0, maxCount = 0;
        // for (int end = 0; end < s.size(); end++) {
        //     maxCount = max(maxCount, ++arr[s[end]]);
        //     if (end - start + 1 - maxCount > k)  
        //         arr[s[start++]]--;
        // }
        // return s.length() - start;
        
        
        if(s.size() == 0) return 0;
        
        // vector<int> freq(26, 0);
        int freq[26] = {};
        int start =0, end = 0, maxC = 0;
        
        while(end < s.size()){
            freq[s[end] - 'A']++;
            
            
            int maxFreq = *max_element(freq, freq+26);
            
            while(end-start+1 - maxFreq > k){
                freq[s[start] - 'A']--;
                start++;        
            }
            
            maxC = max(maxC, end-start+1);
            end++;
        }
        
        return maxC;
    }
};