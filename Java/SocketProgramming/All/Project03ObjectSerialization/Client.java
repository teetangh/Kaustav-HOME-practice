
/**
 * Client
 */

import java.io.*;
import java.net.*;

public class Client {

    public static void main(String[] args) throws Exception {
        if ((args.length == 2) && Client.isInteger(args[0]) && Client.isInteger(args[1])) {
            Integer firstNumber = Integer.decode(args[0]);
            Integer secondNumber = Integer.decode(args[1]);
            Socket socket = new Socket("localhost", Server.PORT);

            ObjectOutputStream objectOutputStream = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream objectInputStream = new ObjectInputStream(socket.getInputStream());
            Message message = new Message(firstNumber, secondNumber);
            objectOutputStream.writeObject(message);

            Message returnMessage = (Message) objectInputStream.readObject();
            System.out.println(returnMessage.getResult());
            socket.close();
        } else {
            System.out.println("Usage: Client <integer> <integer>");
        }
    }

    private static boolean isInteger(String value) {
        boolean returnValue = true;
        try {
            Integer.parseInt(value);
        } catch (Exception e) {
            returnValue = false;
        }
        return returnValue;
    }
}