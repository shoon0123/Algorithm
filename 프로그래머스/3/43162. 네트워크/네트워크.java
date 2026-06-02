class Solution {
    static boolean[] visited;
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        visited = new boolean[n];
        
        for(int i = 0; i < n; i++){
            if(visited[i]){
                continue;
            }
            answer++;
            dfs(n, computers, i);
        }
        
        return answer;
    }
    
    private void dfs(int n, int[][] computers, int index){
        visited[index] = true;
        
        for(int i = 0; i < n; i++){
            if(visited[i]){
                continue;
            }
            if(computers[index][i] == 0){
                continue;
            }
            dfs(n, computers, i);
        }
    }
}