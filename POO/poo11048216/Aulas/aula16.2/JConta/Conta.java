abstract class Conta
{
    private String numero;
    private String cpf;
    private String titular;
    private boolean bloqueada;
    private float saldo;
    
    public Conta()
    {   }
    
    public Conta(String cpf, String nome)
    {
        this.setNumero(Conta.geraNumero(10));
        this.setTitular(nome);
        this.setCpf(cpf);
        this.setSaldo(0);
        this.setBloqueada(false);
    }
    
    public void setNumero(String n)
    {
        this.numero = n;
    }
    
    public void setTitular(String t)
    {
        this.titular = t;
    }
    
    public void setCpf(String c)
    {
        this.cpf = c;
    }
    
    public void setBloqueada(boolean b)
    {
        this.bloqueada = b;
    }
    
    public void setSaldo(float s)
    {
        this.saldo = s;
    }
    
    public String getNumero()
    {
        return this.numero;
    }
    
    public String getTitular()
    {
        return this.titular;
    }
    
    public String getCpf()
    {
        return this.cpf;
    }
    
    public boolean isBloqueada()
    {
        return this.bloqueada;
    }
    
    public float getSaldo()
    {
        return this.saldo;
    }
    
    public boolean saque(float v)
    {
        if(this.getSaldo() >= v && !this.isBloqueada())
        {
            this.setSaldo(this.getSaldo()-v);
            return true;
        }
        return false;
    }
    
    public boolean deposito(float v)
    {
        if(!this.isBloqueada())
        {
            this.setSaldo(this.getSaldo()+v);
            return true;
        }
        return false;
    }
    
    public void extrato()
    {
        System.out.println("============= EXTRATO =============");
        System.out.println("NUMERO ..: " + this.getNumero());
        System.out.println("CPF .....: " + this.getCpf());
        System.out.println("TITULAR .: " + this.getTitular());
        System.out.println("SALDO ...: " + this.getSaldo());
        System.out.println("===================================");
    }
    
    public abstract void correcao();
    
    public static String geraNumero(int n)
    {
        String num="";
        int i;
        java.util.Random rd = new java.util.Random();
        for(i=0; i<n; i++)
        {
            num += (char)((rd.nextInt(10))+48);
        }
        return num;
    }
}