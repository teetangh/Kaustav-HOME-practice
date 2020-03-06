import java.util.Scanner;

/**
 * ScannerUserInput
 */
public class ScannerUserInput {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        double y = sc.nextDouble();
        // flushing Buffer
        // sc.next(); Doesn't Work
        sc.nextLine();
        String z = sc.nextLine();

        System.out.println(" Printing " + x);
        System.out.println(" Printing " + y);
        System.out.println(" Printing " + z);

        System.out.println("Enter P,R,T");
        int principal = sc.nextInt();
        float rate = sc.nextFloat();
        int time = sc.nextInt();
        float simpleInterest = (principal * rate * time) / 100;
        System.out.println("The Simple Interest is " + simpleInterest);
        sc.close();

    }
}

// Sample IO
// 5
// 6
// Hello
//  Printing 5
//  Printing 6.0
//  Printing Hello
// Enter P,R,T
// 2000 8.34 34
// The Simple Interest is 5671.2