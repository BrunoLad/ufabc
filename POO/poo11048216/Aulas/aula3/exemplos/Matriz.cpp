#include <iostream>
#include <cstdlib>

void printMat (int [][3], int, int);

int main(){
    
    int mat[3][3], i, j;
    srand(time(NULL));
    
    for(i=0; i<3; i++)
    {
        
        for(j=0; j<3; j++)
        {
            mat[i][j] = rand()%10;
        }
    }
    
    printMat(mat, 3, 3);
}

void printMat(int m[][3], int l, int c)
{
    int i, j;
    
    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
        {
            std::cout << m[i][j] << ' ';
        }
        
        std::cout << std::endl;
        
    }
}