class Solution {
public:
    
    bool isVowel(char c){
        if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        
        
        int i = 0;
        int j = s.length() -1;
        
        while(i < j  ){
            while(i< j && !isVowel(s[i])) i++;
            
            while(i<j && !isVowel(s[j])) j--;
            
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        
        return s;
    }
};