class ContaPoupanca extends Conta
{
    private Data aniversario;
    private float txRef;
    
    public ContaPoupanca()
    {   }
    
    public ContaPoupanca(String n, String cpf, Data dt)
    {
        super(cpf, n);
        this.setAniversario(dt);
    }
    
    public ContaPoupanca(String n, String cpf, int d, int m, int a)
    {
        super(cpf, n);
        this.setAniversario(new Data(d, m, a));
    }
    
    public void setAniversario(Data d)
    {
        this.aniversario = d;
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
    
    public void extrato()
    {
        super.extrato();
        System.out.println("ANIVERSARIO .: " + this.getAniversario().getDia());
        System.out.println("===================================");        
    }
}