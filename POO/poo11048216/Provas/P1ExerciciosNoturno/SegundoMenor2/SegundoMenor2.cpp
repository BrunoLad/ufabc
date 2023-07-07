#include <iostream>

void insereVetor(int *,int);

int SegMenor(int *, int);

int main(){
    
    int n, *v, m2;
    
    std::cin >> n;
    
    v = new int[n];
    
    insereVetor(v,n);
    
    m2 = SegMenor(v,n);
    
    std::cout << m2 << std::endl;
    
    return 0;
}

void insereVetor(int *v, int n){
    for(int i=0; i<n; i++){
        std::cin >> *(v+i);
    }
}

int SegMenor(int *v, int n){
    int m = 10001, m2 = 10001;
    
    if(n>2){
    
        for(int i=0; i< n; i++){
            if(v[i] < m && v[i] < m2){
                m2 = m;
                m = v[i];
            }else{
                if(v[i] < m2 && v[i]!=m){
                    m2 = v[i];
                }
            }
        }
        
        return m2;
    }else{
        if(n==1){
            return v[0];
        }else{
            if(v[0] > v[1]){
                return v[0];
            }else{
                return v[1];
            }
        }
    }
}