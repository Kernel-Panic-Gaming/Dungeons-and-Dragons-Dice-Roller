* Philip Fairchild
 * 6/21/2020
 * Terminal Dice
 * This program will roll various types of dice for Dungeons & Dragons
 * There are inputs for Character Name, Race and Class
 * Outputs are Character Name, Race, Class as well as dice rolls
 * To use this program you enter Name, Race and class then pick
 * various roll options from the menu system.
 */





#include <iostream>
#include <string>
#include <cstdlib>
#include <zconf.h>
#include <iomanip>
#include <ctime>

using namespace std;
int main()

{

    string characterName = "",
            characterClass,
            characterRace;


    cout << "████████╗███████╗██████╗ ███╗   ███╗██╗███╗   ██╗ █████╗ ██╗         ██████╗ ██╗ ██████╗███████╗\n"
         << "╚══██╔══╝██╔════╝██╔══██╗████╗ ████║██║████╗  ██║██╔══██╗██║         ██╔══██╗██║██╔════╝██╔════╝\n"
         << "   ██║   █████╗  ██████╔╝██╔████╔██║██║██╔██╗ ██║███████║██║         ██║  ██║██║██║     █████╗\n"
         << "   ██║   ██╔══╝  ██╔══██╗██║╚██╔╝██║██║██║╚██╗██║██╔══██║██║         ██║  ██║██║██║     ██╔══╝\n"
         << "   ██║   ███████╗██║  ██║██║ ╚═╝ ██║██║██║ ╚████║██║  ██║███████╗    ██████╔╝██║╚██████╗███████╗\n"
         << "   ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝    ╚═════╝ ╚═╝ ╚═════╝╚══════╝\n";

    sleep(1);

    cout << "A Dungeons and Dragons Dice Roller created by Philip Fairchild \n\n\n";
    sleep(1);

    // This is where you will enter you name class and race

    string contChoice;
    string mainMenu;
    bool run = true;
    while (run)
    {
        cout << "Welcome adventurer, what is your name? "; getline(cin, characterName); cout << "\n";

        cout << "Enter your class: "; getline(cin, characterClass); cout << "\n";

        cout << "Enter your race: "; getline(cin, characterRace); cout << "\n";

        cout << "Is this information correct? \n\n";

        cout << "Character name: " << characterName; cout << " \n";

        cout << "Character class: " << characterClass; cout << " \n";

        cout << "Character race: " << characterRace; cout << "\n";



        cout << "Type Yes to continue No to re-enter information . . . "; cin >> contChoice; cout << "\n";
        if (contChoice == "Yes" || contChoice == "yes")
        {
            run = false;
        }
        else if(contChoice == "No" || contChoice == "no")
        {
            run = true;
            cin.ignore();
        }

    }

    //Variables and constants for Roll Menu
    int rollChoice;
    const int ROLL_INITIATIVE = 1,
              ABILITY_CHECK = 2,
              ATTACK_ROLL = 3,
              DAMAGE_ROLL = 4,
              QUIT_THE_PROGRAM = 5;

    do
    {
        //This is the main menu and you get a choice of dice rolls

        cout << "\t\tDice Roll Menu\n"
             << "1. Roll for Initiative\n"
             << "2. Roll for Ability Check\n"
             << "3. Roll for Attack\n"
             << "4. Roll for Damage\n"
             << "5. Quit the Program\n\n"
             << "Enter your choice: ";
        cin >> rollChoice;

        //Validate menu selection
        while (rollChoice < ROLL_INITIATIVE || rollChoice > QUIT_THE_PROGRAM)
        {
            cout << "Please enter a valid menu  choice: ";
            cin >> rollChoice;
        }

        cout << fixed << showpoint << setprecision(2);
        //Dice constants and variables for d20

        const int MIN_VALUE20 = 1,
                MAX_VALUE20 = 20;

        int d4,
                d6,
                d8,
                d10,
                d12,
                d20;

    //Constants and variables for weapon rolls
        const int MIN_VALUE4 = 1,
                MAX_VALUE4 = 4,
                MIN_VALUE6 = 1,
                MAX_VALUE6 = 6,
                MIN_VALUE8 = 1,
                MAX_VALUE8 = 8,
                MIN_VALUE10 = 1,
                MAX_VALUE10 = 10,
                MIN_VALUE12 = 1,
                MAX_VALUE12 = 12;

        int diceChoice;
        const int DIE_4 = 1,
                DIE_6 = 2,
                DIE_8 = 3,
                DIE_10 = 4,
                DIE_12 = 5,
                DICE_MENU = 6;



        //Time system for dice rolls
        unsigned seed = time(0);
        srand(seed);


        //The start of the switch statement for menu

        switch(rollChoice)
        {

            case ROLL_INITIATIVE : cout << "Rolling for initiative\n\n";
                d20 = (rand() % (MAX_VALUE20 - MIN_VALUE20 + 1)) + MIN_VALUE20;
                cout << d20; cout << "\n\n";
                cout << "Press enter to return to main menu\n\n";
                cin.ignore(); cin.get();
                break;

            case ABILITY_CHECK : cout << "Rolling for ability check.\n\n";
                d20 = (rand() % (MAX_VALUE20 - MIN_VALUE20 + 1)) + MIN_VALUE20;
                cout << d20; cout << "\n\n";
                cout << "Press enter to return to main menu\n\n";
                cin.ignore(); cin.get();
                break;

            case ATTACK_ROLL : cout << "Rolling for attack.\n\n";
                d20 = (rand() % (MAX_VALUE20 - MIN_VALUE20 + 1)) + MIN_VALUE20;
                cout << d20; cout << "\n\n";
                if(d20 == 20)
                {
                    cout << "You got a critical hit for "; cout << "\n";
                    cout << "Press enter to return to main menu\n\n";
                    cin.ignore();
                    cin.get();

                }
                else if (d20 < 20)
                {
                    cout << "Press enter to return to main menu\n\n";
                    cin.ignore();
                    cin.get();
                }
                break;
                //This is where the sub menu starts for damage dice rolls
                do
                {
                    case DAMAGE_ROLL : cout << "\t\t Damage Roll Menu \n\n"
                                            << "1. Roll 4 sided die\n"
                                            << "2. Roll 6 sided die\n"
                                            << "3. Roll 8 sided die\n"
                                            << "4. Roll 8 sided die\n"
                                            << "5. Roll 12 sided die\n"
                                            << "Enter your choice: ";
                    cin >> diceChoice;

                    //Validate menu selection
                    while(diceChoice < DIE_4 || diceChoice > DICE_MENU || !diceChoice)
                    {
                        cout << "Please enter a valid menu  choice: ";
                        cin >> diceChoice;
                    }
                    cout << fixed << showpoint << setprecision(2);

                    switch(diceChoice)
                    {
                        case DIE_4 : cout << "Rolling d4 for damage\n\n";
                            d4 = (rand() % (MAX_VALUE4 - MIN_VALUE4 + 1)) + MIN_VALUE4,
                            cout << characterName; cout << " the "; cout << characterRace << " "; cout << characterClass; cout << " hit for "; cout << d4; cout << "\n\n";
                            cout << "Press any key to return to main menu\n\n";
                            cin.ignore(); cin.get();
                            break;

                        case DIE_6 : cout << "Rolling d6 for damage\n\n";
                            d6 = (rand() % (MAX_VALUE6 - MIN_VALUE6 + 1)) + MIN_VALUE6,
                            cout << characterName; cout << " the "; cout << characterRace << " "; cout << characterClass; cout << " hit for "; cout << d6; cout << "\n\n";
                            cout << "Press any key to return to main menu\n\n";
                            cin.ignore(); cin.get();
                            break;

                        case DIE_8 : cout << "Rolling d8 for damage\n\n";
                            d8 = (rand() % (MAX_VALUE8 - MIN_VALUE8 + 1)) + MIN_VALUE8,
                            cout << characterName; cout << " the "; cout << characterRace << " "; cout << characterClass; cout << " hit for "; cout << d8; cout << "\n\n";
                            cout << "Press any key to return to main menu\n\n";
                            cin.ignore(); cin.get();
                            break;

                        case DIE_10 : cout << "Rolling d10 for damage\n\n";
                            d10 = (rand() % (MAX_VALUE10 - MIN_VALUE10 + 1)) + MIN_VALUE10,
                            cout << characterName; cout << " the "; cout << characterRace << " "; cout << characterClass; cout << " hit for "; cout << d10; cout << "\n\n";
                            cout << "Press any key to return to main menu\n\n";
                            cin.ignore(); cin.get();
                            break;

                        case DIE_12 : cout << "Rolling d12 for damage\n\n";
                            d12 = (rand() % (MAX_VALUE12 - MIN_VALUE12 + 1)) + MIN_VALUE12,
                            cout << characterName; cout << " the "; cout << characterRace << " "; cout << characterClass; cout << " hit for "; cout << d12; cout << "\n\n";
                            cout << "Press any key to return to main menu\n\n";
                            cin.ignore(); cin.get();
                            break;



                    }

                    break;

                }
                while (diceChoice != DICE_MENU);

                break;


        }


    }






    while (rollChoice != QUIT_THE_PROGRAM);

    return 0;
}

        if (contChoice == "Yes" || contChoice == "yes")
        {
            run = false;
        }
        else if(contChoice == "No" || contChoice == "no")
        {
            run = true;
            cin.ignore();
        }
    }

    //Variables and constants for Roll Menu
    int rollChoice;
    const int ROLL_INITIATIVE = 1,
              ABILITY_CHECK = 2,
              ATTACK_ROLL = 3,
              DAMAGE_ROLL = 4,
              QUIT_THE_PROGRAM = 5;

    do
        {
            //Display the menu and get a choice of dice rolls

            cout << "\t\tDice Roll Menu\n"
                 << "Certainty of death. Small chance of success. What are we waiting for?\n\n"
                 << "1. Roll for Initiative\n"
                 << "2. Roll for Ability Check\n"
                 << "3. Roll for Attack\n"
                 << "4. Roll for Damage\n"
                 << "5. Quit the Program\n\n"
                 << "Enter your choice: ";
            cin >> rollChoice;

            //Validate menu selection
            while (rollChoice < ROLL_INITIATIVE || rollChoice > QUIT_THE_PROGRAM)
            {
                cout << "Please enter a valid menu  choice: ";
                cin >> rollChoice;
            }

            cout << fixed << showpoint << setprecision(2);
//Dice constants and variables for d20

        const int MIN_VALUE20 = 1,
                  MAX_VALUE20 = 20;

        int d4,
            d6,
            d8,
            d10,
            d12,
            d20;

//Constants and variables for weapon rolls
        const int MIN_VALUE4 = 1,
                  MAX_VALUE4 = 4,
                  MIN_VALUE6 = 1,
                  MAX_VALUE6 = 6,
                  MIN_VALUE8 = 1,
                  MAX_VALUE8 = 8,
                  MIN_VALUE10 = 1,
                  MAX_VALUE10 = 10,
                  MIN_VALUE12 = 1,
                  MAX_VALUE12 = 12;

        int diceChoice;
        const int DIE_4 = 1,
                  DIE_6 = 2,
                  DIE_8 = 3,
                  DIE_10 = 4,
                  DIE_12 = 5,
                  DICE_MENU = 6;


        const int D_4 = (rand() % (MAX_VALUE4 - MIN_VALUE4 + 1)) + MIN_VALUE4,
                  D_6 = (rand() % (MAX_VALUE6 - MIN_VALUE6 + 1)) + MIN_VALUE6,
                  D_8 = (rand() % (MAX_VALUE8 - MIN_VALUE8 + 1)) + MIN_VALUE8,
                  D_10 = (rand() % (MAX_VALUE10 - MIN_VALUE10 + 1)) + MIN_VALUE10,
                  D_12 = (rand() % (MAX_VALUE12 - MIN_VALUE12 + 1)) + MIN_VALUE12;

        //Time system for dice rolls
        unsigned seed = time(0);
        srand(seed);

        switch(rollChoice)
        {

            case ROLL_INITIATIVE : cout << "Rolling for initiative\n\n";
                sleep(.5);
                d20 = (rand() % (MAX_VALUE20 - MIN_VALUE20 + 1)) + MIN_VALUE20;
                cout << d20; cout << "\n\n";
                cout << "Press enter to return to main menu\n\n";
                cin.ignore(); cin.get();
                break;

            case ABILITY_CHECK : cout << "Rolling for ability check.\n\n";
                sleep(.5);
                d20 = (rand() % (MAX_VALUE20 - MIN_VALUE20 + 1)) + MIN_VALUE20;
                cout << d20; cout << "\n\n";
                cout << "Press enter to return to main menu\n\n";
                cin.ignore(); cin.get();
                break;

            case ATTACK_ROLL : cout << "Rolling for attack.\n\n";
                 sleep(.5);
                 d20 = (rand() % (MAX_VALUE20 - MIN_VALUE20 + 1)) + MIN_VALUE20;
                 cout << d20; cout << "\n\n";
                    if(d20 == 20)
                    {
                        cout << "You got a critical hit for "; cout << "\n";
                        cout << "Press enter to return to main menu\n\n";
                        cin.ignore();
                        cin.get();

                    }
                    else if (d20 < 20)
                    {
                        cout << "Press enter to return to main menu\n\n";
                        cin.ignore();
                        cin.get();
                    }
                        break;

                    do
                    {
                        case DAMAGE_ROLL : cout << "\t\t Damage Roll Menu \n\n"
                                              << "1. Roll 4 sided die\n"
                                              << "2. Roll 6 sided die\n"
                                              << "3. Roll 8 sided die\n"
                                              << "4. Roll 8 sided die\n"
                                              << "5. Roll 12 sided die\n"
                                              << "6. Go back to main menu\n"
                                              << "Enter your choice: ";
                        cin >> diceChoice;

                        //Validate menu selection
                        while(diceChoice < DIE_4 || diceChoice > (DIE_12))
                        {
                            cout << "Please enter a valid menu  choice: ";
                            cin >> diceChoice;
                        }
                        cout << fixed << showpoint << setprecision(2);

                        switch(diceChoice)
                        {
                            case DIE_4 : cout << "Rolling d4 for damage\n\n";
                                sleep(.5);
                                d4 = (rand() % (MAX_VALUE4 - MIN_VALUE4 + 1)) + MIN_VALUE4,
                                        cout << d4; cout << "\n\n";
                                        cout << "Press any key to return to main menu\n\n";
                                cin.ignore(); cin.get();
                                break;

                            case DIE_6 : cout << "Rolling d6 for damage\n\n";
                                sleep(.5);
                                d6 = (rand() % (MAX_VALUE6 - MIN_VALUE6 + 1)) + MIN_VALUE6,
                                        cout << d6; cout << "\n\n";
                                cout << "Press any key to return to main menu\n\n";
                                cin.ignore(); cin.get();
                                break;

                            case DIE_8 : cout << "Rolling d8 for damage\n\n";
                                sleep(.5);
                                d8 = (rand() % (MAX_VALUE8 - MIN_VALUE8 + 1)) + MIN_VALUE8,
                                        cout << d8; cout << "\n\n";
                                cout << "Press any key to return to main menu\n\n";
                                cin.ignore(); cin.get();
                                break;

                            case DIE_10 : cout << "Rolling d10 for damage\n\n";
                                sleep(.5);
                                d10 = (rand() % (MAX_VALUE10 - MIN_VALUE10 + 1)) + MIN_VALUE10,
                                        cout << d10; cout << "\n\n";
                                cout << "Press any key to return to main menu\n\n";
                                cin.ignore(); cin.get();
                                break;

                            case DIE_12 : cout << "Rolling d12 for damage\n\n";
                                sleep(.5);
                                d12 = (rand() % (MAX_VALUE12 - MIN_VALUE12 + 1)) + MIN_VALUE12,
                                        cout << d12; cout << "\n\n";
                                cout << "Press any key to return to main menu\n\n";
                                cin.ignore(); cin.get();

                                break;

                        }

                        break;

                    }

                    while (diceChoice != DICE_MENU);

                break;

            default: cout << "You did not enter a choice.\n";
        }


    }






while (rollChoice != QUIT_THE_PROGRAM);

    return 0;
}
