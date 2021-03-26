#pragma once
#include "PhoneAccessories.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class PortableSpeakers :
    public PhoneAccessories
{
private:
    int outputPower;
    int batteryLife;

	PortableSpeakers* portableSpeakersList;
	int listSize;
public:
	int getOutputPower();
	int getBateryLife();

	//������� ��'��� �� ID
	PortableSpeakers getPortableSpeakersByID(int id);

	int listSizeCheck();

	//�������� ������� ������
	void viewProducts(string filePath) override;
	//�������� ��������� ����� ������ �� ������ � ����
	void initProduct(std::ifstream& file) override;
	//������� ���� ������ � ������� true ���� �� ������� � false ���� �
	bool updateProductList(int id, int amount) override;
};

