/* Rock Paper Scissors game with C++17 by Sergi Sampai
 * https://github.com/SergiSampai */
#include <iostream>
#include <cstdlib>

using namespace std;

string welcome();  // shows the instructions and gets user name
void showComputerChoice(char choice);  // shows computer choice with hand
void printRook();
void printPaper();
void printScissors();

int main()
{
    static const char HANDS[3]  = {'r', 'p', 's'};
    string user_name;
    int user_wins = 0, computer_wins = 0, random_index;
    char user_choice, computer_choice;

    user_name = welcome();  // gets user name

    do
    {
        // starts with 0 0
        cout << user_name << " points: " << user_wins << endl;
        cout << "Computer points: " << computer_wins << endl << endl;

        do
        {
            cout << "Choose (r) Rock, (p) Paper or (s) Scissors: ";
            cin >> user_choice;
        } while(user_choice != 'r' && user_choice != 'p' && user_choice != 's');  // until user choose correct

        // random number selection from 1 to 3
        random_index = rand() % 3;

        // depending on the random number it selects from the table
        computer_choice = HANDS[random_index];

        // prints computer choice
        showComputerChoice(HANDS[random_index]);

        // user wins
        if((user_choice == 'r' && computer_choice == 's') ||
           (user_choice == 'p' && computer_choice == 'r') ||
           (user_choice == 's' && computer_choice == 'p'))
        {
            cout << user_name << " wins the round!" << endl;
            user_wins++;
        }
        // computer wins
        else if((computer_choice == 'r' && user_choice == 's') ||
                (computer_choice == 'p' && user_choice == 'r') ||
                (computer_choice == 's' && user_choice == 'p'))
        {
            cout << "Computer wins wins the round!" << endl;
            computer_wins++;
        }
        // tie (same choice)
        else
            cout << "Tie!" << endl;

    } while(user_wins != 3 && computer_wins != 3);  // until someone wins 3 rounds

    cout <<  endl << user_name << " points: " << user_wins << endl;
    cout << "Computer points: " << computer_wins << endl << endl;

    if(user_wins == 3)
        cout << endl << user_name << " wins the match!";
    else
        cout << endl << "Computer wins the match!" << endl;

    return 0;
}

string welcome()
{
    string name;

    cout << "********************************************************************" << endl;
    cout << "Welcome to Rock Paper Scissors game!" << endl;
	cout << "Can you beat the computer?" << endl << endl;
	
    cout << "Please enter your name: ";
    cin >> name;

    cout << endl << "The rules are simple:" << endl;
    cout << "Rock crushes Scissors." << endl;
    cout << "Paper covers Rock." << endl;
    cout << "Scissors cut Paper." << endl << endl;
    cout << "You will play against computer, the first to reach 3 points wins the match." << endl << endl;
    cout << "Good luck!" << endl;
    cout << "********************************************************************" << endl << endl;

    return name;
}

void showComputerChoice(char choice)
{
    if(choice == 'r')
        printRook();
    else if(choice == 'p')
        printPaper();
    else
        printScissors();
}

void printRook()
{
    cout << "   _______" << endl;
    cout << "---'   ____)" << endl;
    cout << "       (_____)" << endl;
    cout << "       (_____)" << endl;
    cout << "       (____)" << endl;
    cout << "---.__(___)" << endl << endl;
}

void printPaper()
{
    cout << "     _______" << endl;
    cout << "---'    ____)____" << endl;
    cout << "           ______)" << endl;
    cout << "          _______)" << endl;
    cout << "         _______)" << endl;
    cout << "---.__________)" << endl << endl;
}

void printScissors()
{
    cout << "    _______" << endl;
    cout << "---'   ____)____" << endl;
    cout << "           ______)" << endl;
    cout << "        __________)" << endl;
    cout << "       (____)" << endl;
    cout << "---.__ (___)" << endl << endl;
}
