import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;
public class Main {
    static class Pair<L, R> {
        L left;
        R right;

        public Pair(L left, R right) {
            this.left = left;
            this.right = right;
        }

        static <L, R> Pair<L, R> of(L left, R right) {
            return new Pair<L, R>(left, right);
        }
    }
    static int N, M, ry, rx, rd;
    static int ydir[] = {-1, 0, 1, 0};
    static int xdir[] = {0, 1, 0, -1};
    static int map[][] = new int[50][50]; //0: empty, 1:wall, 2:cleansed
    static int rotate(int d) {
        if (d == 0) d = 3;
        else if (d == 1) d = 0;
        else if (d == 2) d = 1;
        else if (d == 3) d = 2;
        return d;
    }
    static int move() {
        int i=(rd+3)%4, n=4;
        while(n!=0) {
            int newY = ry + ydir[i];
            int newX = rx + xdir[i];

            if (map[newY][newX] == 0) {
                ry = newY;
                rx = newX;
                rd = i;
                map[newY][newX] = 2;
                return 1;
            }
            i = (i+3)%4;
            n--;
        }
        //4 dirs are cleansed
        //back wall
        if (map[ry - ydir[rd]][rx - xdir[rd]] == 1) {
            return 0;
        }
        else {
            ry -= ydir[rd];
            rx -= xdir[rd];
            return 2;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        ry = Integer.parseInt(st.nextToken());
        rx = Integer.parseInt(st.nextToken());
        rd = Integer.parseInt(st.nextToken());

        for (int i=0; i<N; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j<M; ++j) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        int ans = 1;
        map[ry][rx] = 2;
        while(true) {
            int tmp = move();
            if (tmp == 0) break;
            else if (tmp == 1) ans += 1;
        }
        System.out.println(ans);
    }
}