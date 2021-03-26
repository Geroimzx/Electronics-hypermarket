#pragma once
#include "PhoneAccessories.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Cover :
    public PhoneAccessories
{
private:
    string compatible;
    string color;

	Cover* сoverList;
	int listSize;
public:
	string getCompatible();
	string getColor();

	//повертає об'єкт за ID
	Cover getCoverByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

