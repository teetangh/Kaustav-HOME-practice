
/**
 * Server
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    ServerSocket serverSocket;
    Socket socket;

    BufferedReader br;
    PrintWriter pw;

    // Constructor
    public Server() {
        try {
            serverSocket = new ServerSocket(7777);
            System.out.println("Server is ready to accept connection. Waiting...");
            socket = serverSocket.accept();

            br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            pw = new PrintWriter(socket.getOutputStream());

        } catch (Exception e) {
            e.printStackTrace();
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
                        System.out.println("Client terminated the chat");
                        socket.close();
                        break;
                    }
                    System.out.println("Client :" + msg);
                }

            } catch (Exception e) {
                // e.printStackTrace();
                System.out.println("Server Reader Closed");
            }
            System.out.println("Server Reader Closed");

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
                // e.printStackTrace();
                System.out.println("Server Writer Closed");
            }
            System.out.println("Server Writer Closed");
        };
        new Thread(r2).start();

    }

    public static void main(String[] args) {
        System.out.println("This is the server. Going to start the server");
        Server server = new Server();
    }

}