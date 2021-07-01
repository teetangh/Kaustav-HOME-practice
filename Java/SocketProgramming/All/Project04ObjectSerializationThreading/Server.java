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
        while (true) {
            Socket socket = serverSocket.accept();
            new ServerThread(socket).start();
        }
    }

}