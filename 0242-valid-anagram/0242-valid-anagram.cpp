#pragma GCC optimize("Ofast")
static const auto io_sync_off = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool  isAnagram(string s, string t) {
//         hashmap approach
//         if(s.length() != t.length())
//             return false;
        
//         unordered_map<char,int> mp;
//         for(int i=0;i<s.length();i++)
//         {
//             mp[s[i]] += 1;
//         }
        
//         for(int i=0;i<t.length();i++)
//         {
//             if(mp.find(t[i]) != mp.end())
//             {
//                 mp[t[i]] -= 1;
//             }
//         }
//         for(auto m : mp)
//         {
//             if(m.second !=0)
//                 return false;
//         }
//         return true;
        // =================
        
        // fixed length approach
//         int list[26] ={0};
        
//         if(s.length() != t.length())
//             return false;
//         for(int i=0;i<s.length();i++)
//         {
//             int idx = s[i] - 'a';
//             list[idx]++;
//         }
//         for(int i=0;i<t.length();i++)
//         {
//             int idx = t[i] - 'a';
//             list[idx]--;
//         }
//         for(int i=0;i<26;i++)
//         {
//             if(list[i]!= 0)
//                 return false;
//         }
//         return true;
        // ===============================
        
        // Generic HashMap approach-- improved
        int lenS = s.length();
        int lenT = t.length();
        
        if(lenS == lenT)
        {
        
        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;
        
        for( int i=0;i<lenS;++i)
        {
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        
        unordered_map<char,int>:: iterator  it;
        for(it = mps.begin(); it!= mps.end();++it)
        {
            auto itr = mpt.find(it->first);
            if(itr == mpt.end())
                return false;
            else
            {
                if(it->second != itr->second)
                    return false;               
            }
        }
        return true;
        }
        else
            return false;
    }
};