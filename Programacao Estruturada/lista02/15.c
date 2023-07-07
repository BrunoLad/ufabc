#include <stdio.h>

//char torre_hanoi(int n);
void torre_hanoi(int torL, int torM, int torR, int atu, int ref, int contL, int contR, int contM);

int main(){
    
    int n;
    int target;
    scanf("%d", &n);
    
    torre_hanoi(n, 0, 0, 0, n, 0, 0, 0);
    printf("\n");
    
    return 0;
}

/*char torre_hanoi(int n){
    if(n == 1) return 'A';
    
    return torre_hanoi(n-1);
}*/
//tentar fazer por peso, ao invés dos conts forem peso talvez dê certo

void torre_hanoi(int torL, int torM, int torR, int atu, int ref, int contL, int contR, int contM){
    if(torR!=ref){
        if(!atu){
            if(!(torL % 2)){
                torM++;
                contL++;
                printf("A-B ");
                
                if((!(torL-1)) || contL==2){ 
                    atu = 2;
                    contL = 0;
                }
            }else{
                torR++;
                contL++;
                printf("A-C ");
                
                if((!(torL-1)) || contL==2){ 
                    atu = 1;
                    contL = 0;   
                }
            }
            torre_hanoi((torL-1), torM, torR, atu, ref, contL, contR, contM);
        }else{
            if(atu==1){
                if(!(torM % 2)){
                    torL++;
                    contM++;
                    printf("B-A ");
                    
                    if((!(torM-1)) || contM==2){ 
                        atu = 2;
                        contM = 0;
                    }
                }else{
                    torR++;
                    contM++;
                    printf("B-C ");
                    
                    if((!(torM-1)) || contM==2){ 
                        atu = 0;
                        contM = 0;
                    }
                }
                torre_hanoi(torL, (torM-1), torR, atu, ref, contL, contR, contM);
            }else{
                if(!(torR % 2)){
                    torL++;
                    contR++;
                    printf("C-A ");
                    
                    if((!(torR-1)) || (contR==2)){ 
                        atu = 1;
                        contR = 0;
                    }
                }else{
                    torM++;
                    contR++;
                    printf("C-B ");
                    
                    if((!(torR-1)) || (contR==2)){ 
                        atu = 0;
                        contR = 0;
                    }
                }
                torre_hanoi(torL, torM, (torR-1), atu, ref, contL, contR, contM);
            }
        }
    }
}

//bugado