#pragma once
#include "PhoneAccessories.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class BluetoothHeadset :
    public PhoneAccessories
{
private:
    string bluetoothVersion;

	BluetoothHeadset* bluetoothHeadsetList;
	int listSize;
public:
	string getBluetoothVersion();

	//������� ��'��� �� ID
	BluetoothHeadset getBluetoothHeadsetByID(int id);

	int listSizeCheck();

	//�������� ������� ������
	void viewProducts(string filePath) override;
	//�������� ��������� ����� ������ �� ������ � ����
	void initProduct(std::ifstream& file) override;
	//������� ���� ������ � ������� true ���� �� ������� � false ���� �
	bool updateProductList(int id, int amount) override;
};

