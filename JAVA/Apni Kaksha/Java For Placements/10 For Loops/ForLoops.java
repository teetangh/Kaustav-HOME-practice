/**
 * ForLoops
 */
public class ForLoops {
    public static void main(String[] args) {
        for (int i = 0; i < 100; i++) {
            System.out.println("1st World " + i);
        }
        for (int i = 0; i < 100; i = i + 2) {
            System.out.println("2nd World " + i);
        }
        for (int i = 1; i < 100; i = i * 2) {
            System.out.println("3rd World " + i);
        }
        for (int i = 2; i < 100; i = i * i) {
            System.out.println("4th World " + i);
        }

        int sum = 0;
        int n = 100;
        for (int i = 0; i <= n; i++) {
            sum += i;
        }j
        System.out.println(sum);

        for (int i = 5; i > 0; i--) {
            System.out.println(i);

        }

        int tableOf = 4;
        for (int i = 1; i <= 10; i++) {
            System.out.println(tableOf * i);

        }
    }

}