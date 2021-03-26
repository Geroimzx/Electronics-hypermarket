#pragma once
#include "PhoneAccessories.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Headphone :
    public PhoneAccessories
{
private:
    string connectorType;
    string noiseReduction;
    string color;

	Headphone* headphoneList;
	int listSize;
public:
	string getConnectorType();
	string getNoiseReduction();
	string getColor();

	//повертає об'єкт за ID
	Headphone getHeadphoneByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

