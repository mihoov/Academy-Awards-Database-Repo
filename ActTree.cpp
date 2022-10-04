//
// Created by hoove on 11/5/2019.
//

#include "ActTree.h"

//default constructor for ActTree
ActTree::ActTree() : rootPtr(nullptr), treeSize(0), headPtr(nullptr), listSize(0){}

//--------deleteTree--------
// pre-condition: accepts an int to determine which tree to delete
// 1: deletes year tree
// 2: deletes award tree
// 3: deletes winner tree
// 4: deletes main tree, sorted by name
// 5: deletes film tree
void ActTree::deleteTree(int deleteChoice) {

    stack<ActNode*> deleteStack;
    ActNode *currPtr = nullptr;

    switch(deleteChoice){
        case 1: {
            currPtr = rootYearPtr;
            rootYearPtr = nullptr;
            break;
        }
        case 2: {
            currPtr = rootAwardPtr;
            rootAwardPtr = nullptr;
            break;
        }
        case 3: {
            currPtr = rootWinnerPtr;
            rootWinnerPtr = nullptr;
            break;
        }
        case 4: {
            currPtr = rootPtr;
            rootPtr = nullptr;
            break;
        }
        case 5: {
            currPtr = rootFilmPtr;
            rootFilmPtr = nullptr;
            break;
        }
    }// end scope of switch

    // if there is a tree in the root
    if (currPtr != nullptr){

        //push root on to stack
        deleteStack.push(currPtr);

        //while loop to delete all elements of the tree
        while(!deleteStack.empty()){

            //set top of stack to currPtr and pop stack
            currPtr = deleteStack.top();
            deleteStack.pop();

            //if left subtree is not empty then push it on stack
            if (currPtr->getLeftSubTree() != nullptr){
                deleteStack.push(currPtr->getLeftSubTree());
            }

            //if right subtree is not empty then push it on stack
            if(currPtr->getRightSubTree() != nullptr) {
                deleteStack.push(currPtr->getRightSubTree());
            }

            //delete the current node
            delete currPtr;

        }//end while loop
    }
}

//--------printTreeInOrder---------
void ActTree::printTreeInOrder(int choice) {

    stack<ActNode*> printStack;
    ActNode *currPtr;

    switch(choice){
        case 1:
            currPtr = rootYearPtr;
            break;

        case 2:
            currPtr = rootAwardPtr;
            break;

        case 3:
            currPtr = rootWinnerPtr;
            break;

        case 4:
            currPtr = rootPtr;
            break;

        case 5:
            currPtr = rootFilmPtr;
            break;

        default:
            currPtr = nullptr;
    }


    //while loop executes as long as stack is not empty
    while((!printStack.empty()) || (currPtr != nullptr))
    {
        if(currPtr != nullptr)// executes when the current node is an element of the tree
        {
            printStack.push(currPtr); // push currPtr onto stack
            currPtr = currPtr->getLeftSubTree(); //set currPtr to left subtree
        }
        else //executes when search has reached the end of a leaf of the tree
        {
            currPtr = printStack.top(); //set currPtr to top of stack
            printStack.pop();

            currPtr->printToScreen();
            currPtr = currPtr->getRightSubTree();
        }
    }//end while loop

}

//--------getListSize--------
int ActTree::getListSize() {
    return listSize;
}

//--------compYear--------
//function does a complete search for field: year
void ActTree::compYear(int target) {


    deleteList();// empties search list

    stack<ActNode*> searchStack;
    ActNode* currPtr;

    searchStack.push(rootPtr);
    currPtr = rootPtr->getLeftSubTree();

    //while loop executes as long as stack is not empty
    while((!searchStack.empty()) || (currPtr != nullptr))
    {
        if(currPtr != nullptr)//if statement executes when the current node is an element of the tree
        {
            searchStack.push(currPtr); // push currPtr onto stack
            currPtr = currPtr->getLeftSubTree(); //set currPtr to left subtree
        }
        else //executes when search has reached the end of a leaf of the tree
        {
            currPtr = searchStack.top(); //set currPtr to top of stack

            if (currPtr->getYear() == target){
                //if target year matches currPtr year, add currPtr to list of search results
                addToList(currPtr);
            }

            searchStack.pop();
            currPtr = currPtr->getRightSubTree();
        }


    }//end while loop

    printList();
}

//--------compAward--------
//function executes a complete search for field: award
void ActTree::compAward(string target) {

    deleteList();// empties search list

    stack<ActNode*> searchStack;
    ActNode* currPtr;
    string currAward;

    //set target to lowercase
    for (int i = 0; i < target.length(); i++){
        target[i] = tolower(target[i]);
    }

    searchStack.push(rootPtr);
    currPtr = rootPtr->getLeftSubTree();

    //while loop executes as long as stack is not empty
    while((!searchStack.empty()) || (currPtr != nullptr))
    {
        if(currPtr != nullptr)//if statement executes when the current node is an element of the tree
        {
            searchStack.push(currPtr); // push currPtr onto stack
            currPtr = currPtr->getLeftSubTree(); //set currPtr to left subtree
        }
        else //executes when search has reached the end of a leaf of the tree
        {
            currPtr = searchStack.top(); //set currPtr to top of stack

            currAward = currPtr->getAward();
            for (int i = 0; i < currAward.length(); i++){
                currAward[i] = tolower(currAward[i]);
            }

            if(currAward == target){
                //if target is found add currPtr to list of search results
                addToList(currPtr);
            }

            searchStack.pop();
            currPtr = currPtr->getRightSubTree();
        }
    }//end while loop
    printList();
}


//--------compName--------
//function executes a complete search for field: name
void ActTree::compName(string target){
    ActNode* targetPtr = new ActNode;
    targetPtr->setName(target);
    ActNode* currPtr = searchTree(targetPtr);

    if (currPtr->getName() == targetPtr->getName()){
        targetPtr = currPtr;
        targetPtr->printToScreen();
    }
}

