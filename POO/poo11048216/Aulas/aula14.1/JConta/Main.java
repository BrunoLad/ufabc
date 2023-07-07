class Data
{
    private int dia, mes, ano;
    
    public Data()
    {   }
    
    public Data(int d, int m, int a)
    {
        this.setDia(d);
        this.setMes(m);
        this.setAno(a);
    }
    
    public void setDia(int d)
    {
        this.dia = d;
    }
    
    public void setMes(int m)
    {
        this.mes = m;
    }
    
    public void setAno(int a)
    {
        this.ano = a;
    }
    
    public int getDia()
    {
        return this.dia;
    }
    
    public int getMes()
    {
        return this.mes;
    }
    
    public int getAno()
    {
        return this.ano;
    }
}

class Conta
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