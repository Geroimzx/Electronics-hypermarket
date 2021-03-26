#pragma once
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Telephone :
    public Product
{
private:
	Telephone* telephoneList;
	int listSize;
public:
	//повертає об'єкт за ID
	Telephone getTelephoneByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

