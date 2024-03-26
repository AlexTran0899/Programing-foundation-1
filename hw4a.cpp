/******************************************************************************
Purpose:    Starter code for homework 4a
Author: 010796179 
Date: 10/06/2022
*******************************************************************************/
#include <iomanip>
#include <iostream>

using namespace std;

// global variables
const char COFFEE = 'C';
const char LATTE = 'L';
const char TEA = 'T';
const char BLENDS = 'B';
const char JUICE = 'J';
const char HOT = 'H';
const char ICED = 'I';
const float BASE_COFFEE_COST = 3.75;
const float BASE_LATTE_COST = 4.50;
const float BASE_TEA_COST = 3.50;
const float BASE_BLENDS_COST = 5.25;
const float BASE_JUICE_COST = 4.25;
const float SIZE_UPCHARGE = 0.25;
const float EXTRA_UPCHARGE = 0.5;
const float CUP_DISCOUNT = 0.50;

//----------------------------------------------------------------------
// Function: setDrink
// Purpose: To get the user's drink choice
// Parameters: char &drinkChoice, char &drinkType
// Returns: N/A
//----------------------------------------------------------------------
void setDrink(char &drinkChoice, char &drinkType) {
  // get type of drink
  cout << "What type of drink do you want to get today? Type (H) for hot or "
          "(I) for iced."
       << endl;
  cin >> drinkType;
  drinkType = toupper(drinkType);

  // error checking for drinkType
  while (drinkType != HOT && drinkType != ICED) {
    cout << "Invalid choice! Try again." << endl;
    cin >> drinkType;
    drinkType = toupper(drinkType);
  }

  // get drinkChoice
  cout << "\nWhat kind of drink do you like to get today?" << endl;
  cout << "<\tT ~ for Tea                     $3.50       >" << endl;
  cout << "<\tC ~ for Coffee                  $3.75       >" << endl;
  cout << "<\tJ ~ for Juice                   $4.25       >" << endl;
  cout << "<\tL ~ for Latte                   $4.50       >" << endl;
  if (drinkType == ICED)
    cout << "<\tB ~ for Blended Beverages       $5.25       >" << endl;

  cin >> drinkChoice; // get input
  drinkChoice = toupper(drinkChoice);

  // error checking loop for drinkChoice
  while (drinkChoice != COFFEE && drinkChoice != LATTE && drinkChoice != TEA &&
         drinkChoice != BLENDS && drinkChoice != JUICE) {
    cout << "\nOops! Your choice is not included on the menu. Try again."
         << endl;
    cout << "<\tT ~ for Tea                     $3.50       >" << endl;
    cout << "<\tC ~ for Coffee                  $3.75       >" << endl;
    cout << "<\tJ ~ for Juice                   $4.25       >" << endl;
    cout << "<\tL ~ for Latte                   $4.50       >" << endl;
    if (drinkType == ICED)
      cout << "<\tB ~ for Blended Beverages       $5.25       >" << endl;

    cin >> drinkChoice; // get input again
    drinkChoice = toupper(drinkChoice);
  }
}

//----------------------------------------------------------------------
// Function: setDrinkSize
// Purpose: To determine what size of drink the customer want
// Parameters: N/A
// Returns: int - selected drink's size
//----------------------------------------------------------------------
int setDrinkSize() {
  int size;

  // Prompt user for drink size
  cout << "What size of drink would you like?" << endl;
  cout << "1 = Small || 2 = Medium || 3 = Large" << endl;
  cin >> size;

  // error checking loop
  while (size < 1 || size > 3) {
    cout << "INVALID! Try again." << endl;
    cin >> size;
  }

  // Message
  if (size == 3)
    cout << "Extra $0.75 for size Large." << endl;
  else if (size == 2)
    cout << "Extra $0.50 for size Medium." << endl;

  return size;
}

