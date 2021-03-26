#pragma once
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class SIMCard :
    public Product
{
private:
    string vipNumber;

	SIMCard* simCardList;
	int listSize;
public:
	string getVipNumber();

	//������� ��'��� �� ID
	SIMCard getSIMCardByID(int id);

	int listSizeCheck();

	//�������� ������� ������
	void viewProducts(string filePath) override;
	//�������� ��������� ����� ������ �� ������ � ����
	void initProduct(std::ifstream& file) override;
	//������� ���� ������ � ������� true ���� �� ������� � false ���� �
	bool updateProductList(int id, int amount) override;
};

