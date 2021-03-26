#pragma once
#include "PhoneAccessories.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class BluetoothHeadset :
    public PhoneAccessories
{
private:
    string bluetoothVersion;

	BluetoothHeadset* bluetoothHeadsetList;
	int listSize;
public:
	string getBluetoothVersion();

	//повертає об'єкт за ID
	BluetoothHeadset getBluetoothHeadsetByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

