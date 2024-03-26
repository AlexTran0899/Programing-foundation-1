#include "Animal.h"
#include "AnimalDB.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>

using namespace std;

void readFile(const string filename, AnimalDB &animals) {
  // open file, check if failed
  ifstream din;
  din.open(filename.c_str());

  if (din.fail()) {
    cout << "Error; file " << filename << " could not be opened" << endl;
    return;
  }

  // declare local temp. class variables for reading data
  string type;
  float weight;
  int age;
  float price;
  string extra;
  char dollar;

  while (!din.eof()) {
    // logic for reading in data, ignoring unwanted data
    din >> type >> weight;
    getline(din, extra);
    din >> age;
    getline(din, extra);
    din.get(dollar);
    din >> price;
    getline(din, extra);

    // define new Animal object and insert new animal into Donna's inventory
    Animal newAnimal(type, weight, age, price);
    if (!din.eof())
      animals.insertDonnaAnimal(newAnimal);
  }
  din.close();
}

void writeFile(const string filename, AnimalDB animals) {
  // open file for output, check if failed
  ofstream dout;

  dout.open(filename.c_str());

  if (dout.fail()) {
    cout << "Error; file " << filename << " could not be opened" << endl;
    return;
  }

  // loop for each index in the userCart array, write data of each Animal object
  // to output file in CSV formats
  for (int i = 0; i < animals.getNumCartItems(); i++) {
    Animal currentAnimal = animals.getUserAnimalByIDX(i);
    dout << currentAnimal.getID() << ',' << currentAnimal.getType() << ','
         << currentAnimal.getWeight() << ',' << currentAnimal.getAge() << ','
         << currentAnimal.getPrice() << ',' << endl;
  }
  dout << ",,,," << animals.getCurrentTotal();
  dout.close();
}

void printMenu() {
  cout << "\n1: Print all animals in Donna's inventory"
       << "\n2: Print animals of a certain type, weight and age range"
       << "\n3: Add an animal to your shopping cart"
       << "\n4: Complete your order, print receipt and exit the program\n";
}

char getUserChoice() {
  char userChoice = '\0';

  do {
    cout << "\nEnter menu selection: ";
    cin >> userChoice;
    if (userChoice < '1' || userChoice > '4')
      cout << "\nError: invalid input. Please try again." << endl;
  } while (userChoice < '1' || userChoice > '4');
  cout << endl;

  return userChoice;
}

int main() {
  char userChoice;
  AnimalDB animals;
  readFile("donnaInventory.txt", animals);
  cout << "This program takes up a lot of vertical space, ";
  cout << "Please expand your terminal vertically ;)" << endl << endl;
  cout << "Moving on in: " << endl;
  
  for(int i = 3; i >= 0; i--){
    sleep(1);
    cout << i << endl;
  }

  system("clear");

  cout << "\nWelcome to Donna's Farm! Here are your choices:" << endl;

  do {
    // this while loop will start by printing the previous user search result every time.
    animals.printPrevFilteredResult();
    // Next it will print what the user have in their shopping cart and total
    animals.printShopingCart();
    animals.printCurrentTotal();

    printMenu();
    cout << "\x1b[B";
    userChoice = getUserChoice();

    switch (userChoice) {
    case '1':
      animals.setPrintArrayToPrintDonnaInventory();
      break;
    case '2':
      animals.setPrintArrayToPrintAnimalByTypeWeightAge();
      break;
    case '3':
      animals.insertItemIntoCart();
      break;
    case '4':
      cout << "Are you sure you want to exit the program?" << endl;
      cout << "Please enter 'y' for yes";
      cout << " or any other character to cancel program termination: ";
      cin >> userChoice;
      userChoice = userChoice == 'y' ? '4' : 'n';
      break;
    default:
      cout << "Invalid input" << endl;
    }
    system("clear");
  } while (userChoice != '4');

  if(animals.getNumCartItems() < 1){
    cout << "You have nothing in your cart" << endl;
  } else {
    animals.printShopingCart();
    animals.printCurrentTotal();
    writeFile("output.txt",animals);
  }
  cout << "Goodbye." << endl;

  return 0;
}