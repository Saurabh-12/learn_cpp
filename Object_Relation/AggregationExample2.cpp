#include<iostream>
#include<string>
#include<vector>

class Teachers
{
    private:
    std::string m_name ;

    public:
    Teachers(std::string name):m_name(name)
    {
    }

    std::string getName(){ return m_name; }

};

class Departments
{
    private:
    std::vector<Teachers*> m_teacher;

    public:
    Departments()
    {
    }

    void addTeacher(Teachers *teacher)
    {
        m_teacher.push_back(teacher);
    }

friend std::ostream& operator<<(std::ostream &out, const Departments &dept)
	{
		out << "Department: ";
		for (unsigned int count = 0; count < dept.m_teacher.size(); ++count)
			out << dept.m_teacher[count]->getName() << ' ';
		out << '\n';
 
		return out;
	}
};

int main()
{
    	// Create a teacher outside the scope of the Department
	Teachers *t1 = new Teachers("Bob"); // create a teacher
	Teachers *t2 = new Teachers("Frank");
	Teachers *t3 = new Teachers("Beth");
 
	{
		// Create a department and add some Teachers to it
		Departments dept; // create an empty Department
		dept.addTeacher(t1);
		dept.addTeacher(t2);
		dept.addTeacher(t3);
 
		std::cout << dept;
 
	} // dept goes out of scope here and is destroyed
 
	std::cout << t1->getName() << " still exists!\n";
	std::cout << t2->getName() << " still exists!\n";
	std::cout << t3->getName() << " still exists!\n";
 
	delete t1;
	delete t2;
	delete t3;

    return 0;
}