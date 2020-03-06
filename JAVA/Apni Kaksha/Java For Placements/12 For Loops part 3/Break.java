import java.util.Scanner;

/**
 * Break
 */
public class Break {

    public static void main(String[] args) {
        for (int i = 1; i < 100; i++) {
            System.out.print(i + " ");
            if (i == 35)
                break;

        }

        Scanner sc = new Scanner(System.in);
        System.out.println();
        for (;;) {
            int n = sc.nextInt();
            if (n < 0) {
                break;
            }
        }
        sc.close();
    }
}

// Sample IO
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
// 30 31 32 33
// 34 35
// 6
// 7
// 8
// -1