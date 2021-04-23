import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
public class Main {
    static class Pair<L extends Comparable<L>, R extends Comparable<R>> implements Comparable<Pair<L, R>>{
        L left;
        R right;

        Pair (L left, R right) {
            this.left = left;
            this.right = right;
        }

        static <L extends Comparable<L>, R extends Comparable<R>> Pair<L, R> of(L left, R right) {
            return new Pair<>(left, right);
        }

        @Override
        public int compareTo(Pair<L, R> p) {
            return this.right.compareTo(p.right);
        }
    }
    static ArrayList<ArrayList<Pair<Integer, Integer>>> adjList = new ArrayList<>();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int V, E, sNode;
        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        sNode = Integer.parseInt(st.nextToken());
        int[] ans = new int[V+1];
        Arrays.fill(ans, 99999999);
        ans[sNode] = 0;

        for (int i=0; i<=V; ++i) {
            ArrayList<Pair<Integer, Integer>> tmp = new ArrayList<>();
            adjList.add(tmp);
        }
        for (int i=0; i<E; ++i) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int len = Integer.parseInt(st.nextToken());
            adjList.get(s).add(new Pair<Integer, Integer>(e, len));
        }

        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>();
        pq.add(new Pair<Integer, Integer>(sNode, 0));
        while (!pq.isEmpty()) {
            Pair<Integer, Integer> cur = pq.peek(); pq.poll();
            int d = cur.right;
            if (d > ans[cur.left]) continue;
            for (Pair<Integer, Integer> next : adjList.get(cur.left)) {
                if (ans[next.left] > d + next.right) {
                    ans[next.left] = d + next.right;
                    pq.add(new Pair<Integer, Integer>(next.left, ans[next.left]));
                }
            }
        }
        for (int i=1; i<=V; ++i) {
            if (ans[i] == 99999999) System.out.println("INF");
            else System.out.println(ans[i]);
        }

        
    }
}
