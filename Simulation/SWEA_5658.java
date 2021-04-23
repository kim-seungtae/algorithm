import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;

public class Solution {
    static int T, N, K, numLen;
    static char[] input;
    static HashSet<Integer> set;
    static int hexToInt(int start, int end) {
        StringBuilder tmp = new StringBuilder();
        for (int i=start; i!=end; i=(i+1)%N) {
            tmp.append(input[i]);
        }
        return Integer.parseInt(tmp.toString(), 16);
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        T = Integer.parseInt(br.readLine());
        
        for (int t=1; t<=T; t++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            input = br.readLine().toCharArray();

            numLen = N / 4;
            set = new HashSet<>();

            for (int i=0; i<N; ++i) {
                for (int j=i; j!=(i+3*numLen)%N; j=(j+numLen)%N) {
                    set.add(hexToInt(j, (j+numLen)%N));
                }
            }
            ArrayList<Integer> arr = new ArrayList<>();
            for (int i : set) arr.add(i);

            Collections.sort(arr, Collections.reverseOrder());

            System.out.println("#" + t + " " + arr.get(K-1));
        }
    }
}
