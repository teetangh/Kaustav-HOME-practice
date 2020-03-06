/**
 * TypeCasting
 */
public class TypeCasting {

    public static void main(String[] args) {
        // Automatic TypeCasting(Widening)
        byte x = 4;
        int y = x;
        double z = y;
        System.out.println(x);
        System.out.println(y);
        System.out.println(z);

        // Manual Typecasting(Narrowing)
        double myDouble = 3.14;
        int myInt = (int) myDouble;
        System.out.println(myInt);
    }
}