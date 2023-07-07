import java.util.Scanner;

public class ConvTemperaturaInteira{ 

    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);
    
        double T;
        double Tk, Tra, Td, Tf, Tro, Tre;
        
        T = entrada.nextDouble();
        
        Tk = (T + 273.15);
        Tf = (((T)*(9.0/5.0)) + 32.00);
        Tra = (T+273.15)*(9.0/5.0);
        Tre = (T)*(4.0/5.0);
        Tro = T*(21.0/40.0) + 7.5;
        Td = (100.0-T)*(3.0/2.0);
        
        System.out.println((int)Tk);
        System.out.println((int)Tf);
        System.out.println((int)Tra);
        System.out.println((int)Tre);
        System.out.println((int)Tro);
        System.out.println((int)Td);
    }
}