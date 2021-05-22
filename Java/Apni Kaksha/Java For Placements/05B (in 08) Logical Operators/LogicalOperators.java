/**
 * LogicalOperators
 */
public class LogicalOperators {

    public static void main(String[] args) {
        int number = 45;
        if (number >= 1 && number <= 100)
            System.out.println("NUmber is in Range");

        int grade = 10;
        if (grade == 10 || grade == 12) {
            System.out.println("YOu can give Board Exams now");
        } else
            System.out.println("YOu cant give board exams now");
    }

}