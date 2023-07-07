#include <iostream>

void findWally(int **, int, int);
void deletaMat(int **, int);

int main(){
    
    int **mat, n, m;
    
    std::cin >> n >> m;
    
    mat = new int*[n];
    
    for(int i=0; i<n; i++){
        
        mat[i] = new int[m];
        
        for(int j=0; j<m; j++){
            std::cin >> *(*mat+j+(i*m));
            //std::cout << mat[i][j] << std::endl;
        }
    }
    
    findWally(mat, n, m);
    
    deletaMat(mat, n);
    
    return 0;
}

void findWally(int **mat, int n, int m){
    
    
   /* for(int i=0; i <n; i++){
        for(int j=0; j<m; j++){
            std::cout << "[" << i << "][" << j <<"]= " << mat[i][j] << std::endl;
        }
    }*/
    //ta acessando normal pelo indice, bug ta pelo i quando o tamanho é t
    
    
    int t=n*m;
    int l=0,c=0, px=-1 , py=-1;
    
    for(int i=0; i<t; i++){
        //std::cout << l << " " << c << std::endl;
        if(*(*mat+i) == 1111){
            if(l==0 && c==0){
                if(*(*mat + 1)==0 && *(*mat+m)==8 && *(*mat+((n-1)*m))==4 && *(*mat + (m-1))==0){
                    px=l;
                    py=c;
                    break;
                }   
            }else{
                if(l==(n-1) && c==(m-1)){
                    if(*(*mat - (m-1)+i)==0 && *(*mat - ((n-1)*m) +i)==8 && *(*mat-m+i)==4 && *(*mat+i-1)==0){
                        px=l;
                        py=c;
                        break;
                    }
                }else{
                    
                    if(l==0 && c==(m-1)){
                        if(*(*mat -(m-1)+i) ==0 && *(*mat + m + i)==8 && *(*mat+((n-1)*m)+i)==4 && *(*mat+i-1)==0){
                            px=l;
                            py=c;
                            break;
                        }
                    }else{
                        if(l==(n-1) && c==0){
                            if(*(*mat+i+1)==0 && *(*mat - ((n-1)*m) +i)==8 && *(*mat-m+i)==4 && *(*mat+(m-1)+i)==0){
                                px=l;
                                py=c;
                                break;
                            }
                        }else{
                        //código abaixo aqui dentro
                            if(l==0){
                        
                                if(*(*mat+i+1)==0 && *(*mat+m+i)==8 && *(*mat+((n-1)*m)+i)==4 && *(*mat+i-1)==0){
                                    px=l;
                                    py=c;
                                    break;
                                }
                        
                            }else{
                                if(c==0){
                            
                                    if(*(*mat+i+1)==0 && *(*mat+m+i)==8 && *(*mat-m+i)==4 && *(*mat + (m-1)+i)==0){
                                        //std::cout << *(*mat+m) << std::endl;
                                        //std::cout << c << std::endl;
                                        px=l;
                                        py=c;
                                        break;
                                    }
                                //corrigido
                                /*std::cout << "direita: " << *(*mat+i+1) << std::endl;
                                std::cout << "baixo: " << *(*mat+m) << std::endl;
                                std::cout << "topo: " << *(*mat-m) << std::endl;
                                std::cout << "esquerda: " << *(*mat+(m-1)) << std::endl;*/
                            
                                    }else{
                                        if(l==(n-1)){
                                
                                            if(*(*mat+i+1)==0 && *(*mat-((n-1)*m)+i)==8 && *(*mat-m+i)==4 && *(*mat+i-1)==0){
                                                px=l;
                                                py=c;
                                                break; 
                                            }
                                
                                            }else{
                                                if(c==(m-1)){
                                    
                                                    if(*(*mat-(m-1)+i)==0 && *(*mat+m+i)==8 && *(*mat-m+i)==4 && *(*mat-1+i)==0){
                                                        px=l;
                                                        py=c;
                                                        break;
                                                    }
                                    
                                                }else{
                                    
                                                    if(*(*mat+1+i)==0 && *(*mat+m+i)==8 && *(*mat-m+i)==4 && *(*mat-1+i)==0){
                                                        px=l;
                                                        py=c;
                                                        break;
                                                    }
                                    
                                                }
                                            }
                                        }
                                }
                        
                            
                        }
                    }
                    
                }
            }
        }else{
            //std::cout << *(*mat+i) << std::endl;
            //std::cout << "indice: " << i << std::endl;
        
            c++;
        
            if(c==m){
                c=0;
                l++;
            }
        
            
        }
        
    }
    
    if(px==-1 && py==-1){
        std::cout << "WALLY NAO ESTA NA MATRIZ" << std::endl;
    }else{
        std::cout << px << " " << py << std::endl;
    }
    
}

void deletaMat(int **mat, int n){
    for(int i=0; i<n; i++){
        delete *(mat+i);
    }
    delete mat;
}