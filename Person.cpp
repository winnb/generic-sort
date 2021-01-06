#include <string>
#include "Person.h"

//Friend Funtions - These are not members of the class but still overloaded functions
std::ostream& operator<<(std::ostream& out, const Person& inst) {
	out << inst.name << ", " << inst.age;

	return out;
}//End of function operator<<

//Overloaded Operators
//These functions define operator usage with the class Person
bool Person::operator<(Person rh) {
	if (name < rh.name && age < rh.age)	//If name and age are both less than. Comparison of strings and ints are already defined
		return true;
	else if (name == rh.name and age < rh.age)
		return true;
	else if (name < rh.name)
		return true;
	else
		return false;
}//End of function operator<

bool Person::operator>(Person rh) {
	if (name > rh.name && age > rh.age)	//If name and age are both greater than. Comparison of strings and ints are already defined
		return true;
	else if (name == rh.name and age > rh.age)
		return true;
	else if (name > rh.name)
		return true;
	else
		return false;
}//End of function operator>

bool Person::operator==(Person rh) {
	if (name == rh.name && age == rh.age)	//If name and age are both equal to. Comparison of strings and ints are already defined
		return true;
	else
		return false;
}//End of function operator==

bool Person::operator!=(Person rh) {
	if (name != rh.name || age != rh.age)	//If either name or age is not equal to. Comparison of strings and ints are already defined
		return true;
	else
		return false;
}//End of function operator!=

bool Person::operator<=(Person rh) {
	if (!(*this > rh))	//If greater than is false, then less than or equal to is true
		return true;
	else
		return false;
}//End of function operator<=

bool Person::operator>=(Person rh) {
	if (!(*this < rh))	//If less than is false, then greater than or equal to is true
		return true;
	else
		return false;
}//End of function operator>=

Person Person::operator=(Person rh) {	//A function to assign the values of rh to the calling instance
	name = rh.name;
	age = rh.age;
	return *this;
}//End of function operator=

//Constructors
//These functions establish the default values of an instance at creation

Person::Person() {
	//Do nothing because variables already have a default value
}//End of defauult constructor

Person::Person(std::string initName, int initAge)	{
	//Give the member variables an initial value defined in the header
	name = initName;
	age = initAge;
}//End of overloaded constructor

//Getters - The Accessor functions for the class
const std::string Person::getName() {return name; }//End of function getName
const int Person::getAge() { return age; }//End of function getAge

//Setters - The Mutator functions for the class
void Person::setName(std::string newName) { name = newName; }
void Person::setAge(int newAge) { age = newAge; }