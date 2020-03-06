/**
 * SwtichCaseStatements
 */
public class SwtichCaseStatements {

    public static void main(String[] args) {
        int dayOfWeek = 4;
        // if (dayOfWeek == 1) {

        // }
        // if (dayOfWeek == 2) {

        // }
        // if (dayOfWeek == 3) {

        // }
        // if (dayOfWeek == 4) {

        // }
        // if (dayOfWeek == 5) {

        // }
        // if (dayOfWeek == 6) {

        // }
        // if (dayOfWeek == 7) {

        // }

        switch (dayOfWeek) {
            case 1:
                System.out.println("Monday");
                break;
            case 2:
                System.out.println("Tuesday");
                break;
            case 3:
                System.out.println("Wednesday");
                break;
            case 4:
                System.out.println("Thursday");
                break;
            case 5:
                System.out.println("Friday");
                break;
            case 6:
                System.out.println("Saturday");
                break;
            case 7:
                System.out.println("Sunday");
                break;
            default:
                System.out.println("Invalid Day");
                break;
        }
    }
}