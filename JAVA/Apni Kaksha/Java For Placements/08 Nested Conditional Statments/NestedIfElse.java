
/**
 * NestedIfElse
 */
import java.util.Scanner;

public class NestedIfElse {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        int result = 0;
        if (a > b) {
            if (a > c) {
                result = a;
            } else
                result = c;
        } else {
            if (b > c) {
                result = b;
            } else {
                result = c;
            }
        }
        System.out.println("Largest of 3 nos is " + result);
        sc.close();

        int result2 = a > b ? a > c ? a : c : b > c ? b : c;
        System.out.println("Largest of 3 nos is " + result2);

    }
}

// Sample IO
// 6 7 8
// Largest of 3 nos is 8
// Largest of 3 nos is 8