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
    string compatible;//сумісність
    string coatingType;//тип покриття

	ProtectiveGlass* protectiveGlassList;
	int listSize;
public:
	string getCompatible();
	string getCoatingType();

	//повертає об'єкт за ID
	ProtectiveGlass getProtectiveGlassByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

