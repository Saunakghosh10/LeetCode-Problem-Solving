class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
          int n = graph.size();
          vector<int> color(n,-1);
           for(int i = 0; i < n; i++){
               if(!bfs(0, i, color, graph))
                return false;
           }
        return true;
    }

    bool bfs(int A, int B, vector<int>& color , vector<vector<int>>& graph){
          queue<int> v;
          v.push(B);
          while(!v.empty()){
              int node = v.front();
              v.pop();
              for(auto edge:graph[node]){
                  if(color[edge] == -1){
                      color[edge] = !color[node];
                      v.push(edge);
                  }
                  else if(color[edge] == color[node])
                   return false;
              }
          }
        return true;  
    }
};