//----------------------------------------------------------------------
// Function: addExtra
// Purpose: Ask user whether or not want to add any extra (flavor, shot, ice,
// topping, ... ) Parameters: bool &extra, const char drink Return: N/A
//----------------------------------------------------------------------
void addExtra(bool &extra, const char drink) {
  char choice;
  do {
    // prompt user
    switch (drink) {
    case COFFEE:
      cout << "Do you want an extra shot for your coffee? ";
      break;
    case LATTE:
      cout << "Do you want extra foam? ";
      break;
    case TEA:
    case JUICE:
      cout << "Do you want to add more sugar/flavor? ";
      break;
    case BLENDS:
      cout << "Do you want extra whipped cream? ";
      break;
    default:
      cout << "UH OH! You haven't selected your choice of drink! Try again "
              "later.";
      return;
    }
    cout << "For only 50 cents more!" << endl; // advertising
    cout << "Type (Y) for yes or (N) for no. Program will keep asking if you "
            "enter an invalid answer."
         << endl;
    cin >> choice;
    choice = tolower(choice);
  } while (choice != 'y' && choice != 'n');

  if (choice == 'y')
    extra = true;
  else
    extra = false;

  return;
}

//----------------------------------------------------------------------
// Name: addMore
// Purpose: Ask user whether or not they want to add more drink to current order
// Parameters: None
// Return: bool - true if they want to add to their order, otherwise false
//----------------------------------------------------------------------
bool addMore() {
  char more;
  cout << "Would you like to order another drink? (y/n)\n";
  cin >> more;
  more = tolower(more);
  if (more == 'y')
    return true;
  return false;
}

//----------------------------------------------------------------------
// Function: getDiscount
// Purpose: give the customer discount if they bring their own cup
// Parameter: None
// Return: bool - true if they did, otherwise false
//----------------------------------------------------------------------
bool getDiscount() {
  char reusable;

  cout << "You can save $0.50 if you use a reusable cup!" << endl;
  cout << "Do you bring your cup? Type (Y)es/(N)o. " << endl;
  cin >> reusable;
  reusable = tolower(reusable);
  // error checking
  while (reusable != 'y' && reusable != 'n') {
    cout << "INVALID! Try again." << endl;
    cin >> reusable;
    reusable = tolower(reusable);
  }

  if (reusable == 'n')
    return false;
  return true;
}

//----------------------------------------------------------------------
// Function: getDrinkCost
// Purpose: To calculate cost of a drink and add to subtotal
// Parameters:  const char drink, const char size, const bool extra, const bool
// discount Returns: float - cost of the drink
//----------------------------------------------------------------------
float getDrinkCost(const char drink, const int size, const bool extra,
                   const bool discount) {
  float cost = 0;

  // add base cost of drink choice
  if (drink == TEA)
    cost += BASE_TEA_COST;
  else if (drink == COFFEE)
    cost += BASE_COFFEE_COST;
  else if (drink == JUICE)
    cost += BASE_JUICE_COST;
  else if (drink == LATTE)
    cost += BASE_LATTE_COST;
  else if (drink == BLENDS)
    cost += BASE_BLENDS_COST;

  // add upcharge for medium and large size
  if (size > 1)
    cost += (size * SIZE_UPCHARGE);

  // add upcharge if they wanted to add extra (flavor, shot, ice, topping, ... )
  if (extra)
    cost += EXTRA_UPCHARGE;

  // discount if the user brings their own cup
  if (discount)
    cost -= CUP_DISCOUNT;

  return cost;
}

//----------------------------------------------------------------------
// Function: reset
// Purpose: Resets local drink's variables
// Parameters:   char &drinkChoice, int &drinkSize, char &drinkType,
//              bool &extra, bool &cupDiscount, float &drinkCost
// Return: N/A
//----------------------------------------------------------------------
void reset(char &drinkChoice, char &drinkType, int &drinkSize, bool &extra,
           bool &cupDiscount, float &drinkCost) {
  drinkChoice = '\0';
  drinkSize = 0;
  drinkType = '\0';
  extra = false;
  cupDiscount = false;
  drinkCost = 0;
}

