#pragma once
#include <iostream>
#include <string>

// ����� ����������� �����, ��� ������ ��������� �� ������������� ����� � ����������
class SafeInput
{
public:
	// ���������� ��� ������������� ����������
	void safe_input(std::string message, int& val);

	// ���������� ��� ��������� ����������
	void safe_input(std::string message, std::string& val);

	// ���������� ��� ������������ ����������
	void safe_input(std::string message, double& val);

	// ������ �� �� ��� ���
	bool end_request(std::string message);
};