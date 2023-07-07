import java.util.Scanner;
import java.lang.String;

public class Spirit
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int cont=0, a=1;
        String s;
        
        s = sc.next();
        
        for(int i = 0; i<s.length(); i++)
        {
            
            if(i==a){
                if(s.charAt(i)!='O')
                {
                    cont++;
                }
                a+=3;
            }else{
                if(s.charAt(i)!='S'){
                    cont++;
                }
            }
        }
        
        System.out.println(cont);
        
    }
}