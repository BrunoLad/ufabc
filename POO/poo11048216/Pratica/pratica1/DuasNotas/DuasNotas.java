import java.util.Scanner;

public class DuasNotas
{
    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);
        int N,M,d,T;
        
        N = entrada.nextInt();
        M = entrada.nextInt();
        
        while(N!=0 || M!=0){
            T=0;
            d = M-N;
            
            if(d==100 || d==20 || d==10){
                
                T=2;
                d=0;
                
            }else{
            
                T+=d/100;
                d%=100;
            
                T+=d/50;
                d%=50;
            
                T+=d/20;
                d%=20;
            
                T+=d/10;
                d%=10;
            
                T+=d/5;
                d%=5;
            
                T+=d/2;
                d%=2;
            }
            
            if(d==0 && T==2){
                System.out.println("possible");
            }else{
                System.out.println("impossible");
            }
            
            N = entrada.nextInt();
            M = entrada.nextInt();
        }
        
    }    
}