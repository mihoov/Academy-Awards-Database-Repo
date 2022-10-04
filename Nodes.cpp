//
// Created by hoove on 11/5/2019.
//

#include <iostream>
#include "Nodes.h"

void ActNode::setYear(int newYear) {
    year = newYear;
}

void ActNode::setAward(string newAward) {
    award = newAward;
}

void ActNode::setWinner(bool newWinner) {
    winner = newWinner;
}

void ActNode::setName(string newName) {
    name = newName;
}

void ActNode::setFilm(string newFilm) {
    film = newFilm;
}


void ActNode::printToScreen() {

    cout << setfill(' ') << setw(6) << year << setw(30) << award << setw(10) << "Winner:";
    if (winner == true){
        cout << setw(5) << "Yes";
    }
    else{
        cout << setw(5) << "No";
    }
    cout << setw(30) << name << "  " << film << endl;
}