#include "AnimalDB.h"
#include "Animal.h"
#include <iomanip>
#include <iostream>
#include <unistd.h>

// default constructor. 
AnimalDB::AnimalDB() { 

}

// copy construcotr 
AnimalDB::AnimalDB(const AnimalDB &copy) {
  this->animals     = copy.getAllAnimalInZooArr();
  this->userCart    = copy.getAllAnimalInShoppingCart();
  this->typeHashIDX = copy.getTypeHashIDX();
}
// deconstrutor 
AnimalDB::~AnimalDB() {
  // no pointers no problem.
}

// Print the header for each column;
void AnimalDB::printHeader() const {
  cout << setw(10) << left << "ID";
  cout << setw(10) << "Type";
  cout << setw(10) << "Age";
  cout << setw(15) << "Weight";
  cout << setw(10) << "Price" << endl << endl;
}

// Print method for user’s shopping cart
void AnimalDB::printShopingCart() const {
  if (!userCart.empty()) {
    cout << "---------- Animal in your shopping cart ------------" << endl;
    printHeader();
    for (int i = 0; i < userCart.size(); i++) {
      userCart[i].print();
    }
    cout << endl;
  }
}

// Print method for the current running total of the user’s shopping cart
void AnimalDB::printCurrentTotal() const {
  if (!userCart.empty()) {
    cout << "Your total is: ";
    cout << fixed << setprecision(2) << "$ " << getCurrentTotal() << endl;
  }
}

// Print the previously set filtered result from the user input
void AnimalDB::printPrevFilteredResult() const {
  if (printArray.empty()) {
    return;
  }
  cout << "--------------- Your filtered result ---------------" << endl;
  printHeader();
  for (int i = 0; i < printArray.size(); i++) {
    if(userCartAnimalIdHash.count(printArray[i].getID())){
       cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    } else {
      printArray[i].print();
    }
  }
  cout << endl;
}

// filter animal array by certain weight range from user input.
void AnimalDB::filterAnimalByWeight(vector<Animal> &selectionArr) {
  float minWeight;
  float maxWeight;
  vector<Animal> tempArr;
  cout << "------------ Animal weight range filter ------------" << endl;
  cout << "Enter a minimum weight or -1 if you would like to skip this filter: ";
  cin >> minWeight;
  if (minWeight == -1) {
    cout << "Got it, you don't care about the animal weight, moving on."
         << endl;
    return;
  }
  if (minWeight < 0) {
    cout << endl;
    cout << "It look like you enter a negative number that is not -1" << endl;
    cout << "Unfortunatly we do not sell any animal filled with helium so..."
         << endl;
    cout << "We changed the minimum weight to be 0" << endl << endl;
    minWeight = 0;
  }
  do {
    cout << "Please enter max weight: ";
    cin >> maxWeight;
    if (maxWeight <= minWeight) {
      cout << "Please enter a number higher than " << minWeight << endl;
    }
  } while (maxWeight <= minWeight);
  for (int i = 0; i < selectionArr.size(); i++) {
    if (selectionArr[i].getWeight() >= minWeight and
        selectionArr[i].getWeight() <= maxWeight) {
      tempArr.push_back(selectionArr[i]);
    }
  }
  selectionArr = tempArr;
}

// filter animal by certain age range, yes I know I can refactor the 2 functions
// but i'm going to, nor am I going to format this line to look better.;
void AnimalDB::filterAnimalByAge(vector<Animal> &selectionArr) {
  int minAge;
  int maxAge;
  vector<Animal> tempArr;
  cout << "------------- Animal age range filter --------------" << endl;
  cout << "Enter a minimum age or -1 if you would like to skip this filter: ";
  cin >> minAge;
  if (minAge == -1) {
    cout << "Got it, you don't care about the animal age, moving on." << endl;
    return;
  }
  if (minAge < 0) {
    cout << endl;
    cout << "It look like you enter a negative number that is not -1" << endl;
    cout << "You must be a time traveler" << endl;
    cout << "Unfortunately we do not sell any unbored animal so..." << endl;
    cout << "We changed the minimum age to be 0" << endl << endl;
    minAge = 0;
  }
  do {
    cout << "Please enter max age: ";
    cin >> maxAge;
    if (maxAge <= minAge) {
      cout << "Please enter a number higher than " << minAge << endl;
    }
  } while (maxAge <= minAge);
  for (int i = 0; i < selectionArr.size(); i++) {
    if (selectionArr[i].getAge() >= minAge and
        selectionArr[i].getAge() <= maxAge) {
      tempArr.push_back(selectionArr[i]);
    }
  }
  selectionArr = tempArr;
}

