import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class Solution {
    static class WormHole {
        int y, x, num;
        public WormHole() {}
        public WormHole(int num, int y, int x) {
            this.y = y;
            this.x = x;
            this.num = num;
        }
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int T, N, ans = 0;
    static int[][] map = new int[100][100];
    static int[] dy = {0, 1, 0, -1};
    static int[] dx = {1, 0, -1, 0};
    static ArrayList<WormHole> wormHoles = new ArrayList<>();
    static void input() throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j<N; ++j) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] >= 6 && map[i][j] <= 10) {
                    wormHoles.add(new WormHole(map[i][j], i, j));
                }
            }
        }
    }
    static int change_d(int wall, int d) {
        if (wall == 5) d = (d + 2) % 4;
        else if (wall % 4 == d) d = (d + 3) % 4;
        else if (wall % 4 == (d + 3) % 4) d = (d + 1) % 4;
        else d = (d + 2) % 4;
        return d;
    }
    static WormHole move_WormHole(WormHole start) {
        WormHole end = new WormHole();
        for (WormHole i : wormHoles) {
            if (i.num == start.num && (i.y != start.y || i.x != start.x)) {
                end = i;
            }
        }
        return end;
    }
    static int play(int sy, int sx, int d) {
        int y = sy, x = sx, score = 0;
        while (true) {
            y = y + dy[d]; x = x + dx[d];
            if (y < 0 || y >= N || x < 0 || x >= N) {
                score += 1;
                d = (d+2)%4;
            }
            else if (y == sy && x == sx || map[y][x] == -1) break;
            else if (map[y][x] >= 1 && map[y][x] <= 5) {
                score += 1;
                d = change_d(map[y][x], d);
            }
            else if (map[y][x] >= 6 && map[y][x] <= 10) {
                WormHole wh = move_WormHole(new WormHole(map[y][x], y, x));
                y = wh.y;
                x = wh.x;
            }
        }
        return score;
    }
    static void solve() {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                for (int k=0; k<4; ++k) {
                    if (map[i][j] == 0) {
                        ans = Math.max(ans, play(i, j, k));
                    }
                }
            }
        }
    }
    static void init() {
        wormHoles.clear();
        ans = 0;
    }
    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());

        for (int t=1; t<=T; t++) {
            init();
            input();
            solve();
            System.out.println("#" + t + " " + ans);
        }
    }
}
