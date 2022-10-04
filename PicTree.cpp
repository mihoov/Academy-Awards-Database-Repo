 #include "PicTree.h"
#include <string>

//default contstructor for PicTree
PicTree::PicTree() : rootPtr(nullptr), treeSize(0), headPtr(nullptr), listSize(0) {}

//set sort false
void PicTree::setSortFalse()
{
	sortName = false;
	sortYear = false;
	sortNom = false;
	sortRating = false;
	sortDur = false;
	sortG1 = false;
	sortG2 = false;
	sortRel = false;
	sortMeta = false;
	sortSyn = false;
}

//displayTree
void PicTree::displayTree()
{
	PicTree* tempTree;
	PicNode* currPtr = rootPtr;

	//make sure tree is non empty
	if (rootPtr == nullptr)
	{
	}

	else
	{
		//recursively call displayTree for each leftSubTree
		//in order
		if (currPtr->getLeftSubTree() != nullptr)
		{
			tempTree = new PicTree();
			tempTree->addToTree(currPtr->getLeftSubTree());
			tempTree->displayTree();
		}

		//base case, reached when null leftSubTree is reached
		currPtr->printToScreen();

		//recursively call displayTree for each righSubTree until one is null
		if (currPtr->getRightSubTree() != nullptr)
		{
			tempTree = new PicTree();
			tempTree->addToTree(currPtr->getRightSubTree());
			tempTree->displayTree();
		}
	}
}


//--------addToList--------
void PicTree::addToList(PicNode* toAddPtr) 
{
	if (headPtr == nullptr) {
		headPtr = new PicSearchResultNode(toAddPtr);
		listSize = 1;
	}
	else {
		//set currPtr to beginning of list
		PicSearchResultNode* currPtr;
		currPtr = headPtr;

		// loop traverses list until end of list is found.
		while (currPtr->getNext() != nullptr) {
			currPtr = currPtr->getNext();
		}

		//add new search result to the end of list.
		currPtr->setNext(new PicSearchResultNode(toAddPtr));
		listSize++;
	}

}


//--------searchTree--------
PicNode* PicTree::searchTree(PicNode* targetPtr, PicNode* rootPtr)
{
	PicNode* searchPtr = rootPtr;

	//search with respect to name
	if (sortName)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return searchFieldTree<string>(targetPtr, searchPtr, targetPtr->getName(), searchPtr->getName());
		}
	}

	//search with respect to year
	else if (sortYear)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return searchFieldTree<int>(targetPtr, searchPtr, targetPtr->getYear(), searchPtr->getYear());
		}
	}

	else if (sortNom)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return searchFieldTree<int>(targetPtr, searchPtr, targetPtr->getNom(), searchPtr->getNom());
		}
	}

	else if (sortRating)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return searchFieldTree<double>(targetPtr, searchPtr, targetPtr->getRating(), searchPtr->getRating());
		}
	}

	else if (sortDur)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return searchFieldTree<int>(targetPtr, searchPtr, targetPtr->getDur(), searchPtr->getDur());
		}
	}

	else if (sortG1)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return searchFieldTree<string>(targetPtr, searchPtr, targetPtr->getG1(), searchPtr->getG1());
		}
	}

	else if (sortG2)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return searchFieldTree<string>(targetPtr, searchPtr, targetPtr->getG2(), searchPtr->getG2());
		}
	}

	else if (sortRel)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return searchFieldTree<string>(targetPtr, searchPtr, targetPtr->getRel(), searchPtr->getRel());
		}
	}

	else if (sortMeta)
	{
	//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return searchFieldTree<int>(targetPtr, searchPtr, targetPtr->getMeta(), searchPtr->getMeta());
		}	
	}
}

//search with respect to field being sorted
template <class ItemType>
PicNode* PicTree::searchFieldTree(PicNode* targetPtr, PicNode* searchPtr, ItemType targetField, ItemType searchField) 
{
	PicNode* tempPtr;

	bool found = false;

	if (targetField == searchField) { return searchPtr; }

	//if target is less than current node go to left subtree
	else if (targetField < searchField && searchPtr->getLeftSubTree() != nullptr)
	{
		searchPtr = searchPtr->getLeftSubTree();
		return searchTree(targetPtr, searchPtr);

		//if left subtree is empty end search
	}

	//if target is greater than current node go to right subtree
	else if (targetField > searchField && searchPtr->getRightSubTree() != nullptr) 
	{
		searchPtr = searchPtr->getRightSubTree();
		return searchTree(targetPtr, searchPtr);

		//if right subtree is empty end search
	}

	return searchPtr;
}

//--------addToTree--------

void PicTree::addToTree(string n, int y, int nom, double rat, int d, string g1, string g2, string rel, int m, string s)
{
	PicNode* nodeToAdd = new PicNode(n, y, nom, rat, d, g1, g2, rel, m, s);

	addToTree(nodeToAdd);
}

//add based on current sort field
void PicTree::addToTree(PicNode* nodeToAdd)
{
	PicNode* whereToAdd;

	//add with respect to name
	if (sortName)
	{
		//call searchTree to find location to add the new node
		whereToAdd = searchTree(nodeToAdd, rootPtr);

		//add node to beginning of tree if tree is empty
		if (rootPtr == nullptr)
		{
			rootPtr = nodeToAdd;
		}
		else
		{
			addFieldToTree<string>(nodeToAdd, whereToAdd, nodeToAdd->getName(), whereToAdd->getName());
		}
	}

	//add with respect to year
	else if (sortYear)
	{
		//call searchTree to find location to add the new node
		whereToAdd = searchTree(nodeToAdd, rootPtr);

		//add node to beginning of tree if tree is empty
		if (whereToAdd == nullptr)
		{
			rootPtr = nodeToAdd;
		}
		else
		{
			addFieldToTree<int>(nodeToAdd, whereToAdd, nodeToAdd->getYear(), whereToAdd->getYear());
		}
	}

	else if (sortNom)
	{
		//call searchTree to find location to add the new node
		whereToAdd = searchTree(nodeToAdd, rootPtr);

		//add node to beginning of tree if tree is empty
		if (whereToAdd == nullptr)
		{
			rootPtr = nodeToAdd;
		}
		else
		{
			addFieldToTree<int>(nodeToAdd, whereToAdd, nodeToAdd->getNom(), whereToAdd->getNom());
		}
	}

	else if (sortRating)
	{
		//call searchTree to find location to add the new node
		whereToAdd = searchTree(nodeToAdd, rootPtr);

		//add node to beginning of tree if tree is empty
		if (whereToAdd == nullptr)
		{
			rootPtr = nodeToAdd;
		}
		else
		{
			addFieldToTree<double>(nodeToAdd, whereToAdd, nodeToAdd->getRating(), whereToAdd->getRating());
		}
	}

	else if (sortDur)
	{
		//call searchTree to find location to add the new node
		whereToAdd = searchTree(nodeToAdd, rootPtr);

		//add node to beginning of tree if tree is empty
		if (whereToAdd == nullptr)
		{
			rootPtr = nodeToAdd;
		}
		else
		{
			addFieldToTree<int>(nodeToAdd, whereToAdd, nodeToAdd->getDur(), whereToAdd->getDur());
		}
	}

	else if (sortG1)
	{
		//call searchTree to find location to add the new node
		whereToAdd = searchTree(nodeToAdd, rootPtr);

		//add node to beginning of tree if tree is empty
		if (whereToAdd == nullptr)
		{
			rootPtr = nodeToAdd;
		}
		else
		{
			addFieldToTree<string>(nodeToAdd, whereToAdd, nodeToAdd->getG1(), whereToAdd->getG1());
		}
	}

	else if (sortG2)
	{
		//call searchTree to find location to add the new node
		whereToAdd = searchTree(nodeToAdd, rootPtr);

		//add node to beginning of tree if tree is empty
		if (whereToAdd == nullptr)
		{
			rootPtr = nodeToAdd;
		}
		else
		{
			addFieldToTree<string>(nodeToAdd, whereToAdd, nodeToAdd->getG2(), whereToAdd->getG2());
		}
	}

	else if (sortRel)
	{
		//call searchTree to find location to add the new node
		whereToAdd = searchTree(nodeToAdd, rootPtr);

		//add node to beginning of tree if tree is empty
		if (whereToAdd == nullptr)
		{
			rootPtr = nodeToAdd;
		}
		else
		{
			addFieldToTree<string>(nodeToAdd, whereToAdd, nodeToAdd->getRel(), whereToAdd->getRel());
		}
	}

	else if (sortMeta)
	{
		//call searchTree to find location to add the new node
		whereToAdd = searchTree(nodeToAdd, rootPtr);

		//add node to beginning of tree if tree is empty
		if (whereToAdd == nullptr)
		{
			rootPtr = nodeToAdd;
		}
		else
		{
			addFieldToTree<int>(nodeToAdd, whereToAdd, nodeToAdd->getMeta(), whereToAdd->getMeta());
		}
	}
}

