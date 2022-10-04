//
// Created by hoove on 11/5/2019.
//

#ifndef PRACTICE_BINARY_SEARCH_TREE_ACTTREE_H
#define PRACTICE_BINARY_SEARCH_TREE_ACTTREE_H

#include "Nodes.h"
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <stack>
#include <vector>
#include <algorithm>


using namespace std;

//class definition for SearchResultNode
class SearchResultNode{
private:
    ActNode* actorPtr;
    SearchResultNode* next;

public:
    SearchResultNode() : actorPtr(nullptr), next(nullptr) {}
    SearchResultNode(ActNode* newFound) : actorPtr(newFound), next(nullptr) {}
    void setItem(ActNode *itemPtr) {actorPtr = itemPtr;}
    void setNext(SearchResultNode *newNext) {next = newNext;}
    ActNode* getItem() {return actorPtr;}
    SearchResultNode* getNext() {return next;}
}; // end definition for SearchResultNode



//class definition for ActTree
// --------ActTree--------
class ActTree {
private:
    ActNode* rootPtr;
    ActNode* rootYearPtr;
    ActNode* rootAwardPtr;
    ActNode* rootWinnerPtr;
    ActNode* rootFilmPtr;

    int treeSize;

    SearchResultNode *headPtr;
    int listSize;

public:
    ActTree();

    void setRoot(ActNode* newRoot) {rootPtr = newRoot;}
    ActNode* getRoot() {return rootPtr;}

    void printTreeInOrder(int choice);
    int getListSize();
    void deleteTree(int deleteChoice);

    void buildTreeFromFile(string fileName);
    ActNode* searchTree(ActNode *targetPtr);
    void addToTree(ActNode *nodeToAdd);
    void addToList(ActNode* toAddPtr);
    void deleteList();
    void printList();
    void modActRecord(int modifyChoice);

    // complete search functions
    void compYear(int target);
    void compAward(string target);
    void compName(string target);
    void compFilm(string target);


    //partial search functions
    //void callPartialSearch(string target);
    void partYear(int partialYear);
    void partAward(string target);
    void partName(string target);
    void partFilm(string target);

    //sort functions
    void sortYear();
    void sortAward();
    void sortWinner();
    void sortFilm();

    //add actor node function
    void addActNode(int year, string award, bool winner, string name, string film);

    //remove actor function
    void removeActNode(ActNode* nodeToRemovePtr);
    void findAndRemoveNode(int choice);

    //output to file
    void writeToFile(string fileName, int choice);

    //calculate statistics
    void calcStatistics();


};//end definition for ActTree

#endif //PRACTICE_BINARY_SEARCH_TREE_ACTTREE_H
