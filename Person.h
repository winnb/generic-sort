


#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {

public:
	//Friend Functions
	friend std::ostream& operator<<(std::ostream& out, const Person& inst);
	//Overloaded Operators 
	bool operator<(Person rh);
	bool operator>(Person rh);
	bool operator==(Person rh);
	bool operator!=(Person rh);
	bool operator<=(Person rh);
	bool operator>=(Person rh);
	Person operator=(Person rh);

	//Constructors
	Person();
	Person(std::string initName, int initAge);

	//Getters
	const std::string getName();
	const int getAge();

	//Setters
	void setName(std::string newName);
	void setAge(int newAge);

	//Member Variables
	std::string name;
	int age;

};//End of class Person

#endif // !PERSON_H

