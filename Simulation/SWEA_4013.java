import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    static int[][] gear = new int[4][8];
    static int[][] rList = new int[2][20];
    static int[] isRotate = new int[4];
    static int T, K, ans;
    static void rotate(int idx, int dir) {
        if (dir == 0) return;
        int i=0, cnt=7;
        int tmp = gear[idx][0];
        while (cnt != 0) {
            gear[idx][i] = gear[idx][(i-dir+8)%8];
            i = (i - dir + 8) % 8;
            cnt--;
        }
        gear[idx][i] = tmp;
    }
    static void play(int idx, int dir) {
        int i = idx;
        isRotate[idx] = dir;
        while (i > 0) {
            if (gear[i][6] != gear[i-1][2]) {
                isRotate[i-1] = isRotate[i] * -1;
            }
            else break;
            i--;
        }
        i = idx;
        while (i < 3) {
            if (gear[i][2] != gear[i+1][6]) {
                isRotate[i+1] = isRotate[i] * -1;
            }
            else break;
            i++;
        }
        for (int j=0; j<4; ++j) {
            rotate(j, isRotate[j]);
        }
    }
    static int score() {
        int score = 0;
        for (int i=0; i<4; ++i) {
            if (gear[i][0] == 1) score += 1 << i;
        }
        return score;
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
        
        for (int t=1; t<=T; ++t) {
            st = new StringTokenizer(br.readLine());
            K = Integer.parseInt(st.nextToken());
            for (int i=0; i<4; ++i) {
                st = new StringTokenizer(br.readLine());
                for (int j=0; j<8; ++j) {
                    gear[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            for (int i=0; i<K; ++i) {
                st = new StringTokenizer(br.readLine());
                rList[0][i] = Integer.parseInt(st.nextToken()) - 1;
                rList[1][i] = Integer.parseInt(st.nextToken());
            }
            
            for (int i=0; i<K; ++i) {
                for (int j=0; j<4; ++j) isRotate[j] = 0;
                play(rList[0][i], rList[1][i]);
            }
            System.out.println("#" + t + " " + score());
        }
    }
}
