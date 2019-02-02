#include<iostream>
#include<string>

class Teacher
{
    private:
    std::string m_name;

    public:
    Teacher(std::string name) : m_name(name)
    {
    }

    std::string getName(){ return m_name;}

};

class Department
{
    private:
    // This dept holds only one teacher for simplicity, but it could hold many teachers
    Teacher *m_teacher;
    public:
    Department(Teacher *teacher = nullptr):m_teacher(teacher)
    {
    }
};

int main()
{
    // Create a teacher outside the scope of the Department
    Teacher *teacher = new Teacher("Bob"); // create a teacher
    {
        // Create a department and use the constructor parameter to pass
        // the teacher to it.
        Department dept(teacher);
 
    } // dept goes out of scope here and is destroyed
 
    // Teacher still exists here because dept did not delete m_teacher
 
    std::cout << teacher->getName() << " still exists!";
 
    delete teacher;
 
    return 0;
}