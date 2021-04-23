import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    static int N, M;
    static int[][] map = new int[20][20];
    static int max(int a, int b) {return a>b?a:b;}
    static int numOfHouse(int i, int j, int k) {
        int num = 0;
        int ylen = k-1, xlen = 0;
        for (int y=i-ylen; y<i; ++y) {
            for (int x=j-xlen; x<=j+xlen; ++x) {
                if (y < 0 || y >= N || x < 0 || x >= N) continue;
                if (map[y][x] == 1) num += 1;
            }
            xlen += 1;
        }
        for (int x=j-xlen; x<=j+xlen; ++x) {
            if (i < 0 || i >= N || x < 0 || x >= N) continue;
            if (map[i][x] == 1) num += 1;
        }
        for (int y=i+1; y<=i+ylen; ++y) {
            xlen -= 1;
            for (int x=j-xlen; x<=j+xlen; ++x) {
                if (y < 0 || y >= N || x < 0 || x >= N) continue;
                if (map[y][x] == 1) num += 1;
            }
        }
        return num;
    }
    static int score(int i, int j, int k) {
        int cost = k*k + (k-1)*(k-1);
        int houseNum = numOfHouse(i, j, k);
        int profit = houseNum * M - cost;
        return profit >= 0 ? houseNum : 0;
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        
        for (int t=1; t<=T; ++t) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            for (int i=0; i<N; ++i) {
                st = new StringTokenizer(br.readLine());
                for (int j=0; j<N; ++j) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            
            int ans = 0;
            for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) for (int k=1; k<=N+1; ++k) {
                ans = max(ans, score(i, j, k));
            }
            System.out.println("#" + t + " " + ans);
        }
    }
}
