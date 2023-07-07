import java.util.Scanner;

public class SaltandoNuvens
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int N, cont=0, aux=0;
        
        N = sc.nextInt();
        
        int v[] = new int[N];
        
        for(int i = 0; i < N; i++)
        {
            v[i] = sc.nextInt();
        }
        
        int j=0;
        
        while(j<(N-1)){
            if(v[j+2]!=1 && j<=(N-3)){
                aux++;
                j+=2;
            }else{
                aux++;
                j++;
            }    
        }
        
        System.out.println(aux);
    }
}