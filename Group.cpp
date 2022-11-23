//Group.cpp
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#include "Group.h"
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

    //creates a group
    Group::Group(){   
    }

    //adds a player to the players vector 
    bool Group::addPlayer(Player p){
        players.push_back(p);
    }

    Player Group::getPlayer(int index){
        return players.at(index);
    }

    void Group::setPlayerFullness(int index, int fullness){
        players.at(index).setFullness(fullness);
    }

    int Group::getSize(){
        return players.size();
    }

    void Group::removePlayer(int index){
        
    }

    //returns the rooms cleared
    int Group::getRoomsCleared(){
        return rooms_cleared;
    }

    //returns the number of keys 
    int Group::getNumKeys(){
        return num_keys;
    }

    //returns the anger level of the Sorcerer
    int Group::getAngerLevel(){
        return anger_level;
    }

    //returns the gold 
    int Group::getGold(){
        return gold;
    }

    //returns the ingredients
    int Group::getIngredients(){
        return ingredients;
    }

    //returns the number of pots
    int Group::getNumPots(){
        return cookware[0];
    }

    //returns the number of pans
    int Group::getNumPans(){
        return cookware[1];
    }

    //returns the number of cauldrons
    int Group::getNumCauldrons(){
        return cookware[2];
    }

    //returns the number of clubs
    int Group::getNumClubs(){
        return weapons[0];
    }

    //returns the number of weapons
    int Group::getNumSpears(){
        return weapons[1];
    }

    //returns the number of rapiers 
    int Group::getNumRapiers(){
        return weapons[2];
    }

    //returns the number of battle axes 
    int Group::getNumBattleAxes(){
        return weapons[3];
    }

    //returns the number of long swords
    int Group::getNumLongSwords(){
        return weapons[4];
    }

    int Group::getNumArmor(){
        return armor;
    }

    int Group::getNumRings(){
        return treasures[0];
    }
    int Group::getNumNecklace(){
        return treasures[1];
    }
    int Group::getNumBraclet(){
        return treasures[2];
    }
    int Group::getNumCirclet(){
        return treasures[3];
    }
    int Group::getNumGoblet(){
        return treasures[4];
    }

    //sets the number of rooms cleared 
    void Group::setRoomsCleared(int rooms_cleared_){
        rooms_cleared = rooms_cleared_;
    }

    //sets the number of keys 
    void Group::setNumKeys(int num_keys_){
        num_keys = num_keys_;
    }

    //sets the anger level of the sorcerer 
    void Group::setAngerLevel(int anger_level_){
        anger_level = anger_level_;
    }

    //sets the gold 
    void Group::setGold(int gold_){
        gold = gold_;
    }

    //sets the ingredients
    void Group::setIngredients(int ingredients_){
        ingredients = ingredients_;
    }

    //sets the number of pots 
    void Group::setNumPots(int num_pots){
        cookware[0] = num_pots;
    }

    //sets the number of pans
    void Group::setNumPans(int num_pans){
        cookware[1] = num_pans;
    }

    //sets the number of cauldrons
    void Group::setNumCauldrons(int num_cauldrons){
        cookware[2] = num_cauldrons;
    }

    //sets the number of clubs
    void Group::setNumClubs(int num_clubs){
        weapons[0] = num_clubs;
    }

    //sets the number of spears 
    void Group::setNumSpears(int num_spears){
        weapons[1] = num_spears;
    }

    //sets the number of rapiers 
    void Group::setNumRapiers(int num_rapiers){
        weapons[2] = num_rapiers;
    }

    //sets the number of battle axes
    void Group::setNumBattleAxes(int num_battleAxes){
        weapons[3] = num_battleAxes;
    }

    //sets the number of longswords
    void Group::setNumLongSwords(int num_longSwords){
        weapons[4] = num_longSwords;
    }

    void Group::setNumArmor(int num_armor){
        armor = num_armor;
    }
    void Group::setNumRings(int num_rings){
        treasures[0] = num_rings;
    }
    void Group::setNumNecklace(int num_necklace){
        treasures[1] = num_necklace;
    }
    void Group::setNumBraclet(int num_braclet){
        treasures[2] = num_braclet;
    }
    void Group::setNumCirclet(int num_circlet){
        treasures[3] = num_circlet;
    }
    void Group::setNumGoblet(int num_goblet){
        treasures[4] = num_goblet;
    }
