import java.util.Scanner;
import java.lang.Math;

public class NumerosMarcianos{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int v[]={0,8,9,7,3,1,2,6,4,5};
        int n, nM=0;
        int i=0;
        
        while(sc.hasNextInt()){
            n = sc.nextInt();
            
            while(n!=0){
                nM+=(v[n%10]*Math.pow(10,i));
                n-= (n%10);
                n/=10;
                i++;
                
            }
            i=0;
            System.out.println(nM);
            nM=0;
        }
        
    }
}