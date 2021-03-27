#pragma once
#include "PCAccessories.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class DDR :
    public PCAccessories
{
private:
	int modulesCount;
	int memoryCapacity;
	int frequency;
	string timings;

	DDR* ddrList;
	int listSize;
public:
	//повертає об'єкт за ID
	DDR getDDRByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

