#pragma once
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Smartphone : public Product
{
private:
	int storageMemory;
	int RAM;
	string chipset;
	string operatingSystem;
	float displaySize;
	string displayType;
	int mainCamera;
	int selfieCamera;
	string color;
	int batteryCapacity;
	string features;

	Smartphone* smartphoneList;
	int listSize;
public:
	//������� ��'��� �� ID
	Smartphone getSmartphoneByID(int id);

	int listSizeCheck();

	//�������� ������� ������
	void viewProducts(string filePath) override;
	//�������� ��������� ����� ������ �� ������ � ����
	void initProduct(std::ifstream& file) override;
	//������� ���� ������ � ������� true ���� �� ������� � false ���� �
	bool updateProductList(int id, int amount) override;
};

