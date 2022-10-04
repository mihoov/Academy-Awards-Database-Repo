#include <iostream>
#include <string>
#include <iomanip>
#include "Menu.h"


using namespace std;

//------------------------------------------------------------------
//Search "CODE NEEDED" to easily find where actor/picture functions need to be added
//------------------------------------------------------------------

//---------Main Menu---------------

//Displays the main menu and reads in user choice.
int displayMenu()
{
    //try/catch statement ensure that user inputs a valid integer
    try
    {
        int choice = 0;

        cout << "Academy Awards Database" << endl;
        cout << "-----------------------" << endl << endl;
        cout << "1. Access actor/actress data" << endl;
        cout << "2. Access picture data" << endl;
        cout << "3. Access nominations data" << endl;
        cout << "4. Exit program" << endl;
        cout << "Enter your choice (1 - 4): " << endl;

        cin >> choice;

        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw 1;
        }


        return choice;
    }
    catch(int error)
    {
        cout << "INPUT ERROR: Make sure to enter an integer." << endl << endl;

        return displayMenu();
    }
}

//Navigates main menu based on user input
void mainMenu() {

    ActTree actors;
    PicTree* pictures = new PicTree;

    int choice = 0;
    bool done = false;
    bool exit = false;

    while (!done) {
        //display and allow user to input so long as exit is not required
        if (!exit)
        {
            choice = displayMenu();
        }

        switch (choice)
        {
            case 1:
                //Enter actor menu function, set exit to true if necessary
                if (actorMenu() == 1)
                {
                    choice = 4;
                    exit = true;
                }
                break;
            case 2:
                //Enter nomination menu
                if (pictureMenu(pictures) == 1)
                {
                    choice = 4;
                    exit = true;
                }
                break;

            case 3:
                if (nominationMenu() == 1)
                {
                    choice = 4;
                    exit = true;
                }

            case 4:
                //Quit the program
                done = true;
                break;

            default:
                cout << choice << " is not a valid option. Try again" << endl << endl;
        }
    }
}

//This segment is entered when option 1 from main menu is selected.
//---------Actor Menu---------------

//Displays the actor menu and reads in user choice
int displayActor()
{
    try
    {
        int choice = 0;

        cout << "Actors" << endl;
        cout << "------" << endl << endl;
        cout << "1. Read actor data from a file" << endl;
        cout << "2. Complete search" << endl;
        cout << "3. Partial search" << endl;
        cout << "4. Sort by field" << endl;
        cout << "5. Add an actor" << endl;
        cout << "6. Remove an actor" << endl;
        cout << "7. Modify actor" << endl;
        cout << "8. Save actor data" << endl;
        cout << "9. Back" << endl;
        cout << "10. Exit program" << endl;
        cout << "Enter your choice (1 - 10): " << endl;

        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw 1;
        }

        return choice;
    }
    catch (int error)
    {
        cout << "Make sure to enter an integer." << endl << endl;

        return displayActor();
    }
}

//Navigates actor menu based on user input
int actorMenu() {
    string temp;
    int choice = 0;
    int sortChoice = 0;
    bool check;
    bool done = false;
    ActTree actDataBase;

    while (!done)
    {
        choice = displayActor();

        switch (choice) {
            case 1: {
                cout << "Give name of the csv file to read in (i.e. 'name.csv')" << endl;
                cin >> temp;
                cout << endl;


                //actor tree function that reads in a csv file, use temp as file name

                actDataBase.buildTreeFromFile(temp);

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();
                break;
            }
            case 2:
                if (actorCompMenu(actDataBase) == 1)
                {
                    return 1;
                }
                break;
            case 3:
                if (actorPartMenu(actDataBase) == 1)
                {
                    return 1;
                }
                break;
            case 4:
                if (actorSortMenu(actDataBase) == 1)
                {
                    return 1;
                }
                break;
            case 5:
                addActor(actDataBase);
                break;
            case 6:
                removeActor(actDataBase);
                break;
            case 7:
                if (actorModify(actDataBase) == 1)
                {
                    return 1;
                }
                break;
            case 8:
                cout << "Give name of the csv file to save the actor data to (i.e. 'name.csv')" << endl;
                cin >> temp;
                cout << endl;

                do {
                    cout << "Choose the field the file will be sorted by:" << endl;
                    cout << "1. Year" << endl;
                    cout << "2. Award" << endl;
                    cout << "3. Winner" << endl;
                    cout << "4. Name" << endl;
                    cout << "5. Film" << endl;
                    cout << "Enter option (1-5):";

                    cin >> sortChoice;
                    if (cin.fail())
                    {
                        cout << "Be sure to enter a number 1-5."<< endl;
                        check = false;
                    }
                    else if ((sortChoice < 1) || (sortChoice > 5)){
                        cout << "Be sure to enter a number 1-5." << endl;
                        check = false;
                    }
                    else
                    {
                        check = true;
                    }
                }while (!check);


                //actor tree function that saves actor data to a csv file, use temp as file name
                actDataBase.writeToFile(temp, sortChoice);

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();


                break;
            case 9:
                done = true;
                break;
            case 10:
                return 1;
            default:
                cout << choice << " is not a valid option. Try again" << endl << endl;
        }
    }
    return 0;
}

//This segment is entered when option 2 from actor menu is selected.
//---------Actor Complete Search Menu---------------

//Displays the actor complete search menu and reads in user choice
int actorCompDisplay()
{
    try
    {
        int choice = 0;

        cout << "Actor Complete Search" << endl;
        cout << "---------------------" << endl << endl;
        cout << "Choose a field to search: " << endl;
        cout << "1. Year" << endl;
        cout << "2. Award" << endl;\
		cout << "3. Name" << endl;
        cout << "4. Film" << endl;
        cout << "5. Back" << endl;
        cout << "6. Exit program" << endl;
        cout << "Enter your choice (1 - 6): " << endl;

        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw 1;
        }

        return choice;
    }
    catch (int error)
    {
        cout << "Make sure to enter an integer." << endl << endl;

        return actorCompDisplay();
    }
}

