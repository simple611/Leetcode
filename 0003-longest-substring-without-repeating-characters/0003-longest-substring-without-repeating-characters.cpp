class Solution {
public:
    int max(int a, int b){
        if(a>b)
            return a;
        else
            return b;
    }
    
    // TC- O(n)  SC- O(m) // m = size of set
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int end=0;
        int maxL = 0;
        
        unordered_set<char> ss;
        while(end < s.length()){
            // cout<<"End======"<<end<<endl;
            if(ss.find(s[end]) != ss.end()){
                //duplicate
                // cout<<"start="<<start<<endl;
                // cout<<"s[start]="<<s[start]<<endl;
                ss.erase(ss.find(s[start]));
                start++;
            }
            else{
                ss.insert(s[end]);
                end++;
                maxL=max(ss.size(),maxL);
            }
            // cout<<"ss size = "<<ss.size()<<endl;
        }
        return maxL;
    }
};