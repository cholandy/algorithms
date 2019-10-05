import java.util.Comparator;

public class TaskK {
    static class Pair {
        int id;
        int deg;

        public Pair(int id, int deg) {
            this.id = id;
            this.deg = deg;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();

        int[] deg = new int[n];
        for (int i = 0; i < m; ++i) {
            int a = in.nextInt();
            int b = in.nextInt();
            ++deg[a];
            ++deg[b];
        }

        Pair[] pairs = new Pair[n];
        for (int i = 0; i < n; ++i) {
            pairs[i] = new Pair(i, deg[i]);
        }

        Arrays.sort(pairs, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return o1.deg - o2.deg;
            }
        });

        int cnt = 0;
        int sum = 0;
        for (Pair p : pairs) {
            int ncnt = cnt + 1;
            int nsum = sum + p.deg;
            if (nsum + (n - ncnt) <= 2 * (n - 1)) {
                cnt = ncnt;
                sum = nsum;
            } else {
                break;
            }
        }

        int togo = 2 * (n - 1) - sum;
        for (int i = cnt; i < n; ++i) {
            deg[pair[i].id] = (i == n - 1 ? togo : 1);
            --togo;
        }
        out.println(n - cnt);
        out.println(n + " " + (n - 1));

        while (true) {
            int m1 = 0;
            int v1 = -1;
            for (int j = 0; j < n; ++j) {
                int d = deg[j];
                if (d > m1) {
                    m1 = d;
                    v1 = j;
                }
            }
            if (v1 < 0)
                break;
            for (int j = 0; j < n; ++j)
                if (j != v1 && deg[j] == 1) {
                    --deg[j];
                    --deg[v1];
                    out.println(j + " " + v1);
                    break;
                }
        }

        for (int x : deg)
            if (x != 0)
                throw new RuntimeException();
    }
}