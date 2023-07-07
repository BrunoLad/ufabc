//package socketudp;

// created on 29/09/2010 at 22:33
import java.io.*;
import java.net.*;

class UDPServer
{
   public static void main(String args[]) throws Exception
      {
         DatagramSocket serverSocket = new DatagramSocket(9876);
            byte[] receiveData = new byte[1024];
            byte[] sendData = new byte[1024];
            
            //iniciando numa porta aleatória, vou criar uma outra variável de referência
            DatagramPacket receivePacket1 = new DatagramPacket(receiveData, receiveData.length);
            System.out.println("Servidor aguardando..." );
            serverSocket.receive(receivePacket1);
            String sentence1 = new String( receivePacket1.getData(), 0, receivePacket1.getLength());
            System.out.println("Mensagem recebida: " + sentence1);
            int port1 = receivePacket1.getPort();
            DatagramPacket sendPacket1 = new DatagramPacket(sendData, 0, sendData.length, receivePacket1.getAddress(), port1);
            serverSocket.send(sendPacket1);
            DatagramPacket receivePacket2 = new DatagramPacket(receiveData, receiveData.length);
            System.out.println("Servidor aguardando..." );
            serverSocket.receive(receivePacket2);
            String sentence2 = new String( receivePacket2.getData(), 0, receivePacket2.getLength());
            System.out.println("Mensagem recebida: " + sentence2);
            int port2 = receivePacket2.getPort();
            DatagramPacket sendPacket2 = new DatagramPacket(sendData, 0, sendData.length, receivePacket1.getAddress(), port1);
            serverSocket.send(sendPacket2);
            //what I need to take in consideration is saving the ports that the clients use to send message
            //allow a client to send message indefinetly, and be saved in a buffer
            //take care that the other client receives and send accordingly to the times I receive a message
            //so I need to modify both the client and the server code
            while(true)
               {
                  DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                  System.out.println("Servidor aguardando..." );
                  serverSocket.receive(receivePacket);
                  String sentence = new String( receivePacket.getData(), 0, receivePacket.getLength());
                  System.out.println("Mensagem recebida: " + sentence);
                  InetAddress IPAddress = receivePacket.getAddress();
                  String capitalizedSentence = sentence.toUpperCase();
                  sendData = capitalizedSentence.getBytes();
                  int port = receivePacket.getPort();
                  //must solve the first message that is being sent, cause it is being lost
                  //also must open up a thread in order to receive multiple messages
                  System.out.println("Porta em questao: " + port);
                  System.out.println("Porta1: " + port1);
                  System.out.println("Porta2: " + port2);

                  DatagramPacket sendPacket;
                  if(port1 == port){
                     sendPacket = new DatagramPacket(sendData, 0, sendData.length, IPAddress, port2);
                     serverSocket.send(sendPacket);
                     sendPacket = new DatagramPacket(sendData, 0, 0, IPAddress, port1);
                     serverSocket.send(sendPacket);
                  } else {
                     sendPacket = new DatagramPacket(sendData, 0, sendData.length, IPAddress, port1);
                     serverSocket.send(sendPacket);
                     sendPacket= new DatagramPacket(sendData, 0, 0, IPAddress, port2);
                     serverSocket.send(sendPacket);
                  }
                  // serverSocket.send(sendPacket);
                  //System.out.println("A porta do servidor eh: " + serverSocket.getLocalPort());
                  // System.out.println("O porta do cliente eh: " + receivePacket.getPort());
               }
      }
}
