//total_time : x초에 시작하는 재생마다 +1, x초에 끝나는 재생마다 -1
//           ->x초~x+1초에 재생 수
//           ->0~x+1초에 재생되는 초의 누적합

class Solution {
    public String solution(String play_time, String adv_time, String[] logs) {
        String answer = "";
        long[] total_time = new long[360000];
        int at, pt, h, m, s;
        String[] adv = adv_time.split(":");
        h = Integer.parseInt(adv[0]);
        m = Integer.parseInt(adv[1]);
        s = Integer.parseInt(adv[2]);
        at = h*3600 + m*60 + s;
        String[] play = play_time.split(":");
        h = Integer.parseInt(play[0]);
        m = Integer.parseInt(play[1]);
        s = Integer.parseInt(play[2]);
        pt = h*3600 + m*60 + s;
        
        for (int i=0; i<logs.length; ++i) {
            String[] log = logs[i].split("-");
            int start;
            String[] s1 = log[0].split(":");
            h = Integer.parseInt(s1[0]);
            m = Integer.parseInt(s1[1]);
            s = Integer.parseInt(s1[2]);
            start = h*3600 + m*60 + s;
            total_time[start]++;
            
            int end;
            String[] s2 = log[1].split(":");
            h = Integer.parseInt(s2[0]);
            m = Integer.parseInt(s2[1]);
            s = Integer.parseInt(s2[2]);
            end = h*3600 + m*60 + s;
            total_time[end]--;
        }
        
        for (int i=1; i<pt; ++i) {
            total_time[i] = total_time[i] + total_time[i-1];
        }
        for (int i=1; i<pt; ++i) {
            total_time[i] = total_time[i] + total_time[i-1];
        }
        long max_time = total_time[at-1];
        int idx = at-1;
        for (int i=at; i<pt; ++i) {
            if (total_time[i] - total_time[i-at] > max_time) {
                max_time = total_time[i] - total_time[i-at];
                idx = i;
            }
        }
        idx -= at-1;
        h = idx / 3600;
        m = (idx % 3600) / 60;
        s = (idx % 3600) % 60;
        answer = String.format("%02d", h) + ":" + String.format("%02d", m) + ":" + String.format("%02d", s);
        return answer;
    }
}