//Navigates actor complete search menu based on user input
int actorCompMenu(ActTree &actDataBase)
{
    int year;
    string temp;

    int choice = 0;
    bool done = false;

    while (!done)
    {
        choice = actorCompDisplay();

        switch (choice) {
            case 1:
                try
                {
                    cout << "Enter a year" << endl;
                    cin >> year;
                    cout << endl;


                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        throw 1;
                    }

                    //actor tree function that executes a complete search of year
                    //year to be searched held in year variable
                    actDataBase.compYear(year);

                    cout << "Press enter to return to menu" << endl << endl;
                    cin.clear();
                    cin.get();
                    cin.ignore();
                }

                catch(int error)
                {
                    cout << "Make sure to enter an integer." << endl << endl;

                    return actorCompMenu( actDataBase);
                }

                break;

            case 2:
                cout << "Enter an award name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;


                //actor tree function that executes a complete search of award name
                //award name to be searched held in temp variable
                actDataBase.compAward(temp);

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                break;
            case 3: {
                cout << "Enter an actor/actress name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;

                //actor tree function that executes a complete search of actor name
                //actor name to be searched held in temp variable
                actDataBase.compName(temp);

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                break;}

            case 4:

                cout << "Enter a film name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;


                //actor tree function that executes a complete search of film name
                //film name to be searched held in temp variable
                actDataBase.compFilm(temp);

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                break;

            case 5:
                done = true;
                break;
            case 6:
                return 1;
            default:
                cout << choice << " is not a valid option. Try again" << endl << endl;
        }
    }
    return 0;
}

//This segment is entered when option 3 from actor menu is selected.
//---------Actor Partial Search Menu---------------

//Displays the actor partial search menu and reads in user choice
int actorPartDisplay()
{
    try
    {
        int choice = 0;

        cout << "Actor Partial Search" << endl;
        cout << "--------------------" << endl << endl;
        cout << "Choose a field to search: " << endl;
        cout << "1. Year" << endl;
        cout << "2. Award" << endl;
        cout << "3. Name" << endl;
        cout << "4. Film" << endl;
        cout << "5. Back" << endl;
        cout << "6. Exit program" << endl;
        cout << "Enter your choice (1 - 6): " << endl;

        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw 1;
        }

        return choice;
    }
    catch (int error)
    {
        cout << "Make sure to enter an integer." << endl << endl;

        return actorPartDisplay();
    }
}

//Navigates actor partial search menu based on user input
int actorPartMenu(ActTree &actDataBase)
{
    int year;
    string temp;

    int choice = 0;
    bool done = false;

    while (!done)
    {
        choice = actorPartDisplay();

        switch (choice) {
            case 1:
                try
                {
                    cout << "Enter a year" << endl;
                    cin >> year;
                    cout << endl;


                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        throw 1;
                    }

                    //actor tree function that executes a partial search of year
                    //year to be searched held in year variable
                    actDataBase.partYear(year);

                    cout << "Press enter to return to menu" << endl << endl;
                    cin.clear();
                    cin.get();
                    cin.ignore();
                }

                catch (int error)
                {
                    cout << "Make sure to enter an integer." << endl << endl;

                    return actorPartMenu(actDataBase);
                }

                break;

            case 2:
                cout << "Enter an award name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;


                //actor tree function that executes a partial search of award name
                //award name to be searched held in temp variable
                actDataBase.partAward(temp);

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                break;
            case 3:
                cout << "Enter an actor/actress name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;


                //actor tree function that executes a partial search of actor name
                //actor name to be searched held in temp variable
                actDataBase.partName(temp);


                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                break;
            case 4:
                cout << "Enter a film name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;


                //actor tree function that executes a partial search of film name
                //film name to be searched held in temp variable
                actDataBase.partFilm(temp);

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                break;
            case 5:
                done = true;
                break;
            case 6:
                return 1;
            default:
                cout << choice << " is not a valid option. Try again" << endl << endl;
        }
    }
    return 0;
}

//This segment is entered when option 4 from actor menu is selected.
//---------Actor Sort Menu---------------

//Displays the actor sort menu and reads in user choice
int actorSortDisplay()
{
    try
    {
        int choice = 0;

        cout << "Actor Sort" << endl;
        cout << "----------" << endl << endl;
        cout << "Choose a field to sort by: " << endl;
        cout << "1. Year" << endl;
        cout << "2. Award" << endl;
        cout << "3. Winner" << endl;
        cout << "4. Name" << endl;
        cout << "5. Film" << endl;
        cout << "6. Back" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (1 - 7): " << endl;

        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw 1;
        }

        return choice;
    }
    catch (int error)
    {
        cout << "Make sure to enter an integer." << endl << endl;

        return actorSortDisplay();
    }
}

//Navigates actor sort menu based on user input
int actorSortMenu(ActTree &actDataBase)
{
    int choice = 0;
    bool done = false;

    while (!done)
    {
        choice = actorSortDisplay();

        switch (choice)
        {
            case 1: {

                //actor tree function that sorts by year
                actDataBase.sortYear();


                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            }

            case 2: {
                //actor tree function that sorts by award name
                actDataBase.sortAward();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            }

            case 3: {
                //actor tree function that sorts by winner
                actDataBase.sortWinner();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            }

            case 4: {
                //the original database is already sorted by actor name
                const int PRINT_BY_NAME = 4;
                actDataBase.printTreeInOrder(PRINT_BY_NAME);

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            }

            case 5: {
                //actor tree function that sorts by film name
                actDataBase.sortFilm();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            }

            case 6: {
                done = true;
                break;
            }

            case 7: {
                return 1;
            }

            default: {
                cout << choice << " is not a valid option. Try again" << endl << endl;
            }

        }
    }
    return 0;
}