//--------compFilm--------
//function executes a complete search for field: film
void ActTree::compFilm(string target) {

    deleteList();

    stack<ActNode*> searchStack;
    ActNode* currPtr;
    string currFilm;

    //set target to lowercase
    for (int i = 0; i < target.length(); i++){
        target[i] = tolower(target[i]);
    }

    searchStack.push(rootPtr);
    currPtr = rootPtr->getLeftSubTree();

    //while loop executes as long as stack is not empty
    while((!searchStack.empty()) || (currPtr != nullptr))
    {
        if(currPtr != nullptr)//if statement executes when the current node is an element of the tree
        {
            searchStack.push(currPtr); // push currPtr onto stack
            currPtr = currPtr->getLeftSubTree(); //set currPtr to left subtree
        }
        else //executes when search has reached the end of a leaf of the tree
        {
            currPtr = searchStack.top(); //set currPtr to top of stack

            currFilm = currPtr->getFilm();
            for (int i = 0; i < currFilm.length(); i++){
                currFilm[i] = tolower(currFilm[i]);
            }

            if(currFilm == target){
                //if target is found add currPtr to list of search results
                addToList(currPtr);
            }

            searchStack.pop();
            currPtr = currPtr->getRightSubTree();
        }
    }//end while loop
    printList();

}



//--------searchTree--------
ActNode* ActTree::searchTree(ActNode * targetPtr){

    ActNode* searchPtr = rootPtr;

    bool found = false;

    //begin while loop t continue until value is found or search reaches a nullptr
    while( found != true){

        //checking if target is found at current node
        if (targetPtr->getName() == searchPtr->getName()){
            found = true;
        }

            //if target is less than current node go to left subtree
        else if (targetPtr->getName() < searchPtr->getName()){
            if(searchPtr->getLeftSubTree() != nullptr) {
                searchPtr = searchPtr->getLeftSubTree();
            }
                //if left subtree is empty end search
            else if (searchPtr->getLeftSubTree() == nullptr){
                found = true;
            }
        }
            //if target is greater than current node go to right subtree
        else if (targetPtr->getName() > searchPtr->getName()){
            if (searchPtr->getRightSubTree() != nullptr) {

                searchPtr = searchPtr->getRightSubTree();
            }
                //if right subtree is empty end search
            else if (searchPtr->getRightSubTree() == nullptr){
                found = true;
            }
        }
    }
    return searchPtr;

}





/*
//--------callPartialSearch--------
void ActTree::callPartialSearch(string target) {
    ActNode* targetPtr = new ActNode;
    targetPtr->setName(target);

    //execute partial search which builds linked list of results
    //partialSearch(rootPtr, targetPtr);


    //output list of search results to screen
    SearchResultNode* currPtr = headPtr;
    int count = 1;
    int modNum;

    while (currPtr != nullptr){
        cout<< setfill(' ') << setw(3) << count << ".";
        currPtr->getItem()->printToScreen();
        currPtr = currPtr->getNext();
        count ++;
    }
}
 */

//--------partYear--------
void ActTree::partYear(int partialYear) {

    deleteList();


    stack<ActNode*> searchStack;
    ActNode *currPtr;
    string currYear;
    string target = to_string(partialYear);

    searchStack.push(rootPtr);
    currPtr = rootPtr->getLeftSubTree();

    //while loop executes as long as stack is not empty
    while((!searchStack.empty()) || (currPtr != nullptr))
    {
        if(currPtr != nullptr)//if statement executes when the current node is an element of the tree
        {
            searchStack.push(currPtr); // push currPtr onto stack
            currPtr = currPtr->getLeftSubTree(); //set currPtr to left subtree
        }
        else //executes when search has reached the end of a leaf of the tree
        {
            currPtr = searchStack.top(); //set currPtr to top of stack

            currYear = to_string(currPtr->getYear());

            if(currYear.find(target) != -1){
                //if substring is found in currPtr year, add currPtr to list of search results
                addToList(currPtr);
            }

            searchStack.pop();
            currPtr = currPtr->getRightSubTree();
        }
    }//end while loop

    if (listSize > 0) {
        printList();
    }
    else{
        cout << "No records found matching search criteria." << endl << endl;
    }

}


//--------partAward--------
void ActTree::partAward(string target) {

    deleteList();// empties search list

    stack<ActNode*> searchStack;
    ActNode* currPtr;
    string currAward;

    //set target to lowercase
    for (int i = 0; i < target.length(); i++){
        target[i] = tolower(target[i]);
    }

    searchStack.push(rootPtr);
    currPtr = rootPtr->getLeftSubTree();

    //while loop executes as long as stack is not empty
    while((!searchStack.empty()) || (currPtr != nullptr))
    {
        if(currPtr != nullptr)//if statement executes when the current node is an element of the tree
        {
            searchStack.push(currPtr); // push currPtr onto stack
            currPtr = currPtr->getLeftSubTree(); //set currPtr to left subtree
        }
        else //executes when search has reached the end of a leaf of the tree
        {
            currPtr = searchStack.top(); //set currPtr to top of stack

            currAward = currPtr->getAward();
            for (int i = 0; i < currAward.length(); i++){
                currAward[i] = tolower(currAward[i]);
            }

            if(currAward.find(target) != -1){
                //if substring is found in currPtr award, add currPtr to list of search results
                addToList(currPtr);
            }

            searchStack.pop();
            currPtr = currPtr->getRightSubTree();
        }
    }//end while loop

    if (listSize > 0) {
        printList();
    }
    else{
        cout << "No records found matching search criteria." << endl << endl;
    }
}


//--------partName--------
void ActTree::partName(string targetString){

    deleteList();// empties search list

    stack<ActNode*> searchStack;
    ActNode* currPtr;
    string currName;

    //set target to lowercase
    for (int i = 0; i < targetString.length(); i++){
        targetString[i] = tolower(targetString[i]);
    }

    searchStack.push(rootPtr);
    currPtr = rootPtr->getLeftSubTree();

    //while loop executes as long as stack is not empty
    while((!searchStack.empty()) || (currPtr != nullptr))
    {
        if(currPtr != nullptr)//if statement executes when the current node is an element of the tree
        {
            searchStack.push(currPtr); // push currPtr onto stack
            currPtr = currPtr->getLeftSubTree(); //set currPtr to left subtree
        }
        else //executes when search has reached the end of a leaf of the tree
        {
            currPtr = searchStack.top(); //set currPtr to top of stack

            currName = currPtr->getName();
            for (int i = 0; i < currName.length(); i++){
                currName[i] = tolower(currName[i]);
            }

            if(currName.find(targetString) != -1){
                //if substring is found in currPtr name, add currPtr to list of search results
                addToList(currPtr);
            }

            searchStack.pop();
            currPtr = currPtr->getRightSubTree();
        }


    }//end while loop

    if (listSize > 0) {
        printList();
    }
    else{
        cout << "No records found matching search criteria." << endl << endl;
    }


    //the code below is for a recursive search of the tree
    /*
     * string targetString, searchString;

    targetString = targetPtr->getName();
    for (int i = 0; i < targetString.length(); i++){
        targetString[i] = tolower(targetString[i]);
    }

    if (startPtr != nullptr){

        searchString = startPtr->getName();
        for (int i = 0; i < searchString.length(); i++){
            searchString[i] = tolower(searchString[i]);

        }
        //check if target substring is contained in the ActNode
        if(searchString.find(targetString) != -1){
            //add ActNode to the list of search results
            addToList(startPtr);

            }

        //search left subtree
        partialSearch(startPtr->getLeftSubTree(), targetPtr);
        //search right subtree
        partialSearch(startPtr->getRightSubTree(), targetPtr);
    }
    // if startPtr is nullPtr function does nothing
     */
}