//----------------------------------------------------------------------
// Function: confirmOrder
// Purpose: to confirm the order of one drink before calculate that drink's cost
// Parameters: const char drink, const int size, const char type, const bool
// extra Return: bool - confirms all selection are correct
//----------------------------------------------------------------------
bool confirmOrder(const char userDrink, const char userType, const int userSize,
                  const bool userExtra) {
  string confirmedDrink, confirmedSize, confirmedType, confirmedExtra;
  char choice;

  cout << "Let's make sure the order is correct." << endl;

  switch (userDrink) {
  case TEA:
    confirmedDrink = "tea";
    if (userExtra)
      confirmedExtra = "sugar/flavor";
    break;
  case COFFEE:
    confirmedDrink = "coffee";
    if (userExtra)
      confirmedExtra = "shot";
    break;
  case JUICE:
    confirmedDrink = "juice";
    if (userExtra)
      confirmedExtra = "sugar/flavor";
    break;
  case LATTE:
    confirmedDrink = "latte";
    if (userExtra)
      confirmedExtra = "foam";
    break;
  case BLENDS:
    confirmedDrink = "blended beverage";
    if (userExtra)
      confirmedExtra = "whipped cream";
    break;
  }

  switch (userSize) {
  case 1:
    confirmedSize = "small";
    break;
  case 2:
    confirmedSize = "medium";
    break;
  case 3:
    confirmedSize = "large";
    break;
  }

  if (userType == HOT)
    confirmedType = "hot";
  else
    confirmedType = "iced";

  if (userExtra)
    cout << "You order a " << confirmedSize << " cup of " << confirmedType
         << " " << confirmedDrink << " with extra " << confirmedExtra << "."
         << endl;
  else
    cout << "You order a " << confirmedSize << " cup of " << confirmedType
         << " " << confirmedDrink << "." << endl;

  // check with user if everything is correct
  cout << "If everything seems correct, type (Y) for yes. Otherwise, type (N) "
          "for no."
       << endl;
  cin >> choice;
  choice = toupper(choice);
  while (choice != 'Y' && choice != 'N') {
    cout << "You entered an invalid input. Try again." << endl;
    cin >> choice;
    choice = toupper(choice);
  }

  // return true if Y
  if (choice == 'Y')
    return true;
  else
    return false;
}

//----------------------------------------------------------------------
// Function: printBill
// Purpose: print item quantity, subtotal, tax, and total for the bill
// Parameters: const float subtotal, const int quantity
// Return: N/A
//----------------------------------------------------------------------
void printBill(const float subtotal, const int quantity) {
  float tax = subtotal * 0.1; // 10% of subtotal for tax
  // Print total
  cout << fixed << setprecision(2);
  cout << "\nYour bill: " << endl;
  cout << "------------------------------------------" << endl;
  cout << "\tItem Quantity:          " << quantity << endl;
  cout << "\tSubtotal:           $" << subtotal << endl;
  cout << "\tTax :               $" << tax << endl;
  cout << "\tTOTAL:              $" << subtotal + tax << endl;
  cout << "------------------------------------------" << endl;
  cout << "Thank you for your order!\nEnjoy!" << endl;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//**Don't change anything outside the main function or above this comment
// other than name, date, and assignment description at the top
int main() {
  // local variables for user's drink selections
  char drinkChoice = '\0';
  char drinkType = '\0';
  float drinkCost = 0;
  int drinkSize = 0;
  bool cupDiscount = false;
  bool extra = false;

  // local variables only for main function
  float subtotal = 0;
  int numDrink = 0;
  bool confirmed = false;

  // set up for two decimal places

  // Welcome new customer with a short message

  cout << "University ID: 010796179" << endl << endl;

  do {
    // get type and choice of drink from the user
    setDrink(drinkChoice, drinkType);
    // get what size of drink the user wants

    drinkSize = setDrinkSize();

    // ask user if they want to add any extra options
    addExtra(extra, drinkChoice);
   
    // confirm the drink
    confirmed = confirmOrder(drinkChoice,drinkType,drinkSize, extra);

    // if not confirmed, give a message and start another loop
    if(confirmed == false){
      cout << "Please enter your drink again, thank you" << endl;
    } else {
        //increment numbers of drinks ordered/confirmed
      numDrink += 1;

        //ask if they brought their own cup and update cupDiscount
      cupDiscount = getDiscount();

        //get drinkCost of new confirmed drink then add it to subtotal
      drinkCost = getDrinkCost(drinkChoice, drinkSize, extra, cupDiscount);
      subtotal += drinkCost;
        //Print confirmed drink's cost
      cout << "Your drink cost: " << drinkCost << " dollars" << endl;
        //ask if the user wants to add another drink to the current order
      if(addMore()){
        //loop again for new drink if yes by updating confirmed variable
        confirmed = false;
        //reset variables related to the drink to store new drink in the next lop
        reset(drinkChoice, drinkType, drinkSize, extra, cupDiscount, drinkCost);
      }
    }

  } while (!confirmed); // while the order is NOT confirmed

  printBill(subtotal, numDrink);

  return 0;
}

