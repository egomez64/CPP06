#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	uintptr_t ptr;
	data->data = 222;

	try
	{
		std::cout << "Before : " << data->data << std::endl;
		ptr = Serializer::serialize(data);
		std::cout << "After : " << Serializer::deserialize(ptr)->data << " / " << ptr << std::endl;
		delete data;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}