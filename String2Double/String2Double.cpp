// String2Double.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

double str2double(const char *name, int length)
{
	double result = 0;
	float back = 0;
	int commaPos = 1;
	bool comma = 0;

	for (int i = 0; i < length - 1; i++)
	{
		if (name[i] == '.')
			comma = 1;
		if (name[i] <= '9' && name[i] >= '0')
		{
			float tmp = name[i] - '0';
			if (!comma)
				result = result * 10 + tmp;
	
			else if (comma)
			{
				commaPos *= 10;
				back = back + (tmp / commaPos);
			}
		}
	}
	return result + back;
}

int main()
{	
	char str[] = "a%&s12f.67d$";
    
	double res = str2double(str, sizeof(str)/sizeof(str[0]));

	std::cout << res;

	return 0;
}