//This segment is entered when option 5 from actor menu is selected.
//---------Add actor---------------
void addActor(ActTree &actDataBase)
{
    int year;
    string award;
    bool winner;
    string name;
    string film;

    cout << "Add actor" << endl;
    cout << "---------" << endl << endl;

    //Recieves year info from user, ensures valid type
    bool isInt = false;
    while (!isInt)
    {
        try
        {
            cout << "Enter year: ";
            cin >> year;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                throw 1;
            }

            isInt = true;
        }
        catch (int error)
        {
            cout << "Make sure to enter an integer." << endl << endl;
        }
    }

    //recieves award info
    cout << "Enter award name: ";
    cin.ignore();
    getline(cin, award);

    //recieves winner data, ensures valid answer
    bool done = false;
    char input;
    while (!done)
    {
        cout << "Did the actor win the award? (Y/N): ";
        cin >> input;

        if (input == 'Y' || input == 'y')
        {
            winner = true;
            done = true;
        }

        else if (input == 'N' || input == 'n')
        {
            winner = false;
            done = true;
        }

        else
        {
            cout << "Invalid input, please answer with 'Y' or 'N'" << endl << endl;
        }
    }
    //Sets winnerStr

    //recieves name info
    cout << "Enter actor name: ";
    cin.ignore();
    getline(cin, name);

    //recieves film info
    cout << "Enter film name: ";
    getline(cin, film);

    cout << endl;

    //show added actor
    cout << "Added actor:" << endl;
    cout.width(20);
    cout << left << "Year";
    cout.width(20);
    cout << left << "Award";
    cout.width(20);
    cout << left << "Winner";
    cout.width(20);
    cout << left << "Name";
    cout.width(20);
    cout << left << "Film" << endl;

    cout.width(20);
    cout << left << year;
    cout.width(20);
    cout << left << award.substr(0,19);
    if (winner){
        cout.width(20);
        cout << left << "Yes";

    }
    else {
        cout.width(20);
        cout << left << "No";
    }
    cout.width(20);
    cout << left << name.substr(0,19);
    cout.width(20);
    cout << left << film.substr(0,19) << endl;

    //CODE NEEDED
    //actor tree function that creates new node using year, award, winner, name, and film variables
    actDataBase.addActNode(year, award, winner, name, film);

    cout << endl;

    cout << "Press enter to return to menu" << endl << endl;
    cin.ignore();
}

//This segment is entered when option 6 from actor menu is selected.
//---------Remove actor---------------
void removeActor(ActTree &actDataBase)
{
    int year;
    string temp;

    int choice = 0;
    int deleteChoice = 0;
    bool done = false;

    while (!done)
    {

        cout << "Search for Record to Delete" << endl;
        cout << "------" << endl << endl;
        cout << "Choose a field to search: " << endl;
        cout << "1. Year" << endl;
        cout << "2. Award" << endl;
        cout << "3. Name" << endl;
        cout << "4. Film" << endl;
        cout << "5. Back" << endl;
        cout << "Enter your choice (1 - 5): " << endl;

        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            cout << "Make sure to enter an integer." << endl << endl;
            cin.clear();
            cin.ignore();
        }
        else if ( (choice < 1) || (choice > 5))
        {
            cout << "Make sure to enter a choice 1-5.";
            cin.clear();
            cin.ignore();
        }
        else
        {
            done = true;
        }
    }

    done = false;

    while (!done)
    {
        switch (choice) {
            case 1:
            {
                cout << "Enter a year" << endl;
                cin >> year;
                cout << endl;


                if (cin.fail())
                {
                    cout << "Make sure to enter an integer." << endl << endl;
                    cin.clear();
                    cin.ignore();
                }
                else {
                    //actor tree function that executes a partial search of year
                    //year to be searched held in year variable
                    actDataBase.partYear(year);
                    done = true;
                }
            }

                break;

            case 2:
                cout << "Enter an award name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;


                //actor tree function that executes a partial search of award name
                //award name to be searched held in temp variable
                actDataBase.partAward(temp);
                done = true;
                break;

            case 3:
                cout << "Enter an actor/actress name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;


                //actor tree function that executes a partial search of actor name
                //actor name to be searched held in temp variable
                actDataBase.partName(temp);
                done = true;

                break;
            case 4:
                cout << "Enter a film name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;


                //actor tree function that executes a partial search of film name
                //film name to be searched held in temp variable
                actDataBase.partFilm(temp);
                done = true;

                break;
            case 5:
                done = true;
                break;
            default:
                done = true;
        }
    }

    //actor tree function that allows for choosing and removing one of displayed  options
    done = false;

    while (!done) {
        cout << "Choose the record number to delete. Or enter '0' to go back to main menu:";
        cin >> deleteChoice;

        if (deleteChoice == 0)
        {
            done = true;
        }
        else if(cin.fail())
        {
            cout << "Make sure to enter an integer." << endl << endl;
            cin.clear();
            cin.ignore();
        }
        else if ( (deleteChoice < 0) || (deleteChoice > actDataBase.getListSize()) )
        {
            cout << "Make sure to enter a valid option." << endl << endl;
            cin.clear();
            cin.ignore();
        }
        else {

            actDataBase.findAndRemoveNode(deleteChoice);
            done = true;
        }
    }


    cout << "Press enter to return to menu" << endl << endl;
    cin.ignore();
}


