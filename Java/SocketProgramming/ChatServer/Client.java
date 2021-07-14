
/**
 * Client
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {

    Socket socket;

    BufferedReader br;
    PrintWriter pw;

    public Client() {
        try {
            System.out.println("Sending request to server");
            socket = new Socket("127.0.0.1", 7777);
            System.out.println("Connection done.");

            br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            pw = new PrintWriter(socket.getOutputStream());

        } catch (Exception e) {
            // TODO: handle exception
        }

        startReading();
        startWriting();

    }

    public void startReading() {
        // thread - read karke deta rahega
        Runnable r1 = () -> {
            System.out.println("reader started");

            try {
                while (true) {
                    String msg = br.readLine();
                    if (msg.equals("exit")) {
                        System.out.println("Server terminated the chat");
                        socket.close();
                        break;
                    }
                    System.out.println("Server :" + msg);
                }

            } catch (Exception e) {
                e.printStackTrace();
                System.out.println("Client Reader Closed");
            }
            System.out.println("Client Reader Closed");
        };

        new Thread(r1).start();
    }

    public void startWriting() {
        // thread - data user lega and then send karega client tak
        Runnable r2 = () -> {

            System.out.println("writer started");

            try {
                while (!socket.isClosed()) {

                    BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
                    String content = br1.readLine();
                    pw.println(content);
                    pw.flush();

                    if (content.equals("exit")) {
                        socket.close();
                        break;
                    }

                }
            } catch (Exception e) {
                e.printStackTrace();
                System.out.println("Client Writer Closed");
            }
            System.out.println("Client Writer Closed");

        };
        new Thread(r2).start();

    }

    public static void main(String[] args) {
        System.out.println("This is the client");
        Client client = new Client();
    }
}