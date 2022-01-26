#pragma once
#include <string>
#include <iostream>
#include "PersonBuilder.h"

class Person
{
	std::string name = "undefined";
	std::string street = "undefined";
	int age = 0;

	public:
	Person();
	Person(std::string, int);
	void print_detials();

	static PersonBuilder<Person> create_person();

	template<class T>
	friend class PersonBuilder;


	template <class T>
	friend class PersonAgeBuilder;


	template <class T>
	friend class PersonNameBuilder;

	template <class T>
	friend class PersonStreetBuilder;
};