//This segment is entered when option 7 from actor menu is selected.
//---------Actor Modify Menu---------------
int actorModify(ActTree &actDataBase)
{

    int year;
    string temp;

    int choice = 0;
    int modifyChoice = 0;
    bool done = false;

    while (!done)
    {

        cout << "Search for Record to Modify" << endl;
        cout << "------" << endl << endl;
        cout << "Choose a field to search: " << endl;
        cout << "1. Year" << endl;
        cout << "2. Award" << endl;
        cout << "3. Name" << endl;
        cout << "4. Film" << endl;
        cout << "5. Back" << endl;
        cout << "Enter your choice (1 - 5): " << endl;

        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            cout << "Make sure to enter an integer." << endl << endl;
            cin.clear();
            cin.ignore();
        }
        else if ( (choice < 1) || (choice > 5))
        {
            cout << "Make sure to enter a choice 1-5.";
            cin.clear();
            cin.ignore();
        }
        else
        {
            done = true;
        }
    }

    done = false;

    while (!done)
    {
        switch (choice) {
            case 1:
            {
                cout << "Enter a year" << endl;
                cin >> year;
                cout << endl;


                if (cin.fail())
                {
                    cout << "Make sure to enter an integer." << endl << endl;
                    cin.clear();
                    cin.ignore();
                }
                else {
                    //actor tree function that executes a partial search of year
                    //year to be searched held in year variable
                    actDataBase.partYear(year);
                    done = true;
                }
            }

                break;

            case 2:
                cout << "Enter an award name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;


                //actor tree function that executes a partial search of award name
                //award name to be searched held in temp variable
                actDataBase.partAward(temp);
                done = true;
                break;

            case 3:
                cout << "Enter an actor/actress name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;


                //actor tree function that executes a partial search of actor name
                //actor name to be searched held in temp variable
                actDataBase.partName(temp);
                done = true;

                break;
            case 4:
                cout << "Enter a film name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;


                //actor tree function that executes a partial search of film name
                //film name to be searched held in temp variable
                actDataBase.partFilm(temp);
                done = true;

                break;
            case 5:
                done = true;
                break;
            default:
                done = true;
        }
    }



    done = false;

    while (!done) {
        cout << "Choose the record number to modify. Or enter '0' to go back to main menu:";
        cin >> modifyChoice;

        if (modifyChoice == 0)
        {
            done = true;
        }
        else if(cin.fail())
        {
            cout << "Make sure to enter an integer." << endl << endl;
            cin.clear();
            cin.ignore();
        }
        else if ( (modifyChoice < 0) || (modifyChoice > actDataBase.getListSize()) )
        {
            cout << "Make sure to enter a valid option." << endl << endl;
            cin.clear();
            cin.ignore();
        }
        else {
            actDataBase.modActRecord(modifyChoice);
            done = true;
        }
    }


    cout << "Press enter to return to menu" << endl << endl;
    cin.ignore();

    return 0;
}




//This segment is entered when option 2 from main menu is selected.
//---------Picture Menu---------------

//Displays the picture menu and reads in user choice
int displayPicture()
{
    try
    {
        int choice = 0;

        cout << "Pictures" << endl;
        cout << "--------" << endl << endl;
        cout << "1. Read picture data from a file" << endl;
        cout << "2. Complete search" << endl;
        cout << "3. Partial search" << endl;
        cout << "4. Sort by field" << endl;
        cout << "5. Add a picture" << endl;
        cout << "6. Remove a picture" << endl;
        cout << "7. Modify picture" << endl;
        cout << "8. Save picture data" << endl;
        cout << "9. Display picture data" << endl;
        cout << "10. Back" << endl;
        cout << "11. Exit program" << endl;
        cout << "Enter your choice (1 - 11): " << endl;

        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw 1;
        }

        return choice;
    }
    catch (int error)
    {
        cout << "Make sure to enter an integer." << endl << endl;

        return displayPicture();
    }
}

//Navigates picture menu based on user input
int pictureMenu(PicTree* pictures) {
    string temp;
    int choice = 0;
    bool done = false;

    while (!done)
    {
        choice = displayPicture();

        switch (choice) {
            case 1:
                cout << "Give name of the csv file to read in (i.e. 'name.csv')" << endl;
                cin >> temp;
                cout << endl;

                pictures->buildTreeFromFile(temp);

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();
                break;
            case 2:
                if (pictureCompMenu(pictures) == 1)
                {
                    return 1;
                }
                break;
            case 3:
                if (picturePartMenu(pictures) == 1)
                {
                    return 1;
                }
                break;
            case 4:
                if (pictureSortMenu(pictures) == 1)
                {
                    return 1;
                }
                break;
            case 5:
                addPicture(pictures);
                break;
            case 6:
                removePicture(pictures);
                break;
            case 7:
                pictureModify(pictures);
                break;
            case 8:
                cout << "Give name of the csv file to save the picture data to (i.e. 'name.csv')" << endl;
                cin >> temp;
                cout << endl;

                //picture tree function that saves actor data to a csv file, use temp as file name
                pictures->saveTreeToFile(temp);

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            case 9:
                cout << endl;
                cout.width(20);
                cout << left << "Name";
                cout.width(15);
                cout << left << "Year";
                cout.width(15);
                cout << left << "Nominations";
                cout.width(15);
                cout << left << "Rating";
                cout.width(15);
                cout << left << "Duration";
                cout.width(15);
                cout << left << "Genre1";
                cout.width(15);
                cout << left << "Genre2";
                cout.width(15);
                cout << left << "Release";
                cout.width(15);
                cout << left << "Metacritic";
                cout.width(15);
                cout << left << "Synopsis";

                cout << endl << endl;
                pictures->displayTree();
                cout << endl << endl;

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();
                break;
            case 10:
                done = true;
                break;
            case 11:
                return 1;
            default:
                cout << choice << " is not a valid option. Try again" << endl << endl;
        }
    }
    return 0;
}

//This segment is entered when option 2 from picture menu is selected.
//---------Picture Complete Search Menu---------------

