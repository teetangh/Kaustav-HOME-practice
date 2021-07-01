
/**
 * ServerThread
 */

import java.io.*;
import java.net.*;

public class ServerThread extends Thread {

    Socket socket;

    ServerThread(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        Message message = null;
        try {

            ObjectInputStream objectInputStream = new ObjectInputStream(socket.getInputStream());
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(socket.getOutputStream());
            String username = (String) objectInputStream.readObject();
            System.out.println(username + " is now connected ");

            while ((message = (Message) objectInputStream.readObject()) != null) {
                doSomething(message);
                objectOutputStream.writeObject(message);
            }
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void doSomething(Message message) {
        message.setResult(message.getFirstNumber().intValue() * message.getSecondNumber().intValue());
    }

}