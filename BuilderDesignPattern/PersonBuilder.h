#pragma once
#include "Person.h"


template <class T>
class PersonAgeBuilder;

template <class T>
class PersonNameBuilder;

template <class T>
class PersonStreetBuilder;

template <class T>
class PersonBuilder
{
	T person;
	protected:
	T& person_address;

	public:
	PersonBuilder() : person_address{person}
	{

	}
	PersonBuilder(PersonBuilder<T>&& other): person_address{other.person_address}
	{

	}
	PersonBuilder(T& person_address) : person_address{ person_address } {};

	operator T()
	{
		return std::move(person_address);
	}

	PersonAgeBuilder<T> age();
	PersonNameBuilder<T> name();
	PersonStreetBuilder<T> street();

	void print_details()
	{
		std::cout << "Name: " << person_address.name << std::endl;
		std::cout << "Age: " << person_address.age << std::endl;
		std::cout << "Street: " << person_address.street << std::endl;
	}
	
};


//age builder section

template <class T>
class PersonAgeBuilder : public PersonBuilder<T>
{
	public:
	PersonAgeBuilder(T& person_address) : PersonBuilder<T>{person_address} {};
	PersonAgeBuilder& set_age(int age_)
	{
		PersonBuilder<T>::person_address.age = age_;
		return *this;
	}

};

template <class T>
PersonAgeBuilder<T> PersonBuilder<T>::age()
{
	return PersonAgeBuilder<T>{ PersonBuilder<T>::person_address };
}


//end of age builder section



//.....................................................paragraph...........................................................//



//name builder section

template <class T>
class PersonNameBuilder : public PersonBuilder<T>
{
	public:
	PersonNameBuilder(T& person_address) : PersonBuilder<T>{ person_address } {};
	PersonNameBuilder& set_name(std::string name_)
	{
		PersonBuilder<T>::person_address.name = name_;
		return *this;
	}

};


template <class T>
PersonNameBuilder<T> PersonBuilder<T>::name()
{
	return PersonNameBuilder<T>{ PersonBuilder<T>::person_address };
}


//end of name builder section



//.....................................................paragraph...........................................................//



//street builder section

template <class T>
class PersonStreetBuilder : public PersonBuilder<T>
{
	public:
	PersonStreetBuilder(T& person_address) : PersonBuilder<T>{ person_address } {};
	PersonStreetBuilder& set_street(std::string street_)
	{
		PersonBuilder<T>::person_address.street = street_;
		return *this;
	}

};


template <class T>
PersonStreetBuilder<T> PersonBuilder<T>::street()
{
	return PersonStreetBuilder<T>{ PersonBuilder<T>::person_address };
}


//end of street builder section