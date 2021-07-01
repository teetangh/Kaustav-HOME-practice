
/**
 * Client
 */

import java.io.*;
import java.net.*;

public class Client {

    public static void main(String[] args) throws Exception {
        if (args.length == 1) {
            String name = args[0];
            Socket socket = new Socket("localhost", Server.PORT);

            ObjectOutputStream objectOutputStream = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream objectInputStream = new ObjectInputStream(socket.getInputStream());
            objectOutputStream.writeObject(name);
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

            while (true) { // Message message = new Message(firstNumber, secondNumber);
                String readerInput = bufferedReader.readLine();
                String[] readerInputTokens = readerInput.split("\u0020");
                Message message = new Message(Integer.decode(readerInputTokens[0]),
                        Integer.decode(readerInputTokens[1]));

                objectOutputStream.writeObject(message);

                Message returnMessage = (Message) objectInputStream.readObject();
                System.out.println(returnMessage.getResult());
            }
        } else {
            System.out.println("Usage: Client <name of client> ");
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