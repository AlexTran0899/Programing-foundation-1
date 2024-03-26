#include <iostream>
#include <time.h>
#include <iomanip>
#include <cctype>
using namespace std;

//global declaration
const int numWeek = 12;
const int numDayInWeek = 7;

const char MONDAY = 'M';
const char TUESDAY = 'T';
const char WEDNESDAY = 'W';
const char THURSDAY = 'R';
const char FRIDAY = 'F';
const char SATURDAY = 'S';
const char SUNDAY = 'U';

//prototype:
void randomTipAmount(int tipsArr[][numDayInWeek]);
void changeTipAmount(int tipsArr[][numDayInWeek]);
void printWeek(int tipsArr[][numDayInWeek]);
void printAllWeek(int tipsArr[][numDayInWeek]);

// main function
int main(){
    int tipsArr[numWeek][numDayInWeek] = {{0}};
    int ch = -1;

    cout << "Please select one of the follow: \n";
    cout << "Enter '0' to exit the program.\n";
    cout << "Enter '1' to fill each day of the week with a random value between a min and max. \n";
    cout << "Enter '2' to manually change the tip amount on a particular day.\n";
    cout << "Enter '3' to print a particular week.\n";
    cout << "Enter '4' to print each week and display the tips made everyday along with:\n";
    cout << setw(10) << " " << "- The sum of every week.\n";
    cout << setw(10) << " " << "- Which week made the most tips.\n";
    cout << setw(10) << " " << "- The average number of tips earned for each day of the week.\n";
    cout << setw(10) << " " << "- What day of the week on average have the highest tip amount.\n";

    do{
        cout << endl;
        cout << "Please enter a number between 0 to 4: \n";
        cin >> ch;

        switch(ch){
            case 0:
                cout << "Exiting program goodbye";
                break;
            case 1:
                randomTipAmount(tipsArr);
                break;
            case 2:
                changeTipAmount(tipsArr);
                break;
            case 3:
                printWeek(tipsArr);
                break;
            case 4:
                printAllWeek(tipsArr);
                break;
            default:
                cout << "invalid input :( ";
        }
    }while(ch != 0);

}
// day of the week
string dayOfTheWeek(int i){
    switch(i){
        case 0:
            return "Monday";
            break;
        case 1:
            return "Tuesday";
            break;
        case 2:
            return "Wednesday";
            break;
        case 3:
            return "Thursday";
            break;
        case 4:
            return "Friday";
            break;
        case 5:
            return "Saturday";
            break;
        case 6:
            return "Sunday";
            break;
        default:
            cout << "invalid input";
    }
}

// Fill the 2d array with a random between 2 integer;
void randomTipAmount(int tipsArr[numWeek][numDayInWeek]){
    bool confirmed = false;
    int minTip;
    int maxTip;
    char selection;
    do{
        do{
            cout << "Please enter your minimum tip value as a positive integer more than zero" << endl;
            cin >> minTip;
        } while(minTip < 0);
        do{
            cout << "Please enter your maximum tip value as a positive integer greater than your minimum tip value" << endl;
            cin >> maxTip;
        } while(maxTip <= minTip);
        cout << "Your minimum tip value is : " << minTip << endl;
        cout << "Your maximum tip value is : " << maxTip << endl;
        do{
            cout << "please enter 'y' to confirm and 'n' to re-enter your tips amount: ";
            cin >> selection;
        } while (selection != 'y' and selection != 'n');
        confirmed = selection == 'y';
    } while(!confirmed);
    for(int w = 0; w < numWeek; w++){
        for(int d = 0; d < numDayInWeek; d++ ){
            tipsArr[w][d] = rand() % (maxTip-minTip + 1) + minTip;
        }
    }
}

