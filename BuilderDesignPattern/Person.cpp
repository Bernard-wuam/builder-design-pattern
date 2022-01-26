#include "Person.h"

Person::Person(){
	
}

Person::Person(std::string name, int age) : name{ name }, age{ age }{};

void Person::print_detials()
{
	std::cout << "name: " << name << std::endl;
	std::cout << "street name: " << street << std::endl;
	std::cout << "age : " << age << std::endl;
};

PersonBuilder<Person> Person::create_person()
{
	return PersonBuilder<Person>{};
}
