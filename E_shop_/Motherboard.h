#pragma once
#include "PCAccessories.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Motherboard :
    public PCAccessories
{
private:
	string socket;
	string RAMType;
	string formFactor;

	Motherboard* motherboardList;
	int listSize;
public:
	//повертає об'єкт за ID
	Motherboard getMotherboardByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