//add with respect to field being sorted
template <class ItemType>
void PicTree::addFieldToTree(PicNode* nodeToAdd, PicNode* whereToAdd, ItemType addField, ItemType whereField)
{
	//add node to beginning of tree if tree is empty
	if (rootPtr == nullptr)
	{
		rootPtr = nodeToAdd;
	}

	//If picture node name has been entered before, insert nodeToAdd next to it
	else if (whereField == addField)
	{
		nodeToAdd->setLeftSubTree(whereToAdd->getLeftSubTree());
		nodeToAdd->setRightSubTree(nullptr);

		whereToAdd->setLeftSubTree(nodeToAdd);
	}

	else if (addField < whereField) {
		whereToAdd->setLeftSubTree(nodeToAdd);
	}
	//add node to right subtree
	else if (addField > whereField) {
		whereToAdd->setRightSubTree(nodeToAdd);
	}

}

//--------buildTreeFromFile--------
//Returns 0 if successful, 1 if unsuccessful
int PicTree::buildTreeFromFile(string fileName) 
{
	setSortFalse();
	sortName = true;

	ifstream inFile;
	inFile.open(fileName);

	if (!inFile)
	{
		return 1;
	}
	int newYear, newNom, newDur, newMeta;
	double newRat;
	string newName, newG1, newG2, newRel, newSyn;
	string tempYear, tempNom, tempRat, tempDur, tempMeta;

	char tempChar;

	//ignore first line of file
	getline(inFile, tempYear);

	//ignore initial space
	inFile.ignore();
	//read first line from the file and save the data to corresponding variables
	getline(inFile, newName, ',');
	getline(inFile, tempYear, ',');
	newYear = stoi(tempYear);
	//accounts for case where nomination is unavailable
	getline(inFile, tempNom, ',');
	if (tempNom == "" || tempNom == "-")
	{
		newNom = 0;
	}
	else
	{
		newNom = stoi(tempNom);
	}

	//accounts for case where rating is unavailable
	getline(inFile, tempRat, ',');
	if (tempRat == "")
	{
		newRat = 0;
	}
	else 
	{
		newRat = stod(tempRat);

	}
	getline(inFile, tempDur, ',');
	newDur = stoi(tempDur);
	getline(inFile, newG1, ',');
	//accounts for case where genre is not available
	getline(inFile, newG2, ',');
	if (newG2 == "")
	{
		newG2 == "n/a";
	}
	//accounts for case where release date is not available
	getline(inFile, newRel, ',');
	if (newRel == "")
	{
		newRel = "n/a";
	}
	//accounts for case where metadata is not available
	getline(inFile, tempMeta, ',');
	if (tempMeta == "")
	{
		newMeta = 0;
	}
	else
	{
		newMeta = stoi(tempMeta);
	}
	
	getline(inFile, newSyn);


	//use the first line of the file to create the root of the tree
	rootPtr = new PicNode(newName, newYear, newNom, newRat, newDur, newG1, newG2, newRel, newMeta, newSyn);
	treeSize++;

	PicNode* currPtr;

	//begin loop to read lines from file until end of file
	while (inFile.ignore())
	{
		getline(inFile, newName, ',');
		getline(inFile, tempYear, ',');
		newYear = stoi(tempYear);
		//accounts for case where nomination is unavailable
		getline(inFile, tempNom, ',');
		if (tempNom == "" || tempNom == "-")
		{;
			newNom = 0;
		}
		else
		{
			newNom = stoi(tempNom);
		}
		//accounts for case where rating is unavailable
		getline(inFile, tempRat, ',');
		if (tempRat == "")
		{
			newRat = 0;
		}
		else
		{
			newRat = stod(tempRat);

		}
		getline(inFile, tempDur, ',');
		newDur = stoi(tempDur);
		getline(inFile, newG1, ',');
		//accounts for case where genre is not available
		getline(inFile, newG2, ',');
		if (newG2 == "")
		{
			newG2 = "n/a";
		}
		//accounts for case where release date is not available
		getline(inFile, newRel, ',');
		if (newRel == "")
		{
			newRel = "n/a";
		}
		//accounts for case where metadata is not available
		getline(inFile, tempMeta, ',');
		if (tempMeta == "")
		{
			newMeta = 0;
		}
		else
		{
			newMeta = stoi(tempMeta);
		}
		getline(inFile, newSyn);

		//have pointer point to a PicNode with the data read from file
		currPtr = new PicNode(newName, newYear, newNom, newRat, newDur, newG1, newG2, newRel, newMeta, newSyn);

		//add node to tree
		addToTree(currPtr);
		treeSize++;

	}// end while loop

	return 0;
}

int PicTree::saveTreeToFile(string fileName)
{
	queue<PicNode*>* nodeQueue = new queue<PicNode*>;
	PicNode* currPtr;

	pushTreeToQueue(nodeQueue);

	ofstream outFile;
	outFile.open(fileName);

	outFile << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis" << endl;

	while (!nodeQueue->empty())
	{
		currPtr = nodeQueue->front();
		nodeQueue->pop();
		outFile << " " << currPtr->getName() << "," << currPtr->getYear() << "," << currPtr->getNom() << ",";
		outFile << currPtr->getRating() << "," << currPtr->getDur() << "," << currPtr->getG1() << ",";
		outFile << currPtr->getG2() << "," << currPtr->getRel() << "," << currPtr->getMeta() << ",";
		outFile << currPtr->getSyn() << endl;
	}

	return 0;
}

