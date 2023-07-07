public class Main
{
    public static void main(String[] args)
    {
        Conta agencia[] = new Conta[10];
        int i;
        for(i=0; i<10; i++)
        {
            if(i%2==0)
            {
                agencia[i] = new ContaPoupanca("22654347891", "Fulano", 20, 7, 2017, 2);
            }
            else
            {
                agencia[i] = new ContaInvestimento("63521496874", "Beltrano", 10, 2);
            }
            agencia[i].deposito(100);
        }
        
        for(i=0; i<10; i++)
        {
            agencia[i].correcao();
        }
        
        for(i=0; i<10; i++)
        {
            agencia[i].extrato();
        }
    }
}