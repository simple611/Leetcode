class Solution {
public:
    
    //TC - O(V+E)   SC- O(V+E)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> gr(numCourses);
        
        vector<int> inDegree(numCourses, 0);
        
        for(auto &pre: prerequisites){
            int preCourse = pre[1];
            int course = pre[0];
            
            gr[preCourse].push_back(course);
            inDegree[course]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int course = q.front();
            q.pop();
            
            for(auto &nextCourse: gr[course]){
                inDegree[nextCourse]--;
                
                if(inDegree[nextCourse] == 0)
                    q.push(nextCourse);
            }
        }
        
        for(auto &i: inDegree){
            if(i!=0)
                return false;
        }
        
        return true;
    }
};