//------------complete search----------------

void PicTree::completeSearch(string target)
{
	PicNode* searchPtr = rootPtr;

	headPtr = nullptr;

	completeSearch(target, searchPtr);
}

void PicTree::completeSearch(string target, PicNode* searchPtr)
{
	PicNode* targetPtr;

	//search with respect to name
	if (sortName)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
		}
		else
		{
			targetPtr = new PicNode;
			targetPtr->setName(target);

			searchPtr = searchTree(targetPtr, searchPtr);

			if (searchPtr != nullptr)
			{
				completeFieldSearch<string>(targetPtr, searchPtr, targetPtr->getName(), searchPtr->getName());
			}
		}
	}

	//search with respect to genre 1
	else if (sortG1)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
		}
		else
		{
			targetPtr = new PicNode;
			targetPtr->setG1(target);

			searchPtr = searchTree(targetPtr, searchPtr);

			completeFieldSearch<string>(targetPtr, searchPtr, targetPtr->getG1(), searchPtr->getG1());
		}
	}

	//search with respect to genre 2
	else if (sortG2)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
		}
		else
		{
			targetPtr = new PicNode;
			targetPtr->setG2(target);

			searchPtr = searchTree(targetPtr, searchPtr);

			completeFieldSearch<string>(targetPtr, searchPtr, targetPtr->getG2(), searchPtr->getG2());
		}
	}

	//search with respect to release
	else if (sortRel)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
		}
		else
		{
			targetPtr = new PicNode;
			targetPtr->setRel(target);

			searchPtr = searchTree(targetPtr, searchPtr);

			completeFieldSearch<string>(targetPtr, searchPtr, targetPtr->getRel(), searchPtr->getRel());
		}
	}
}

void PicTree::completeSearch(int target)
{
	headPtr = nullptr;

	PicNode* searchPtr = rootPtr;

	completeSearch(target, searchPtr);
}

void PicTree::completeSearch(int target, PicNode* searchPtr)
{
	PicNode* targetPtr;

	//search with respect to year
	if (sortYear)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
		}
		else
		{
			targetPtr = new PicNode;
			targetPtr->setYear(target);

			searchPtr = searchTree(targetPtr, searchPtr);

			if (searchPtr != nullptr)
			{
				completeFieldSearch<int>(targetPtr, searchPtr, targetPtr->getYear(), searchPtr->getYear());
			}
		}
	}
	
	//search with respect to nomination
	else if (sortNom)
	{
		//if tree is empty
		if (rootPtr == nullptr)
		{
		}
		else
		{
			targetPtr = new PicNode;
			targetPtr->setNom(target);

			searchPtr = searchTree(targetPtr, searchPtr);

			if (searchPtr != nullptr)
			{
				completeFieldSearch<int>(targetPtr, searchPtr, targetPtr->getNom(), searchPtr->getNom());
			}
		}
	}

	//search with respect to duration
	else if (sortDur)
	{
		//if tree is empty
		if (rootPtr == nullptr)
		{
		}
		else
		{
			targetPtr = new PicNode;
			targetPtr->setDur(target);

			searchPtr = searchTree(targetPtr, searchPtr);

			if (searchPtr != nullptr)
			{
				completeFieldSearch<int>(targetPtr, searchPtr, targetPtr->getDur(), searchPtr->getDur());
			}
		}
	}

	//search with respect to metacritic
	else if (sortMeta)
	{
		//if tree is empty
		if (rootPtr == nullptr)
		{
		}
		else
		{
			targetPtr = new PicNode;
			targetPtr->setMeta(target);

			searchPtr = searchTree(targetPtr, searchPtr);

			if (searchPtr != nullptr)
			{
				completeFieldSearch<int>(targetPtr, searchPtr, targetPtr->getMeta(), searchPtr->getMeta());
			}
		}
	}
}

void PicTree::completeSearch(double target)
{
	PicNode* searchPtr = rootPtr;

	headPtr = nullptr;

	completeSearch(target, searchPtr);
}
void PicTree::completeSearch(double target, PicNode* searchPtr)
{
	PicNode* targetPtr;

	//search with respect to rating
	if (sortRating)
	{
		//if tree is empty, make return null
		if (rootPtr == nullptr)
		{
		}
		else
		{
			targetPtr = new PicNode;
			targetPtr->setRating(target);

			searchPtr = searchTree(targetPtr, searchPtr);

			completeFieldSearch<double>(targetPtr, searchPtr, targetPtr->getRating(), searchPtr->getRating());
		}
	}
}

template<class ItemType>
void PicTree::completeFieldSearch(PicNode* targetPtr, PicNode* searchPtr, ItemType targetField, ItemType searchField)
{

	PicSearchResultNode* currSearchPtr = headPtr;
	PicSearchResultNode* tempSearchPtr;

	if (targetField == searchField)
	{
		if (headPtr == nullptr)
		{
			headPtr = new PicSearchResultNode(searchPtr);

			completeSearch(targetField, searchPtr->getLeftSubTree());
		}

		else
		{
			tempSearchPtr = new PicSearchResultNode(searchPtr);
			while (currSearchPtr->getNext() != nullptr)
			{
				currSearchPtr = currSearchPtr->getNext();
			}
			currSearchPtr->setNext(tempSearchPtr);
			currSearchPtr = currSearchPtr->getNext();

			completeSearch(targetField, searchPtr->getLeftSubTree());
		}
	}
}

