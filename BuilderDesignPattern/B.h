#pragma once
class C;

class B
{
	protected:
	int a;
	public:
	B(int);
	void print()
	{
		std::cout << "the value of a: " << a << std::endl;
	}
	C doings();
};

B::B(int a) : a{ a } {};

//the class for c, that runs from the main loop of the longest threading instance.......
class C : public B
{
	public:
	C(int a) : B{ a } {};

};

C B::doings()
{
	return C{ 3 };
}
