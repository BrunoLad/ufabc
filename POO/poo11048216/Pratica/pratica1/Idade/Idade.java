import java.util.Scanner;

public class Idade
{
    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);
        String nome;
        int ano_a, ano_n, r;
        
        ano_a = entrada.nextInt();
        nome = entrada.next();
        ano_n = entrada.nextInt();
        
        r = ano_a-ano_n;
        
        System.out.println(nome + ", voce completa " + r + " anos de idade neste ano.");
    }    
}