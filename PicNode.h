//
// Created by hoove on 11/5/2019.
//

#ifndef PICNODES_H
#define PICNODES_H

#include<string>
#include <iomanip>

using namespace std;

class PicNode 
{
private:
	string name;
	int year;
	int nomination;
	double rating;
	int duration;
	string genre1;
	string genre2;
	string release;
	int metacritic;
	string synopsis;

	PicNode* lSubTree, * rSubTree;
public:
	PicNode() :
		name(" "), year(0), nomination(0), rating(0), duration(0), genre1(" "), genre2(" "), release(" "), metacritic(0), synopsis(" "), lSubTree(nullptr), rSubTree(nullptr) {}
	PicNode(string n, int y, int nom, double rat, int d, string g1, string g2, string rel, int m, string s) :
		name(n), year(y), nomination(nom), rating(rat), duration(d), genre1(g1), genre2(g2), release(rel), metacritic(m), synopsis(s), lSubTree(nullptr), rSubTree(nullptr) {}

	void setLeftSubTree(PicNode* ptr) { lSubTree = ptr; }
	void setRightSubTree(PicNode* ptr) { rSubTree = ptr; }
	PicNode* getLeftSubTree() { return lSubTree; }
	PicNode* getRightSubTree() { return rSubTree; }

	void setName(string newName) { name = newName; }
	void setYear(int newYear) { year = newYear; }
	void setNom(int newNom) { nomination = newNom; }
	void setRating(double newRat) { rating = newRat; }
	void setDur(int newDur) { duration = newDur; }
	void setG1(string newG1) { genre1 = newG1; }
	void setG2(string newG2) { genre2 = newG2; }
	void setRel(string newRel) { release = newRel; }
	void setMeta(int newMeta) { metacritic = newMeta; }
	void setSyn(string newSyn) { synopsis = newSyn; }

	string getName() { return name; }
	int getYear() { return year; }
	int getNom() { return nomination; }
	double getRating() { return rating; }
	int getDur() { return duration; }
	string getG1() { return genre1; }
	string getG2() { return genre2; }
	string getRel() { return release; }
	int getMeta() { return metacritic; }
	string getSyn() { return synopsis; }

	void printToScreen();

};


//class definition for SearchResultNode
class PicSearchResultNode
{
private:
	PicNode* picPtr;
	PicSearchResultNode* next;

public:
	PicSearchResultNode() : picPtr(nullptr), next(nullptr) {}
	PicSearchResultNode(PicNode* newFound) : picPtr(newFound), next(nullptr) {}
	void setItem(PicNode* itemPtr) { picPtr = itemPtr; }
	void setNext(PicSearchResultNode* newNext) { next = newNext; }
	PicNode* getItem() { return picPtr; }
	PicSearchResultNode* getNext() { return next; }

}; // end definition for SearchResultNode
#endif