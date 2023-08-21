class Solution {
public:
    
    bool isSafe(string curString, string orgString){
            for(int i=0;i<orgString.length();i=i+curString.length()){
                string tmpStr = orgString.substr(i, curString.length());
                
                if(tmpStr != curString) return false;
            }
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        
        string curString = "";
        
        for(int i =0;i<n/2;i++){
            curString+=s[i];
            if(n%curString.length() == 0){
                bool result = isSafe(curString, s.substr(i+1));
                if(result) return true;
            }
        }
        
        return false;
    }
};