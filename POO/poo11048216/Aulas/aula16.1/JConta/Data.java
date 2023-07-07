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