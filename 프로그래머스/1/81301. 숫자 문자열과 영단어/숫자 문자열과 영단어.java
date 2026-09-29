class Solution {
    public int solution(String s) {
        
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0 ; i < s.length(); i++){
            switch(s.charAt(i)){
                case 'z':
                    i += 3;
                    sb.append('0');
                    break;
                case 'o':
                    i += 2;
                    sb.append('1');
                    break;
                case 't':
                    if(s.charAt(i + 1) == 'w'){
                        i += 2;
                        sb.append('2');
                    }else{
                        i += 4;
                        sb.append('3');
                    }
                    break;
                case 'f':
                    if(s.charAt(i + 1) == 'o'){
                        i += 3;
                        sb.append('4');
                    }else{
                        i += 3;
                        sb.append('5');
                    }
                    break;
                case 's':
                    if(s.charAt(i + 1) == 'i'){
                        i += 2;
                        sb.append('6');
                    }else{
                        i += 4;
                        sb.append('7');
                    }
                    break;
                case 'e':
                    i += 4;
                    sb.append('8');
                    break;
                case 'n':
                    i += 3;
                    sb.append('9');
                    break;
                default:
                    sb.append(s.charAt(i));
            }
        }
        
        int answer = Integer.parseInt(sb.toString());
        return answer;
    }
}