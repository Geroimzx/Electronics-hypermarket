#pragma once
#include "PhoneAccessories.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Cover :
    public PhoneAccessories
{
private:
    string compatible;
    string color;

	Cover* �overList;
	int listSize;
public:
	string getCompatible();
	string getColor();

	//������� ��'��� �� ID
	Cover getCoverByID(int id);

	int listSizeCheck();

	//�������� ������� ������
	void viewProducts(string filePath) override;
	//�������� ��������� ����� ������ �� ������ � ����
	void initProduct(std::ifstream& file) override;
	//������� ���� ������ � ������� true ���� �� ������� � false ���� �
	bool updateProductList(int id, int amount) override;
};

