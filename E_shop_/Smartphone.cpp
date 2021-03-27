#include "Smartphone.h"

void Smartphone::viewProducts(string filePath)
{
	ifstream file;
	file.open(filePath);
	if (!file)
		cout << "Cannot open file" << endl;
	listSizeCheck();
	smartphoneList = new Smartphone[listSize];
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "ROM" << "|";
	cout << setw(scale) << "RAM" << "|";
	cout << setw(15) << "Процесор" << "|";
	cout << setw(scale) << "ОС" << "|";
	cout << setw(scale) << "Діагональ екрану" << "|";
	cout << setw(scale) << "Тип екрану" << "|";
	cout << setw(scale) << "Основна камера" << "|";
	cout << setw(scale) << "Фронтальна камера" << "|";
	cout << setw(scale) << "Колір" << "|";
	cout << setw(scale) << "Ємність акумулятора" << "|";
	cout << setw(scale) << "Особливості";
	for (int i = 0; i < listSize; i++)
	{
		smartphoneList[i].initProduct(file);
		cout << "\n|";
		cout.width(scale);
		cout << smartphoneList[i].ID << "|";
		cout.width(scale);
		cout << smartphoneList[i].available << "|";
		cout.width(scale);
		cout << smartphoneList[i].price << "|";
		cout.width(scale);
		cout << smartphoneList[i].brand << "|";
		cout.width(scale);
		cout << smartphoneList[i].type << "|";
		cout.width(scale);
		cout << smartphoneList[i].storageMemory << "|";
		cout.width(scale);
		cout << smartphoneList[i].RAM << "|";
		cout.width(15);
		cout << smartphoneList[i].chipset << "|";
		cout.width(scale);
		cout << smartphoneList[i].operatingSystem << "|";
		cout.width(16);
		cout << smartphoneList[i].displaySize << "|";
		cout.width(scale);
		cout << smartphoneList[i].displayType << "|";
		cout.width(14);
		cout << smartphoneList[i].mainCamera << "|";
		cout.width(17);
		cout << smartphoneList[i].selfieCamera << "|";
		cout.width(scale);
		cout << smartphoneList[i].color << "|";
		cout.width(19);
		cout << smartphoneList[i].batteryCapacity << "|";
		cout.width(11);
		cout << smartphoneList[i].features;
	}
	cout << "\n";
	file.close();
}

void Smartphone::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> storageMemory;
		file >> RAM;
		file >> chipset;
		file >> operatingSystem;
		file >> displaySize;
		file >> displayType;
		file >> mainCamera;
		file >> selfieCamera;
		file >> color;
		file >> batteryCapacity;
		file >> features;
	}
}

bool Smartphone::updateProductList(int id, int amount)
{
	if (smartphoneList[id - 1].isAvailable() && smartphoneList[id - 1].getAvailable() >= amount)
	{
		smartphoneList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("SmartphonesList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << smartphoneList[i].ID << ' ';
			outFile << smartphoneList[i].available << ' ';
			outFile << smartphoneList[i].price << ' ';
			outFile << smartphoneList[i].brand << ' ';
			outFile << smartphoneList[i].type << ' ';
			outFile << smartphoneList[i].storageMemory << ' ';
			outFile << smartphoneList[i].RAM << ' ';
			outFile << smartphoneList[i].chipset << ' ';
			outFile << smartphoneList[i].operatingSystem << ' ';
			outFile << smartphoneList[i].displaySize << ' ';
			outFile << smartphoneList[i].displayType << ' ';
			outFile << smartphoneList[i].mainCamera << ' ';
			outFile << smartphoneList[i].selfieCamera << ' ';
			outFile << smartphoneList[i].color << ' ';
			outFile << smartphoneList[i].batteryCapacity << ' ';
			outFile << smartphoneList[i].features << '\n';
		}
		outFile.close();
		return true;
	}else{
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}

Smartphone Smartphone::getSmartphoneByID(int id)
{
	return smartphoneList[id-1];
}

int Smartphone::listSizeCheck()
{
	int i = 0;
	ifstream base("SmartphonesList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}