class ContaInvestimento extends Conta
{
    private float taxaRendimento;
    private float taxaAdministracao;
    
    public ContaInvestimento()
    {   }
    
    public ContaInvestimento(String cpf, String nome, float txR, float txA)
    {
        super(cpf, nome);
        this.setTaxaRendimento(txR);
        this.setTaxaAdministracao(txA);
    }
    
    public void setTaxaRendimento(float tx)
    {
        this.taxaRendimento = tx;
    }
    
    public void setTaxaAdministracao(float tx)
    {
        this.taxaAdministracao = tx;
    }
    
    public float getTaxaRendimento()
    {
        return this.taxaRendimento;
    }
    
    public float getTaxaAdministracao()
    {
        return this.taxaAdministracao;
    }
    
    public void correcao()
    {
        this.deposito(this.getSaldo()*(this.getTaxaRendimento()/100.0f));
    }
    
    public void extrato()
    {
        super.extrato();
        System.out.println("TAXA DE RENDIMENTO ....: " + this.getTaxaRendimento() + "/% a.m.");
        System.out.println("TAXA DE ADMINISTRACAO .: " + this.getTaxaAdministracao() + "/% a.m.");
        System.out.println("===================================");
    }
}