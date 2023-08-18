class Solution {
public:
    bool matches(int s1map[], int s2map[]){
        for(int i=0; i < 26; i++){
            if(s1map[i] != s2map[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
//         int lenS1=s1.length();
//         if(lenS1 > s2.length())
//             return false;
//         unordered_set<char> sS1;
        
//         for(int i=0;i<s1.length();i++){
//             sS1.insert(s1[i]);
//         }
        
//         int start=0,end=0;
        
       
//         int count=0;
//         while(end<s2.length()){
//             if(sS1.find(s2[end]) != sS1.end()){
//                 count++;
//                 end++;
//                 if(count == lenS1)
//                     return true;
//             }else{
//                 start++;
//                 end++;
//                 count=0;
//             }
//         }
//         return false;
        
//         // array approach
        
//         if(s1.length() > s2.length()){
//             return false;
//         }
        
//         int s1map[26];
//         //int s2map[26];
        
//         for(int i=0;i<s1.length();i++){
//             s1map[s1[i]-'a']++;
//             // s2map[s2[i]-'a']++;
//         }
//         for(int i = 0; i <= s2.length() - s1.length(); i++){
//             int s2map[26];
//             for(int j=0;j<s1.length();j++){
//                 s2map[s2[i+j]-'a']++;
//             }
//             if (matches(s1map,s2map))
//                 return true;
//         }
//         return false;
        // sliding window
        
        int l1= s1.length();
        int l2=s2.length();
        if(l1>l2)
            return false;
        
        vector<int> s1h(26,0);
        vector<int> s2h(26,0);
        
        int start=0,end=0;
        
        while(end<l1){
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