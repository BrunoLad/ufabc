class Lista
{
    private Item primeiro;
    private Item ultimo;
    
    public Lista()
    {
        this.setPrimeiro(null);
        this.setUltimo(null);
    }
    
    public void setPrimeiro(Item it)
    {
        this.primeiro = it;
    }
    
    public void setUltimo(Item it)
    {
        this.ultimo = it;
    }
    
    public Item getPrimeiro()
    {
        return this.primeiro;
    }
    
    public Item getUltimo()
    {
        return this.ultimo;
    }
    
    public void inserir(Item novo)
    {
        Item ant=null, atu=this.getPrimeiro();
        boolean achei=false;
        
        while(atu!=null && !achei)
        {
            if(atu.getChave()<novo.getChave())
            {
                ant = atu;
                atu = atu.getProximo();
            }
            else
            {
                achei = true;
                if(atu.getChave()==novo.getChave())
                {
                    return;
                }
            }
        }
        if(atu!=null && ant!=null) // inserindo no meio
        {
            ant.setProximo(novo);
            novo.setProximo(atu);
        }
        else if(ant==null) // inserindo no inicio
        {
            if(this.vazia())
            {
                this.setUltimo(novo);
            }
            this.setPrimeiro(novo);
            novo.setProximo(atu);
        }
        else // inserindo no final
        {
            ant.setProximo(novo);
            this.setUltimo(novo);
        }
    }
    
    public Item remover(int ch)
    {
        Item ant=null, atu=this.getPrimeiro();
        if(!this.vazia())
        {
            while(atu!=null && atu.getChave() != ch)
            {
                ant = atu;
                atu = atu.getProximo();
            }
            if(atu!=null && ant!=null) // removendo do meio ou final
            {
                ant.setProximo(atu.getProximo()); // meio ou final
                if(atu == this.getUltimo()) // soh o final
                {
                    this.setUltimo(ant);
                }
            }
            else if(ant==null)// removendo do inicio
            {
                this.setPrimeiro(atu.getProximo());
                if(atu == this.getUltimo())
                {
                    this.setUltimo(null);
                }
            }
        }
        return atu;
    }
    
    public void mostrar()
    {
        Item atu = this.getPrimeiro();
        while(atu!=null)
        {
            System.out.print(atu.getChave() + (atu.getProximo()!=null?" ":"\n"));
            atu = atu.getProximo();
        }
    }
    
    public boolean vazia()
    {
        return this.getPrimeiro()==null && this.getUltimo()==null;
    }
    
}