#pragma once
#include "PhoneAccessories.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class ProtectiveGlass :
    public PhoneAccessories
{
private:
    string compatible;//��������
    string coatingType;//��� ��������

	ProtectiveGlass* protectiveGlassList;
	int listSize;
public:
	string getCompatible();
	string getCoatingType();

	//������� ��'��� �� ID
	ProtectiveGlass getProtectiveGlassByID(int id);

	int listSizeCheck();

	//�������� ������� ������
	void viewProducts(string filePath) override;
	//�������� ��������� ����� ������ �� ������ � ����
	void initProduct(std::ifstream& file) override;
	//������� ���� ������ � ������� true ���� �� ������� � false ���� �
	bool updateProductList(int id, int amount) override;
};

