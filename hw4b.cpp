/******************************************************************************
Author: Homework 4b starter code
Date: 10/19/2022


*******************************************************************************/
#include <iomanip>
#include <iostream>

using namespace std;

// main dish costs
const double costSpecial1 = 14.95;
const double costSpecial2 = 9.95;
const string special1 = "Chicken parmesean";
const string special2 = "Cheese ravioli";

//---------------------------------------------------------------------------
// Name: getTableOrder
// Parameters: const int numPeople, int & numSpecial1, int & numSpecial2
// Returns: none
// Purpose: This function asks how many people ordered special1, how many
// ordered special2, and updates through the pass-by-reference parameters There
// should be an error-checking loop to make sure that the total number of dishes
// ordered is less than the number of people sitting there (some people may just
// be eating unlimited breadsticks, so the number doesn't have to match exactly)
//---------------------------------------------------------------------------
void getTableOrder(const int numPeople, int &numSpecial1, int &numSpecial2) {
  do {
    cout << "how many people are ordering the " << ::special1 << "?" << endl;
    cin >> numSpecial1;
    cout << "how many people are ordering the " << ::special2 << "?" << endl;
    cin >> numSpecial2;
    if (numSpecial1 + numSpecial2 > numPeople) {
      cout << "It looked like you ordered more dishes than the amount of "
              "people sitting at your table, please try again"
           << endl
           << endl;
    }
  } while (numSpecial1 + numSpecial2 > numPeople);
}

//---------------------------------------------------------------------------
// Name: calculateTip
// Parameters: const int numPeople, const double bill, double & tip
// Returns: none
// Purpose: Calculate the tip.  If there are 8 or more people,
// the tip was already added, but ask if they would like to add more.
// The user should be able to add a percentage or a specific amount.
// (be sure to add to the tip that's possibly already there)
// Include error checking for inputs.
//---------------------------------------------------------------------------
void calculateTip(const int numPeople, const double bill, double &tip) {
  float additionalTip;
  bool confirmed = false;
  string confirmedInput;

  do {
    do {
        additionalTip = 0;
        if (tip != 0) {
            cout << "How much more tip would you like to add to your current bill? \n";
        } else {
            cout << "How much tip would you like to add to your current bill? \n";
        }
        cin >> additionalTip;

        if(additionalTip < 0){
            cout << "Please enter a positive amount of tip. \n";
        }

    } while(additionalTip < 0);

    cout << fixed << setprecision(2);
    cout << "You wish to add $" << additionalTip << " dollars to the tip? \n";

    do {
      cout << "Please type \"yes\" or \"no\". \n";
      cin >> confirmedInput;
    } while(confirmedInput != "yes" && confirmedInput != "no");

    confirmed = (confirmedInput == "yes") ? true : false;

  } while (!confirmed);

  tip += additionalTip;
}

//---------------------------------------------------------------------------
// Name: calculateCost
// Parameters: const int numPeople, const int numSpecial1, const int
// numSpecial2, double & tip Returns: the cost of the meal Purpose: Calculate
// the total cost of everyone's meals.  If there are more than 8 people dining,
// update the tip parameter to a mandatory 20%.  Then, call the calculateTip
// function to find out how much they tip Note: if there are more people than
// meals ordered, the extra people should be charged $5 each for unlimited
// breadsticks
//---------------------------------------------------------------------------
float calculateCost(const int numPeople, const int numSpecial1,
                    const int numSpecial2, double &tip) {
  int totalMealCount = numSpecial1 + numSpecial2;
  int numPeopleDidntOrder = numPeople - totalMealCount;
  float totalCost = (numSpecial1 * costSpecial1) + (numSpecial2 * costSpecial2);

  if (numPeopleDidntOrder > 0) {
    cout << "It look like " << numPeopleDidntOrder
         << " people didnt order food." << endl;
    cout << "We have added an additional $5 charge for each of the "
         << numPeopleDidntOrder;
    cout << " people who didnt order food." << endl << endl;
    totalCost += numPeopleDidntOrder * 5.00;
  }

  if (numPeople > 8) {
    tip = totalCost * 0.20;
    cout << "There are more than 8 people at your dining table, ";
    cout << "a mandatory 20% tip has been applied to your bill. \n";
    cout << "your current tip amount is: $" << tip << endl;
  }

  calculateTip(numPeople, totalCost, tip);
  totalCost += tip;

  return totalCost;
}

