#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <string.h>
#include <limits>
#include <cstdlib>

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void convert(const std::string &str);

	private:
		static int type(const std::string &str);
		static void char_type(const char &c);
		static void int_type(const long int &nb);
		static void float_type(const float &nb);
		static void double_type(const double &nb);
		static void inf_type(const std::string &str);
		static void nan_type(const std::string &str);

	private:
		enum TYPE
		{
			BAD,
			INT,
			FLOAT,
			DOUBLE,
			CHAR,
			INF,
			_NAN,
		};

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
};

#endif