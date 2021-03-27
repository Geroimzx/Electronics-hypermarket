#pragma once
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Printer3D :
    public Product
{
private:
	string technology;
	string material;
	int nozzlesCount;
	int maxSpeed;

	Printer3D* printer3DList;
	int listSize;
public:
	//повертає об'єкт за ID
	Printer3D getPrinter3DByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

