#include "safe_input.h"

// Проверка на ввод целого числа 
void SafeInput::safe_input(std::string message, int& val)
{
	std::string answer = "";
	bool bad_input = 0;
	do
	{
		try
		{
			std::cout << message;
			std::cin >> answer;
			std::cin.ignore();
			bad_input = 0;
			val = stoi(answer);
		}
		catch (std::invalid_argument e)
		{
			std::cerr << "\nНекорректный ввод. Повторите попытку." << std::endl << std::endl;
			bad_input = 1;
		}
	} while (bad_input);
	return;
}

// Проверка на ввод строки 
void SafeInput::safe_input(std::string message, std::string& val)
{
	std::string answer = "";
	bool bad_input = 0;
	do
	{
		try
		{
			std::cout << message;
			std::getline(std::cin, answer, '\n');
			val = answer;

			bad_input = 0;
		}
		catch (std::invalid_argument e)
		{
			std::cerr << "\nНекорректный ввод. Повторите попытку." << std::endl;
			bad_input = 1;
		}
	} while (bad_input);
	return;
}

// Проверка на ввод вещественного числа 
void SafeInput::safe_input(std::string message, double& val)
{
	std::string answer;
	while (true)
	{
		try
		{
			std::cout << message;
			std::getline(std::cin, answer, '\n');
			stod(answer);
		}
		catch (...)
		{
			std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
			std::cin.ignore();
			continue;
		}
		val = stod(answer);
		return;
	}
}

// Запрос да или нет 
bool SafeInput::end_request(std::string message)
{
	std::string answer = "";
	bool bad_input = 0;
	do
	{
		try
		{
			std::cout << message;
			std::cin >> answer;
			std::cin.ignore();
			if (answer == "Да" || answer == "да" || answer == "1")
			{
				return 1;
			}
			else if (answer == "Нет" || answer == "нет" || answer == "0")
			{
				return 0;
			}
			bad_input = 1;
		}
		catch (std::invalid_argument e)
		{
			std::cerr << "\nНекорректный ввод. Повторите попытку." << std::endl;
			bad_input = 1;
		}
	} while (bad_input);
	return 0;
}