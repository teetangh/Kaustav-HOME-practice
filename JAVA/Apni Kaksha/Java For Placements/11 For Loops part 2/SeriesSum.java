import java.util.Scanner;

/**
 * SeriesSum
 */
public class SeriesSum {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        float result = 0;
        for (float i = 1; i <= n; i++) {
            result += 1 / i;
        }

        System.out.println("Result is" + result);
        // WRONG APPROACH
        // result = 0;
        // for (int i = 1; i <= n; i++) {
        // result += 1 / i;
        // }

        // System.out.println("Result is" + result);
        sc.close();
    }
}