//ensure that original sort is maintained
void PicTree::completeNameSearch(string target)
{
	//do complete search of name, ensure that original sort is maintained
	if (sortName)
	{
		completeSearch(target);
	}
	
	else if (sortYear)
	{
		sortByName();
		completeSearch(target);
		sortByYear();
	}

	else if (sortNom)
	{
		sortByName();
		completeSearch(target);
		sortByNom();
	}

	else if (sortRating)
	{
		sortByName();
		completeSearch(target);
		sortByRating();
	}

	else if (sortDur)
	{
		sortByName();
		completeSearch(target);
		sortByDur();
	}

	else if (sortG1)
	{
		sortByName();
		completeSearch(target);
		sortByG1();
	}

	else if (sortG2)
	{
		sortByName();
		completeSearch(target);
		sortByG2();
	}

	else if (sortRel)
	{	
		sortByName();
		completeSearch(target);
		sortByRel();
	}

	else if (sortMeta)
	{
		sortByName();
		completeSearch(target);
		sortByMeta();
	}
}
void PicTree::completeYearSearch(int target)
{
	//do complete search of year, ensure that original sort is maintained
	if (sortName)
	{
		sortByYear();
		completeSearch(target);
		sortByName();
	}

	else if (sortYear)
	{
		completeSearch(target);
	}

	else if (sortNom)
	{
		sortByYear();
		completeSearch(target);
		sortByNom();
	}

	else if (sortRating)
	{
		sortByYear();
		completeSearch(target);
		sortByRating();
	}

	else if (sortDur)
	{
		sortByYear();
		completeSearch(target);
		sortByDur();
	}

	else if (sortG1)
	{
		sortByYear();
		completeSearch(target);
		sortByG1();
	}

	else if (sortG2)
	{
		sortByYear();
		completeSearch(target);
		sortByG2();
	}

	else if (sortRel)
	{
		sortByYear();
		completeSearch(target);
		sortByRel();
	}

	else if (sortMeta)
	{
		sortByYear();
		completeSearch(target);
		sortByMeta();
	}
}
void PicTree::completeNomSearch(int target)
{
	//do complete search of nomination, ensure that original sort is maintained
	if (sortName)
	{
		sortByNom();
		completeSearch(target);
		sortByName();
	}

	else if (sortYear)
	{
		sortByNom();
		completeSearch(target);
		sortByYear();
	}

	else if (sortNom)
	{
		completeSearch(target);
	}

	else if (sortRating)
	{
		sortByNom();
		completeSearch(target);
		sortByRating();
	}

	else if (sortDur)
	{
		sortByNom();
		completeSearch(target);
		sortByDur();
	}

	else if (sortG1)
	{
		sortByNom();
		completeSearch(target);
		sortByG1();
	}

	else if (sortG2)
	{
		sortByNom();
		completeSearch(target);
		sortByG2();
	}

	else if (sortRel)
	{
		sortByNom();
		completeSearch(target);
		sortByRel();
	}

	else if (sortMeta)
	{
		sortByNom();
		completeSearch(target);
		sortByMeta();
	}
}
void PicTree::completeRatingSearch(double target)
{
	//do complete search of rating, ensure that original sort is maintained
	if (sortName)
	{
		sortByRating();
		completeSearch(target);
		sortByName();
	}

	else if (sortYear)
	{
		sortByRating();
		completeSearch(target);
		sortByYear();
	}

	else if (sortNom)
	{
		sortByRating();
		completeSearch(target);
		sortByNom();
	}

	else if (sortRating)
	{
		completeSearch(target);
	}

	else if (sortDur)
	{
		sortByRating();
		completeSearch(target);
		sortByDur();
	}

	else if (sortG1)
	{
		sortByRating();
		completeSearch(target);
		sortByG1();
	}

	else if (sortG2)
	{
		sortByRating();
		completeSearch(target);
		sortByG2();
	}

	else if (sortRel)
	{
		sortByRating();
		completeSearch(target);
		sortByRel();
	}

	else if (sortMeta)
	{
		sortByRating();
		completeSearch(target);
		sortByMeta();
	}
}
void PicTree::completeDurSearch(int target)
{
	//do complete search of duration, ensure that original sort is maintained
	if (sortName)
	{
		sortByDur();
		completeSearch(target);
		sortByName();
	}

	else if (sortYear)
	{
		sortByDur();
		completeSearch(target);
		sortByYear();
	}

	else if (sortNom)
	{
		sortByDur();
		completeSearch(target);
		sortByNom();
	}

	else if (sortRating)
	{
		sortByDur();
		completeSearch(target);
		sortByRating();
	}

	else if (sortDur)
	{
		completeSearch(target);
	}

	else if (sortG1)
	{
		sortByDur();
		completeSearch(target);
		sortByG1();
	}

	else if (sortG2)
	{
		sortByDur();
		completeSearch(target);
		sortByG2();
	}

	else if (sortRel)
	{
		sortByDur();
		completeSearch(target);
		sortByRel();
	}

	else if (sortMeta)
	{
		sortByDur();
		completeSearch(target);
		sortByMeta();
	}
}
void PicTree::completeG1Search(string target)
{
	//do complete search of genre 1, ensure that original sort is maintained
	if (sortName)
	{
		sortByG1();
		completeSearch(target);
		sortByName();
	}

	else if (sortYear)
	{
		sortByG1();
		completeSearch(target);
		sortByYear();
	}

	else if (sortNom)
	{
		sortByG1();
		completeSearch(target);
		sortByNom();
	}

	else if (sortRating)
	{
		sortByG1();
		completeSearch(target);
		sortByRating();
	}

	else if (sortDur)
	{
		sortByG1();
		completeSearch(target);
		sortByDur();
	}

	else if (sortG1)
	{
		completeSearch(target);
	}

	else if (sortG2)
	{
		sortByG1();
		completeSearch(target);
		sortByG2();
	}

	else if (sortRel)
	{
		sortByG1();
		completeSearch(target);
		sortByRel();
	}

	else if (sortMeta)
	{
		sortByG1();
		completeSearch(target);
		sortByMeta();
	}
}
void PicTree::completeG2Search(string target)
{
	//do complete search of genre 1, ensure that original sort is maintained
	if (sortName)
	{
		sortByG2();
		completeSearch(target);
		sortByName();
	}

	else if (sortYear)
	{
		sortByG2();
		completeSearch(target);
		sortByYear();
	}

	else if (sortNom)
	{
		sortByG2();
		completeSearch(target);
		sortByNom();
	}

	else if (sortRating)
	{
		sortByG2();
		completeSearch(target);
		sortByRating();
	}

	else if (sortDur)
	{
		sortByG2();
		completeSearch(target);
		sortByDur();
	}

	else if (sortG1)
	{
		sortByG2();
		completeSearch(target);
		sortByG1();
	}

	else if (sortG2)
	{
		completeSearch(target);
	}

	else if (sortRel)
	{
		sortByG2();
		completeSearch(target);
		sortByRel();
	}

	else if (sortMeta)
	{
		sortByG2();
		completeSearch(target);
		sortByMeta();
	}
}
void PicTree::completeRelSearch(string target)
{
	//do complete search of genre 1, ensure that original sort is maintained
	if (sortName)
	{
		sortByRel();
		completeSearch(target);
		sortByName();
	}

	else if (sortYear)
	{
		sortByRel();
		completeSearch(target);
		sortByYear();
	}

	else if (sortNom)
	{
		sortByRel();
		completeSearch(target);
		sortByNom();
	}

	else if (sortRating)
	{
		sortByRel();
		completeSearch(target);
		sortByRating();
	}

	else if (sortDur)
	{
		sortByRel();
		completeSearch(target);
		sortByDur();
	}

	else if (sortG1)
	{
		sortByRel();
		completeSearch(target);
		sortByG1();
	}

	else if (sortG2)
	{
		sortByRel();
		completeSearch(target);
		sortByG2();
	}

	else if (sortRel)
	{
		completeSearch(target);
	}

	else if (sortMeta)
	{
		sortByRel();
		completeSearch(target);
		sortByMeta();
	}
}
void PicTree::completeMetaSearch(int target)
{
	//do complete search of genre 1, ensure that original sort is maintained
	if (sortName)
	{
		sortByMeta();
		completeSearch(target);
		sortByName();
	}

	else if (sortYear)
	{
		sortByMeta();
		completeSearch(target);
		sortByYear();
	}

	else if (sortNom)
	{
		sortByMeta();
		completeSearch(target);
		sortByNom();
	}

	else if (sortRating)
	{
		sortByMeta();
		completeSearch(target);
		sortByRating();
	}

	else if (sortDur)
	{
		sortByMeta();
		completeSearch(target);
		sortByDur();
	}

	else if (sortG1)
	{
		sortByMeta();
		completeSearch(target);
		sortByG1();
	}

	else if (sortG2)
	{
		sortByMeta();
		completeSearch(target);
		sortByG2();
	}

	else if (sortRel)
	{
		sortByMeta();
		completeSearch(target);
		sortByRel();
	}

	else if (sortMeta)
	{
		completeSearch(target);
	}
}

