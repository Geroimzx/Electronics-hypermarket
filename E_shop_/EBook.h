#pragma once
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class EBook :
    public Product
{
private:
	int storageMemory;
	int RAM;
	string formatSupport;
	string operatingSystem;
	float displaySize;
	string displayType;
	string color;
	int batteryCapacity;

	EBook* ebookList;
	int listSize;
public:
	//повертає об'єкт за ID
	EBook getEBookByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

