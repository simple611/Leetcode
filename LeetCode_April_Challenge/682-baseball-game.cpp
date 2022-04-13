class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        //int lastIdx =0;
        for(string s: ops){
                if(s == "C"){
                    record.pop_back();
                } 
                else if(s == "D"){
                    record.push_back(2* record.back());
                    // record.push_back(record[lastIdx]*2);
                }
                else if(s == "+"){
                    int x = record.back();
                    record.pop_back();
                    int y = record.back();
                    record.push_back(x);
                    record.push_back(x+y);           
                    // record.push_back(record[lastIdx]+record[lastIdx-1]);
                }
                else{
                    record.push_back(stoi(s));
                }
            // lastIdx=record.size()-1;
        }
        
        int ans=0;
        for(int n:record){
            ans+=n;
        }
        return ans;
    }
};