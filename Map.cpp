//Map.cpp
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <vector>
#include <ctime>
#include "Map.h"
using namespace std;

//creates an instance of a map 
Map::Map(){
    srand(time(0));
    //setting all map_data_ spaces to UNEXPLORED
    for (int i = 0; i < num_rows_; i++){
        for (int j = 0; j < num_cols_; j++){
            map_data_[i][j] = UNEXPLORED;
        }
    }

    //setting the initial player position
    map_data_[0][0] = PARTY;
    player_position_[0] = 0;
    player_position_[1] = 0;

    //generating the random positions for the rooms
    while (room_count_ < max_rooms_){
        int rand1 = (rand()%11) + 1;
        int rand2 = (rand()%11) + 1;
        if (map_data_[rand1][rand2] == UNEXPLORED){
            map_data_[rand1][rand2] = ROOM;
            room_positions_[room_count_][0] = rand1;
            room_positions_[room_count_][1] = rand2;
            room_count_++;
        }
    }

    //generating the random positions for the npcs
    while (npc_count_ < max_npcs_){
        int rand1 = (rand()%11) + 1; 
        int rand2 = (rand()%11) + 1;
        if (map_data_[rand1][rand2] == UNEXPLORED){
            map_data_[rand1][rand2] = NPC;
            npc_positions_[npc_count_][0] = rand1;
            npc_positions_[npc_count_][1] = rand2;
            npc_positions_[npc_count_][2] = false;
            npc_count_++;
        }
    }

    //generating the random dungeon exit
    do{
        int rand1 = (rand()%11) + 1; 
        int rand2 = (rand()%11) + 1; 
        dungeon_exit_[0] = rand1;
        dungeon_exit_[1] = rand2;
    }while(map_data_[dungeon_exit_[0]][dungeon_exit_[1]] != UNEXPLORED);
    map_data_[dungeon_exit_[0]][dungeon_exit_[1]] = EXIT;
}

//sets the map and all its variables back to their default values
void Map::resetMap(){
    
}

//returns the row of the player position
int Map::getPlayerRow(){
    return player_position_[0];
}

//returns the col of the player position
int Map::getPlayerCol(){
    return player_position_[1];
}

//returns the dungeon exit row position
int Map::getDungeonExitRow(){
    return dungeon_exit_[0];
}

//returns the dungeon exit col position
int Map::getDungeonExitCol(){
    return dungeon_exit_[1];
}

//returns the number of rooms on the map
int Map::getRoomCount(){
    return room_count_;
}

//returns the number of npc's on the map 
int Map::getNPCCount(){
    return npc_count_;
}

//returns the number of rows on the map
int Map::getNumRows(){
    return num_rows_;
}

//returns the number os columns on the map
int Map::getNumCols(){
    return num_cols_;
}

//returns true if the inputted (row,col) is a valid position on the map
bool Map::isOnMap(int row, int col){
    if (row < num_rows_ && row >= 0 && col < num_cols_ && col >= 0){
        return true;
    }
    else{
        return false;
    }
}

//loop through npc_positions_:
//     if the inputted (row,col) equals the position of an NPC, set that NPC to found and return true
//return false
bool Map::isNPCLocation(int row, int col){
    for(int i = 0; i < npc_count_; i++){
        if (npc_positions_[i][0] == row && npc_positions_[i][1] == col){
            return true;
        }
    }
    return false;
}

//loop through room_positions:
//     if the inputted (row,col) equals the position of a room, return true;
//returns false 
bool Map::isRoomLocation(int row, int col){
    for (int i = 0; i < room_count_; i++){
        if (room_positions_[i][0] == row && room_positions_[i][1] == col){
            return true;
        }
    }
    return false;
}

//returns true if the inputted (row,col) is an explored space
//returns false otherwise
bool Map::isExplored(int row, int col){
    for (int i = 0; i < exploredCount; i++){
        if (explored_positions_[i][0] == row && explored_positions_[i][1] == col){
            return true;
        }
    }
    return false;
}

//returns true if the inputted (row,col) is a free space
//returns false otherwise
bool Map::isFreeSpace(int row, int col){

}

//returns true if the inputted (row,col) is the dungeon exit
//returns false otherwise
bool Map::isDungeonExit(int row, int col){
    if (dungeon_exit_[0] == row && dungeon_exit_[1] == col){
        return true;
    }
    else{
        return false;
    }
}

//sets the playerPosition to (row,col)
void Map::setPlayerPosition(int row, int col){
    player_position_[0] = row;
    player_position_[1] = col;
    map_data_[row][col] = PARTY;
}

