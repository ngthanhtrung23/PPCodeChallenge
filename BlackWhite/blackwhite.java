import java.util.*;

public class blackwhite{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ntest = sc.nextInt();
        for(int test = 0; test < ntest; ++test) {
            // Read input
            int x1 = sc.nextInt(),
                y1 = sc.nextInt(),
                x2 = sc.nextInt(),
                y2 = sc.nextInt();

            // Handle trap: x1 > x2 and y1 > y2
            if (x1 > x2) {
                int tmp = x1;
                x1 = x2;
                x2 = tmp;
            }
            if (y1 > y2) {
                int tmp = y1;
                y1 = y2;
                y2 = tmp;
            }

            int res = 0;
            for(int i = x1; i <= x2-2; ++i)
                for(int j = y1; j <= y2-2; ++j) {
                    int cnt = 0;
                    if (i != j) ++res;
                }
            System.out.println(res);
        }
        sc.close();
    }
}
