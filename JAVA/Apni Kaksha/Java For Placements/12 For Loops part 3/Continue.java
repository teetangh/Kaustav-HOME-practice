/**
 * Continue
 */
public class Continue {

    public static void main(String[] args) {
        for (int i = 1; i <= 100; i++) {
            if (i >= 40 && i <= 50)
                continue;
            else
                System.out.print(i + " ");
        }
    }
}