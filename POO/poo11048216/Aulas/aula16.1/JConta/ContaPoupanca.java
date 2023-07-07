class ContaPoupanca extends Conta
{
    private Data aniversario;
    private float txRef;
    
    public ContaPoupanca()
    {   }
    
    public ContaPoupanca(String cpf, String nome, int d, int m, int a, float tx)
    {
        super(cpf, nome);
        this.setAniversario(new Data(d, m, a));
        this.setTxRef(tx);
    }
    
    public void setAniversario(Data dt)
    {
        this.aniversario = dt;
    }
    
    public void setTxRef(float t)
    {
        this.txRef = t;
    }
    
    public Data getAniversario()
    {
        return this.aniversario;
    }
    
    public float getTxRef()
    {
        return this.txRef;
    }
    
    public void correcao()
    {
        this.deposito(this.getSaldo()*0.02f);
    }
    
    public void extrato()
    {
        super.extrato();
        System.out.println("ANIVERSARIO .: " + this.getAniversario().getDia());
        System.out.println("===================================");
    }
}