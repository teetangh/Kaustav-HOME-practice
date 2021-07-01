import java.io.*;
import java.net.*;

public class Server {
    public static final int PORT = 4444;

    public static void main(String[] args) throws Exception {
        new Server().runServer();
    }

    public void runServer() throws Exception {
        ServerSocket serverSocket = new ServerSocket(PORT);
        System.out.println("Server up and ready for connections...");

        Socket socket = serverSocket.accept();
        ObjectInputStream objectInputStream = new ObjectInputStream(socket.getInputStream());
        ObjectOutputStream objectOutputStream = new ObjectOutputStream(socket.getOutputStream());
        Message message = (Message) objectInputStream.readObject();
        doSomething(message);
        objectOutputStream.writeObject(message);
        socket.close();
        serverSocket.close();

        // while (true) {
        // new ServerThread(socket).start();
        // }
    }

    private void doSomething(Message message) {
        message.setResult(message.getFirstNumber().intValue() * message.getSecondNumber().intValue());
    }

}