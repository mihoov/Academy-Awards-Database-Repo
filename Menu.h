#ifndef _MENU
#define _MENU

#include <iostream>
#include "ActTree.h"
#include"Nodes.h"
#include "PicNode.h"
#include "PicTree.h"

using namespace std;

//----------MAIN MENU------------

//Displays the main menu and reads in user choice.
int displayMenu();
//Navigates main menu based on user input
void mainMenu();

//----------ACTOR MENU-------------

//Displays the actor menu and reads in user choice
int displayActor();
//Navigates actor menu based on user input
int actorMenu();

//Displays the actor complete search menu and reads in user choice
int actorCompDisplay();
//Navigates actor complete search menu based on user input
int actorCompMenu(ActTree &actDataBase);

//Displays the actor partial search menu and reads in user choice
int actorPartDisplay();
//Navigates actor partial search menu based on user input
int actorPartMenu(ActTree &actDataBase);

//Displays the actor sort menu and reads in user choice
int actorSortDisplay();
//Navigates actor sort menu based on user input
int actorSortMenu(ActTree &actDataBase);

void addActor(ActTree &actDataBase);

int actorModify(ActTree &actDataBase);

void removeActor(ActTree &actDataBase);

//------------PICTURE MENU-------------

//Displays the picture menu and reads in user choice
int displayPicture();
//Navigates picture menu based on user input
int pictureMenu(PicTree* pictures);

//Displays the actor complete search menu and reads in user choice
int pictureCompDisplay();
//Navigates picture complete search menu based on user input
int pictureCompMenu(PicTree* pictures);

//Displays the actor partial search menu and reads in user choice
int picturePartDisplay();
//Navigates picture partial search menu based on user input
int picturePartMenu(PicTree* pictures);

//Displays the picture sort menu and reads in user choice
int pictureSortDisplay();
//Navigates picture sort menu based on user input
int pictureSortMenu(PicTree* pictures);

void addPicture(PicTree* pictures);

int pictureModify(PicTree* pictures);

int removePicture(PicTree* pictures);

//----------NOMINATIONS MENU-------------

//Displays the nominations menu and reads in user choice
int displayNomination();
//Navigates nominations menu based on user input
int nominationMenu();

//Displays the nominations complete search menu and reads in user choice
int nominationCompDisplay();

#endif