//Change tip amount for a given day
void changeTipAmount(int tipsArr[numWeek][numDayInWeek]){
    bool done = true;
    bool dayOfWeekConfirmed = true;
    bool weekConfirmed = false;
    int newTipAmount;
    int dayOfTheWeeKInt;
    int weekInFiscalQuarter;
    char dayOfTheWeek;
    cout << "What day and week would you like to change the tip?\n";
    do{
        dayOfWeekConfirmed = true;
        cout << "Which day of the week would you like to select. \n";
        cout << "'M' for Monday. \n";
        cout << "'T' for Tuesday. \n";
        cout << "'W' for Wednesday. \n";
        cout << "'R' for Thursday. \n";
        cout << "'F' for Friday. \n";
        cout << "'S' for Saturday. \n";
        cout << "'U' for Sunday. \n";
        cout << "Please enter a single character: ";
        cin >> dayOfTheWeek;
        dayOfTheWeek = toupper(dayOfTheWeek);
        switch (dayOfTheWeek) {
            case MONDAY:
                cout << "You selected Monday \n";
                dayOfTheWeeKInt = 0;
                break;
            case TUESDAY:
                cout << "You selected Tuesday \n";
                dayOfTheWeeKInt = 1;
                break;
            case WEDNESDAY:
                cout << "You selected Wednesday \n";
                dayOfTheWeeKInt = 2;
                break;
            case THURSDAY:
                cout << "You selected Thursday \n";
                dayOfTheWeeKInt = 3;
                break;
            case FRIDAY:
                cout << "You selected Friday \n";
                dayOfTheWeeKInt = 4;
                break;
            case SATURDAY:
                cout << "You selected Saturday \n";
                dayOfTheWeeKInt = 5;
                break;
            case SUNDAY:
                cout << "You selected Sunday";
                dayOfTheWeeKInt = 6;
                break;
            default:
                cout << "Please enter a valid character. \n";
                dayOfWeekConfirmed = false;
        }
    } while(!dayOfWeekConfirmed);
    do{
        cout << "Which week in the fiscal quarters would you like to select?\n";
        cout << "Please enter 1 for week 1, 2 for week 2 and so on...\n";
        cout << "Please enter a number between 1 and 12:";
        cin >> weekInFiscalQuarter;
        if (weekInFiscalQuarter > 12 or weekInFiscalQuarter < 1){
            cout << "Please enter a valid number between 1 and 12\n";
            weekConfirmed = false;
        } else {
            cout << "You selected week " << weekInFiscalQuarter << endl;
            weekConfirmed = true;
        };
        weekInFiscalQuarter -= 1;
    } while(!weekConfirmed);
    cout << "What is the new tip amount you would like to change it to? \n";
    do{
        cout << "Please enter a positive integer: ";
        cin >> newTipAmount;
    }while(newTipAmount < 0);
    tipsArr[weekInFiscalQuarter][dayOfTheWeeKInt] = newTipAmount;
    cout << "Cool beans, I changed week " << weekInFiscalQuarter + 1 << " on "
         << ::dayOfTheWeek(dayOfTheWeeKInt) << " tip amount to " << newTipAmount << " dollars." << endl;
}

// Print week tips
void printWeek(int tipsArr[numWeek][numDayInWeek]){
    bool weekInputValid = false;
    int weekInput = 1;
    cout << "Which week in the current fiscal quarters would you like to print?\n";
    do{
        cout << "Please enter 1 for week 1, 2 for week 2 and so on...\n";
        cout << "Please enter a number between 1 and 12: ";
        cin >> weekInput;
        weekInputValid = weekInput <= 12 and weekInput > 0;
    }while(!weekInputValid);
    cout << setw(5 ) << "Week"
         << setw(7) << "M"
         << setw(7) << "T"
         << setw(7) << "W"
         << setw(7) << "R"
         << setw(7) << "F"
         << setw(7) << "S"
         << setw(7) << "U"
         << endl;
    cout << setw(55) << setfill('-') << "" << endl;
    cout << setfill(' ');
    cout << setw(5 ) << weekInput;
    for(int i = 0; i < 7; i++){
        cout << setw(7) << tipsArr[weekInput - 1][i];
    }
    cout << endl;
}

// Print every day of all week tips
void printAllWeek(int tipsArr[numWeek][numDayInWeek]){
    int currentSum = 0;
    int highestSumWeek = 0;
    int highestSum = 0;
    int highestDay = 0;
    float highestSumDay = 0;
    int weekDayTotal[7] = {};
    cout << setw(12 ) << "Week"
         << setw(7) << "M"
         << setw(7) << "T"
         << setw(7) << "W"
         << setw(7) << "R"
         << setw(7) << "F"
         << setw(7) << "S"
         << setw(7) << "U"
         << setw(10) << "Sum"
         << endl;
    cout << setw(72) << setfill('-') << "" << endl;
    cout << setfill(' ');
    for(int w = 0; w < 12; w++)
    {
        currentSum = 0;
        cout << setw(12 ) << w + 1;
        for(int d = 0; d < 7; d++)
        {
            currentSum += tipsArr[w][d];
            weekDayTotal[d] += tipsArr[w][d];
            cout << setw(7) << tipsArr[w][d];
        }
        if(highestSum < currentSum){
            highestSumWeek = w;
            highestSum = currentSum;
        }
        cout << setw(10) << currentSum;
        cout << endl;
    }
    cout << setw(72) << setfill('-') << "" << endl;
    cout << setfill(' ');
    cout << setw(12 ) << "Day Average:";
    for(int i = 0; i < 7; i++){
        highestDay = highestSumDay < weekDayTotal[i] ? i : highestDay;
        highestSumDay = highestSumDay < weekDayTotal[i] ? weekDayTotal[i]: highestSumDay;
        cout << setw(7) << fixed << setprecision(2) << weekDayTotal[i] / 12;
    }
    cout << endl;
    cout << "Highest week: " << highestSumWeek + 1 << endl;
    cout << "Highest average day of the week is: " << dayOfTheWeek(highestDay);
    cout << endl;
}