//------------partial search------------
//ensure that original sort is maintained
void PicTree::partialNameSearch(string target)
{
	PicNode* searchPtr = rootPtr;

	headPtr = nullptr;

	if (rootPtr != nullptr)
	{
		partialNameSearch(target, searchPtr);
	}
}
void PicTree::partialNameSearch(string target, PicNode* searchPtr)
{
	PicNode* targetPtr = new PicNode;
	targetPtr->setName(target);

	string targetString, searchString;

	targetString = targetPtr->getName();
	searchString = searchPtr->getName();

	for (int i = 0; i < targetString.length(); i++) 
	{
		targetString[i] = tolower(targetString[i]);
	}

	if (searchPtr != nullptr) {

		searchString = searchPtr->getName();
		for (int i = 0; i < searchString.length(); i++) 
		{
			searchString[i] = tolower(searchString[i]);

		}
		//check if target substring is contained in the PicNode
		if (searchString.find(targetString) != -1) 
		{
			//add PicNode to the list of search results
			addToList(searchPtr);

		}

		//search left subtree
		if (searchPtr->getLeftSubTree() != nullptr)
		{
			partialNameSearch(target, searchPtr->getLeftSubTree());
		}
		
		//search right subtree
		if (searchPtr->getRightSubTree() != nullptr)
		{
			partialNameSearch(target, searchPtr->getRightSubTree());
		}
	}
}

void PicTree::partialYearSearch(int target)
{
	PicNode* searchPtr = rootPtr;

	headPtr = nullptr;

	if (rootPtr != nullptr)
	{
		partialYearSearch(target, searchPtr);
	}
}
void PicTree::partialYearSearch(int target, PicNode* searchPtr)
{
	PicNode* targetPtr = new PicNode;
	targetPtr->setYear(target);

	int targetInt, searchInt;
	string targetString, searchString;

	targetInt = targetPtr->getYear();

	targetString = to_string(targetInt);

	if (searchPtr != nullptr) {

		searchInt = searchPtr->getYear();
		searchString = to_string(searchInt);;
		for (int i = 0; i < searchString.length(); i++)
		{
			searchString[i] = tolower(searchString[i]);

		}
		//check if target substring is contained in the PicNode
		if (searchString.find(targetString) != -1)
		{
			//add PicNode to the list of search results
			addToList(searchPtr);

		}

		//search left subtree
		if (searchPtr->getLeftSubTree() != nullptr)
		{
			partialNomSearch(target, searchPtr->getLeftSubTree());
		}

		//search right subtree
		if (searchPtr->getRightSubTree() != nullptr)
		{
			partialNomSearch(target, searchPtr->getRightSubTree());
		}
	}
}

void PicTree::partialNomSearch(int target)
{
	PicNode* searchPtr = rootPtr;

	headPtr = nullptr;

	if (rootPtr != nullptr)
	{
		partialNomSearch(target, searchPtr);
	}
}
void PicTree::partialNomSearch(int target, PicNode* searchPtr)
{
	PicNode* targetPtr = new PicNode;
	targetPtr->setNom(target);

	int targetInt, searchInt;
	string targetString, searchString;

	targetInt = targetPtr->getNom();

	targetString = to_string(targetInt);

	if (searchPtr != nullptr) {

		searchInt = searchPtr->getNom();
		searchString = to_string(searchInt);;
		for (int i = 0; i < searchString.length(); i++)
		{
			searchString[i] = tolower(searchString[i]);

		}
		//check if target substring is contained in the PicNode
		if (searchString.find(targetString) != -1)
		{
			//add PicNode to the list of search results
			addToList(searchPtr);

		}

		//search left subtree
		if (searchPtr->getLeftSubTree() != nullptr)
		{
			partialNomSearch(target, searchPtr->getLeftSubTree());
		}

		//search right subtree
		if (searchPtr->getRightSubTree() != nullptr)
		{
			partialNomSearch(target, searchPtr->getRightSubTree());
		}
	}
}

void PicTree::partialRatingSearch(double target)
{
	PicNode* searchPtr = rootPtr;

	headPtr = nullptr;

	if (rootPtr != nullptr)
	{
		partialRatingSearch(target, searchPtr);
	}
}
void PicTree::partialRatingSearch(double target, PicNode* searchPtr)
{
	PicNode* targetPtr = new PicNode;
	targetPtr->setRating(target);

	double targetDouble, searchDouble;
	string targetString, searchString;

	targetDouble = targetPtr->getRating();

	targetString = to_string(targetDouble);

	if (searchPtr != nullptr) {

		searchDouble = searchPtr->getRating();
		searchString = to_string(searchDouble);;
		for (int i = 0; i < searchString.length(); i++)
		{
			searchString[i] = tolower(searchString[i]);

		}
		//check if target substring is contained in the PicNode
		if (searchString.find(targetString) != -1)
		{
			//add PicNode to the list of search results
			addToList(searchPtr);

		}

		//search left subtree
		if (searchPtr->getLeftSubTree() != nullptr)
		{
			partialRatingSearch(target, searchPtr->getLeftSubTree());
		}

		//search right subtree
		if (searchPtr->getRightSubTree() != nullptr)
		{
			partialRatingSearch(target, searchPtr->getRightSubTree());
		}
	}
}

void PicTree::partialDurSearch(int target)
{
	PicNode* searchPtr = rootPtr;

	headPtr = nullptr;

	if (rootPtr != nullptr)
	{
		partialDurSearch(target, searchPtr);
	}
}
void PicTree::partialDurSearch(int target, PicNode* searchPtr)
{
	PicNode* targetPtr = new PicNode;
	targetPtr->setDur(target);

	int targetInt, searchInt;
	string targetString, searchString;

	targetInt = targetPtr->getDur();

	targetString = to_string(targetInt);

	if (searchPtr != nullptr) 
	{

		searchInt = searchPtr->getDur();
		searchString = to_string(searchInt);;
		for (int i = 0; i < searchString.length(); i++)
		{
			searchString[i] = tolower(searchString[i]);

		}
		//check if target substring is contained in the PicNode
		if (searchString.find(targetString) != -1)
		{
			//add PicNode to the list of search results
			addToList(searchPtr);

		}

		//search left subtree
		if (searchPtr->getLeftSubTree() != nullptr)
		{
			partialDurSearch(target, searchPtr->getLeftSubTree());
		}

		//search right subtree
		if (searchPtr->getRightSubTree() != nullptr)
		{
			partialDurSearch(target, searchPtr->getRightSubTree());
		}
	}
}

