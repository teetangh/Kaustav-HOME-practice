import java.util.Collection;
import java.util.ArrayList;

/**
 * ArrayListDifference
 */
public class ArrayListDifference {
    public static void main(String[] args) {
        // Create a couple ArrayList objects and populate them
        // with some delicious fruits.
        ArrayList prevList = new ArrayList() {
            {
                add("apple");
                add("orange");
                add("mango");
            }
        };

        ArrayList currList = new ArrayList() {
            {
                add("apple");
                add("orange");
                add("banana");
                add("strawberry");
            }
        };

        // Show the "before" lists
        System.out.println("First List: " + prevList);
        System.out.println("Second List: " + currList);

        // Remove all elements in prevList from currList
        ArrayList addedList = new ArrayList(currList);
        addedList.removeAll(prevList);

        ArrayList removedList = new ArrayList(prevList);
        removedList.removeAll(currList);

        // Show the "after" list
        System.out.println(" ");
        System.out.println("Previous List: " + prevList);
        System.out.println("Current List: " + currList);
        System.out.println("Added List: " + addedList);
        System.out.println("Removed List: " + removedList);

    }
}