import java.util.*;

class Solution {
    public String[] solution(String[] files) {
        String[] answer = new String[files.length];
        for(int i = 0; i < files.length; i++){
            answer[i] = files[i];
        }
        
        Arrays.sort(answer, (a,b) -> {
            int aIndex = 0; 
            int bIndex = 0;
            while(true){
                if(a.charAt(aIndex) >= '0' && a.charAt(aIndex) <= '9'){
                    break;
                }
                aIndex++;
            }
            
            while(true){
                if(b.charAt(bIndex) >= '0' && b.charAt(bIndex) <= '9'){
                    break;
                }
                bIndex++;
            }
            
            String aHead = a.substring(0, aIndex).toUpperCase();
            String bHead = b.substring(0, bIndex).toUpperCase();
            
            if(!aHead.equals(bHead)){
                return aHead.compareTo(bHead);
            }
            
            // NUMBER 비교
            int aStartIndex = aIndex;
            int bStartIndex = bIndex;
            
            while(aIndex < a.length()){
                if(a.charAt(aIndex) < '0' || a.charAt(aIndex) > '9'){
                    break;
                }
                aIndex++;
            }
            
            while(bIndex < b.length()){
                if(b.charAt(bIndex) < '0' || b.charAt(bIndex) > '9'){
                    break;
                }
                bIndex++;
            }
            int aN = Integer.parseInt(a.substring(aStartIndex, aIndex));
            int bN = Integer.parseInt(b.substring(bStartIndex, bIndex));
            
            if(aN != bN){
                return aN < bN ? -1 : 1;
            }
            
            int aI = Arrays.asList(files).indexOf(a);
            int bI = Arrays.asList(files).indexOf(b);
            
            return aI < bI ? -1 : 1;
        });
        
        
        return answer;
    }
}