#include "Base.hpp"
#include <ctime>

int	main(void)
{
	Base	*test;
	std::srand(std::time(NULL));

	try
	{
		test = generate();
		identify(test);
		identify(*test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete test;
	test = NULL;
	try
	{
		identify(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		identify(*test);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}