//Displays the actor complete search menu and reads in user choice
int pictureCompDisplay()
{
    try
    {
        int choice = 0;

        cout << "Picture Complete Search" << endl;
        cout << "-----------------------" << endl << endl;
        cout << "Choose a field to search: " << endl;
        cout << "1. Name" << endl;
        cout << "2. Year" << endl;
        cout << "3. Nominations" << endl;
        cout << "4. Rating" << endl;
        cout << "5. Duration" << endl;
        cout << "6. Genre 1" << endl;
        cout << "7. Genre 2" << endl;
        cout << "8. Release" << endl;
        cout << "9. Metacritic" << endl;
        cout << "10. Back" << endl;
        cout << "11. Exit program" << endl;
        cout << "Enter your choice (1 - 11): " << endl;

        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw 1;
        }

        return choice;
    }
    catch (int error)
    {
        cout << "Make sure to enter an integer." << endl << endl;

        return pictureCompDisplay();
    }
}

//Navigates picture complete search menu based on user input
int pictureCompMenu(PicTree* pictures)
{
    int tempInt;
    double rating;
    string temp;

    int choice = 0;
    bool done = false;

    while (!done)
    {
        choice = pictureCompDisplay();

        switch (choice)
        {
            case 1:
                cout << "Enter a film name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;

                //picture tree function that executes a complete search of film name
                //picture name to be searched held in temp variable
                pictures->completeNameSearch(temp);
                pictures->displaySearchResults();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();

                break;
            case 2:
                try
                {
                    cout << "Enter a year" << endl;
                    cin >> tempInt;
                    cout << endl;


                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        throw 1;
                    }

                    //picture tree function that executes a complete search of year
                    //year to be searched held in tempInt variable
                    pictures->completeYearSearch(tempInt);
                    pictures->displaySearchResults();

                    cout << "Press enter to return to menu" << endl << endl;
                    cin.clear();
                    cin.get();
                    cin.ignore();
                }

                catch (int error)
                {
                    cout << "Make sure to enter an integer." << endl << endl;

                    return pictureCompMenu(pictures);
                }

                break;

            case 3:
                try
                {
                    cout << "Enter number of nominations" << endl;
                    cin >> tempInt;
                    cout << endl;


                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        throw 1;
                    }

                    //picture tree function that executes a complete search of number of nominations
                    //nominations to be searched held in tempInt variable
                    pictures->completeNomSearch(tempInt);
                    pictures->displaySearchResults();

                    cout << "Press enter to return to menu" << endl << endl;
                    cin.clear();
                    cin.get();
                    cin.ignore();
                }

                catch (int error)
                {
                    cout << "Make sure to enter an integer." << endl << endl;

                    return pictureCompMenu(pictures);
                }

                break;

            case 4:
                try
                {
                    cout << "Enter a rating (i.e. '8.1'): " << endl;
                    cin >> rating;
                    cout << endl;


                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        throw 1;
                    }

                    //picture tree function that executes a complete search of rating
                    //rating to be searched held in rating variable
                    pictures->completeRatingSearch(rating);
                    pictures->displaySearchResults();

                    cout << "Press enter to return to menu" << endl << endl;
                    cin.clear();
                    cin.get();
                    cin.ignore();
                }

                catch (int error)
                {
                    cout << "Make sure to enter a floating point number (i.e. '8.1')." << endl << endl;

                    return pictureCompMenu(pictures);
                }

                break;

            case 5:
                try
                {
                    cout << "Enter duration of film (i.e. '120'): " << endl;
                    cin >> tempInt;
                    cout << endl;


                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        throw 1;
                    }

                    //picture tree function that executes a complete search of duration of film
                    //duration to be searched held in tempInt variable
                    pictures->completeDurSearch(tempInt);
                    pictures->displaySearchResults();

                    cout << "Press enter to return to menu" << endl << endl;
                    cin.clear();
                    cin.get();
                    cin.ignore();
                }

                catch (int error)
                {
                    cout << "Make sure to enter an integer." << endl << endl;

                    return pictureCompMenu(pictures);
                }

                break;
            case 6:
                cout << "Enter a genre name for genre 1: " << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;

                //picture tree function that executes a complete search of genre 1
                //picture genre1 to be searched held in temp variable
                pictures->completeG1Search(temp);
                pictures->displaySearchResults();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();

                break;

            case 7:
                cout << "Enter a genre name for genre 2: " << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;

                //picture tree function that executes a complete search of genre 2
                //picture genre2 to be searched held in temp variable
                pictures->completeG2Search(temp);
                pictures->displaySearchResults();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();

                break;
            case 8:
                cout << "Enter a release month: " << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;

                //picture tree function that executes a complete search of the release month
                //picture release month to be searched held in temp variable
                pictures->completeRelSearch(temp);
                pictures->displaySearchResults();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();

                break;
            case 9:
                try
                {
                    cout << "Enter metacritic score of film (i.e. '68'): " << endl;
                    cin >> tempInt;
                    cout << endl;


                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        throw 1;
                    }

                    //picture tree function that executes a complete search of metacritic score of film
                    //metacritic score to be searched held in tempInt variable
                    pictures->completeMetaSearch(tempInt);
                    pictures->displaySearchResults();

                    cout << "Press enter to return to menu" << endl << endl;
                    cin.clear();
                    cin.get();
                    cin.ignore();
                }

                catch (int error)
                {
                    cout << "Make sure to enter an integer." << endl << endl;

                    return pictureCompMenu(pictures);
                }

                break;
            case 10:
                done = true;
                break;
            case 11:
                return 1;
            default:
                cout << choice << " is not a valid option. Try again" << endl << endl;
        }
    }
    return 0;
}

//This segment is entered when option 3 from picture menu is selected.
//---------Picture Partial Search Menu---------------

//Displays the actor partial search menu and reads in user choice
int picturePartDisplay()
{
    try
    {
        int choice = 0;

        cout << "Picture Partial Search" << endl;
        cout << "-----------------------" << endl << endl;
        cout << "Choose a field to search: " << endl;
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

        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw 1;
        }

        return choice;
    }
    catch (int error)
    {
        cout << "Make sure to enter an integer." << endl << endl;

        return pictureCompDisplay();
    }
}