//--------partFilm--------
void ActTree::partFilm(string target) {

    deleteList();// empties search list

    stack<ActNode*> searchStack;
    ActNode* currPtr;
    string currFilm;

    //set target to lowercase
    for (int i = 0; i < target.length(); i++){
        target[i] = tolower(target[i]);
    }

    searchStack.push(rootPtr);
    currPtr = rootPtr->getLeftSubTree();

    //while loop executes as long as stack is not empty
    while((!searchStack.empty()) || (currPtr != nullptr))
    {
        if(currPtr != nullptr)//if statement executes when the current node is an element of the tree
        {
            searchStack.push(currPtr); // push currPtr onto stack
            currPtr = currPtr->getLeftSubTree(); //set currPtr to left subtree
        }
        else //executes when search has reached the end of a leaf of the tree
        {
            currPtr = searchStack.top(); //set currPtr to top of stack

            currFilm = currPtr->getFilm();
            for (int i = 0; i < currFilm.length(); i++){
                currFilm[i] = tolower(currFilm[i]);
            }

            if(currFilm.find(target) != -1){
                //if substring is found in currPtr film, add currPtr to list of search results
                addToList(currPtr);
            }

            searchStack.pop();
            currPtr = currPtr->getRightSubTree();
        }
    }//end while loop
    if (listSize > 0) {
        printList();
    }
    else{
        cout << "No records found matching search criteria." << endl << endl;
    }
}


//--------sortYear--------
void ActTree::sortYear() {
    ActNode* currPtr = nullptr;
    ActNode* searchPtr;
    ActNode* nodeToPlace;
    bool found;
    stack<ActNode*> nodeStack;
    const int BY_YEAR = 1;

    deleteTree(BY_YEAR);

    if (rootPtr != nullptr) {
        //create root for tree sorted by year
        nodeToPlace = new ActNode(rootPtr->getYear(), rootPtr->getAward(), rootPtr->getWinner(), rootPtr->getName(), rootPtr->getFilm());
        rootYearPtr = nodeToPlace;

        if (rootPtr->getRightSubTree() != nullptr) {
            nodeStack.push(rootPtr->getRightSubTree());
        }
        if (rootPtr->getLeftSubTree() != nullptr) {
            nodeStack.push(rootPtr->getLeftSubTree());
        }

        //loop executes as long as stack is not empty
        while (!nodeStack.empty()) {
            found = false;
            searchPtr = rootYearPtr;

            currPtr = nodeStack.top();
            nodeStack.pop();


            //if the left and right subtrees of currPtr contain nodes, push them onto stack
            if (currPtr->getRightSubTree() != nullptr) {
                nodeStack.push(currPtr->getRightSubTree());
            }
            if (currPtr->getLeftSubTree() != nullptr) {
                nodeStack.push(currPtr->getLeftSubTree());
            }

            //loop to find where to place node in tree sorted by year
            while (!found) {

                //if currPtr(the node to be placed) is less than searchPtr
                if (currPtr->getYear() < searchPtr->getYear()) {
                    //if left subtree of searchPtr is empty than place the currPtr node there
                    if (searchPtr->getLeftSubTree() == nullptr) {
                        nodeToPlace = new ActNode(currPtr->getYear(), currPtr->getAward(), currPtr->getWinner(), currPtr->getName(), currPtr->getFilm());
                        searchPtr->setLeftSubTree(nodeToPlace);
                        found = true;
                        nodeToPlace = nullptr;
                        currPtr = nullptr;
                    }
                        //if left subtree of searchPtr contains a node, set searchPtr to the left subtree
                    else {
                        searchPtr = searchPtr->getLeftSubTree();
                    }
                } else {//if currPtr node is greater than or equal to searchPtr
                    //if right subtree of searchPtr is empty than place node there.
                    if(searchPtr->getRightSubTree() == nullptr){
                        nodeToPlace = new ActNode(currPtr->getYear(), currPtr->getAward(), currPtr->getWinner(), currPtr->getName(), currPtr->getFilm());
                        searchPtr->setRightSubTree(nodeToPlace);
                        found = true;
                        nodeToPlace = nullptr;
                        currPtr = nullptr;
                    }
                        //if right subtree of searchPtr contains a node, set searchPtr to the right subtree
                    else {
                        searchPtr = searchPtr->getRightSubTree();
                    }
                }
            }// end while loop that finds placement of node
        }// end while loop that runs until stack is empty
        //print sorted tree to screen in order
        printTreeInOrder(BY_YEAR);
    }// end if statement (rootPtr != nullptr)
    else {
        cout << "There is no data to sort. Please upload a file first." << endl << endl;
    }

}

