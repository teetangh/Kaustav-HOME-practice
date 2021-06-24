
import java.util.ArrayList;

interface ListListener<T> {
    /* .. */
    void beforeAdd(T item);

    void afterAdd(T item);

    /* .. */
    void beforeRemove(T item);

    void afterRemove(T item);
}

interface Listenable<T> {
    /* .. */
    void setListener(ListListener<T> listener);
    /* .. */

}

public class ListenableArrayList<T> extends ArrayList<T> implements Listenable<T> {

    private ArrayList<T> internalList;
    private ListListener<T> listener;

    /* .. */
    public ListenableArrayList() {
        this.internalList = new ArrayList<T>();
        this.setListener(new ListListener<T>() {
            @Override
            public void beforeAdd(T item) {
                System.out.println("About to add element " + item + "...");
            }

            @Override
            public void afterAdd(T item) {
                System.out.println("...element " + item + " has been added.");
            }

            @Override
            public void beforeRemove(T item) {
                System.out.println("About to Remove element " + item + "...");
            }

            @Override
            public void afterRemove(T item) {
                System.out.println("...element " + item + " has been Removeed.");
            }
        });
    }

    public void addItem(T item) {
        listener.beforeAdd(item);
        internalList.add(item);
        listener.afterAdd(item);
    }

    public void removeItem(T item) {
        listener.beforeRemove(item);
        internalList.remove(item);
        listener.afterRemove(item);
    }

    /* .. */

    public void setListener(ListListener<T> listener) {
        this.listener = listener;
    }

    public static void main(String[] args) {
        ListenableArrayList<String> list = new ListenableArrayList<String>();
        System.out.println(list);

        list.addItem("first-string-example");
        list.addItem("second-string-example");
        list.addItem("third-string-example");

        list.removeItem("second-string-example");

        System.out.println(list.internalList);
    }

}
