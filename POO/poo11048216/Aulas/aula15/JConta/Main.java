public class Main
{
    public static void main(String[] args)
    {
        ContaPoupanca cta = new ContaPoupanca("22598713800", "Monael", new Data(20, 1, 2017));
        cta.extrato();
        cta.deposito(100);
        cta.extrato();
    }
}