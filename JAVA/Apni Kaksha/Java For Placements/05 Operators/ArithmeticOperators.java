/**
 * ArithmeticOperators
 */
public class ArithmeticOperators {

    public static void main(String[] args) {

        int a = 23;
        int b = 45;

        {
            int c = a + b;
            System.out.println(c);
            c = a - b;
            System.out.println(c);
            c = a * b;
            System.out.println(c);
            c = a / b;
            System.out.println(c);

            // BODMAS Rule
            c = a * a + b * b + 2 * a * b;
            System.out.println(c);
            int d = (a + b) * (a + b);
            System.out.println(d);

        }
        {
            // Division
            double c = (double) b / (double) a;
            System.out.println(c);
        }
        {
            // Modulo
            int c = b % a;
            System.out.println(c);
        }
        {
            // Post increment
            int c = b++;
            System.out.println(c + " " + b);
        }
        {
            // Pre increment
            int c = ++b;
            System.out.println(c + " " + b);
        }
        {
            // Post decrement
            int c = b--;
            System.out.println(c + " " + b);
        }
        {
            // Pre decrement
            int c = --b;
            System.out.println(c + " " + b);
        }
    }
}