#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>

class String
{
private:
	char *array;
	int size;
public:
	String() : size(0) { array = nullptr; }
	String(const char *str)
	{
		size = strlen(str);
		array = new char[size + 1];
		strcpy(array, str);
	}
	String(const String &str)
	{
		size = str.size;
		array = new char[size + 1];
		strcpy(array, str.array);
	}
	~String()
	{
		if (size != 0)
		{
			delete[] array;
		}
	}

	bool empty() const
	{
		if (size == 0) { return true; }
		return false;
	}
	int size_() const { return size; }
	void clear()
	{
		size = 0;
		delete[] array;
		array = nullptr;
	}
	const char *c_str() const { if (size == 0) { return ""; } return array; }

	void operator=(const char *str)
	{
		if (size != 0)
		{
			delete[] array;
		}
		size = strlen(str);
		array = new char[size + 1];
		strcpy(array, str);
	}
	void operator=(const String &str)
	{
		if (size != 0)
		{
			delete[] array;
		}
		size = strlen(str.array);
		array = new char[size + 1];
		strcpy(array, str.array);
	}
	void operator+=(const char *str)
	{
		char *s_cpy = nullptr;
		s_cpy = new char[size + 1];
		strcpy(s_cpy, array);
		delete[] array;
		size = strlen(str) + strlen(s_cpy);
		array = new char[size + 1];
		strcpy(array, s_cpy);
		delete[] s_cpy;
		strcat(array, str);
	}
	void operator+=(const String &str)
	{
		char *s_cpy = nullptr;
		s_cpy = new char[size + 1];
		strcpy(s_cpy, array);
		delete[] array;
		size = strlen(str.array) + strlen(s_cpy);
		array = new char[size + 1];
		strcpy(array, s_cpy);
		delete[] s_cpy;
		strcat(array, str.array);
	}
	bool operator==(const char *str) const
	{
		if (strcmp(array, str) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator==(const String &str) const
	{
		if (strcmp(array, str.array) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const char *str) const
	{
		if (strcmp(array, str) != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const String &str) const
	{
		if (strcmp(array, str.array) != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	String s1;
	String s2;

	s1 = "Jesus";
	s2 = "Marc";

	std::cout << s1.c_str() << std::endl;
	std::cout << s1.size_() << std::endl;
	std::cout << s2.c_str() << std::endl;

	s1 += " Jesus 2.0";
	std::cout << s1.c_str() << std::endl;
	std::cout << s1.size_() << std::endl;

	if (s2 == "Marc")
	{
		std::cout << "True" << std::endl;
	}
	if (s2 != "Mark")
	{
		std::cout << "True" << std::endl;
	}

	if (s1.empty() != true)
	{
		std::cout << "not empty" << std::endl;
	}
	s1.clear();
	if (s1.empty() == true)
	{
		std::cout << "empty" << std::endl;
	}
	std::cout << s1.c_str() << std::endl;

	s1 = s2;
	std::cout << s1.c_str() << std::endl;
	s1 += s2;
	std::cout << s1.c_str() << std::endl;

	if (s1 != s2)
	{
		std::cout << "True" << std::endl;
	}
	s2 = s1;
	if (s1 == s2)
	{
		std::cout << "True" << std::endl;
	}
	
	system("pause");
	return 0;
}