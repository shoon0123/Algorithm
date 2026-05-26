class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        //가로 x, 세로 y
        //brown == 2(x+y-2)
        //x+y = (brown+4)/2;
        int xy = (brown + 4) / 2;
        for(int i = 1; i < xy; i++){
            if((i - 2) * (xy - i -2) == yellow){
                answer[0] = xy - i;
                answer[1] = i;
                break;
            }
        }
        
        return answer;
    }
}