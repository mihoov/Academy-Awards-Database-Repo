#ifndef _PICTREE_H
#define _PICTREE_H

#include "PicNode.h"
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <stack>
#include <queue>


using namespace std;

//class definition for PicTree
// --------PicTree--------
class PicTree {
private:
	PicNode* rootPtr;
	int treeSize;
	PicSearchResultNode* headPtr;
	int listSize;

	void pushTreeToStack(stack<PicNode*>* nodeStack);
	void popTreeFromStack(stack<PicNode*>* nodeStack);

	void pushTreeToQueue(queue<PicNode*>* nodeQueue);

	bool sortName = true;
	bool sortYear = false;
	bool sortNom = false;
	bool sortRating = false;
	bool sortDur = false;
	bool sortG1 = false;
	bool sortG2 = false;
	bool sortRel = false;
	bool sortMeta = false;
	bool sortSyn = false;

	//sets all sort booleans to false
	void setSortFalse();

	void addToList(PicNode* toAddPtr);

	//
	void completeSearch(string target);
	void completeSearch(string target, PicNode* searchPtr);

	void completeSearch(int target);
	void completeSearch(int target, PicNode* searchPtr);

	void completeSearch(double target);
	void completeSearch(double target, PicNode* searchPtr);

	template<class ItemType>
	void completeFieldSearch(PicNode* target, PicNode* searchPtr, ItemType targetField, ItemType searchField);

	void partialNameSearch(string target, PicNode* searchPtr);
	void partialYearSearch(int target, PicNode* searchPtr);
	void partialNomSearch(int target, PicNode* searchPtr);
	void partialRatingSearch(double target, PicNode* searchPtr);
	void partialDurSearch(int target, PicNode* searchPtr);
	void partialG1Search(string target, PicNode* searchPtr);
	void partialG2Search(string target, PicNode* searchPtr);
	void partialRelSearch(string target, PicNode* searchPtr);
	void partialMetaSearch(int target, PicNode* searchPtr);
	void partialSynSearch(string target, PicNode* searchPtr);
	
	PicNode* searchTree(PicNode* targetPtr, PicNode* rootPtr);
	template<class ItemType>
	PicNode* searchFieldTree(PicNode* targetPtr, PicNode* searchPtr, ItemType targetField, ItemType searchField);

	//add with respect to field being sorted
	template <class ItemType>
	void addFieldToTree(PicNode* nodeToAdd, PicNode* whereToAdd, ItemType whereField, ItemType addField);

	void sortTree();
public:
	PicTree();

	void displayTree();

	void completeNameSearch(string target);
	void completeYearSearch(int target);
	void completeNomSearch(int target);
	void completeRatingSearch(double target);
	void completeDurSearch(int target);
	void completeG1Search(string target);
	void completeG2Search(string target);
	void completeRelSearch(string target);
	void completeMetaSearch(int target);

	void partialNameSearch(string target);
	void partialYearSearch(int target);
	void partialNomSearch(int target);
	void partialRatingSearch(double target);
	void partialDurSearch(int target);
	void partialG1Search(string target);
	void partialG2Search(string target);
	void partialRelSearch(string target);
	void partialMetaSearch(int target);
	void partialSynSearch(string target);

	int buildTreeFromFile(string fileName);
	int saveTreeToFile(string fileName);

	void addToTree(string n, int y, int nom, double rat, int d, string g1, string g2, string rel, int m, string s);
	//add based on current sort field
	void addToTree(PicNode* nodeToAdd);

	//returns number of matches found
	int displaySearchResults();

	void clearTree();

	void sortByName();
	void sortByYear();
	void sortByNom();
	void sortByRating();
	void sortByDur();
	void sortByG1();
	void sortByG2();
	void sortByRel();
	void sortByMeta();

	bool removeRecordSearch(int choice);
	void removeRecord(PicNode* removePtr);

	bool modifyRecordSearch(int choice);
	bool modifyRecordMenu(PicNode* modifyPtr);

};//end definition for PicTree

#endif
