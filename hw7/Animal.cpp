#include "Animal.h"
#include <iostream>
#include <iomanip>

int Animal::currentID = 1;

Animal::Animal() {
  this->ID     = 0;
  this->Type   = "";
  this->Weight = 0.0;
  this->Age    = 0;
  this->Price  = 0.0;
}

Animal::Animal(const string Type, const float Weight,
               const int Age, const float Price) {
  this->ID     = this->currentID++;
  this->Type   = Type;
  this->Weight = Weight;
  this->Age    = Age;
  this->Price  = Price;
}

Animal::Animal(const Animal &copy) {
  this->ID     = copy.ID;
  this->Type   = copy.Type;
  this->Weight = copy.Weight;
  this->Age    = copy.Age;
  this->Price  = copy.Price;
}

Animal::~Animal() {
  // no pointers no problem.
  
}

// utility
void Animal::print() const {
  cout << setw(10) << left << this->getID();
  cout << setw(10) << this->getType();
  cout << setw(10) << this->getAge();
  cout << setw(15) << this->getWeight();
  cout << fixed << setprecision(2) << "$ " << this->getPrice();
  cout << endl;
}

// get methods functions
int Animal::getID() const { return this->ID; }
string Animal::getType() const { return this->Type; }
float Animal::getWeight() const { return this->Weight; }
int Animal::getAge() const { return this->Age; }
float Animal::getPrice() const { return this->Price; }

// set methods functions
void Animal::setID(int ID) { this->ID = ID; }

void Animal::setType(string Type) { this->Type = Type; }

void Animal::setWeight(float Weight) { this->Weight = Weight; }

void Animal::setAge(int Age) { this->Age = Age; }

void Animal::setPrice(float Price) { this->Price = Price; }