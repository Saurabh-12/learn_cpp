#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
    std::string studentName;
    char mGrade;
};

class GradeMap
{
  private:
    std::vector<StudentGrade> m_map;

  public:
    GradeMap()
    {
    }
    char& operator[](const std::string &name);
};

char & GradeMap::operator[](const std::string &name)
{
    // See if we can find the name in the vector
    for (auto &ref : m_map)
    {
        // If we found the name in the vector, return the grade
        if (ref.studentName == name)
            return ref.mGrade;
    }

    // otherwise create a new StudentGrade for this student
    StudentGrade temp{name, ' '};

    // otherwise add this to the end of our vector
    m_map.push_back(temp);

    // and return the element
    return m_map.back().mGrade;
}

int main()
{
	GradeMap grades;
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
 
	return 0;
}