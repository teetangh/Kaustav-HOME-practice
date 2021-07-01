
/**
 * ServerThread
 */
import java.io.*;
import java.net.*;

public class ServerThread extends Thread {

    Socket socket;

    public ServerThread(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        try {
            String message = null;
            PrintWriter printWriter = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            System.out.println("User " + bufferedReader.readLine() + "is now connected to the server");

            while ((message = bufferedReader.readLine()) != null) {
                System.out.println("Incoming client message: " + message);
                printWriter.println("Server Echoing Client Message ===>" + message);
            }
            socket.close();

        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        }
    }

}