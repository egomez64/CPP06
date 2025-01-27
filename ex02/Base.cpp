#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base *generate()
{
	int nb = std::rand() % 3;
	switch (nb)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
		{
			std::cerr << "error on the random switch" << std::endl;
			return NULL;
		}
	}
}

void identify(Base *p)
{
	if (!p)
		throw(std::out_of_range("Pointer NULL"));
	if (dynamic_cast <A*> (p))
		std::cout << "Pointer type : A" << std::endl;
	else if (dynamic_cast <B*> (p))
		std::cout << "Pointer type : B" << std::endl;
	else if (dynamic_cast <C*> (p))
		std::cout << "Pointer type : C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A test = dynamic_cast <A&> (p);
		std::cout << "Reference type : A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B test = dynamic_cast <B&> (p);
		std::cout << "Reference type : B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C test = dynamic_cast <C&> (p);
		std::cout << "Reference type : C" << std::endl;
			}
			catch(const std::exception& e)
			{
				throw(std::out_of_range("Reference is not A, B or C"));
			}
		}
	}
}