//--------sortAward--------
void ActTree::sortAward() {
    ActNode* currPtr = nullptr;
    ActNode* searchPtr;
    ActNode* nodeToPlace;
    bool found;
    stack<ActNode*> nodeStack;
    const int BY_AWARD = 2;

    deleteTree(BY_AWARD);

    if (rootPtr != nullptr) {
        //create root for tree sorted by award
        nodeToPlace = new ActNode(rootPtr->getYear(), rootPtr->getAward(), rootPtr->getWinner(), rootPtr->getName(), rootPtr->getFilm());
        rootAwardPtr = nodeToPlace;

        if (rootPtr->getRightSubTree() != nullptr) {
            nodeStack.push(rootPtr->getRightSubTree());
        }
        if (rootPtr->getLeftSubTree() != nullptr) {
            nodeStack.push(rootPtr->getLeftSubTree());
        }

        //loop executes as long as stack is not empty
        while (!nodeStack.empty()) {
            found = false;
            searchPtr = rootAwardPtr;

            currPtr = nodeStack.top();
            nodeStack.pop();


            //if the left and right subtrees of currPtr contain nodes, push them onto stack
            if (currPtr->getRightSubTree() != nullptr) {
                nodeStack.push(currPtr->getRightSubTree());
            }
            if (currPtr->getLeftSubTree() != nullptr) {
                nodeStack.push(currPtr->getLeftSubTree());
            }

            //loop to find where to place node in tree sorted by award
            while (!found) {

                //if currPtr(the node to be placed) is less than searchPtr
                if (currPtr->getAward() < searchPtr->getAward()) {
                    //if left subtree of searchPtr is empty than place the currPtr node there
                    if (searchPtr->getLeftSubTree() == nullptr) {
                        nodeToPlace = new ActNode(currPtr->getYear(), currPtr->getAward(), currPtr->getWinner(), currPtr->getName(), currPtr->getFilm());
                        searchPtr->setLeftSubTree(nodeToPlace);
                        found = true;
                        nodeToPlace = nullptr;
                        currPtr = nullptr;
                    }
                        //if left subtree of searchPtr contains a node, set searchPtr to the left subtree
                    else {
                        searchPtr = searchPtr->getLeftSubTree();
                    }
                } else {//if currPtr node is greater than or equal to searchPtr
                    //if right subtree of searchPtr is empty than place node there.
                    if(searchPtr->getRightSubTree() == nullptr){
                        nodeToPlace = new ActNode(currPtr->getYear(), currPtr->getAward(), currPtr->getWinner(), currPtr->getName(), currPtr->getFilm());
                        searchPtr->setRightSubTree(nodeToPlace);
                        found = true;
                        nodeToPlace = nullptr;
                        currPtr = nullptr;
                    }
                        //if right subtree of searchPtr contains a node, set searchPtr to the right subtree
                    else {
                        searchPtr = searchPtr->getRightSubTree();
                    }
                }
            }// end while loop that finds placement of node
        }// end while loop that runs until stack is empty
        //print sorted tree to screen in order
        printTreeInOrder(BY_AWARD);
    }// end if statement (rootPtr != nullptr)
    else {
        cout << "There is no data to sort. Please upload a file first." << endl << endl;
    }

}//end sortAward function

//--------sortWinner--------
void ActTree::sortWinner() {
    ActNode* currPtr = nullptr;
    ActNode* searchPtr;
    ActNode* nodeToPlace;
    bool found;
    stack<ActNode*> nodeStack;
    const int BY_WINNER = 3;

    deleteTree(BY_WINNER);

    if (rootPtr != nullptr) {
        //create root for tree sorted by winner
        nodeToPlace = new ActNode(rootPtr->getYear(), rootPtr->getAward(), rootPtr->getWinner(), rootPtr->getName(), rootPtr->getFilm());
        rootWinnerPtr = nodeToPlace;

        if (rootPtr->getRightSubTree() != nullptr) {
            nodeStack.push(rootPtr->getRightSubTree());
        }
        if (rootPtr->getLeftSubTree() != nullptr) {
            nodeStack.push(rootPtr->getLeftSubTree());
        }

        //loop executes as long as stack is not empty
        while (!nodeStack.empty()) {
            found = false;
            searchPtr = rootWinnerPtr;

            currPtr = nodeStack.top();
            nodeStack.pop();

            //if the left and right subtrees of currPtr contain nodes, push them onto stack
            if (currPtr->getRightSubTree() != nullptr) {
                nodeStack.push(currPtr->getRightSubTree());
            }
            if (currPtr->getLeftSubTree() != nullptr) {
                nodeStack.push(currPtr->getLeftSubTree());
            }

            //loop to find where to place node in tree sorted by Winner
            while (!found) {

                //if currPtr(the node to be placed) is less than searchPtr
                if (currPtr->getWinner() < searchPtr->getWinner()) {
                    //if left subtree of searchPtr is empty than place the currPtr node there
                    if (searchPtr->getLeftSubTree() == nullptr) {
                        nodeToPlace = new ActNode(currPtr->getYear(), currPtr->getAward(), currPtr->getWinner(), currPtr->getName(), currPtr->getFilm());
                        searchPtr->setLeftSubTree(nodeToPlace);
                        found = true;
                        nodeToPlace = nullptr;
                        currPtr = nullptr;
                    }
                        //if left subtree of searchPtr contains a node, set searchPtr to the left subtree
                    else {
                        searchPtr = searchPtr->getLeftSubTree();
                    }
                } else {//if currPtr node is greater than or equal to searchPtr
                    //if right subtree of searchPtr is empty than place node there.
                    if(searchPtr->getRightSubTree() == nullptr){
                        nodeToPlace = new ActNode(currPtr->getYear(), currPtr->getAward(), currPtr->getWinner(), currPtr->getName(), currPtr->getFilm());
                        searchPtr->setRightSubTree(nodeToPlace);
                        found = true;
                        nodeToPlace = nullptr;
                        currPtr = nullptr;
                    }
                        //if right subtree of searchPtr contains a node, set searchPtr to the right subtree
                    else {
                        searchPtr = searchPtr->getRightSubTree();
                    }
                }
            }// end while loop that finds placement of node
        }// end while loop that runs until stack is empty
        //print sorted tree to screen in order
        printTreeInOrder(BY_WINNER);
    }// end if statement (rootPtr != nullptr)
    else {
        cout << "There is no data to sort. Please upload a file first." << endl << endl;
    }
}//end sortWinner function


