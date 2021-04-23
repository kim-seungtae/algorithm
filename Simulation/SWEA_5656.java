import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Stack;

public class Solution {

    static int[][] map = new int[16][13];
    static int T, N, W, H, ans;
    static int ydir[] = {0, 0, -1, 1};
    static int xdir[] = {1, -1, 0, 0};

    static class Pair {
        private int first;
        private int second;

        public Pair(int f, int s) {
            this.first = f;
            this.second = s;
        }

        public void setFirst(int f) { this.first = f;}
        public void setSecond(int s) { this.second = s;}
        public int first() {return this.first;}
        public int second() {return this.second;}
    }
    static void copyAToB(int[][] a, int[][] b) {
        for (int i=0; i<16; ++i) {
            b[i] = Arrays.copyOf(a[i], a[i].length);
        }
    }
    static void drop() {
        ArrayList<Integer> l = new ArrayList<>();
        for (int i=0; i<W; ++i) {
            for (int j=H-1; j>=0; --j) {
                if (map[j][i] != 0) {
                    l.add(map[j][i]);
                    map[j][i] = 0;
                }
            }
            int idx = 0;
            for (int j=H-1; j>=0; --j) {
                if (idx >= l.size()) break;
                map[j][i] = l.get(idx++);
            }
            l.clear();
        }
    }
    static void bomb(int col) {
        int row = 0;
        while (map[row][col] == 0) {
            row++;
            if (row >= H) return;
        }
        Pair root = new Pair(row, col);
        Stack<Pair> s = new Stack<>();
        s.push(root);

        while(!s.isEmpty()) {
            int y = s.peek().first;
            int x = s.peek().second;
            s.pop();

            int bombSize = map[y][x];
            map[y][x] = 0;
            for (int i=0; i<4; ++i) {
                for (int j=0; j<bombSize; ++j) {
                    int newY = y + ydir[i] * j;
                    int newX = x + xdir[i] * j;

                    if (newY >= 0 && newY < H && newX >= 0 && newX < W) {
                        if (map[newY][newX] > 1) {
                            s.push(new Pair(newY, newX));
                        }
                        if (map[newY][newX] == 1) map[newY][newX] = 0;
                    }
                }
            }
        }
    }
    static int score() {
        int cnt = 0;
        for (int y=0; y<H; ++y) {
            for (int x=0; x<W; ++x) {
                if (map[y][x] != 0) cnt++;
            }
        }
        return cnt;
    }
    static void dfs(int count) {
        if (count == N) {
            ans = Math.min(ans, score());
            return;
        }

        for (int i=0; i<W; ++i) {
            int[][] tmp = new int[16][13];
            copyAToB(map, tmp);
            bomb(i);
            drop();
            dfs(count+1);
            copyAToB(tmp, map);
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        T = Integer.parseInt(br.readLine());
        for (int t=1; t<=T; ++t) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());

            ans = 999999999;
            for (int y=0; y<H; ++y) {
                st = new StringTokenizer(br.readLine());
                for (int x=0; x<W; ++x) {
                    map[y][x] = Integer.parseInt(st.nextToken());
                }
            }

            for (int i=0; i<W; i++) {
                dfs(0);
            }
            System.out.println("#" + t + " " + ans);
        }
    }
}
