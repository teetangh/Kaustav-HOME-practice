/**
 * ServerThread
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Socket;

public class ServerThread extends Thread {

    Socket socket;

    public ServerThread(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        try {
            String message = null;
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            while ((message = bufferedReader.readLine()) != null) {
                System.out.println("Incoming client message: " + message);
            }
            socket.close();

        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        }
    }

}