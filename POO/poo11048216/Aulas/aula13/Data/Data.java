import java.util.Scanner;

public class Data
{
    private int dia, mes, ano;
    
    public Data()
    {
        int x;
        Scanner scan = new Scanner(System.in);
        System.out.print("Informe o dia: ");
        x = scan.nextInt();
        this.setDia(x);
        System.out.print("Informe o mes: ");
        x = scan.nextInt();
        this.setMes(x);
        System.out.print("Informe o ano: ");
        x = scan.nextInt();
        this.setAno(x);
    }
    
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
    
    public void printData()
    {
        System.out.println(this.getDia() + "/" + this.getMes() + "/" + this.getAno());
    }
    
    public static void main(String[] args)
    {
        Data descob = new Data(22,4,1500);
        Data natal;
        descob.printData();
        natal = new Data();
        natal.printData();
    }
}