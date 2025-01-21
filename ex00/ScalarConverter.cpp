#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	static_cast <void> (src);
	return *this;
}

void ScalarConverter::convert(const std::string &str)
{
	int _type = type(str);
	switch (_type)
	{
		case INT:
			return ScalarConverter::int_type(std::strtol(str.c_str(), NULL, 10));
		case CHAR:
			return ScalarConverter::char_type(str[0]);
		case FLOAT:
			return ScalarConverter::float_type(strtof(str.c_str(), NULL));
		case DOUBLE:
			return ScalarConverter::double_type(strtod(str.c_str(), NULL));
		case INF:
			return ScalarConverter::inf_type(str);
		case _NAN:
			return ScalarConverter::nan_type(str);
		default:
			std::cerr << "Bad parameter entrance" << std::endl;
	}
}

int ScalarConverter::type(const std::string &str)
{
	if (str.size() == 1 && std::isprint(str.at(0)) && !std::isdigit(str.at(0)))
		return CHAR;
	if (str == "inf" || str == "-inf" || str == "inff" || str == "-inff")
		return INF;
	if (str == "nan" || str == "nanf")
		return _NAN;
	for (std::string::const_iterator i = str.begin(); i < str.end(); i++)
	{
		if (i == str.begin() && (*i == '-' || *i == '+'))
			continue ;
		if (i == str.end() - 1 && *i == 'f')
			break ;
		if (!std::isdigit(*i) && *i != '.')
			return BAD;
	}
	if (str.find('.') == std::string::npos)
		return INT;
	else if (str.find_first_of('.') != str.find_last_of('.'))
		return BAD;
	else if (*(str.end() - 1) == 'f')
		return FLOAT;
	else
		return DOUBLE;
}

void ScalarConverter::char_type(const char &c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast <int> (c) << std::endl;
	std::cout << "float: " << static_cast <float> (c) << "f" << std::endl;
	std::cout << "double: " << static_cast <double> (c) << std::endl;
}

void ScalarConverter::int_type(const long int &nb)
{
	if (nb < 0 || nb > 127 || !std::isprint(nb))
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: " << static_cast <char> (nb) << std::endl;
	if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << static_cast <float> (nb) 
	<< "f" << std::endl;
	std::cout << "double: " << static_cast <double> (nb) << std::endl;
}

void ScalarConverter::float_type(const float &nb)
{
	if (nb < 0 || nb > 127 || !std::isprint(nb))
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: " << static_cast <char> (nb) << std::endl;
	if (nb < static_cast<float>(std::numeric_limits<int>::min()) || nb > static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast <int > (nb) << std::endl;
	std::cout << "float: " << nb << "f" << std::endl;
	std::cout << "double: " << static_cast <double> (nb) << std::endl;
}

void ScalarConverter::double_type(const double &nb)
{
	if (nb < 0 || nb > 127 || !std::isprint(nb))
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: " << static_cast <char> (nb) << std::endl;
	if (nb < static_cast<double>(std::numeric_limits<int>::min()) || nb > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast <int > (nb) << std::endl;
	if (nb < static_cast<double>(std::numeric_limits<float>::min()) || nb > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "float: Impossible" << std::endl;
	else
		std::cout << "float: " << static_cast <float > (nb) << "f" << std::endl;
	std::cout << "double: " << static_cast <double> (nb) << std::endl;
}

void ScalarConverter::inf_type(const std::string &str)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	if (str.compare(1, 4, "inf"))
	{
		double d = std::numeric_limits<double>::infinity();
		if (str[0] == '-')
			d = -d;
		std::cout << "float: " << static_cast <float> (d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else
	{
		float f = std::numeric_limits<float>::infinity();
		if (str[0] == '-')
			f = -f;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast <double> (f) << std::endl;
	}
}

void ScalarConverter::nan_type(const std::string &str)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	if (str == "nanf")
	{
		float f = std::numeric_limits<float>::quiet_NaN();
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast <double> (f) << std::endl;
	}
	else
	{
		double d = std::numeric_limits<double>::quiet_NaN();
		std::cout << "float: " << static_cast <float> (d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}
