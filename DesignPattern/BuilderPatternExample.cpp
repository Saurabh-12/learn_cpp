#include<iostream>

class PersonBuilder;

class Person{
    private:
        std::string name;
        std::string address;
        std::string job;
        Person(){}
    public:
        static PersonBuilder Build();
        friend class PersonBuilder;
};

class PersonBuilder{
    private:
        Person person;
    public:
        PersonBuilder(Person& person):person(person){}
        PersonBuilder& name(std::string name){
            this->person.name = name;
            return *this;
        }
        PersonBuilder& address(std::string address){
            this->person.address = address;
            return *this;
        }
        PersonBuilder& job(std::string job){
            this->person.job = job;
            return *this;
        }
        
        operator Person(){
            return this->person;
        }
};

PersonBuilder Person::Build(){
    Person p;
    return PersonBuilder{p};
}

int main() {
    Person p = Person::Build()
        .name("Amresh")
        .address("Bikram, Patna, Bihar")
        .job("Software Engineer at Arive");

    return 0;
}