public class Ponto
{
    private float x, y;
    
    public Ponto(float px, float py)
    {
        this.setX(px);
        this.setY(py);
    }  
   
   public void setX(float px)
   {
       this.x = px;
   }
   
   public void setY(float py)
   {
       this.y = py;
   }

    public float getX()
    {
        return this.x;
    }
    
    public float getY()
    {
        return this.y;
    }
}