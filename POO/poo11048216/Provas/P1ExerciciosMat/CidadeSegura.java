import java.util.Scanner;

public class CidadeSegura
{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N, cont;
        N=sc.nextInt();
        
        int m[][] = new int[N+1][N+1];
        
        for(int i=0; i<(N+1); i++){
            for(int j=0; j<(N+1); j++){
                m[i][j] = sc.nextInt();
            }
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                
                cont=0;
                
                if(m[i][j]==1){
                    cont++;
                }
                
                if(m[i][j+1]==1){
                    cont++;
                }
                if(m[i+1][j]==1){
                    cont ++;
                }
                if(m[i+1][j+1]==1){
                    cont++;
                }
                
                if(cont>=2){
                    System.out.print('S');
                }else{
                    System.out.print('U');
                }
                
            }
            System.out.println("");
        }
        
    }
}