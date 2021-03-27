#pragma once
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Projectors :
    public Product
{
private:
	string resolution;
	string connectionInterface;

	Projectors* projectorsList;
	int listSize;
public:
	//������� ��'��� �� ID
	Projectors getProjectorByID(int id);

	int listSizeCheck();

	//�������� ������� ������
	void viewProducts(string filePath) override;
	//�������� ��������� ����� ������ �� ������ � ����
	void initProduct(std::ifstream& file) override;
	//������� ���� ������ � ������� true ���� �� ������� � false ���� �
	bool updateProductList(int id, int amount) override;
};