//--------sortFilm--------
void ActTree::sortFilm()
{
    ActNode* currPtr = nullptr;
    ActNode* searchPtr;
    ActNode* nodeToPlace;
    bool found;
    stack<ActNode*> nodeStack;
    const int BY_FILM = 5;

    deleteTree(BY_FILM);

    if (rootPtr != nullptr) {
        //create root for tree sorted by Film
        nodeToPlace = new ActNode(rootPtr->getYear(), rootPtr->getAward(), rootPtr->getWinner(), rootPtr->getName(), rootPtr->getFilm());
        rootFilmPtr = nodeToPlace;

        if (rootPtr->getRightSubTree() != nullptr) {
            nodeStack.push(rootPtr->getRightSubTree());
        }
        if (rootPtr->getLeftSubTree() != nullptr) {
            nodeStack.push(rootPtr->getLeftSubTree());
        }

        //loop executes as long as stack is not empty
        while (!nodeStack.empty()) {
            found = false;
            searchPtr = rootFilmPtr;

            currPtr = nodeStack.top();
            nodeStack.pop();


            //if the left and right subtrees of currPtr contain nodes, push them onto stack
            if (currPtr->getRightSubTree() != nullptr) {
                nodeStack.push(currPtr->getRightSubTree());
            }
            if (currPtr->getLeftSubTree() != nullptr) {
                nodeStack.push(currPtr->getLeftSubTree());
            }

            //loop to find where to place node in tree sorted by Film
            while (!found) {

                //if currPtr(the node to be placed) is less than searchPtr
                if (currPtr->getFilm() < searchPtr->getFilm()) {
                    //if left subtree of searchPtr is empty than place the currPtr node there
                    if (searchPtr->getLeftSubTree() == nullptr) {
                        nodeToPlace = new ActNode(currPtr->getYear(), currPtr->getAward(), currPtr->getWinner(), currPtr->getName(), currPtr->getFilm());
                        searchPtr->setLeftSubTree(nodeToPlace);
                        found = true;
                        nodeToPlace = nullptr;
                        currPtr = nullptr;
                    }
                        //if left subtree of searchPtr contains a node, set searchPtr to the left subtree
                    else {
                        searchPtr = searchPtr->getLeftSubTree();
                    }
                } else {//if currPtr node is greater than or equal to searchPtr
                    //if right subtree of searchPtr is empty than place node there.
                    if(searchPtr->getRightSubTree() == nullptr){
                        nodeToPlace = new ActNode(currPtr->getYear(), currPtr->getAward(), currPtr->getWinner(), currPtr->getName(), currPtr->getFilm());
                        searchPtr->setRightSubTree(nodeToPlace);
                        found = true;
                        nodeToPlace = nullptr;
                        currPtr = nullptr;
                    }
                        //if right subtree of searchPtr contains a node, set searchPtr to the right subtree
                    else {
                        searchPtr = searchPtr->getRightSubTree();
                    }
                }
            }// end while loop that finds placement of node
        }// end while loop that runs until stack is empty
        //print sorted tree to screen in order
        printTreeInOrder(BY_FILM);
    }// end if statement (rootPtr != nullptr)
    else {
        cout << "There is no data to sort. Please upload a file first." << endl << endl;
    }
}// end sortFilm()

//--------printList--------
void ActTree::printList() {

    SearchResultNode *currPtr;
    int count = 1;

    currPtr = headPtr;

    while (currPtr != nullptr){
        cout<< setfill(' ') << setw(3) << count << ".";
        currPtr->getItem()->printToScreen();
        currPtr = currPtr->getNext();
        count ++;
    }
}

//--------addToList--------
void ActTree::addToList(ActNode *toAddPtr) {

    if (headPtr == nullptr){
        headPtr = new SearchResultNode(toAddPtr);
        listSize = 1;
    }
    else {
        //set currPtr to beginning of list
        SearchResultNode *currPtr;
        currPtr = headPtr;

        // loop traverses list until end of list is found.
        while (currPtr->getNext() != nullptr) {
            currPtr = currPtr->getNext();
        }

        //add new search result to the end of list.
        currPtr->setNext(new SearchResultNode(toAddPtr));
        listSize++;
    }

}

//--------modActRecord--------
void ActTree::modActRecord(int modifyChoice) {

    SearchResultNode* currPtr = headPtr;
    ActNode* modifiedNode;
    bool done;
    bool again;
    int choice = 0;
    int year;
    string temp;
    char temp2;

    //find record to modify
    currPtr = headPtr;
    for(int i = 1; i < modifyChoice; i++ ){
        currPtr = currPtr->getNext();
    }

    do {
        done = false;
        again = false;
        choice = 0;

        //displays the record the user has chosen to modify
        cout << "You have chosen to modify the following record: " << endl;
        currPtr->getItem()->printToScreen();
        cout << endl << endl;

        while (!done) {
            cout << "Choose the field you wish to modify:" << endl;
            cout << "1. Year" << endl;
            cout << "2. Award" << endl;
            cout << "3. Winner" << endl;
            cout << "4. Name" << endl;
            cout << "5. Film" << endl;
            cout << "6. Return to main menu." << endl << endl;

            cout << "Enter a field to modify:";
            cin >> choice;
            cout << endl;

            if (cin.fail()) {
                cout << "Make sure to enter an integer." << endl << endl;
                cin.clear();
                cin.ignore();
            } else if ((choice < 1) || (choice > 6)) {
                cout << "Make sure to enter a choice 1-6.";
                cin.clear();
                cin.ignore();
            } else {
                done = true;
            }
        }

        switch (choice) {
            case 1: {
                done = false;
                while (!done) {
                    cout << "Enter the new year to be stored in record:";
                    cin >> year;
                    cout << endl;

                    if (cin.fail()) {
                        cout << "Make sure to enter an integer." << endl << endl;
                        cin.clear();
                        cin.ignore();
                    } else {
                        currPtr->getItem()->setYear(year);
                        cout << "The year has been successfully modified." << endl;
                        cout << "The record now reads: " << endl;
                        currPtr->getItem()->printToScreen();
                        done = true;
                    }
                }

                break;
            }// end case 1

            case 2: {
                cout << "Enter the new award name to be stored in record:" << endl;
                cin.ignore();
                getline(cin, temp);
                cout << endl;

                currPtr->getItem()->setAward(temp);
                cout << "The award name has been successfully modified" << endl;
                cout << "The record now reads:" << endl;
                currPtr->getItem()->printToScreen();

                break;
            }

            case 3: {
                done = false;
                while (!done) {
                    cout << "Enter the new winner status to be stored in record (Y/N):";
                    cin.clear();
                    cin >> temp2;
                    cin.ignore();
                    cout << endl;

                    if (temp2 == 'N' || temp2 == 'n') {
                        currPtr->getItem()->setWinner(false);
                        cout << "The winner status has been successfully modified." << endl;
                        cout << "The record now reads:" << endl;
                        currPtr->getItem()->printToScreen();

                        done = true;
                    } else if (temp2 == 'Y' || temp2 == 'y') {
                        currPtr->getItem()->setWinner(true);
                        cout << "The winner status has been successfully modified." << endl;
                        cout << "The record now reads:" << endl;
                        currPtr->getItem()->printToScreen();

                        done = true;
                    } else {
                        cout << "Be sure to enter either 'Y' or 'N'" << endl;
                    }
                }
                break;
            } // end case 3

            case 4: {
                cout << "Enter the new actor/actress name to be stored in the record:";
                cin.ignore();
                getline(cin, temp);
                cout << endl;

                modifiedNode = new ActNode(currPtr->getItem()->getYear(), currPtr->getItem()->getAward(), currPtr->getItem()->getWinner(), temp, currPtr->getItem()->getFilm());

                removeActNode(currPtr->getItem());
                addToTree(modifiedNode);
                currPtr->setItem(modifiedNode);
                modifiedNode = nullptr;

                cout << "The actor/actress name has been successfully modified." << endl;
                cout << "The record now reads:" << endl;
                currPtr->getItem()->printToScreen();

                break;
            }

            case 5: {
                cout << "Enter the new film name to be stored in the record:";
                cin.ignore();
                getline(cin, temp);
                cout << endl;

                currPtr->getItem()->setFilm(temp);
                cout << "The film name has been successfully modified." << endl;
                cout << "The record now reads:" << endl;
                currPtr->getItem()->printToScreen();

                break;
            }
        }

        done = false;

        while(!done) {
            cout << "Do you want to modify another field? (Y/N):";
            cin.clear();
            cin >> temp2;
            cin.ignore();
            cout << endl;

            if ((temp2 == 'N') || (temp2 == 'n')) {
                again = false;
                done = true;
            }
            else if ((temp2 == 'Y') || (temp2 == 'y')) {
                again = true;
                done = true;
            } else {
                cout << "Be sure to enter either 'Y' or 'N'" << endl;
            }
        }
    } while (again);

}// end modActRecord

