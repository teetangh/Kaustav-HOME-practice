/**
 * BitwiseOperators
 */
public class BitwiseOperators {
    public static void main(String[] args) {
        {
            // eg:
            // 4-> 100
            // 5-> 101
            // 6-> 110

            int a = 5;
            int b = 6;
            int c = a & b;
            System.out.println(c);
        }
        {
            // 10->1010
            // 13->1101

            int a = 10;
            int b = 13;
            int c = a | b;
            System.out.println(c);

        }
        {
            // Shifting
            // Right Shift
            // 1101 -> 0110 ->011 -> 0001 -> 0000 -> 0000
            int b = 13;
            int c = b >> 2;
            System.out.println(c);
            c = b << 2;
            System.out.println(c);
        }
    }
}