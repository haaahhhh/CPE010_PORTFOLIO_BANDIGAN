#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include <string>

class Playlist{
    public:
        std::string song;
        Playlist* next = nullptr;
        Playlist* prev = nullptr;
};

Playlist *NewSong(std::string newSong){
    Playlist *newNode = new Playlist;
    newNode->song = newSong;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

void addSong(std::string song, Playlist** currHead){
    Playlist* newSong = NewSong(song);
    if(*currHead == nullptr){
        *currHead = newSong;
        (*currHead)->next = newSong;
        (*currHead)->prev = newSong;
        return;
    }
    Playlist* tail = (*currHead)->prev;
    tail->next = newSong;
    newSong->next = *currHead;
    newSong->prev = tail;
    (*currHead)->prev = newSong;
}

void playSongs(Playlist* currSong){
    if(currSong == nullptr){
        std::cout <<"Playlist is empty." << std::endl;
        return;
    }
    Playlist *head = currSong;
    std::cout << "========== Playlist ==========" <<std::endl;
    do{
        std::cout << currSong->song;
        if(currSong->next != head){
            std::cout << " -> ";
        }
        currSong = currSong->next;
    }while(currSong != head);
    std::cout << std::endl;
}

void playSong(std::string findSong, Playlist** currentSong, Playlist** head){
    if(*head == nullptr){
        std::cout << "Playlist is empty." << std::endl;
        return;
    }
    Playlist* currSong = *head;
    while(currSong->song != findSong){
        currSong = currSong->next;
        if(currSong == *head){
            std::cout << "Song is not found in the playlist." << std::endl;
            return;
        }
    }
    *currentSong = currSong;
    std::cout << "Now Playing:" << std::endl;
    std::cout << currSong->song <<std::endl;
}

void nextSong(Playlist** currentSong){
    if(currentSong == nullptr){
        std::cout << "Playlist is empty." << std::endl;
        return;
    }
    std::cout << "Now Playing:" <<std::endl;
    std::cout << (*currentSong)->next->song <<std::endl;
    *currentSong = (*currentSong)->next;
}

void prevSong(Playlist** currentSong){
    if(currentSong == nullptr){
        std::cout << "Playlist is empty." << std::endl;
        return;
    }
    std::cout << "Now Playing:" <<std::endl;
    std::cout << (*currentSong)->prev->song <<std::endl;
    *currentSong = (*currentSong)->prev;
}

void removeSong(std::string findSong, Playlist** head){
    if(*head == nullptr){
        std::cout << "Playlist is empty." << std::endl;
        return;
    }
    Playlist* currSong = *head;
    
    while(currSong->song != findSong){
        currSong = currSong->next;
        if(currSong == *head){
            std::cout << "Song is not found in the playlist." << std::endl;
            return;
        }
    }
    if(currSong == *head){
        *head = currSong->next;
    }
    currSong->next->prev = currSong->prev;
    currSong->prev->next = currSong->next; 
    delete currSong;
}

#endif