#pragma once
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Television :
    public Product
{
private:
	float diagonal;
	string resolution;
	string technology;
	string operatingSystem;

	Television* televisionList;
	int listSize;
public:
	//������� ��'��� �� ID
	Television getTVByID(int id);

	int listSizeCheck();

	//�������� ������� ������
	void viewProducts(string filePath) override;
	//�������� ��������� ����� ������ �� ������ � ����
	void initProduct(std::ifstream& file) override;
	//������� ���� ������ � ������� true ���� �� ������� � false ���� �
	bool updateProductList(int id, int amount) override;
};

