#ifndef ANIMALDB_H
#define ANIMALDB_H

#include "Animal.h"
#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class AnimalDB {
public:
  // Constructors
  AnimalDB();
  AnimalDB(const AnimalDB &copy);
  ~AnimalDB();

  // Utility methods
  void printHeader() const;
  void printShopingCart() const;
  void printCurrentTotal() const;
  void printPrevFilteredResult() const;

  void filterAnimalByWeight(vector<Animal>& selectionArr);
  void filterAnimalByAge(vector<Animal>& selectionArr);
  void filterAnimalByType(vector<Animal>& selectionArr);

  // Get methods
  Animal getUserAnimalByIDX(const int i) const; 
  Animal getDonnaAnimalByID(const int i) const;
  int getTotalAnimalInZoo() const ;
  int getNumCartItems() const;
  float getCurrentTotal() const;
  vector<Animal> getAllAnimalInZooArr() const;
  vector<Animal> getAllAnimalInShoppingCart() const;
  unordered_map<string, vector<int> > getTypeHashIDX() const;

  // Set methods
  void setPrintArrayToPrintAnimalByTypeWeightAge();
  void insertDonnaAnimal(const Animal animal);
  void insertItemIntoCart();
  void setPrintArrayToPrintDonnaInventory();

private:
  //Member variables:

  // array of animals inside Donna zoo.
  vector<Animal> animals;
  // Ideally userChoice array would be outside the animalDB but just following the instruction... partially.
  vector<Animal> userCart;
  // Animal userCart[100];

  set<int> userCartAnimalIdHash;

  // hash the index of each animal type
  // could probably use a 2d array
  // {"horse": [1,40,29,...], "cow": [2,4,9,..]}
  unordered_map<string, vector<int> > typeHashIDX; 
  // This will be the search result array that the program
  // will print everytime the main do while loop start
  // yes I know this is pure genius, please feel free to clap 
  vector<Animal> printArray;
};

#endif