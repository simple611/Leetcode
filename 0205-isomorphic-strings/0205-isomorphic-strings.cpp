class Solution {
public:
    bool isSame(string s, string t){
        map<char, char> mp;

        for(int i=0; i<s.length(); i++){
            if (mp.find(s[i]) != mp.end()){
                if(mp[s[i]] != t[i])
                    return false;
            } else
                mp[s[i]]=t[i];
        }
        return true;
    }
    
    bool isSame2(string s, string t){
        unordered_map <char , char> rep;
        unordered_map <char , bool> used;
        for(int idx = 0 ; idx < s.length() ; idx++) {
            if(rep.count(s[idx])) {
                if(rep[s[idx]] != t[idx])
                    return false;
            }
            else {
                if(used[t[idx]])
                    return false;
                rep[s[idx]] = t[idx];
                used[t[idx]] = true;
            }
        }
        // Otherwise, the strings are not isomorphic.
        return true;
    }
    bool isIsomorphic(string s, string t) {
        int m =s.length();
        int n = t.length();
        if(m!=n)
            return false;
        // return isSame(s,t) && isSame(t,s);
        
        return isSame2(s,t);

    }
};