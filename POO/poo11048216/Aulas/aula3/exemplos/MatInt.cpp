#include <iostream>

int main()
{
    int mat[][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} }, i, j;
    
    
    for(i=0; i<3; i++){
        for(j=0; j<4; j++){
            std::cout << mat[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    
    std::cout << "mat: " << mat << std::endl;
    
    for(i=0; i<3; i++)
    {
        std::cout << "mat[" << i << "]: " << mat[i] << std::endl;
    }
    
    for(i=0; i<3; i++)
    {
        std::cout << "*mat[" << i << "]: " << *(mat[i]) << std::endl;
        std::cout << "*mat[" << i << "]+1: " << *(mat[i]+1) << std::endl;
        std::cout << "*mat[" << i << "]+2: " << *(mat[i]+2) << std::endl;
        std::cout << "*mat[" << i << "]+3: " << *(mat[i]+3) << std::endl;
        std::cout << "*mat[" << i << "]+4: " << *(mat[i]+4) << std::endl;
    }
    
    for(i = 0; i<12; i++)
    {
        std::cout << *(*mat+i) << std::endl;
        //percorrendo a matriz com apenas um laço
    }
    
    return 0;
}