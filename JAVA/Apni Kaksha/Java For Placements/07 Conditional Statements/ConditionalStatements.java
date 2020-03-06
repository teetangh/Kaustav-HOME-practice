/**
 * ConditionalStatements
 */
public class ConditionalStatements {

    public static void main(String[] args) {

        // IF
        int age = 18;

        if (age >= 18) {
            System.out.println("Elligble for voting");
        }

        // IF-ELSE
        int noOfPetals = 5;

        if (noOfPetals % 2 == 0) {
            System.out.println("She Loves me");
        } else
            System.out.println("She Doesnt");

        // ELSE-IF LADDER
        int number = 23;
        if (number <= 10) {
            System.out.println("Number is less than 10");
        } else if (number > 10 && number <= 20) {
            System.out.println("number b/w 10 and 20");
        } else if (number > 20 && number <= 30) {
            System.out.println("number b/w 20 and 30");
        } else {
            System.out.println("Number is greater than 30");
        }

        // Ternary Opertor
        // variable =(condtion)?expressionTrue:expressionFalse

        int a = 15;
        int b = 8;
        int maxOfBothNumbers = 0;

        maxOfBothNumbers = (a > b) ? a : b;
        System.out.println("max of Both Numbers is " + maxOfBothNumbers);

    }
}