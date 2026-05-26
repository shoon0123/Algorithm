import java.util.*;

class Solution {
    public int solution(int n, int[][] wires) {
        int answer = 100;
        
        for (int[] cut : wires) {
            ArrayList<Integer>[] graph = new ArrayList[n + 1];
            
            for (int i = 1; i <= n; i++) {
                graph[i] = new ArrayList<>();
            }
            
            for (int[] wire : wires) {
                if ((wire[0] == cut[0] && wire[1] == cut[1])) {
                    continue;
                }
                graph[wire[0]].add(wire[1]);
                graph[wire[1]].add(wire[0]);
            }

            int count = bfs(graph, n);
            int other = n - count;
            answer = Math.min(answer, Math.abs(count - other));
        }
        
        return answer;
    }
    
    private int bfs(ArrayList<Integer>[] graph, int n) {
        boolean[] visited = new boolean[n + 1];
        Queue<Integer> queue = new LinkedList<>();

        queue.add(1);
        visited[1] = true;
        int count = 1;

        while (!queue.isEmpty()) {
            int current = queue.poll();

            for (int next : graph[current]) {
                if (!visited[next]) {
                    visited[next] = true;
                    queue.add(next);
                    count++;
                }
            }
        }

        return count;
    }
}