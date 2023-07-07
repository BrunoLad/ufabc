import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Lista l = new Lista();
        Item it;
        int chave;
        char op;
        Scanner scan = new Scanner(System.in);
        
        while(scan.hasNext())
        {
            op = scan.next().charAt(0);
            if(op == 'I')
            {
                chave = scan.nextInt();
                l.inserir(new Item(chave));
            }
            else if(op == 'R')
            {
                chave = scan.nextInt();
                it = l.remover(chave);
                if(it != null)
                {
                    System.out.println("REMOVIDO: " + it.getChave());
                }
            }
            else
            {
                l.mostrar();
            }
        }
    }
}