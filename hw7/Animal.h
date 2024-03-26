#ifndef ANIMAL_H
#define ANIMAL_H

#include <fstream>

using namespace std;

class Animal {
public:
  // Constructors
  Animal();
  Animal(const string Type, const float Weight, const int Age,
         const float Price);
  Animal(const Animal &copy);
  ~Animal();

  // Utility methods
  void print() const;
  void setCurrentIdToZero();

  // get methods declaration
  int getID() const;
  string getType() const;
  float getWeight() const;
  int getAge() const;
  float getPrice() const;

  // set methods declaration
  void setID(int ID);
  void setType(string Type);
  void setWeight(float Weight);
  void setAge(int Age);
  void setPrice(float Price);

private:
  static int currentID;
  int ID;
  string Type;
  float Weight;
  int Age;
  float Price;
};


#endif