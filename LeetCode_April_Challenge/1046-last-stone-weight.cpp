class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // sort(stones.begin(), stones.end());
        // int ans =0;
        // for(int i=stones.size()-1;i>=0;i--){
        //     if(stones[i] == stones[i+1])
        // }
//         priority_queue<int> s;
//         for(int i=0;i<stones.size();i++){
//             s.push(stones[i]);
//         }
//         while(s.size() >0){
//             if(s.size() == 1)
//                 s.top();
//             int a = s.top();
//             s.pop();
//             int b = s.top();
//             s.pop();
            
//             if(a==b)
//                 continue;
//             else{
//                 s.push(b-a);
//             }
//         }
//         return 0;
        
        priority_queue<int> p(stones.begin(),stones.end());
        while(p.size()>1)
        {
            int y=p.top();
            p.pop();
            int x=p.top();
            p.pop();
            if(x!=y) p.push(y-x);
        }
        return p.empty()? 0 :p.top();
    }
};