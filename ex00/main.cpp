#include "ScalarConverter.hpp"

static void	testSeries()
{
	std::cout << "===== Characters test =====\n" << std::endl; 
	{
		ScalarConverter::convert("c");
		std::cout << std::endl;
		ScalarConverter::convert("asd");
		std::cout << std::endl;
		ScalarConverter::convert(" ");
		std::cout << std::endl;
		ScalarConverter::convert("\t");
		std::cout << std::endl;
		ScalarConverter::convert("\b");
		std::cout << std::endl;
		ScalarConverter::convert(".");
		std::cout << std::endl;
		ScalarConverter::convert("f");
	}
	std::cout << "\n===== Integers test =====\n" << std::endl; 
	{
		ScalarConverter::convert("0");
		std::cout << std::endl;
		ScalarConverter::convert("12");
		std::cout << std::endl;
		ScalarConverter::convert("129");
		std::cout << std::endl;
		ScalarConverter::convert("11111111111111");
		std::cout << std::endl;
		ScalarConverter::convert("-10");
		std::cout << std::endl;
		ScalarConverter::convert("-2147483648");
		std::cout << std::endl;
		ScalarConverter::convert("2147483647");
		std::cout << std::endl;
		ScalarConverter::convert("-2147483649");
		std::cout << std::endl;
		ScalarConverter::convert("2147483648");
	}
	std::cout << "\n===== Float test =====\n" << std::endl; 
	{
		ScalarConverter::convert("0.0f");
		std::cout << std::endl;
		ScalarConverter::convert("12f");
		std::cout << std::endl;
		ScalarConverter::convert("129.1f");
		std::cout << std::endl;
		ScalarConverter::convert("0.000000000001f");
		std::cout << std::endl;
		ScalarConverter::convert("0.000000.000001f");
		std::cout << std::endl;
		ScalarConverter::convert("3402823466f");
		std::cout << std::endl;
		ScalarConverter::convert("-2147483648f");
		std::cout << std::endl;
		ScalarConverter::convert("2147483647f");
		std::cout << std::endl;
		ScalarConverter::convert("-2147483649f");
		std::cout << std::endl;
		ScalarConverter::convert("2147483648f");
		std::cout << std::endl;
		ScalarConverter::convert("+inff");
		std::cout << std::endl;
		ScalarConverter::convert("-inff");
		std::cout << std::endl;
		ScalarConverter::convert("nanf");
	}
	std::cout << "\n===== Double test =====\n" << std::endl; 
	{
		ScalarConverter::convert("0.0");
		std::cout << std::endl;
		ScalarConverter::convert("100000000000000000000000000000000000000000000000000000000000.111111111111111111111111111111111111111111111");
		std::cout << std::endl;
		ScalarConverter::convert("-129.00000000000000000001");
		std::cout << std::endl;
		ScalarConverter::convert("0.000000000001");
		std::cout << std::endl;
		ScalarConverter::convert("0.000000.000001");
		std::cout << std::endl;
		ScalarConverter::convert("+inf");
		std::cout << std::endl;
		ScalarConverter::convert("-inf");
		std::cout << std::endl;
		ScalarConverter::convert("nan");
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; av[i]; i++)
		{
			ScalarConverter::convert(av[i]);
			if (av[i + 1])
				std::cout << std::endl;
		}
	}
	else
		testSeries();
}