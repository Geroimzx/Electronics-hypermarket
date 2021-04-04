#include "Tablet.h"

Tablet Tablet::getTabletByID(int id)
{
    return tabletList[id - 1];
}

int Tablet::listSizeCheck()
{
	int i = 0;
	ifstream base("TabletsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Tablet::viewProducts(string filePath)
{
	ifstream file;
	file.open(filePath);
	if (!file)
		cout << "Cannot open file" << endl;
	listSizeCheck();
	tabletList = new Tablet[listSize];
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(19) << "Наявність" << "|";
	cout << setw(14) << "Ціна" << "|";
	cout << setw(15) << "Бренд" << "|";
	cout << setw(11) << "Тип" << "|";
	cout << setw(scale) << "ROM" << "|";
	cout << setw(scale) << "RAM" << "|";
	cout << setw(23) << "Процесор" << "|";
	cout << setw(12) << "ОС" << "|";
	cout << setw(scale) << "Діагональ екрану" << "|";
	cout << setw(scale) << "Тип екрану" << "|";
	cout << setw(scale) << "Основна камера" << "|";
	cout << setw(scale) << "Фронтальна камера" << "|";
	cout << setw(12) << "Колір" << "|";
	cout << setw(scale) << "Ємність акумулятора" << "|";
	cout << setw(scale) << "Особливості";
	for (int i = 0; i < listSize; i++)
	{
		tabletList[i].initProduct(file);
		cout << "\n|";
		cout.width(scale);
		cout << tabletList[i].ID << "|";
		cout.width(scale);
		cout << tabletList[i].available << "|";
		cout.width(scale);
		cout << tabletList[i].price << "|";
		cout.width(scale);
		cout << tabletList[i].brand << "|";
		cout.width(15);
		cout << tabletList[i].type << "|";
		cout.width(scale);
		cout << tabletList[i].storageMemory << "|";
		cout.width(scale);
		cout << tabletList[i].RAM << "|";
		cout.width(15);
		cout << tabletList[i].chipset << "|";
		cout.width(scale);
		cout << tabletList[i].operatingSystem << "|";
		cout.width(16);
		cout << tabletList[i].displaySize << "|";
		cout.width(scale);
		cout << tabletList[i].displayType << "|";
		cout.width(14);
		cout << tabletList[i].mainCamera << "|";
		cout.width(17);
		cout << tabletList[i].selfieCamera << "|";
		cout.width(13);
		cout << tabletList[i].color << "|";
		cout.width(19);
		cout << tabletList[i].batteryCapacity << "|";
		cout.width(11);
		cout << tabletList[i].features;
	}
	cout << "\n";
	file.close();
}

void Tablet::initProduct(std::ifstream& file)
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

bool Tablet::updateProductList(int id, int amount)
{
	if (tabletList[id - 1].isAvailable() && tabletList[id - 1].getAvailable() >= amount)
	{
		tabletList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("TabletsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << tabletList[i].ID << ' ';
			outFile << tabletList[i].available << ' ';
			outFile << tabletList[i].price << ' ';
			outFile << tabletList[i].brand << ' ';
			outFile << tabletList[i].type << ' ';
			outFile << tabletList[i].storageMemory << ' ';
			outFile << tabletList[i].RAM << ' ';
			outFile << tabletList[i].chipset << ' ';
			outFile << tabletList[i].operatingSystem << ' ';
			outFile << tabletList[i].displaySize << ' ';
			outFile << tabletList[i].displayType << ' ';
			outFile << tabletList[i].mainCamera << ' ';
			outFile << tabletList[i].selfieCamera << ' ';
			outFile << tabletList[i].color << ' ';
			outFile << tabletList[i].batteryCapacity << ' ';
			outFile << tabletList[i].features << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
