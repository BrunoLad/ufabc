// package socketudp;

// created on 29/09/2010 at 22:30import java.io.*;
import java.io.*;
import java.net.*;

class UDPClient
{
   public static void main(String args[]) throws Exception
   {
      BufferedReader inFromUser =
         new BufferedReader(new InputStreamReader(System.in));
      DatagramSocket clientSocket = new DatagramSocket();
      InetAddress IPAddress = InetAddress.getByName("127.0.0.1");
      byte[] sendData = new byte[1024];
      byte[] receiveData = new byte[1024];
      String sentence = inFromUser.readLine();

      while(!sentence.equals("sair")){
         sendData = sentence.getBytes();
         DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 9876);
         clientSocket.send(sendPacket);
         DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
         //maybe opening a thread, or awaiting a response here might help.
         //leaving this assynchronous might be an option. Allows me to continue with the code, while I await response
         //the problem is if the buffer response becomes bigger than I can handle
         //can I set the port the client will use, the client local port?
         clientSocket.receive(receivePacket);
         String modifiedSentence = new String(receivePacket.getData(), 0, receivePacket.getLength());
         System.out.println("Do servidor:" + modifiedSentence);
         System.out.println("Porta do cliente: " + clientSocket.getLocalPort());
         sentence = inFromUser.readLine();
      }
      clientSocket.close();
   }
}
