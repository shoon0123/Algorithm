class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {0, sequence.length - 1};
        
        int left = 0;
        int right = -1;
        int sum = 0;
        
        while(right < sequence.length){
            if(sum == k){
                if(answer[1] - answer[0] > right - left){
                    answer[0] = left;
                    answer[1] = right;
                }
                right++;
                if(right < sequence.length) {
                    sum += sequence[right];
                }
            }
            else if(sum < k){
                right++;
                if(right < sequence.length) {
                    sum += sequence[right];
                }
            }
            else{
                sum -= sequence[left];
                left++;
            }
        }
        
        
        return answer;
    }
}