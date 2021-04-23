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
    static ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
    static int N, M;
    static int visited[] = new int[1001];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i=0; i<=N; ++i) {
            ArrayList<Integer> tmp = new ArrayList<>();
            adjList.add(tmp);
        }

        for (int i=0; i<M; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adjList.get(a).add(b);
            adjList.get(b).add(a);
        }

        Arrays.fill(visited, 0);

        int ans = 0;
        Stack<Integer> s = new Stack<>();
        for (int i=1; i<=N; ++i) {
            if (visited[i] == 0) {
                ans += 1;
                s.push(i);
                visited[i] = 1;
                while (!s.isEmpty()) {
                    int cur = s.peek(); s.pop();
                    for (int next : adjList.get(cur)) {
                        if (visited[next] == 0) {
                            visited[next] = 1;
                            s.push(next);
                        }
                    }
                }
            }
        }
        System.out.println(ans);
    }
}