//--------deleteList--------
void ActTree::deleteList() {

    SearchResultNode* currPtr;
    currPtr = headPtr;

    //loop goes through list and deletes every item
    while(currPtr != nullptr) {
        currPtr = currPtr->getNext();
        delete headPtr;
        headPtr = currPtr;
    }

    //reset list size to zero
    listSize = 0;
    headPtr = nullptr;
}// end deleteList

//--------addToTree--------
void ActTree::addToTree (ActNode *nodeToAdd){


    ActNode* searchPtr = rootPtr;

    bool found = false;

    //begin while loop t continue until value is found or search reaches a nullptr
    while(!found) {

        //if target is less than current node go to left subtree
        if (nodeToAdd->getName() < searchPtr->getName()) {
            if (searchPtr->getLeftSubTree() != nullptr) {
                searchPtr = searchPtr->getLeftSubTree();
            } else {
                found = true;
            }
        }
            //if target is greater than or equal to current node go to right subtree
        else {
            if (searchPtr->getRightSubTree() != nullptr) {
                searchPtr = searchPtr->getRightSubTree();
            } else {
                found = true;
            }
        }
    }

    //add node to left subtree
    if (nodeToAdd->getName() < searchPtr->getName()){
        searchPtr->setLeftSubTree(nodeToAdd);
    }
        //add node to right subtree
    else{
        searchPtr->setRightSubTree(nodeToAdd);
    }

}

//--------buildTreeFromFile--------
void ActTree::buildTreeFromFile(string fileName) {

    ifstream inFile;
    inFile.open(fileName);

    int newYear;
    string tempYear, tempWinner;
    string newAward, newName, newFilm;
    bool newWinner;
    const int BY_NAME = 4;

    deleteTree(BY_NAME);
    treeSize = 0;

    //ignore first line of the file because it is labels for the entry
    getline(inFile, tempYear);


    //read line from the file and save the data to corresponding variables
    getline(inFile, tempYear, ',');
    newYear = stoi(tempYear);
    getline(inFile, newAward, ',');
    getline(inFile, tempWinner, ',');
    if (stoi(tempWinner)) {
        newWinner = true;
    } else {
        newWinner = false;
    }
    getline(inFile, newName, ',');
    getline(inFile, newFilm);

    //use the first line of the file to create the root of the tree
    rootPtr = new ActNode(newYear, newAward, newWinner, newName, newFilm);

    ActNode *currPtr;

    //begin loop to read lines from file until end of file
    while (getline(inFile, tempYear, ',')) {
        //cout << tempYear << "  ";
        newYear = stoi(tempYear);
        getline(inFile, newAward, ',');
        //cout << newAward << "  ";
        getline(inFile, tempWinner, ',');
        //cout << tempWinner << "  ";
        if (stoi(tempWinner) == 1) {
            newWinner = true;
        } else {
            newWinner = false;
        }
        getline(inFile, newName, ',');
        //cout << newName << "  ";
        getline(inFile, newFilm);

        //cout << newFilm << endl;

        //have pointer point to an ActNode with the data read from file
        currPtr = new ActNode(newYear, newAward, newWinner, newName, newFilm);

        //add node to tree
        addToTree(currPtr);

    }// end while loop
}

//--------addActNode--------
void ActTree::addActNode(int year, string award, bool winner, string name, string film) {
    ActNode* nodePtr = new ActNode(year, award, winner, name, film);

    addToTree(nodePtr);
}


