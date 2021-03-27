#pragma once
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class VideoCamera :
    public Product
{
private:
	string matrixType;
	string stabilization;
	string resolution;
	string opticZoom;
	string sensorScreen;
	string audiosystem;
	int batteryCapacity;
	string color;

	VideoCamera* videoCameraList;
	int listSize;
public:
	//повертає об'єкт за ID
	VideoCamera getVideoCameraByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

