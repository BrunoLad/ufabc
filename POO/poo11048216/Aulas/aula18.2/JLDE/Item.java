class Item
{
    private int chave;
    private Item proximo;
    
    public Item()
    {   }
    
    public Item(int ch)
    {
        this.setChave(ch);
        this.setProximo(null);
    }
    
    public void setChave(int ch)
    {
        this.chave = ch;
    }
    
    public void setProximo(Item it)
    {
        this.proximo = it;
    }
    
    public int getChave()
    {
        return this.chave;
    }
    
    public Item getProximo()
    {
        return this.proximo;
    }
}