#include <ScalarConverter.hpp>

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
		case CHAR:
		case FLOAT:
		case DOUBLE:
		case INF:
		case _NAN:
		default:
	}
}

int ScalarConverter::type(const std::string &str)
{
	if (str.size() == 1 && std::isprint(str.at(0)) && !std::isdigit(str.at(0)))
		return CHAR;
	if (str == "inf" || str == "-inf" || str == "inff" || str == "-inff")
		return INF;
	if (str == "nan" || str == "-nan")
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
	std::cout << "int: " << static_cast <double> (c) << std::endl;
}

void ScalarConverter::int_type(const int &nb)
{
	if (nb < 0 || nb > 127 || !std::isprint(nb))
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: " << static_cast <char> (nb) << std::endl;
	if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << static_cast <float> (nb) << "f" << std::endl;
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
