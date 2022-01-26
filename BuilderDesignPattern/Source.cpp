#include <iostream>
#include <string>
#include "Person.h"

int main()
{

	Person::create_person().age().set_age(34)
						   .name().set_name("james")
						   .street().set_street("magagin-gari")
		                   .print_details();
	
	return 0;
}