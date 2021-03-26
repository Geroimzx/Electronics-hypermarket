#pragma once
#include "PhoneAccessories.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Headphone :
    public PhoneAccessories
{
private:
    string connectorType;
    string noiseReduction;
    string color;

	Headphone* headphoneList;
	int listSize;
public:
	string getConnectorType();
	string getNoiseReduction();
	string getColor();

	//������� ��'��� �� ID
	Headphone getHeadphoneByID(int id);

	int listSizeCheck();

	//�������� ������� ������
	void viewProducts(string filePath) override;
	//�������� ��������� ����� ������ �� ������ � ����
	void initProduct(std::ifstream& file) override;
	//������� ���� ������ � ������� true ���� �� ������� � false ���� �
	bool updateProductList(int id, int amount) override;
};