//---------------------------------------------------------------------------
// Name: displayFinalBill
// Parameters: const int numPeople, const int special1, const int special2,
// const double bill, const double tip Returns: nothing Purpose: This function
// prints the receipt information - how many people got which dish, how many
// just had breadsticks, the price of everyone's food, the tip, and the final
// bill
//---------------------------------------------------------------------------
void displayFinalBill(const int numPeople, const int special1,
                      const int special2, const double bill, const double tip) {

    int breadsticksOnly = numPeople - (special1 + special2);
    float special1TotalCost = special1 * costSpecial1;
    float special2TotalCost = special2 * costSpecial2;
    float breadstickOnlyTotalCost = breadsticksOnly * 5.00;

    cout << "|" << left << setw(20) << "Menu"
         << "|" << setw(15) << "Cost"
         << "|" << setw(20)  << "Quantity ordered"
         << "|" << setw(15) << "Selection Cost"
         << "|" << endl;

    cout << setw(75) << setfill('-')  << "" << setfill(' ')  << endl;

    cout << "|" << left << setw(20) << ::special1
         << "|$" << setw(14) << costSpecial1
         << "|" << setw(20)  << special1
         << "|$" << setw(14) << fixed << setprecision(2) << special1TotalCost
         << "|" << endl;

    cout << "|" << left << setw(20) << ::special2
         << "|$" << setw(14) << costSpecial2
         << "|" << setw(20)  << special2
         << "|$" << setw(14) << fixed << setprecision(2) << special2TotalCost
         << "|" << endl;

    cout << "|" << left << setw(20) << "Breadsticks only"
         << "|$" << setw(14) << 5.00
         << "|" << setw(20)  << breadsticksOnly
         << "|$" << setw(14) << fixed << setprecision(2) << breadstickOnlyTotalCost
         << "|" << endl << endl;

    cout << setw(20) << "Amount of tips: " << "$" << tip << endl;
    cout << setw(20) << "Total: " << "$" << bill << endl << endl;

}

//---------------------------------------------------------------------------
// Name: orderMoreEntrees
// Parameters: char & orderMore
// Returns: nothing
// Purpose: This function asks the user if they want to order more food, checks
// to ensure that the user enters a 'y' or an 'n', and returns the answer (by
// updating the parameter) If they enter an uppercase letter, it gets converted
// to lowercase
//---------------------------------------------------------------------------
void orderMoreEntrees(char &orderMore) {
    do {
        cout << "Would you like to order more food?" << endl;
        cout << "Please type 'y' for yes and 'n' for no" << endl;
       cin >> orderMore;
    } while(orderMore != 'n' && orderMore != 'y');
}

//---------------------------------------------------------------------------
// Name: resetVariables
// Parameters: double & totalBill, double & tip, int & numPeople, int &
// numSpecial1, int & numSpecial2 Returns: nothing Purpose: This function resets
// the values of all variables passed in
//---------------------------------------------------------------------------
void resetVariables(double &totalBill, double &tip, int &numPeople,
                    int &numSpecial1, int &numSpecial2) {
    totalBill = 0;
    tip = 0;
    numPeople = 0;
    numSpecial1 = 0;
    numSpecial2 = 0;
}

int main() {
  double totalBill, tip = 0;
  int numPeople, numSpecial1, numSpecial2;
  char orderMore = 'n';

  do {
    cout << "How many people are in your party? >> ";
    cin >> numPeople;
    while (numPeople <= 0) {
      cout << "Invalid input.  How many people are in your party? >> ";
      cin >> numPeople;
    }
    cout << "\n\nWelcome to the Olive Garden!  It appears there are "
         << numPeople << " dining with us today.\n";

    getTableOrder(numPeople, numSpecial1, numSpecial2);
    totalBill = calculateCost(numPeople, numSpecial1, numSpecial2, tip);
    displayFinalBill(numPeople, numSpecial1, numSpecial2, totalBill, tip);
    orderMoreEntrees(orderMore);

    if (orderMore == 'y') {
       resetVariables(totalBill, tip, numPeople, numSpecial1, numSpecial2);
    }

  } while (orderMore != 'n');

  cout << "We hope you enjoyed your meal, and remember, when you're here, "
          "you're family!\n";

  return 0;
}
