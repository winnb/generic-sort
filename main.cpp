#include <iostream>
#include "Person.h"
#include <algorithm> // std::sort
/* For generics in C++, the following statements are logically equivalent
   template <typename T> and template <class T>
   The difference is that typename is an older and less specific term where 
   class leads to less confusion as to what is happening
*/
//Function Declarations
template <typename T> void swap(T* a, T* b);
template <typename T> void printPeople(T arr[], int size);
bool Greater(const Person& a, const Person& b);

int main() {
	Person peepsArray[17] = { Person("Hal", 20), Person("Susann", 31), Person("Dwight", 19), Person("Kassandra", 21), Person("Lawrence", 25), 
                            Person("Cindy", 22), Person("Cory", 27), Person("Mac", 19), Person("Romana", 27), Person("Doretha", 32), 
                            Person("Danna", 20), Person("Zara", 23), Person("Rosalyn", 26), Person("Risa", 24), Person("Benny", 28), 
                            Person("Juan", 33), Person("Natalie", 25) }; // Given names and ages
	double nums[] = { 645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26 }; // Given nums
	int numsSize = sizeof(nums) / sizeof(nums[0]); // Elements in nums
	int peepsSize = sizeof(peepsArray) / sizeof(peepsArray[0]); // Elements in peeps

  // Sort using C++ generic sort function:
  // template <class RandomAccessIterator, class Compare>
  // void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
  
	std::cout << "Numbers Sorted Ascending:\n";
  std::sort(nums, nums+numsSize); // Sort numbers in ascending order
  for (int i=0; i<numsSize; i++) // Loop over nums
    std::cout << nums[i] << " "; // Print each number

  std::cout << "\n\nPeople Sorted by Name:\n";
  std::sort(peepsArray, peepsArray+peepsSize); // Sort people by name
  printPeople(peepsArray, peepsSize); // Print people

	std::cout << "\nPeople Sorted by Age Descending:\n";
	std::sort(peepsArray, peepsArray+peepsSize, Greater); // Sort people by age
  printPeople(peepsArray, peepsSize); // Print people in reverse order

	return 0; // return 0 for no errors
}//End of main

bool Greater(const Person& a, const Person& b) // Custom comparison function to sort by age then by name in descending order
{
  if (a.age != b.age) // First compare age and flip outcome so sort gets reverse order
      return !(a.age < b.age);
  else // If ages are same then compare names
      return (a.name < b.name); // Add ! to flip alphabet order
}

template <typename T>
void printPeople(T arr[], int size) {// Prints array as a column
  for (int i = 0; i < size; i++)// Iterate over entire array
			std::cout << arr[i] << "\n";; // Print each element
}