//--------removeActNode--------
void ActTree::removeActNode(ActNode* nodeToRemove) {

    ActNode *rootToRemovedPtr = rootPtr;
    ActNode *copyNodePtr;
    bool found = false;

    //case 1: the node to be removed has no subtrees
    // action: find the root of the node to be removed. Set the pointer to the node to be removed to nullptr
    // then delete the node
    if ((nodeToRemove->getLeftSubTree() == nullptr) && (nodeToRemove->getRightSubTree() == nullptr)) {

        //loop finds the root of the node that needs to be removed and sets the pointer of the root to nullptr
        while (!found) {
            if (rootToRemovedPtr->getRightSubTree() == nodeToRemove) {
                found = true;
                rootToRemovedPtr->setRightSubTree(nullptr);
            } else if (rootToRemovedPtr->getLeftSubTree() == nodeToRemove) {
                found = true;
                rootToRemovedPtr->setLeftSubTree(nullptr);
            } else if (nodeToRemove->getName() < rootToRemovedPtr->getName()) {
                rootToRemovedPtr = rootToRemovedPtr->getLeftSubTree();
            } else {
                rootToRemovedPtr = rootToRemovedPtr->getRightSubTree();
            }
        }

        //delete node to be removed
        delete nodeToRemove;
    } // end of case 1

        //case 2: the node to be removed has exactly one subtree
        // action: find the root of the Node-to-be-removed. Have the root point to the subtree of the Node-to-be-removed
        // then delete the node-to-be-removed
    else if (((nodeToRemove->getRightSubTree() == nullptr) && (nodeToRemove->getLeftSubTree() != nullptr))) {

        //loop finds the root of the node that needs to be removed
        while (!found) {
            if (rootToRemovedPtr->getRightSubTree() == nodeToRemove) {
                found = true;
                rootToRemovedPtr->setRightSubTree(nodeToRemove->getLeftSubTree());
            } else if (rootToRemovedPtr->getLeftSubTree() == nodeToRemove) {
                found = true;
                rootToRemovedPtr->setLeftSubTree(nodeToRemove->getLeftSubTree());
            } else if (nodeToRemove->getName() < rootToRemovedPtr->getName()) {
                rootToRemovedPtr = rootToRemovedPtr->getLeftSubTree();
            } else {
                rootToRemovedPtr = rootToRemovedPtr->getRightSubTree();
            }
        }

        //delete node to be removed
        delete nodeToRemove;
    } else if ((nodeToRemove->getRightSubTree() != nullptr) && (nodeToRemove->getLeftSubTree() == nullptr)) {

        //loop finds the root of the node that needs to be removed
        while (!found) {
            if (rootToRemovedPtr->getRightSubTree() == nodeToRemove) {
                found = true;
                rootToRemovedPtr->setRightSubTree(nodeToRemove->getRightSubTree());
            } else if (rootToRemovedPtr->getLeftSubTree() == nodeToRemove) {
                found = true;
                rootToRemovedPtr->setLeftSubTree(nodeToRemove->getRightSubTree());
            } else if (nodeToRemove->getName() < rootToRemovedPtr->getName()) {
                rootToRemovedPtr = rootToRemovedPtr->getLeftSubTree();
            } else {
                rootToRemovedPtr = rootToRemovedPtr->getRightSubTree();
            }
        }

        //delete node to be removed
        delete nodeToRemove;

    } // end of case 2

        //case 3: the node-to-be-removed has two subtrees
        // action: In the node-to-be-removed right subtree find the node furthest to the left. Copy the information of this
        //node into the location of the node to be deleted. Then the new node-to-be-deleted is at the node of the information
        // that has just been copied
    else if ( (nodeToRemove->getRightSubTree() != nullptr) && (nodeToRemove->getLeftSubTree() != nullptr)){

        //go to the right subtree
        copyNodePtr = nodeToRemove->getRightSubTree();

        //loop find the further left node on the right subtree
        while (copyNodePtr->getLeftSubTree() != nullptr){
            copyNodePtr = copyNodePtr->getLeftSubTree();
        }

        //replace the information into the nodeToRemove from the found node
        //the pointers to the subtrees are not altered
        nodeToRemove->setYear(copyNodePtr->getYear());
        nodeToRemove->setAward(copyNodePtr->getAward());
        nodeToRemove->setWinner(copyNodePtr->getWinner());
        nodeToRemove->setName(copyNodePtr->getName());
        nodeToRemove->setFilm(copyNodePtr->getFilm());

        //delete the duplicate node
        removeActNode(copyNodePtr);
    } // end of case 3
}// end removeActNode

//--------findAndRemoveNode--------
void ActTree::findAndRemoveNode(int choice) {

    SearchResultNode* userChoice;
    userChoice = headPtr;

    for (int i = 1; i < choice; i++)
    {
        userChoice = userChoice->getNext();
    }

    cout << "The following record has been deleted:" << endl;
    userChoice->getItem()->printToScreen();

    //remove node from tree
    removeActNode(userChoice->getItem());
}// end findAndRemoveNode


//--------writeToFile--------
void ActTree::writeToFile(string fileName, int choice) {

    ActNode *currPtr = nullptr;
    ActNode *tempRootPtr;
    ActNode *searchPtr;
    ActNode *nodeToPlace;
    bool lessThan;
    bool found;
    stack<ActNode *> nodeStack;


    if (rootPtr == nullptr){
        cout << "Error: You must read data in first." << endl;
    }
    else {
        //create root
        tempRootPtr = new ActNode(rootPtr->getYear(), rootPtr->getAward(), rootPtr->getWinner(), rootPtr->getName(),
                                  rootPtr->getFilm());


        if (rootPtr->getRightSubTree() != nullptr) {
            nodeStack.push(rootPtr->getRightSubTree());
        }
        if (rootPtr->getLeftSubTree() != nullptr) {
            nodeStack.push(rootPtr->getLeftSubTree());
        }

        //loop executes as long as stack is not empty
        while (!nodeStack.empty()) {
            found = false;
            searchPtr = tempRootPtr;

            currPtr = nodeStack.top();
            nodeStack.pop();


            //if the left and right subtrees of currPtr contain nodes, push them onto stack
            if (currPtr->getRightSubTree() != nullptr) {
                nodeStack.push(currPtr->getRightSubTree());
            }
            if (currPtr->getLeftSubTree() != nullptr) {
                nodeStack.push(currPtr->getLeftSubTree());
            }

            //loop to find where to place node in sorted
            while (!found) {

                lessThan = false;

                switch (choice) {
                    case 1: {
                        if (currPtr->getYear() < searchPtr->getYear()) {
                            lessThan = true;
                        }
                        break;
                    }
                    case 2: {
                        if (currPtr->getAward() < searchPtr->getAward()) {
                            lessThan = true;
                        }
                        break;
                    }
                    case 3: {
                        if (currPtr->getWinner() < searchPtr->getWinner()) {
                            lessThan = true;
                        }
                        break;
                    }
                    case 4: {
                        if (currPtr->getName() < searchPtr->getName()) {
                            lessThan = true;
                        }
                        break;
                    }
                    case 5: {
                        if (currPtr->getFilm() < searchPtr->getFilm()) {
                            lessThan = true;
                        }
                        break;
                    }
                }

                //if currPtr(the node to be placed) is less than searchPtr
                if (lessThan) {

                    //if left subtree of searchPtr is empty than place the currPtr node there
                    if (searchPtr->getLeftSubTree() == nullptr) {
                        nodeToPlace = new ActNode(currPtr->getYear(), currPtr->getAward(), currPtr->getWinner(),
                                                  currPtr->getName(), currPtr->getFilm());
                        searchPtr->setLeftSubTree(nodeToPlace);
                        found = true;
                        nodeToPlace = nullptr;
                        currPtr = nullptr;
                    }
                        //if left subtree of searchPtr contains a node, set searchPtr to the left subtree
                    else {
                        searchPtr = searchPtr->getLeftSubTree();
                    }
                } else {//if currPtr node is greater than or equal to searchPtr
                    //if right subtree of searchPtr is empty than place node there.
                    if (searchPtr->getRightSubTree() == nullptr) {
                        nodeToPlace = new ActNode(currPtr->getYear(), currPtr->getAward(), currPtr->getWinner(),
                                                  currPtr->getName(), currPtr->getFilm());
                        searchPtr->setRightSubTree(nodeToPlace);
                        found = true;
                        nodeToPlace = nullptr;
                        currPtr = nullptr;
                    }
                        //if right subtree of searchPtr contains a node, set searchPtr to the right subtree
                    else {
                        searchPtr = searchPtr->getRightSubTree();
                    }
                }
            }// end while loop that finds placement of node
        }// end while loop that runs until stack is empty


        switch (choice) {
            case 1: {
                rootYearPtr = tempRootPtr;
                break;
            }
            case 2: {
                rootAwardPtr = tempRootPtr;
                break;
            }
            case 3: {
                rootWinnerPtr = tempRootPtr;
                break;
            }
            case 4: {
                rootPtr = tempRootPtr;
                break;
            }
            case 5: {
                rootFilmPtr = tempRootPtr;
                break;
            }
        }

        //print sorted tree to file

        ofstream outFile;
        outFile.open(fileName);
        stack<ActNode*> printStack;
        currPtr = tempRootPtr;

        outFile << "Year,Award,Winner,Name,Film" << endl;

        while((!printStack.empty()) || (currPtr != nullptr))
        {
            if(currPtr != nullptr)// executes when the current node is an element of the tree
            {
                printStack.push(currPtr); // push currPtr onto stack
                currPtr = currPtr->getLeftSubTree(); //set currPtr to left subtree
            }
            else //executes when search has reached the end of a leaf of the tree
            {
                currPtr = printStack.top(); //set currPtr to top of stack
                printStack.pop();

                outFile << currPtr->getYear() << ",";
                outFile << currPtr->getAward() << ",";
                if(currPtr->getWinner()){
                    outFile << "Yes,";
                }
                else{
                    outFile << "No,";
                }
                outFile << currPtr->getName() << ",";
                outFile << currPtr->getFilm() << endl;

                currPtr = currPtr->getRightSubTree();
            }
        }//end while loop

        outFile.close();
    }
}//end writeToFile