//Navigates picture partial search menu based on user input
int picturePartMenu(PicTree* pictures)
{
    int tempInt;
    double rating;
    string temp;

    int choice = 0;
    bool done = false;

    while (!done)
    {
        choice = picturePartDisplay();

        switch (choice)
        {
            case 1:
                cout << "Enter a partial film name" << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;

                //picture tree function that executes a partial search of film name
                //picture name to be searched held in temp variable
                pictures->partialNameSearch(temp);
                pictures->displaySearchResults();
                cout << endl;

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();

                break;

            case 2:
                try
                {
                    cout << "Enter a year" << endl;
                    cin >> tempInt;
                    cout << endl;


                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        throw 1;
                    }

                    //picture tree function that executes a partial search of year
                    //year to be searched held in tempInt variable
                    pictures->partialYearSearch(tempInt);
                    pictures->displaySearchResults();

                    cout << "Press enter to return to menu" << endl << endl;
                    cin.clear();
                    cin.get();
                    cin.ignore();
                }

                catch (int error)
                {
                    cout << "Make sure to enter an integer." << endl << endl;

                    return picturePartMenu(pictures);
                }

                break;

            case 3:
                try
                {
                    cout << "Enter number of nominations" << endl;
                    cin >> tempInt;
                    cout << endl;


                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        throw 1;
                    }

                    //picture tree function that executes a partial search of number of nominations
                    //nominations to be searched held in tempInt variable
                    pictures->partialNomSearch(tempInt);
                    pictures->displaySearchResults();

                    cout << "Press enter to return to menu" << endl << endl;
                    cin.clear();
                    cin.get();
                    cin.ignore();
                }

                catch (int error)
                {
                    cout << "Make sure to enter an integer." << endl << endl;

                    return picturePartMenu(pictures);
                }

                break;

            case 4:
                try
                {
                    cout << "Enter a rating (i.e. '8.1'): " << endl;
                    cin >> rating;
                    cout << endl;


                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        throw 1;
                    }

                    //picture tree function that executes a partial search of rating
                    //rating to be searched held in rating variable
                    pictures->partialRatingSearch(rating);
                    pictures->displaySearchResults();

                    cout << "Press enter to return to menu" << endl << endl;
                    cin.clear();
                    cin.get();
                    cin.ignore();
                }

                catch (int error)
                {
                    cout << "Make sure to enter a floating point number (i.e. '8.1')." << endl << endl;

                    return picturePartMenu(pictures);
                }

                break;

            case 5:
                try
                {
                    cout << "Enter duration of film (i.e. '120'): " << endl;
                    cin >> tempInt;
                    cout << endl;


                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        throw 1;
                    }

                    //picture tree function that executes a partial search of duration of film
                    //duration to be searched held in tempInt variable
                    pictures->partialDurSearch(tempInt);
                    pictures->displaySearchResults();

                    cout << "Press enter to return to menu" << endl << endl;
                    cin.clear();
                    cin.get();
                    cin.ignore();
                }

                catch (int error)
                {
                    cout << "Make sure to enter an integer." << endl << endl;

                    return picturePartMenu(pictures);
                }

                break;
            case 6:
                cout << "Enter a genre name for genre 1: " << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;

                //picture tree function that executes a partial search of genre 1
                //picture genre1 to be searched held in temp variable
                pictures->partialG1Search(temp);
                pictures->displaySearchResults();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();

                break;

            case 7:
                cout << "Enter a genre name for genre 2: " << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;

                //picture tree function that executes a partial search of genre 2
                //picture genre2 to be searched held in temp variable
                pictures->partialG2Search(temp);
                pictures->displaySearchResults();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();

                break;
            case 8:
                cout << "Enter a release month: " << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;

                //picture tree function that executes a partial search of the release month
                //picture release month to be searched held in temp variable
                pictures->partialRelSearch(temp);
                pictures->displaySearchResults();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();

                break;
            case 9:
                try
                {
                    cout << "Enter metacritic score of film (i.e. '68'): " << endl;
                    cin >> tempInt;
                    cout << endl;


                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        throw 1;
                    }

                    //picture tree function that executes a partial search of metacritic score of film
                    //metacritic score to be searched held in tempInt variable
                    pictures->partialMetaSearch(tempInt);
                    pictures->displaySearchResults();

                    cout << "Press enter to return to menu" << endl << endl;
                    cin.clear();
                    cin.get();
                    cin.ignore();
                }

                catch (int error)
                {
                    cout << "Make sure to enter an integer." << endl << endl;

                    return picturePartMenu(pictures);
                }

                break;

            case 10:
                cout << "Enter a partial synopsis: " << endl;

                cin.ignore();
                getline(cin, temp);
                cout << endl;

                //picture tree function that executes a partial search of the synopsis
                //picture synopsis to be searched held in temp variable
                pictures->partialSynSearch(temp);
                pictures->displaySearchResults();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();

                break;
            case 11:
                done = true;
                break;
            case 12:
                return 1;
            default:
                cout << choice << " is not a valid option. Try again" << endl << endl;
        }
    }
    return 0;
}

//This segment is entered when option 4 from picture menu is selected.
//---------Picture Sort Menu---------------

//Displays the picture sort menu and reads in user choice
int pictureSortDisplay()
{
    try
    {
        int choice = 0;

        cout << "Picture Sort" << endl;
        cout << "----------" << endl << endl;
        cout << "Choose a field to sort by: " << endl;
        cout << "1. Name" << endl;
        cout << "2. Year" << endl;
        cout << "3. Nominations" << endl;
        cout << "4. Rating" << endl;
        cout << "5. Duration" << endl;
        cout << "6. Genre 1" << endl;
        cout << "7. Genre 2" << endl;
        cout << "8. Release" << endl;
        cout << "9. Metacritic" << endl;
        cout << "10. Back" << endl;
        cout << "11. Exit program" << endl;
        cout << "Enter your choice (1 - 11): " << endl;

        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw 1;
        }

        return choice;
    }
    catch (int error)
    {
        cout << "Make sure to enter an integer." << endl << endl;

        return pictureSortDisplay();
    }
}

