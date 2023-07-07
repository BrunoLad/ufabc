// package tcpsocket;

//
import java.io.*;
import java.net.*;

public class TCPServer implements Runnable{
	Socket s;
	TCPServer(Socket s) {
		this.s = s;
	}

    public static void main (String args[]) throws Exception {
				
        	 ServerSocket serverSocket = new ServerSocket(9000);
		 // waits for a new connection. Accepts connetion from multiple clients
		 while (true) 
		 {
			 System.out.println("Esperando conexão na porta 9000");
                 	 Socket s = serverSocket.accept();
			 System.out.println("Conexão estabelecida de " + s.getInetAddress());
			 
			 new Thread(new TCPServer(s)).start();
		 }
    }

	public void run() {
		// create a BufferedReader object to read strings from
			 // the socket. (read strings FROM CLIENT)
			 try{
			 BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			 String input = br.readLine();
			 
			 //create output stream to write to/send TO CLINET
                         DataOutputStream output = new DataOutputStream(s.getOutputStream());
			 
			 output.writeBytes(input.toUpperCase() + "\n");
			 // close current connection
			 s.close();
			 } catch (IOException e) {
				 System.out.println(e);
			 }
	}
}
