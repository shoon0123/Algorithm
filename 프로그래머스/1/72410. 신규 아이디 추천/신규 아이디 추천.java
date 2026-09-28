class Solution {
    public String solution(String new_id) {
        //1단계 대문자->소문자
        String answer = new_id.toLowerCase();
        
        //2단계 제외(^) 소문자(a-z) 숫자(0-9) 빼기,밑줄,마침표 (-_.)
        answer = answer.replaceAll("[^a-z0-9-_.]", "");
        
        //3단계 .이 (\.) 2번 이상 ({2,}) 연속
        answer = answer.replaceAll("\\.{2,}", ".");
        
        //4단계 .으로 시작하거나 (^\.) 또는(|) .으로 끝나거나(\.$)
        answer = answer.replaceAll("^\\.|\\.$", "");
        
        //5단계 빈 문자열 -> "a"
        if(answer.isEmpty()){
            answer = "a";
        }
        
        //6단계 16자 이상이면 15개 뒤는 제거
        if(answer.length() >= 16){
            answer = answer.substring(0, 15);
            //제거 후 끝에 .이 있다면 제거
            answer = answer.replaceAll("\\.$", "");
        }
        
        //7단계 2자 이하라면 3자가 될때까지 마지막 문자 복사
        while(answer.length() <= 2){
            answer += answer.charAt(answer.length() - 1);
        }
        
        
        return answer;
    }
}