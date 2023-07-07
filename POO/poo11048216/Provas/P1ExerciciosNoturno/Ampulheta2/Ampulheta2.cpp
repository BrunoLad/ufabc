#include <iostream>

int MAmplt(int **, int);

int main(){
    
    int N, **mat, resp;
    
    std::cin >> N;
    
    mat = new int*[N];
    
    for(int i=0; i<N; i++){
        
        mat[i] = new int[N];
        
        for(int j=0; j<N; j++){
            std::cin >> mat[i][j]; //torcer pra que não dê o mesmo bug do cadê o Wally
        }
    }
    
    resp = MAmplt(mat, N);
    
    std::cout << resp << std::endl;
    
    for(int i=0; i<N; i++){
        delete mat[i];
    }
    
    delete mat;
    
    return 0;
}

int MAmplt(int **m, int n){
    int s=0, aux=0;
    bool first = true;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j>0 && j < (n-1) && i < (n-2)){
                if(m[i][j]!=0 || m[i][j-1]!=0 || m[i][j+1]!=0 || m[i+1][j]!=0 || m[i+2][j]!=0 || m[i+2][j-1]!=0 || m[i+2][j+1]!=0){
                    aux = m[i][j] + m[i][j-1] + m[i][j+1] + m[i+1][j] + m[i+2][j] + m[i+2][j-1] + m[i+2][j+1];
                    //std::cout << aux << std::endl;
                    if(first){
                        s = aux;
                        first = false;
                    }else{
                        if(aux > s){
                            s = aux;
                        }
                    }
                }
            }
            aux=0;
        }
    }
    
    return s;
}