void PicTree::partialG1Search (string target)
{
	PicNode* searchPtr = rootPtr;

	headPtr = nullptr;

	if (rootPtr != nullptr)
	{
		partialG1Search(target, searchPtr);
	}
}
void PicTree::partialG1Search(string target, PicNode* searchPtr)
{
	PicNode* targetPtr = new PicNode;
	targetPtr->setG1(target);

	string targetString, searchString;

	targetString = targetPtr->getG1();
	searchString = searchPtr->getG1();

	for (int i = 0; i < targetString.length(); i++)
	{
		targetString[i] = tolower(targetString[i]);
	}

	if (searchPtr != nullptr) {

		searchString = searchPtr->getG1();
		for (int i = 0; i < searchString.length(); i++)
		{
			searchString[i] = tolower(searchString[i]);

		}
		//check if target substring is contained in the PicNode
		if (searchString.find(targetString) != -1)
		{
			//add PicNode to the list of search results
			addToList(searchPtr);

		}

		//search left subtree
		if (searchPtr->getLeftSubTree() != nullptr)
		{
			partialG1Search(target, searchPtr->getLeftSubTree());
		}

		//search right subtree
		if (searchPtr->getRightSubTree() != nullptr)
		{
			partialG1Search(target, searchPtr->getRightSubTree());
		}
	}
}

void PicTree::partialG2Search(string target)
{
	PicNode* searchPtr = rootPtr;

	headPtr = nullptr;

	if (rootPtr != nullptr)
	{
		partialG2Search(target, searchPtr);
	}
}
void PicTree::partialG2Search(string target, PicNode* searchPtr)
{
	PicNode* targetPtr = new PicNode;
	targetPtr->setG2(target);

	string targetString, searchString;

	targetString = targetPtr->getG2();
	searchString = searchPtr->getG2();

	for (int i = 0; i < targetString.length(); i++)
	{
		targetString[i] = tolower(targetString[i]);
	}

	if (searchPtr != nullptr) {

		searchString = searchPtr->getG2();
		for (int i = 0; i < searchString.length(); i++)
		{
			searchString[i] = tolower(searchString[i]);

		}
		//check if target substring is contained in the PicNode
		if (searchString.find(targetString) != -1)
		{
			//add PicNode to the list of search results
			addToList(searchPtr);

		}

		//search left subtree
		if (searchPtr->getLeftSubTree() != nullptr)
		{
			partialG2Search(target, searchPtr->getLeftSubTree());
		}

		//search right subtree
		if (searchPtr->getRightSubTree() != nullptr)
		{
			partialG2Search(target, searchPtr->getRightSubTree());
		}
	}
}

void PicTree::partialRelSearch(string target)
{
	PicNode* searchPtr = rootPtr;

	headPtr = nullptr;

	if (rootPtr != nullptr)
	{
		partialRelSearch(target, searchPtr);
	}
}
void PicTree::partialRelSearch(string target, PicNode* searchPtr)
{
	PicNode* targetPtr = new PicNode;
	targetPtr->setRel(target);

	string targetString, searchString;

	targetString = targetPtr->getRel();
	searchString = searchPtr->getRel();

	for (int i = 0; i < targetString.length(); i++)
	{
		targetString[i] = tolower(targetString[i]);
	}

	if (searchPtr != nullptr) {

		searchString = searchPtr->getRel();
		for (int i = 0; i < searchString.length(); i++)
		{
			searchString[i] = tolower(searchString[i]);

		}
		//check if target substring is contained in the PicNode
		if (searchString.find(targetString) != -1)
		{
			//add PicNode to the list of search results
			addToList(searchPtr);

		}

		//search left subtree
		if (searchPtr->getLeftSubTree() != nullptr)
		{
			partialRelSearch(target, searchPtr->getLeftSubTree());
		}

		//search right subtree
		if (searchPtr->getRightSubTree() != nullptr)
		{
			partialRelSearch(target, searchPtr->getRightSubTree());
		}
	}
}

void PicTree::partialMetaSearch(int target)
{
	PicNode* searchPtr = rootPtr;

	headPtr = nullptr;

	if (rootPtr != nullptr)
	{
		partialMetaSearch(target, searchPtr);
	}
}
void PicTree::partialMetaSearch(int target, PicNode* searchPtr)
{
	PicNode* targetPtr = new PicNode;
	targetPtr->setMeta(target);

	int targetInt, searchInt;
	string targetString, searchString;

	targetInt = targetPtr->getMeta();

	targetString = to_string(targetInt);

	if (searchPtr != nullptr)
	{

		searchInt = searchPtr->getMeta();
		searchString = to_string(searchInt);;
		for (int i = 0; i < searchString.length(); i++)
		{
			searchString[i] = tolower(searchString[i]);

		}
		//check if target substring is contained in the PicNode
		if (searchString.find(targetString) != -1)
		{
			//add PicNode to the list of search results
			addToList(searchPtr);

		}

		//search left subtree
		if (searchPtr->getLeftSubTree() != nullptr)
		{
			partialMetaSearch(target, searchPtr->getLeftSubTree());
		}

		//search right subtree
		if (searchPtr->getRightSubTree() != nullptr)
		{
			partialMetaSearch(target, searchPtr->getRightSubTree());
		}
	}
}

void PicTree::partialSynSearch(string target)
{
	PicNode* searchPtr = rootPtr;

	headPtr = nullptr;

	if (rootPtr != nullptr)
	{
		partialSynSearch(target, searchPtr);
	}
}
void PicTree::partialSynSearch(string target, PicNode* searchPtr)
{
	PicNode* targetPtr = new PicNode;
	targetPtr->setSyn(target);

	string targetString, searchString;

	targetString = targetPtr->getSyn();
	searchString = searchPtr->getSyn();

	for (int i = 0; i < targetString.length(); i++)
	{
		targetString[i] = tolower(targetString[i]);
	}

	if (searchPtr != nullptr) {

		searchString = searchPtr->getSyn();
		for (int i = 0; i < searchString.length(); i++)
		{
			searchString[i] = tolower(searchString[i]);

		}
		//check if target substring is contained in the PicNode
		if (searchString.find(targetString) != -1)
		{
			//add PicNode to the list of search results
			addToList(searchPtr);

		}

		//search left subtree
		if (searchPtr->getLeftSubTree() != nullptr)
		{
			partialSynSearch(target, searchPtr->getLeftSubTree());
		}

		//search right subtree
		if (searchPtr->getRightSubTree() != nullptr)
		{
			partialSynSearch(target, searchPtr->getRightSubTree());
		}
	}
}

int PicTree::displaySearchResults()
{
	PicSearchResultNode* currSearchPtr;

	currSearchPtr = headPtr;

	int num = 1;

	if(currSearchPtr != nullptr)
	{
		while (currSearchPtr->getNext() != nullptr)
		{
			cout << num << ". ";
			currSearchPtr->getItem()->printToScreen();
			currSearchPtr = currSearchPtr->getNext();
			num++;
		}

		cout << num << ". ";
		currSearchPtr->getItem()->printToScreen();
	}

	else
	{
		cout << "Search not found." << endl;
		num = 0;
	}

	return num;
}