void ActTree::calcStatistics() {

    cout << "Calculating Statistics, please wait..." << endl << endl;
    struct nameFreq{
        string name;
        int frequency;
    };

    ActNode* currPtr = rootPtr;
    stack<ActNode*> recStack;
    stack<ActNode*> searchStack;
    vector<nameFreq> vecOfNames;
    nameFreq nameToAdd;
    nameFreq temp;
    bool foundMatch;
    int i;

    if (currPtr == nullptr){
        cout << "Error: please upload a file first" << endl << endl;
    }
    else{

        recStack.push(currPtr);

        while ((!recStack.empty())) {

            currPtr = recStack.top();
            recStack.pop();

            if (currPtr->getLeftSubTree() != nullptr) {
                recStack.push(currPtr->getLeftSubTree());
            }

            if (currPtr->getRightSubTree() != nullptr) {
                recStack.push(currPtr->getRightSubTree());
            }

            if (currPtr->getName().size() != 0) {

                foundMatch = false;
                i = 0;
                while ((i < vecOfNames.size()) && (!foundMatch)) {

                    if (currPtr->getName() == vecOfNames[i].name) {
                        foundMatch = true;
                    } else {
                        i++;
                    }
                }// end while

                if (foundMatch) {
                    //increment frequency by 1
                    vecOfNames[i].frequency = vecOfNames[i].frequency + 1;

                } else {
                    nameToAdd.name = currPtr->getName();
                    nameToAdd.frequency = 1;

                    vecOfNames.push_back(nameToAdd);
                }
            }
        }//end while loop

        //loop finds the top ten most frequent names and places them at the front of the vector
        for (int j = 0; j < 20 ; j++){
            for (int p = j+1; p < vecOfNames.size(); p++){
                if ( vecOfNames[p].frequency > vecOfNames[j].frequency){
                    temp = vecOfNames[j];
                    vecOfNames[j] = vecOfNames[p];
                    vecOfNames[p] = temp;
                }//end if
            }//end inner loop
        }//end outer loop


        cout << endl << " Top 20 most nominated people all time" << endl;
        cout << "-------------------------------------------" << endl;

        for (int j = 0; j < 20; j++){
            cout << j+1 << ". " << vecOfNames[j].name << "  " << vecOfNames[j].frequency << endl;
        }

    }

    cout << endl << endl << "Most nominated title by year" << endl;
    cout << "------------------" << endl;

    SearchResultNode *countPtr;
    vector<nameFreq> vecOfTitles;

    string currYear;
    string target;

    while (!searchStack.empty()){
        searchStack.pop();
    }

    for (int j = 1928; j < 2017; j++){

        deleteList();

        target = to_string(j);

        searchStack.push(rootPtr);
        currPtr = rootPtr->getLeftSubTree();

        //while loop executes as long as stack is not empty
        while((!searchStack.empty()) || (currPtr != nullptr))
        {
            if(currPtr != nullptr)//if statement executes when the current node is an element of the tree
            {
                searchStack.push(currPtr); // push currPtr onto stack
                currPtr = currPtr->getLeftSubTree(); //set currPtr to left subtree
            }
            else //executes when search has reached the end of a leaf of the tree
            {
                currPtr = searchStack.top(); //set currPtr to top of stack

                currYear = to_string(currPtr->getYear());

                if(currYear.find(target) != -1){
                    //if substring is found in currPtr year, add currPtr to list of search results
                    addToList(currPtr);
                }

                searchStack.pop();
                currPtr = currPtr->getRightSubTree();
            }
        }//end while loop


        countPtr = headPtr;

        while (countPtr != nullptr){
            if (countPtr->getItem()->getFilm().length() != 0) {
                nameToAdd.name = countPtr->getItem()->getFilm();
                nameToAdd.frequency = 1;


                foundMatch = false;
                i = 0;
                while ((!foundMatch) && (i < vecOfTitles.size())) {
                    if (nameToAdd.name == vecOfTitles[i].name) {
                        vecOfTitles[i].frequency = vecOfTitles[i].frequency + 1;
                        foundMatch = true;
                    } else {
                        i++;
                    }
                }

                if (!foundMatch) {
                    vecOfTitles.push_back(nameToAdd);
                }
            }
            countPtr = countPtr->getNext();
        }//end while loop

        //place title with greatest frequency at front
        for (int p = 1; p < vecOfTitles.size(); p++){
            if (vecOfTitles[p].frequency > vecOfTitles[0].frequency){
                temp = vecOfTitles[0];
                vecOfTitles[0] = vecOfTitles[p];
                vecOfTitles[p] = temp;
            }
        }

        cout << j << " -- " << vecOfTitles[0].name << "  " << vecOfTitles[0].frequency << endl;

        vecOfTitles.erase(vecOfTitles.begin(), vecOfTitles.end());

    }

}