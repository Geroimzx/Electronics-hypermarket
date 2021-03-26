#pragma once
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Telephone :
    public Product
{
private:
	Telephone* telephoneList;
	int listSize;
public:
	//������� ��'��� �� ID
	Telephone getTelephoneByID(int id);

	int listSizeCheck();

	//�������� ������� ������
	void viewProducts(string filePath) override;
	//������� ���� ������ � ������� true ���� �� ������� � false ���� �
	bool updateProductList(int id, int amount) override;
};