// filter the array of animal by a certian type from user input.
void AnimalDB::filterAnimalByType(vector<Animal> &selectionArr) {
  vector<string> typeArr;
  vector<Animal> tempArr;
  vector<int>    resArr;
  int counter       = 0;
  int selection     = 0;
  string typeString = "";

  cout << "-------------- Animal type menu filter ---------------" << endl << endl;
  cout << "-1: "
       << "Don't care about animal type" << endl;

  for (auto const &keyValue : typeHashIDX) {
    cout << " " << counter++ << ": ";
    cout << keyValue.first << endl;
    typeArr.push_back(keyValue.first);
  }

  do {
    cout << "Please enter a number: ";
    cin >> selection;

    if (selection == -1) {
      cout << "Got it, you don't care about the animal type, moving on" << endl;
      selectionArr = animals;
      return;
    }
    if (selection < 0 or selection > typeArr.size() - 1) {
      cout << "Invalid input, please enter a number between 0 and ";
      cout << typeArr.size() - 1 << endl;
    }
  } while (selection < -1 || selection > typeArr.size() - 1);

  typeString = typeArr[selection];
  resArr = typeHashIDX.at(typeString);
  cout << "You selected: " << typeString << endl;

  for (int i = 0; i < resArr.size(); i++) {
    tempArr.push_back(getDonnaAnimalByID(resArr[i] + 1));
  }
  selectionArr = tempArr;
}

// Method for returning an Animal object at a given index
// in the array from the user’s shopping cart.
Animal AnimalDB::getUserAnimalByIDX(int i) const { return userCart[i]; }

// method for getting Donna zoo animal by id
Animal AnimalDB::getDonnaAnimalByID(int i) const { 
  // for(int idx = 0; idx < this->animals.size();idx++){
  //   if(this->animals[idx].getID() == idx){
  //     return animals[idx]
  // }
  return animals[i - 1]; 
}

// method for returning the total number of animal in Donna zoo.
int AnimalDB::getTotalAnimalInZoo() const { return animals.size(); }

// get the number of item in the user cart.
int AnimalDB::getNumCartItems() const { return userCart.size(); }

// Method for returning the current running total of the user’s shopping cart
float AnimalDB::getCurrentTotal() const {
  float currentSum = 0;
  for (int i = 0; i < userCart.size(); i++) {
    currentSum += userCart[i].getPrice();
  }
  return currentSum;
}

// method for getting the array of animal in donna zoo
vector<Animal> AnimalDB::getAllAnimalInZooArr() const{
  return animals;
};
// method for getting the array of animal in the user shopping cart.
vector<Animal> AnimalDB::getAllAnimalInShoppingCart() const{
  return userCart;
}

// method for getting the index hash of each animal type.
unordered_map<string, vector<int> > AnimalDB::getTypeHashIDX() const{
  return typeHashIDX;
}

// Set print array to print all the animal of type, age, weight range
void AnimalDB::setPrintArrayToPrintAnimalByTypeWeightAge() {
  vector<Animal> selectTypeWeightAgeArr;
  
  filterAnimalByType(selectTypeWeightAgeArr);
  cout << endl;
  filterAnimalByWeight(selectTypeWeightAgeArr);
  cout << endl;
  filterAnimalByAge(selectTypeWeightAgeArr);
  cout << endl;
  
  if (selectTypeWeightAgeArr.empty()) {
    // cout << std::setfill ('-') << std::setw (10);
    cout << "********** No animal matches your search :( **********" << endl;
    cout << "Moving on in: " << endl;
    cout << "3" << endl;
    sleep(1);
    cout << "2" << endl;
    sleep(1);
    cout << "1" << endl;
    sleep(1);
  }
  system("clear");
  printArray = selectTypeWeightAgeArr;
}

// Set the print array to Donna inventory
void AnimalDB::setPrintArrayToPrintDonnaInventory() {
  Animal currentAnimal;
  int totalAnimalInZoo = getTotalAnimalInZoo();
  cout << endl;
  printArray = animals;
}

// Insert method for adding a new animal to user’s shopping cart
void AnimalDB::insertItemIntoCart() {
  int idx = -1;
  Animal selectedAnimal;
  bool animalAlreadyExitsInCart = false;
  cout << "Please enter the animal ID you wish to add to shopping cart."
       << endl;
  do {
    cin >> idx;
    if (idx < 1 or idx > animals.size()) {
      cout << "Please enter a number between 1 and " << animals.size() << endl;
    } else {
      selectedAnimal = getDonnaAnimalByID(idx);
    }
  } while (idx < 1 or idx > animals.size());

  // O(n) time complexity for .count
  if (userCartAnimalIdHash.count(selectedAnimal.getID())) {
    cout << "********Animal already in your shopping cart********" << endl;
    cout << "Moving on in: " << endl;
    cout << "3" << endl;
    sleep(1);
    cout << "2" << endl;
    sleep(1);
    cout << "1" << endl;
    sleep(1);
    animalAlreadyExitsInCart = true;
  }
  
  if (!animalAlreadyExitsInCart) {
    userCart.push_back(selectedAnimal);
    userCartAnimalIdHash.insert(selectedAnimal.getID());
    cout << "Animal added to your shopping cart." << endl;
  }
  cout << endl;
}

// insert method for adding a new animal to Donna’s inventory
void AnimalDB::insertDonnaAnimal(Animal animal) {
  string animalType = animal.getType();
  int animalID = animal.getID() - 1;
  
  typeHashIDX[animalType].push_back(animalID);
  animals.push_back(animal);
}