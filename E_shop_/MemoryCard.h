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

	//повертає об'єкт за ID
	MemoryCard getMemoryCardByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

