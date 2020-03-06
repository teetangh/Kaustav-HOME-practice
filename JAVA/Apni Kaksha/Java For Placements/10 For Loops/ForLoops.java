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
    }

}