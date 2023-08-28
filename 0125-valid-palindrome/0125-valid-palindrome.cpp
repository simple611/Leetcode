class Solution {
public:
    bool isPalindrome(string s) {
        // Basic approach
//         for(int i=0;i<s.length();i++)
//             s[i]=tolower(s[i]);
        
//         int l=0;
//         int r = s.length()-1;
        
//         while(l<=r)
//         {
            
//             if(!((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= '0' && s[l] <= '9')))
//                 l++;

//             else if(!((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= '0' && s[r] <= '9')))
//                 r--;
            
//             else if(s[l] == s[r])
//             {
//                 l++;
//                 r--;
//             }
//             else
//                 return false;
//         }
//         return true;
        
        int l=0;
        int r = s.length()-1;
        
        while(l<=r)
        {
            if(isalnum(s[l]))
            {
                if(isalnum(s[r]))
                {
                    s[l] = tolower(s[l]);
                    s[r] = tolower(s[r]);
                    if(s[l] == s[r])
                    {
                        l++;
                        r--;
                    }
                    else
                        return false;
                }
                else
                    r--;
            }
            else
            {
                l++;
            }
        }
        return true;
        
    }
};