#pragma once
#include <iostream>
#include <string>

// Класс безапасного ввода, для защиты программы от некорректного ввода в переменные
class SafeInput
{
public:
	// Перегрузка для целочисленных переменных
	void safe_input(std::string message, int& val);

	// Перегрузка для строковых переменных
	void safe_input(std::string message, std::string& val);

	// Перегрузка для вещественных переменных
	void safe_input(std::string message, double& val);

	// Запрос на Да или Нет
	bool end_request(std::string message);
};