void PicTree::sortTree()
{
	stack<PicNode*>* nodeStack = new stack<PicNode*>;

	pushTreeToStack(nodeStack);

	rootPtr = nullptr;

	popTreeFromStack(nodeStack);
}

void PicTree::sortByName()
{
	setSortFalse();
	sortName = true;

	sortTree();
}
void PicTree::sortByYear()
{
	setSortFalse();
	sortYear = true;

	sortTree();
}
void PicTree::sortByNom()
{
	setSortFalse();
	sortNom = true;

	sortTree();
}
void PicTree::sortByRating()
{
	setSortFalse();
	sortRating = true;

	sortTree();
}
void PicTree::sortByDur()
{
	setSortFalse();
	sortDur = true;

	sortTree();
}
void PicTree::sortByG1()
{
	setSortFalse();
	sortG1 = true;

	sortTree();
}
void PicTree::sortByG2()
{
	setSortFalse();
	sortG2 = true;

	sortTree();
}
void PicTree::sortByRel()
{
	setSortFalse();
	sortRel = true;

	sortTree();
}
void PicTree::sortByMeta()
{
	setSortFalse();
	sortMeta = true;

	sortTree();
}

//returns true if choice corresponds to a valid record
bool PicTree::removeRecordSearch(int choice)
{
	PicSearchResultNode* currSearchPtr;

	currSearchPtr = headPtr;

	int num = 1;

	if (currSearchPtr != nullptr)
	{
		if (num == choice)
		{
			removeRecord(currSearchPtr->getItem());
			return true;
		}

		while (currSearchPtr->getNext() != nullptr)
		{
			currSearchPtr = currSearchPtr->getNext();
			if (num == choice)
			{
				removeRecord(currSearchPtr->getItem());
				return true;
			}
		}
	}

	else
	{
		return false;
	}
}
void PicTree::removeRecord(PicNode* removePtr)
{
	PicNode* parentPtr;
	PicNode* tempPtr;

	parentPtr = rootPtr;

	bool parentFound = false;

	//if record to remove has no subtrees
	if (removePtr->getLeftSubTree() == nullptr && removePtr->getRightSubTree() == nullptr)
	{
		//find parent of record to remove
		while (!parentFound)
		{
			//This case occurs if the record to delete is the root ptr
			if (removePtr == rootPtr)
			{
				parentFound = true;
			}

			else if (parentPtr->getLeftSubTree() == removePtr)
			{
				parentPtr->setLeftSubTree(nullptr);
				parentFound = true;
			}

			else if (parentPtr->getRightSubTree() == removePtr)
			{
				parentPtr->setRightSubTree(nullptr);
				parentFound = true;
			}

			else if (removePtr->getName() == parentPtr->getName())
			{
				parentPtr = parentPtr->getRightSubTree();
			}

			else if (removePtr->getName() < parentPtr->getName())
			{
				parentPtr = parentPtr->getLeftSubTree();
			}

			else if (removePtr->getName() > parentPtr->getName())
			{
				parentPtr = parentPtr->getRightSubTree();
			}
		}

		delete removePtr;
	}

	//if record to remove has a left sub tree but no right sub tree 
	else if (removePtr->getLeftSubTree() != nullptr && removePtr->getRightSubTree() == nullptr)
	{
		while (!parentFound)
		{
			if (parentPtr == removePtr)
			{
				rootPtr = removePtr->getLeftSubTree();
				parentFound = true;
			}

			else if (parentPtr->getLeftSubTree() == removePtr)
			{
				parentPtr->setLeftSubTree(removePtr->getLeftSubTree());
				parentFound = true;
			}

			else if (parentPtr->getRightSubTree() == removePtr)
			{
				parentPtr->setRightSubTree(removePtr->getLeftSubTree());
				parentFound = true;
			}

			else if (removePtr->getName() == parentPtr->getName())
			{
				parentPtr = parentPtr->getRightSubTree();
			}
			else if (removePtr->getName() < parentPtr->getName())
			{
				parentPtr = parentPtr->getLeftSubTree();
			}

			else if (removePtr->getName() > parentPtr->getName())
			{
				parentPtr = parentPtr->getRightSubTree();
			}
		}

		delete removePtr;
	}

	//if record to remove has a right sub tree but no left sub tree 
	else if (removePtr->getRightSubTree() != nullptr && removePtr->getLeftSubTree() == nullptr)
	{
		while (!parentFound)
		{
			if (parentPtr == removePtr)
			{
				rootPtr = removePtr->getRightSubTree();
				parentFound = true;
			}

			else if (parentPtr->getLeftSubTree() == removePtr)
			{
				parentPtr->setLeftSubTree(removePtr->getRightSubTree());
				parentFound = true;
			}

			else if (parentPtr->getRightSubTree() == removePtr)
			{
				parentPtr->setRightSubTree(removePtr->getRightSubTree());
				parentFound = true;
			}

			else if (removePtr->getName() == parentPtr->getName())
			{
				parentPtr = parentPtr->getRightSubTree();
			}

			else if (removePtr->getName() < parentPtr->getName())
			{
				parentPtr = parentPtr->getLeftSubTree();
			}

			else if (removePtr->getName() > parentPtr->getName())
			{
				parentPtr = parentPtr->getRightSubTree();
			}
		}

		delete removePtr;
	}

	//if record to remove has both subtrees full
	else if (removePtr->getLeftSubTree() != nullptr && removePtr->getRightSubTree() != nullptr)
	{
		//get next smallest node (that is, the furthermost left node on the right subtree of removePtr)
		tempPtr = removePtr->getRightSubTree();

		while (tempPtr->getLeftSubTree() != nullptr)
		{
			tempPtr = tempPtr->getLeftSubTree();
		}

		removePtr->setName(tempPtr->getName());
		removePtr->setYear(tempPtr->getYear());
		removePtr->setNom(tempPtr->getNom());
		removePtr->setRating(tempPtr->getRating());
		removePtr->setDur(tempPtr->getDur());
		removePtr->setG1(tempPtr->getG1());
		removePtr->setG2(tempPtr->getG2());
		removePtr->setRel(tempPtr->getRel());
		removePtr->setMeta(tempPtr->getMeta());
		removePtr->setSyn(tempPtr->getSyn());

		removeRecord(tempPtr);
	}
}

bool PicTree::modifyRecordSearch(int recordChoice)
{
	PicSearchResultNode* modifyPtr;

	modifyPtr = headPtr;
	int fieldChoice = 0;

	int num = 1;

	//find search result to modify
	if (modifyPtr != nullptr)
	{
		if (num == recordChoice)
		{
			modifyRecordMenu(modifyPtr->getItem());
			return true;
		}

		while (modifyPtr->getNext() != nullptr)
		{
			modifyPtr = modifyPtr->getNext();
			if (num == recordChoice)
			{
				removeRecord(modifyPtr->getItem());
				return true;
			}
		}
	}
}

