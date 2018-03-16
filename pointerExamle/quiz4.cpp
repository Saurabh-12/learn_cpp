#include<iostream>

struct Student
{
    std::string mStudentname;
    int mGrade;

};

// Function to sort our students.
// Since students is a pointer to an array and doesn't know its length, we need to pass in the length explicitly
void sortNames(Student *students, int length)
{
	// Step through each element of the array
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		// largestIndex is the index of the largest element we've encountered so far.
		int largestIndex = startIndex;
 
		// Look for largest element in the remaining array (starting at startIndex+1)
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// If the current element is larger than our previously found smallest
			if (students[currentIndex].mGrade > students[largestIndex].mGrade)
				// This is the new largest number for this iteration
				largestIndex = currentIndex;
		}
 
		// Swap our start element with our largest element
		std::swap(students[startIndex], students[largestIndex]);
	}
}

int main()
{
    int numStudents = 0;
	do
	{
		std::cout << "How many students do you want to enter? ";
		std::cin >> numStudents;
	} while (numStudents <= 1);

    // Allocate an array to hold the names
	Student *students = new Student[numStudents];


	// Read in all the students
	for (int index = 0; index < numStudents; ++index)
	{
		std::cout << "Enter name #" << index + 1 << ": ";
		std::cin >> students[index].mStudentname;
		std::cout << "Enter grade #" << index + 1 << ": ";
		std::cin >> students[index].mGrade;
	}

    // Sort the names
	sortNames(students, numStudents);
 
	// Print out all the names
	for (int index = 0; index < numStudents; ++index)
		std::cout << students[index].mStudentname << " got a grade of " << students[index].mGrade << "\n";
 
	// Don't forget to deallocate the memory
	delete[] students;


    return 0;
}