//sets the dungeon exit to (row,col)
void Map::setDungeonExit(int row, int col){
    dungeon_exit_[0] = row;
    dungeon_exit_[1] = col;
    map_data_[row][col] = EXIT;
}

//prints the map in some map-like format
void Map::displayMap(){
    for(int i = 0; i < num_rows_; i++){
        for(int j = 0; j < num_cols_; j++){
            if (map_data_[i][j] == NPC){
                for (int count = 0; count < npc_count_; count++){
                    if (npc_positions_[count][0] == i && npc_positions_[count][1] == j){
                        if (npc_positions_[count][2]){
                            cout << map_data_[i][j] << " ";
                            break;
                        }
                        else{
                            cout << UNEXPLORED << " ";
                            break;
                        }
                    }
                }
            }
            else{
                cout << map_data_[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

//returns true if the position of the player was able to be changed
//returns false otherwise
bool Map::move(char direction){
    if (isRoomLocation(player_position_[0], player_position_[1])){
        map_data_[player_position_[0]][player_position_[1]] = ROOM;
    }
    else if (isNPCLocation(player_position_[0], player_position_[1])){
        map_data_[player_position_[0]][player_position_[1]] = NPC;
    }
    else if (isDungeonExit(player_position_[0], player_position_[1])){
        map_data_[player_position_[0]][player_position_[1]] = EXIT;
    }
    else if (isExplored(player_position_[0], player_position_[1])){
        map_data_[player_position_[0]][player_position_[1]] = EXPLORED;
    }
    else{
        map_data_[player_position_[0]][player_position_[1]] = UNEXPLORED;
    }

    switch (direction)
    {
    case 'w':
        if (player_position_[0] == 0){
            return false;
        }
        else{
            player_position_[0]--;
            map_data_[player_position_[0]][player_position_[1]] = PARTY;
            return true;
        }
        break;
    case 'a':
        if (player_position_[1] == 0){
            return false;
        }
        else{
            player_position_[1]--;
            map_data_[player_position_[0]][player_position_[1]] = PARTY;
            return true;
        }
        break;
    case 's':
        if (player_position_[0] == 11){
            return false;
        }
        else{
            player_position_[0]++;
            map_data_[player_position_[0]][player_position_[1]] = PARTY;
            return true;
        }
        break;
    case 'd':
        if (player_position_[1] == 11){
            return false;
        }
        else{
            player_position_[1]++;
            map_data_[player_position_[0]][player_position_[1]] = PARTY;
            return true;
        }
        break;
    
    default:
        cout << direction << " is not a valid direction. Please enter a direction you would like to move (w,a,s,d)." << endl;
        cin >> direction;
        return move(direction);
        break;
    }
}

void Map::foundNPC(int row, int col){
    for (int i = 0; i < npc_count_; i++){
        if (npc_positions_[i][0] == row && npc_positions_[i][1] == col){
            npc_positions_[i][2] = true;
        }
    }
}
//returns true if an NPC is able to be added to the map, i.e. npc_count_ != 5 and (row,col) is not occupied
//returns false otherwise
bool Map::addNPC(int row, int col){

}

//returns true if a room is able to be added to the map, i.e. room_count_ != 5 and (row,col) is not occupied
//returns false otherwise
bool Map::addRoom(int row, int col){

}

//returns true if an NPC can be removed, i.e. there is an NPC at (row,col)
//returns false otherwise
bool Map::removeNPC(int row, int col){
    for (int i = 0; i < npc_count_; i++){
        if (npc_positions_[i][0] == row && npc_positions_[i][1] == col){
            npc_positions_[i][0] = -1;
            npc_positions_[i][1] = -1;
            npc_count_--;
            map_data_[row][col] = EXPLORED;
            explored_positions_[exploredCount][0] = row;
            explored_positions_[exploredCount++][1] = col;
            break;
        }
    }
}

//returns true if a room can be removed, i.e. there is a room at (row,col)
//returns false otherwise
bool Map::removeRoom(int row, int col){
    for (int i = 0; i < room_count_; i++){
        if (room_positions_[i][0] == row && room_positions_[i][1] == col){
            room_positions_[i][0] = -1;
            room_positions_[i][1] = -1;
            room_count_--;
            map_data_[row][col] = EXPLORED;
            explored_positions_[exploredCount][0] = row;
            explored_positions_[exploredCount++][1] = col;
            break;
        }
    }
}

//sets the map value at (row,col) to an explored space
void Map::addExploreSpace(int row, int col){
    explored_positions_[exploredCount][0] = row;
    explored_positions_[exploredCount][1] = col;
    exploredCount++;
}
