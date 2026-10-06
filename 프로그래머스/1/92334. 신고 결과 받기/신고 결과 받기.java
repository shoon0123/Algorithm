import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        
        HashMap<String, HashSet<String>> reportMap = new HashMap<>();
        HashMap<String, Integer> countMap = new HashMap<>();
        
        for(int i = 0; i <  report.length; i++){
            String[] strList = report[i].split(" ");
            HashSet<String> set = reportMap.getOrDefault(strList[0], new HashSet<String>());
            set.add(strList[1]);
            reportMap.put(strList[0], set);
        }
        
        for(HashSet<String> set : reportMap.values()){
            for(String s : set){
                countMap.put(s, countMap.getOrDefault(s, 0) + 1);
            }
        }
        
        for(int i = 0; i < id_list.length; i++){
            if(reportMap.get(id_list[i]) != null){
                for(String s : reportMap.get(id_list[i])){
                    if(countMap.get(s) >= k){
                        answer[i]++;
                    }
                }
            }
        }
        
        return answer;
    }
}