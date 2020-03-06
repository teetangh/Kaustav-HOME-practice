
/**
 * Calculator
 */
import java.util.Scanner;

public class Calculator {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 1st Number");
        int a = sc.nextInt();
        System.out.println("Enter 2nd Number");
        int b = sc.nextInt();
        System.out.println("Enter the operator");
        sc.nextLine();
        char operation = sc.nextLine().charAt(0);
        // nextChar() doesnt exist

        int result = 0;
        switch (operation) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            default:
                System.out.println("Invalid Operation");
                break;
        }
        System.out.println("The result is" + result);

        // DRY: Dont repeat Yourself
        System.out.println("Enter Rating");
        int rating = sc.nextInt();

        switch (rating) {
            case 1:
            case 2:
                System.out.println("Bad Review");
                break;
            case 3:
                System.out.println("Average Review");
                break;
            case 4:
            case 5:
                System.out.println("Good  Review");
                break;

            default:
                System.out.println("Fake Review");
                break;
        }
    }

}