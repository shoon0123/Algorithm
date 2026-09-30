class Solution {
    public int solution(String s) {
        int min = Integer.MAX_VALUE;
        
        if(s.length() == 1){
            return 1;
        }
        
        for(int i = 1; i <= s.length() / 2; i++){
            StringBuilder sb = new StringBuilder();
            int count = 1;
            int j = 0;
            for(; j <= s.length() - 2 * i; j += i){
                if(s.substring(j, j + i).equals(s.substring(j + i, j + 2 * i))){
                    count++;
                }else{
                    if(count != 1){
                        sb.append(Integer.toString(count));
                    }
                    sb.append(s.substring(j, j + i));
                    count = 1;
                }
            }
            
            if(count != 1){
                sb.append(Integer.toString(count));
            }
            sb.append(s.substring(j, j + i));
            
            for(int k = j + i; k < s.length(); k++){
                sb.append(s.charAt(k));
            }
            
            if(min > sb.length()){
                min = sb.length();
            }
        }
        
        return min;
    }
}