//Navigates picture sort menu based on user input
int pictureSortMenu(PicTree* pictures)
{
    int choice = 0;
    bool done = false;

    while (!done)
    {
        choice = pictureSortDisplay();

        switch (choice)
        {
            case 1:
                pictures->sortByName();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;

            case 2:
                pictures->sortByYear();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            case 3:
                pictures->sortByNom();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            case 4:
                pictures->sortByRating();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            case 5:
                pictures->sortByDur();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            case 6:
                pictures->sortByG1();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            case 7:
                pictures->sortByG2();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            case 8:
                pictures->sortByRel();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            case 9:
                pictures->sortByMeta();

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            case 10:
                done = true;
                break;
            case 11:
                return 1;
            default:
                cout << choice << " is not a valid option. Try again" << endl << endl;
        }
    }
    return 0;
}

//This segment is entered when option 5 from picture menu is selected.
//---------Add picture---------------
void addPicture(PicTree* pictures)
{
    string name;
    int year;
    int noms;
    double rating;
    int duration;
    string genre1;
    string genre2;
    string release;
    int metacritic;
    string synopsis;

    cout << "Add Picture" << endl;
    cout << "-----------" << endl << endl;

    //recieves film name info
    cout << "Enter film name: ";
    cin.ignore();
    getline(cin, name);

    //Recieves year info from user, ensures valid type
    bool isInt = false;
    while (!isInt)
    {
        try
        {
            cout << "Enter year: ";
            cin >> year;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                throw 1;
            }

            isInt = true;
        }
        catch (int error)
        {
            cout << "Make sure to enter an integer." << endl << endl;
        }
    }

    //Recieves nomination info from user, ensures valid type
    isInt = false;
    while (!isInt)
    {
        try
        {
            cout << "Enter number of nominations: ";
            cin >> noms;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                throw 1;
            }

            isInt = true;
        }
        catch (int error)
        {
            cout << "Make sure to enter an integer." << endl << endl;
        }
    }

    //Recieves rating info from user, ensures valid type
    bool isDouble = false;
    while (!isDouble)
    {
        try
        {
            cout << "Enter rating: ";
            cin >> rating;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                throw 1;
            }

            isDouble = true;
        }
        catch (int error)
        {
            cout << "Make sure to enter a double (i.e. '8.1')." << endl << endl;
        }
    }

    //Recieves duration info from user, ensures valid type
    isInt = false;
    while (!isInt)
    {
        try
        {
            cout << "Enter duration: ";
            cin >> duration;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                throw 1;
            }

            isInt = true;
        }
        catch (int error)
        {
            cout << "Make sure to enter an integer." << endl << endl;
        }
    }

    //recieves genre1 info
    cout << "Enter genre 1 name: ";
    cin.ignore();
    getline(cin, genre1);

    //recieves genre2 info
    cout << "Enter genre 2 name: ";
    getline(cin, genre2);


    //recieves release info
    cout << "Enter release month: ";
    getline(cin, release);

    //Recieves metacritic info from user, ensures valid type
    isInt = false;
    while (!isInt)
    {
        try
        {
            cout << "Enter metacritic score: ";
            cin >> metacritic;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                throw 1;
            }

            isInt = true;
        }
        catch (int error)
        {
            cout << "Make sure to enter an integer." << endl << endl;
        }
    }

    //recieves synopsis info
    cout << "Enter synopsis: ";
    cin.ignore();
    getline(cin, synopsis);

    cout << endl;

    //show added picture
    cout << "Added picture:" << endl;
    cout.width(20);
    cout << left << "Name";
    cout.width(15);
    cout << left << "Year";
    cout.width(15);
    cout << left << "Nominations";
    cout.width(15);
    cout << left << "Rating";
    cout.width(15);
    cout << left << "Duration";
    cout.width(15);
    cout << left << "Genre 1";
    cout.width(15);
    cout << left << "Genre 2";
    cout.width(15);
    cout << left << "Release";
    cout.width(15);
    cout << left << "Metacritic";
    cout.width(15);
    cout << left << "Synopsis" << endl;

    cout.width(20);
    cout << left << name.substr(0, 19);
    cout.width(15);
    cout << left << year;
    cout.width(15);
    cout << left << noms;
    cout.width(15);
    cout << left << rating;
    cout.width(15);
    cout << left << duration;
    cout.width(15);
    cout << left << genre1.substr(0,14);
    cout.width(15);
    cout << left << genre2.substr(0,14);
    cout.width(15);
    cout << left << release.substr(0,14);
    cout.width(15);
    cout << left << metacritic;
    cout.width(15);
    cout << left << synopsis.substr(0,72) << endl;

    //picture tree function that creates new node using name, year, noms, rating, duration, genre1, genre2, release, metacritic, and synopsis variables
    pictures->addToTree(name, year, noms, rating, duration, genre1, genre2, release, metacritic, synopsis);
    cout << endl;

    cout << "Press enter to return to menu" << endl << endl;
    cin.ignore();
}

