class Solution {
    bool dfs(int node, int col, int color[], vector<vector<int>>& graph){
        color[node]=col;
        for(auto i: graph[node]){
            if(color[i]==-1){
                if(dfs(i, !col, color, graph)==false){
                    return false;
                }
            }
            else if(color[i]==col){
                return false;
            }
        }  
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color[n];
        for(int i=0;i<n;i++){
            color[i]=-1;
        }
        // components of graph
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i, 0, color, graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
