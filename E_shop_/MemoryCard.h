#pragma once
#include "PhoneAccessories.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class MemoryCard :
    public PhoneAccessories
{
private:
    int storageMemory;
    string speedClass;

	MemoryCard* memoryCardList;
	int listSize;
public:
	int getStorageMemory();
	string getSpeedClass();

	//������� ��'��� �� ID
	MemoryCard getMemoryCardByID(int id);

	int listSizeCheck();

	//�������� ������� ������
	void viewProducts(string filePath) override;
	//�������� ��������� ����� ������ �� ������ � ����
	void initProduct(std::ifstream& file) override;
	//������� ���� ������ � ������� true ���� �� ������� � false ���� �
	bool updateProductList(int id, int amount) override;
};

