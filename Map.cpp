#include <iostream>
#include "Map.h"
using namespace std;

//creates an instance of a map 
Map::Map(){
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
            npc_positions_[i][3] = 1;
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
    if (map_data_[row][col] == EXPLORED){
        return true;
    }
    else{
        return false;
    }
}

//returns true if the inputted (row,col) is a free space
//returns false otherwise
bool Map::isFreeSpace(int row, int col){

}

//returns true if the inputted (row,col) is the dungeon exit
//returns false otherwise
bool Map::isDungeonExit(int row, int col){
    if (map_data_[row][col] == EXIT){
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

}

//returns true if the position of the player was able to be changed
//returns false otherwise
bool Map::move(char direction){

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

}

//returns true if a room can be removed, i.e. there is a room at (row,col)
//returns false otherwise
bool Map::removeRoom(int row, int col){

}

//sets the map value at (row,col) to an explored space
void Map::exploreSpace(int row, int col){

}