//This segment is entered when option 6 from picture menu is selected.
//---------Remove picture---------------
int removePicture(PicTree* pictures)
{
    string name;
    int choice;
    int range;

    cout << "Remove Picture" << endl;
    cout << "--------------" << endl << endl;

    cout << "Enter picture name to remove: " << endl;

    cin.ignore();
    getline(cin, name);
    cout << endl;

    //picture tree function that searches for picture name and displays all matches in menu format
    pictures->completeNameSearch(name);
    range = pictures->displaySearchResults();

    if (range == 0)
    {
        cout << "Press enter to return to menu" << endl << endl;
        cin.ignore();

        return 1;
    }
    try
    {
        cout << range + 1 << ". Back" << endl;
        cout << endl;

        cout << "Enter a number to choose a record to remove or to return to menu." << endl;
        cin >> choice;
        cout << endl;


        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw 1;
        }

        if (choice == range + 1)
        {
            return 1;
        }

        //picture tree function that executes a complete search of year
        //year to be searched held in tempInt variable

        //picture tree function that allows for choosing/removing one of displayed  options
        if (pictures->removeRecordSearch(choice))
        {
            cout << "Record removed successfully." << endl << endl;
        }
        else
        {
            throw 1;
        }

        cout << "Press enter to return to menu" << endl << endl;
        cin.clear();
        cin.get();
        cin.ignore();

        return 1;
    }

    catch (int error)
    {
        cout << "Make sure to enter an integer within range." << endl << endl;

        return removePicture(pictures);
    }

    cout << "Press enter to return to menu" << endl << endl;
    cin.ignore();
}

//This segment is entered when option 7 from picture menu is selected.
//---------Picture Modify Menu---------------
int pictureModify(PicTree* pictures)
{
    string name;
    int choice;
    int range;

    cout << "Enter picture name to modify: " << endl;
    cin.ignore();
    getline(cin, name);
    cout << endl;

    //picture tree function that searches for picture name and displays all matches in menu format
    pictures->completeNameSearch(name);
    range = pictures->displaySearchResults();

    if (range == 0)
    {
        cout << "Press enter to return to menu" << endl << endl;
        cin.ignore();

        return 1;
    }
    try
    {
        cout << range + 1 << ". Back" << endl;
        cout << endl;

        cout << "Enter a number to choose a record to modify or to return to menu." << endl;
        cin >> choice;
        cout << endl;


        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw 1;
        }

        if (choice == range + 1)
        {
            return 1;
        }

        //picture tree function that allows for choosing/modifying one of displayed  options
        pictures->modifyRecordSearch(choice);

        cout << "Press enter to return to menu" << endl << endl;
        cin.clear();
        cin.ignore();

        return 1;
    }

    catch (int error)
    {
        cout << "Make sure to enter an integer within range." << endl << endl;

        return pictureModify(pictures);
    }

    cout << "Press enter to return to menu" << endl << endl;
    cin.ignore();

    return 0;
}

//This segment is entered when option 3 from main menu is selected.
//---------Nomination Menu---------------

//Displays the nomination menu and reads in user choice
int displayNomination()
{
    try
    {
        int choice = 0;

        cout << "Nominations" << endl;
        cout << "------" << endl << endl;
        cout << "1. Read nomination data from a file" << endl;
        cout << "2. Complete search" << endl;
        cout << "3. Partial search" << endl;
        cout << "4. Sort by field" << endl;
        cout << "5. Add an nomination" << endl;
        cout << "6. Remove a nomination" << endl;
        cout << "7. Modify nomination" << endl;
        cout << "8. Save nomination data" << endl;
        cout << "9. Display nomination statistics" << endl;
        cout << "10. Back" << endl;
        cout << "11. Exit program" << endl;
        cout << "Enter your choice (1 - 10): " << endl;

        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            throw 1;
        }

        return choice;
    }
    catch (int error)
    {
        cout << "Make sure to enter an integer." << endl << endl;

        return displayActor();
    }
}


//Navigates nomination menu based on user input
int nominationMenu() {
    string temp;
    int choice = 0;
    int sortChoice = 0;
    bool check;
    bool done = false;
    ActTree nominations;

    while (!done)
    {
        choice = displayNomination();

        switch (choice) {
            case 1: {
                cout << "Give name of the csv file to read in (i.e. 'name.csv')" << endl;
                cin >> temp;
                cout << endl;


                //nomination tree function that reads in a csv file, use temp as file name
                nominations.buildTreeFromFile(temp);

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();
                break;
            }
            case 2:
                if (actorCompMenu(nominations) == 1)
                {
                    return 1;
                }
                break;
            case 3:
                if (actorPartMenu(nominations) == 1)
                {
                    return 1;
                }
                break;
            case 4:
                if (actorSortMenu(nominations) == 1)
                {
                    return 1;
                }
                break;
            case 5:
                addActor(nominations);
                break;
            case 6:
                removeActor(nominations);
                break;
            case 7:
                if (actorModify(nominations) == 1)
                {
                    return 1;
                }
                break;
            case 8:
                cout << "Give name of the csv file to save the nomination data to (i.e. 'name.csv')" << endl;
                cin >> temp;
                cout << endl;

                do {
                    cout << "Choose the field the file will be sorted by:" << endl;
                    cout << "1. Year" << endl;
                    cout << "2. Award" << endl;
                    cout << "3. Winner" << endl;
                    cout << "4. Name" << endl;
                    cout << "5. Film" << endl;
                    cout << "Enter option (1-5):";

                    cin >> sortChoice;
                    if (cin.fail())
                    {
                        cout << "Be sure to enter a number 1-5."<< endl;
                        check = false;
                    }
                    else if ((sortChoice < 1) || (sortChoice > 5)){
                        cout << "Be sure to enter a number 1-5." << endl;
                        check = false;
                    }
                    else
                    {
                        check = true;
                    }
                }while (!check);


                //actor tree function that saves actor data to a csv file, use temp as file name
                nominations.writeToFile(temp, sortChoice);

                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();


                break;

            case 9:{
                nominations.calcStatistics();


                cout << "Press enter to return to menu" << endl << endl;
                cin.clear();
                cin.get();
                cin.ignore();

                break;
            }

            case 10:
                done = true;
                break;
            case 11:
                return 1;
            default:
                cout << choice << " is not a valid option. Try again" << endl << endl;
        }
    }
    return 0;
}
