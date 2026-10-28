#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int size = 100;
const int candidates = 5;
void displayArray(int arr[]);
void countVotes(int arr[], int votes[]);
int mostVotes(int votes[]);

int main(){
    int votes[candidates];
    int arr[size];
    srand(time(0));
    for(int i = 0; i<size; i++){
        arr[i] = (rand()%5) + 1;
    }
    std::cout << "Unsorted Array:" << std::endl;
    displayArray(arr);

    insertionSort(arr,size);
    std::cout << "Sorted Array:" << std::endl;
    displayArray(arr);

    countVotes(arr,votes);
    std::cout << "Vote Count" << std::endl;
    std::cout <<"Bo Dalton Capistrano: "<< votes[0] << " votes\n";
    std::cout <<"Cornelius Raymon Agustin: "<< votes[1] << " votes\n";
    std::cout <<"Deja Jayla Banaga: "<< votes[2] << " votes\n";
    std::cout <<"Lalla Brielle Yabut: "<< votes[3] << " votes\n";
    std::cout <<"Franklin Relano Castro: "<< votes[4] << " votes\n";

    int winner = mostVotes(votes);
    switch(winner){
        case 0:
            std::cout << "\nWinning Candidate: Bo Dalton Capistrano" <<std::endl;
            break;
        case 1:
            std::cout << "\nWinning Candidate: Cornelius Raymon Agustin" <<std::endl;
            break;
        case 2:
            std::cout << "\nWinning Candidate: Deja Jayla Banaga" <<std::endl;
            break;
        case 3:
            std::cout << "\nWinning Candidate: Lalla Brielle Yabut" <<std::endl;
            break;
        case 4:
            std::cout << "\nWinning Candidate: Franklin Relano Castro" <<std::endl;
            break;
    }
    return 0;
}

void displayArray(int arr[]){
    for(int i = 0; i<size; i++){
        std::cout << arr[i] <<" ";
    }
    std::cout << std::endl;
}

void countVotes(int arr[], int votes[]){
    int instance;
    for(int i = 0; i < candidates;i++){
        instance = 0;
        for(int j = 0; j<size; j++){
            if(arr[j] == i + 1){
                instance++;
            }
        }
        votes[i] = instance;
    }
}

int mostVotes(int votes[]){
    int largest = 0;
    for(int j=1;j<candidates;j++){
        if(votes[j]> votes[largest]){
            largest = j;
        }
    }
    return largest;
}
