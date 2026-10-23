#include <iostream>
#include "circular.h"
#include <string>

int main(){
    Playlist* head = nullptr;
    Playlist* current = head;
    int choice;
    std::string song;
    do{
        std::cout << "========== Playlist ==========" <<std::endl;
        std::cout << "1.Add a song" << std::endl;
        std::cout << "2.Play all songs" << std::endl;
        std::cout << "3.Play a song" << std::endl;
        std::cout << "4.Play next song" << std::endl;
        std::cout << "5.Play previous song" << std::endl;
        std::cout << "6.Remove a song" << std::endl;
        std::cout << "7.Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch(choice){
            case 1:
                std::cout << "Enter new song: ";
                std::cin >> song;
                addSong(song,&head);
                std::cout << "Successfully added the song.\n" << std::endl;
                break;
            case 2:
                playSongs(head);
                break;
            case 3:
                std::cout << "Enter song you want to play: ";
                std::cin >> song;
                playSong(song,&current,&head);
                break;
            case 4:
                nextSong(&current);
                break;
            case 5:
                prevSong(&current);
                break;
            case 6:
                std::cout << "Enter the song you want to remove: ";
                std::cin >> song;
                removeSong(song,&head);
                std::cout << "Successfully removed the song.\n" <<std::endl;
                break;
            case 7:
                std::cout << "Goodbye." <<std::endl;
                break;
            default:
                std::cout << "Invalid Input. Please Try Again." <<std::endl;
                break;
        }
    }while(choice != 7);
    return 0;
}