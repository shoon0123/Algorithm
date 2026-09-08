import java.util.*;

class Solution {
    public int solution(int[][] scores) {
        int count = 0;
        int wanho[] = {scores[0][0], scores[0][1]};
        
        Arrays.sort(scores,  (a,b) -> {
                        if(a[0] == b[0]) return a[1] - b[1];
                        else return b[0] - a[0];
                    });
        
        int max = 0;
        for(int i = 0; i < scores.length; i++){
            if(max < scores[i][1]){
                max = scores[i][1];
                continue;
            }
            
            if(max > scores[i][1]){
                if(scores[i][0] == wanho[0] && scores[i][1] == wanho[1]) {
                    return -1;
                }
                scores[i][0] = 0;
                scores[i][1] = 0;
            }
        }
        
        int wanhoTotal = wanho[0] + wanho[1];
        
        for(int i = 0; i < scores.length; i++){
            int total = scores[i][0] + scores[i][1];
            if(total > wanhoTotal){
                count++;
            }
        }
        
        return count + 1;
    }
}