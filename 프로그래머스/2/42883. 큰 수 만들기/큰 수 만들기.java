import java.util.*;

class Solution {
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder(number);
      
        for(int i = 0; i < sb.length() - 1 && k > 0; i++){
            if(sb.charAt(i) < sb.charAt(i + 1)){
                sb.deleteCharAt(i);
                k--;
                i--;
                if(i>=0)i--;
            }
        }
 
        if (k > 0) {
            sb.delete(sb.length() - k, sb.length());
        }
        
        String answer = sb.toString();
        return answer;
    }
}