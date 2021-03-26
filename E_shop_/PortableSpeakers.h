#pragma once
#include "PhoneAccessories.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class PortableSpeakers :
    public PhoneAccessories
{
private:
    int outputPower;
    int batteryLife;

	PortableSpeakers* portableSpeakersList;
	int listSize;
public:
	int getOutputPower();
	int getBateryLife();

	//повертає об'єкт за ID
	PortableSpeakers getPortableSpeakersByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

