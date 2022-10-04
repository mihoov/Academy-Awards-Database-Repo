//
// Created by hoove on 11/5/2019.
//

#ifndef PRACTICE_BINARY_SEARCH_TREE_NODES_H
#define PRACTICE_BINARY_SEARCH_TREE_NODES_H

#include<string>
#include <iomanip>

using namespace std;

class ActNode{
private:
    int year;
    string award;
    bool winner;
    string name;
    string film;

    ActNode *lSubTree, *rSubTree;
public:
    ActNode() : year(0), award(" "), winner(false), name(" "), film(" "), lSubTree(nullptr), rSubTree(nullptr) {}
    ActNode(int y, string a, bool w, string n, string f) :
            year(y), award(a), winner(w), name(n), film(f), lSubTree(nullptr), rSubTree(nullptr)  {}


    void setYear (int newYear);
    void setAward (string newAward);
    void setWinner (bool newWinner);
    void setName(string newName);
    void setFilm(string newFilm);

    void setLeftSubTree(ActNode * ptr) {lSubTree = ptr;}
    void setRightSubTree(ActNode * ptr) {rSubTree = ptr;}
    ActNode * getLeftSubTree() {return lSubTree;}
    ActNode * getRightSubTree() {return rSubTree;}
    int getYear() {return year;}
    string getAward() {return award;}
    bool getWinner() {return winner;}
    string getName() { return name;}
    string getFilm() {return film;}
    void printToScreen();
    void modifyNode();

};
#endif //PRACTICE_BINARY_SEARCH_TREE_NODES_H
