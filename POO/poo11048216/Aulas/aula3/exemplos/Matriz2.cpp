#include <iostream>
#include <cstdlib>

void printMat(int **, int, int);

int main()
{
    int **mat, n, m, i, j; //alocação dinâmica de matrizes
    
    std::cin >> m >> n;
    
    mat = new int*[m];
    
    /*for(i=0; i<m; i++)
    {
        mat[i] = new int[n];
    }*/
    
    for(i=0; i<m; i++)
    {
        mat[i] = new int[n];
        for(j=0; j<n; j++)
        {
            mat[i][j] = rand()%10;
        }
    }
    
    printMat(mat, m, n);
    
    return 0;
}

void printMat(int **m, int l, int c)
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