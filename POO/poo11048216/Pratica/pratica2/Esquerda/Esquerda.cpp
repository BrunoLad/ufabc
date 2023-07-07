#include <iostream>

using namespace std;

int main() {

    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     int n,aux=0;
     char c;

     cin >> n;


    for(int i=0; i<n; i++){
        cin >> c;
        if(c=='D'){
            if(aux!=3){
                aux++;
            }else{
                aux=0;
            }

        }else{
            if(aux!=0){
                aux--;
            }else{
                aux=3;
            }
        }
    }

    if(aux==0){
        cout << 'N' << endl;
    }else{
        if(aux==1){
            cout << 'L' << endl;
        }else{
            if(aux==2){
                cout << 'S' << endl;
            }else{
                cout << 'O' << endl;
            }
        }

    }
    
    //aux=0;
    
    return 0;
}