bool PicTree::modifyRecordMenu(PicNode* modifyPtr)
{
	int fieldChoice;
	try
	{
		cout << "Choose a field to modify: " << endl;
		cout << "1. Name" << endl;
		cout << "2. Year" << endl;
		cout << "3. Nominations" << endl;
		cout << "4. Rating" << endl;
		cout << "5. Duration" << endl;
		cout << "6. Genre 1" << endl;
		cout << "7. Genre 2" << endl;
		cout << "8. Release" << endl;
		cout << "9. Metacritic" << endl;
		cout << "10. Synopsis" << endl;
		cout << "11. Back" << endl;
		cout << "12. Exit program" << endl;
		cout << "Enter your choice (1 - 12): " << endl;

		cin >> fieldChoice;
		cout << endl;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			throw 1;
		}
	}
	catch (int error)
	{
		cout << "Make sure to enter an integer." << endl << endl;

		return modifyRecordMenu(modifyPtr);
	}

	bool done = false;
	int tempInt;
	double rating;
	string temp;

	while (!done)
	{
		switch (fieldChoice)
		{
		case 1:
			cout << "Enter a new film name" << endl;

			cin.ignore();
			getline(cin, temp);
			cout << endl;

			modifyPtr->setName(temp);

			done = true;

			break;
		case 2:
			try
			{
				cout << "Enter a new year" << endl;
				cin >> tempInt;
				cout << endl;


				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					throw 1;
				}

				modifyPtr->setYear(tempInt);

				done = true;
			}

			catch (int error)
			{
				cout << "Make sure to enter an integer." << endl << endl;

				return modifyRecordMenu(modifyPtr);
			}

			done = true;

			break;

		case 3:
			try
			{
				cout << "Enter a new number of nominations" << endl;
				cin >> tempInt;
				cout << endl;


				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					throw 1;
				}

				modifyPtr->setNom(tempInt);

				done = true;
			}

			catch (int error)
			{
				cout << "Make sure to enter an integer." << endl << endl;

				return modifyRecordMenu(modifyPtr);
			}

			done = true;

			break;

		case 4:
			try
			{
				cout << "Enter a new rating (i.e. '8.1'): " << endl;
				cin >> rating;
				cout << endl;


				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					throw 1;
				}

				modifyPtr->setRating(rating);

				done = true;
			}

			catch (int error)
			{
				cout << "Make sure to enter a floating point number (i.e. '8.1')." << endl << endl;

				return modifyRecordMenu(modifyPtr);
			}

			done = true;

			break;

		case 5:
			try
			{
				cout << "Enter a new duration of film (i.e. '120'): " << endl;
				cin >> tempInt;
				cout << endl;


				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					throw 1;
				}

				modifyPtr->setDur(tempInt);

				done = true;
			}

			catch (int error)
			{
				cout << "Make sure to enter an integer." << endl << endl;

				return modifyRecordMenu(modifyPtr);
			}

			done = true;

			break;
		case 6:
			cout << "Enter a new genre name for genre 1: " << endl;

			cin.ignore();
			getline(cin, temp);
			cout << endl;

			modifyPtr->setG1(temp);

			done = true;

			break;

		case 7:
			cout << "Enter a new genre name for genre 2: " << endl;

			cin.ignore();
			getline(cin, temp);
			cout << endl;

			modifyPtr->setG2(temp);

			done = true;

			break;
		case 8:
			cout << "Enter a new release month: " << endl;

			cin.ignore();
			getline(cin, temp);
			cout << endl;

			modifyPtr->setRel(temp);

			done = true;

			break;
		case 9:
			try
			{
				cout << "Enter a new metacritic score of film (i.e. '68'): " << endl;
				cin >> tempInt;
				cout << endl;


				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					throw 1;
				}

				modifyPtr->setMeta(tempInt);

				done = true;
			}

			catch (int error)
			{
				cout << "Make sure to enter an integer." << endl << endl;

				return modifyRecordMenu(modifyPtr);
			}

			done = true;

			break;
		case 10:
			cout << "Enter a new synopsis: " << endl;

			cin.ignore();
			getline(cin, temp);
			cout << endl;

			modifyPtr->setSyn(temp);

			done = true;

			break;
		case 11:
			done = true;
			break;
		case 12:
			return 1;
		default:
			cout << fieldChoice << " is not a valid option. Try again" << endl << endl;
		}
	}

	return 0;
}

void PicTree::popTreeFromStack(stack<PicNode*>* nodeStack)
{
	PicNode* currPtr;
	while (!nodeStack->empty())
	{
		currPtr = nodeStack->top();
		currPtr->setLeftSubTree(nullptr);
		currPtr->setRightSubTree(nullptr);

		nodeStack->pop();

		addToTree(currPtr);
	}
}

void PicTree::pushTreeToStack(stack<PicNode*>* nodeStack)
{
	PicTree* tempTree;
	PicNode* currPtr = rootPtr;

	//make sure tree is non empty
	if (rootPtr == nullptr)
	{
	}

	else
	{
		//recursively call pushTreeToStack for each leftSubTree
		//in order
		if (currPtr->getLeftSubTree() != nullptr)
		{
			tempTree = new PicTree();
			tempTree->addToTree(currPtr->getLeftSubTree());
			tempTree->pushTreeToStack(nodeStack);
		}

		//base case, reached when null leftSubTree is reached
		nodeStack->push(currPtr);

		//recursively call displayTree for each righSubTree until one is null
		if (currPtr->getRightSubTree() != nullptr)
		{
			tempTree = new PicTree();
			tempTree->addToTree(currPtr->getRightSubTree());
			tempTree->pushTreeToStack(nodeStack);
		}
	}
}

void PicTree::pushTreeToQueue(queue<PicNode*>* nodeQueue)
{
	PicTree* tempTree;
	PicNode* currPtr = rootPtr;

	//make sure tree is non empty
	if (rootPtr == nullptr)
	{
	}

	else
	{
		//recursively call pushTreeToQueue for each leftSubTree
		//in order
		if (currPtr->getLeftSubTree() != nullptr)
		{
			tempTree = new PicTree();
			tempTree->addToTree(currPtr->getLeftSubTree());
			tempTree->pushTreeToQueue(nodeQueue);
		}

		//base case, reached when null leftSubTree is reached
		nodeQueue->push(currPtr);

		//recursively call displayTree for each righSubTree until one is null
		if (currPtr->getRightSubTree() != nullptr)
		{
			tempTree = new PicTree();
			tempTree->addToTree(currPtr->getRightSubTree());
			tempTree->pushTreeToQueue(nodeQueue);
		}
	}
}

void PicTree::clearTree()
{
	stack<PicNode*>* nodeStack = new stack<PicNode*>;
	pushTreeToStack(nodeStack);

	PicNode* currPtr;

	rootPtr = nullptr;

	while (!nodeStack->empty())
	{
		currPtr = nodeStack->top();
		nodeStack->pop();

		delete currPtr;
	}
}