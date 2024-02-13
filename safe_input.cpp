#include "safe_input.h"

// �������� �� ���� ������ ����� 
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
			std::cerr << "\n������������ ����. ��������� �������." << std::endl << std::endl;
			bad_input = 1;
		}
	} while (bad_input);
	return;
}

// �������� �� ���� ������ 
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
			std::cerr << "\n������������ ����. ��������� �������." << std::endl;
			bad_input = 1;
		}
	} while (bad_input);
	return;
}

// �������� �� ���� ������������� ����� 
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
			std::cout << "������������ ����. ��������� �������." << std::endl;
			std::cin.ignore();
			continue;
		}
		val = stod(answer);
		return;
	}
}

// ������ �� ��� ��� 
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
			if (answer == "��" || answer == "��" || answer == "1")
			{
				return 1;
			}
			else if (answer == "���" || answer == "���" || answer == "0")
			{
				return 0;
			}
			bad_input = 1;
		}
		catch (std::invalid_argument e)
		{
			std::cerr << "\n������������ ����. ��������� �������." << std::endl;
			bad_input = 1;
		}
	} while (bad_input);
	return 0;
}