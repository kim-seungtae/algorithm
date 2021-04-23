import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] lan = new int[10000];
    static int K, N;
    static long numOfLan(long len) {
        long ret = 0;
        for (int i=0; i<K; ++i) {
            ret += (lan[i] / len);
        }
        return ret;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        for (int i=0; i<K; ++i) {
            st = new StringTokenizer(br.readLine());
            lan[i] = Integer.parseInt(st.nextToken());
        }
        long ans = 1;
        long start = 1, end = Integer.MAX_VALUE;
        while (start <= end) {
            long mid = (start + end) / 2;
            if (numOfLan(mid) >= N) {
                start = mid + 1;
                ans = Math.max(ans, mid);
            }
            else {
                end = mid - 1;
            }
        }
        System.out.println(ans);
    }
}
