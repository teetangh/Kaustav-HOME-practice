import java.net.*;
import java.io.*;

/**
 * Server
 */
public class Server {

    public static int PORT = 3191;

    public static void main(String[] args) throws Exception {
        new Server();
    }

    public Server() throws Exception {
        System.out.println("Server is up and running on port" + PORT);
        ServerSocket serverSocket = new ServerSocket(PORT);
        Socket socket = serverSocket.accept();

        ObjectOutputStream outStream = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream inStream = new ObjectInputStream(socket.getInputStream());

        Packet recvPacket = (Packet) inStream.readObject();
        System.out.println(recvPacket.message);

        if (recvPacket.message.equals("Hello")) {
            Packet packet = new Packet("Hi from the server :)");
            outStream.writeObject(packet);
        }

        serverSocket.close();
    }

}