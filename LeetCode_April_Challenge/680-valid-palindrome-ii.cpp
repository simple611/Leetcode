class Solution {
public:
    bool checkPal(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        //bool isValid = false;
        
        /*int l=0;
        int h = s.length()-1;
        bool skipped = false;
        while(l<h){
            if(s[l]!=s[h])
            {
                cout<<"::l="<<l<<"\t"<<"h="<<h<<"\n";
                
                // cannot write if-else like this because need to check both the order of l,h-1 or l+1,h
                if(!skipped){
                   //delete element at h
                    if(l<h-1 && s[l] == s[h-1]){
                        cout<<"inside A"<<"\n";
                        h= h-1;
                        skipped=true;
                        continue;
                    }
                    //deleted element at l
                    if(l+1<h && s[l+1]==s[h] )
                    {
                        cout<<"inside B"<<"\n";
                        l = l+1;
                        skipped = true;
                        continue;
                    }
                    if(l+1 == h)
                        return true;
                    
                    cout<<"exit1";
                    return false;
                }
                else{
                    cout<<"l="<<l<<"\t"<<"h="<<h<<"\n";
                    cout<<"exit2";
                    return false;
                }
            }
            else{
                cout<<"inside C"<<"\n";
                l++;
                h--;
            }
        }
        return true;
        
    */
        int l=0;
        int h= s.length()-1;
        while(l<h){
            if(s[l] != s[h]){
                int i1=l, j1= h-1;
                int i2=l+1, j2=h;
                
                while(i1<j1 && s[i1]== s[j1]){
                    i1++;
                    j1--;
                }
                while(i2<j2 && s[i2] == s[j2]){
                    i2++;
                    j2--;
                }
                
                return (i1>=j1)  || (i2 >=j2);
            }
            l++;
            h--;
        }
        
        return true;
        
        /*
        int i=0;
        int j= s.length()-1;
        while(i<j){
            if(s[i] != s[j]){
                return (checkPal(s, i, j-1) || checkPal(s, i+1,j));
            }
            i++;
            j--;
        }
        return true;
        */
    }
};