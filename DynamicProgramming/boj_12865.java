import java.util.Scanner;


public class Main {
    static class Pair {
        public Integer Key;
        public Integer Value;
        public Pair(Integer key, Integer value) {
            this.Key = key;
            this.Value = value;
        }
        public void setKey(Integer key) {this.Key = key;}
        public void setValue(Integer value) {this.Value = value;}
        public Integer getKey() {return Key;}
        public Integer getValue() {return Value;}
    }
    static int n, k;
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        
        n = sc.nextInt();
        k = sc.nextInt();
        Pair[] l = new Pair[n+1];
        int[][] dp = new int[n+1][k+1];
        for (int i=1; i<=n; i++) {
            l[i] = new Pair(sc.nextInt(), sc.nextInt());
        }

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=k; j++) {
                dp[i][j] = dp[i-1][j];
                if (j-l[i].getKey() >= 0) {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-l[i].getKey()] + l[i].getValue());
                }
            }
        }
        System.out.println(dp[n][k]);
    }
}
