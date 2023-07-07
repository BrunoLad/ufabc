import java.util.Scanner;

public class VetorZigZag
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int N, posUltimo=0, cont=0;
        boolean ultimo;
        N = sc.nextInt();
        int a[] = new int[N];
        
        for(int i=0; i<N; i++)
        {
            a[i] = sc.nextInt();    
        }
        
        if(N>2){
            
        
            if(a[0]>a[1]){
                ultimo=true;
            }else{
                ultimo=false;
            }
        
            for(int i=1; i<(N-1);i++){
            
                if(posUltimo!=0){
                    if(ultimo){
                        if(a[posUltimo]<a[i+1]){
                            posUltimo=0;
                            ultimo =false;
                        }else{
                            cont++;
                        }
                    }else{
                        if(a[posUltimo]>a[i+1]){
                            posUltimo = 0;
                            ultimo = true;
                        }else{
                            cont++;
                        }
                    }
                }else{
            
                    if(a[i]>a[i+1] && ultimo){
                        posUltimo = i;
                        cont++;
                    }else{
                        if(a[i]<a[i+1] && !ultimo){
                            posUltimo = i;
                            cont++;
                        }else{
                            if(a[i]>a[i+1]){
                                ultimo=true;
                            }else{
                                ultimo=false;
                            }
                        }
                    }
                }
            
            }
        
        }
        
        System.out.println(cont);
        
    }
}