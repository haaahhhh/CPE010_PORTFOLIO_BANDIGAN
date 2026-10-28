#include <iostream>

const int col = 4; 
const int row = 4;

int matrix[row][col] = {
        {4,7,1,6},
        {6,7,3,9},
        {3,8,1,2},
        {7,1,7,3}
    };

int pathCount(int cost, int i, int j);

int main(){
    int cost = 25;
    std::cout << "Cost: " << cost <<  std::endl;  
    std::cout<< "Paths: " << pathCount(cost,0,0);

    return 0;
}

int pathCount(int cost, int i, int j){   
    if(i >= row || j >= col){
        return 0;
    }
    cost -= matrix[i][j];

    if(cost < 0){
        return 0;
    }

    if(i == row-1 && j == col-1){
        if(cost == 0){
            return 1;
        }else{
            return 0;
        }
    }
    int right = (pathCount(cost,i,j+1));
    int down = (pathCount(cost,i+1,j));

    return right + down;
}