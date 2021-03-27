#include "Laptop.h"

Laptop Laptop::getLaptopByID(int id)
{
    return laptopList[id - 1];
}

int Laptop::listSizeCheck()
{
	int i = 0;
	ifstream base("LaptopsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Laptop::viewProducts(string filePath)
{
	ifstream file;
	file.open(filePath);
	if (!file)
		cout << "Cannot open file" << endl;
	listSizeCheck();
	laptopList = new Laptop[listSize];
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "Діагональ екрану" << "|";
	cout << setw(scale) << "Тип матриці" << "|";
	cout << setw(scale) << "Роздільна здатність" << "|";
	cout << setw(scale) << "Серія процесора" << "|";
	cout << setw(scale) << "Кількість ядер" << "|";
	cout << setw(scale) << "Об'єм ОЗУ" << "|";
	cout << setw(scale) << "Відеокарта" << "|";
	cout << setw(scale) << "Об'єм пам'яті" << "|";
	cout << setw(scale) << "ОС" << "|";
	cout << setw(scale) << "Колір" << "|";
	cout << setw(scale) << "Вага" << "|";
	for (int i = 0; i < listSize; i++)
	{
		laptopList[i].initProduct(file);
		cout << "\n|";
		cout.width(scale);
		cout << laptopList[i].ID << "|";
		cout.width(scale);
		cout << laptopList[i].available << "|";
		cout.width(scale);
		cout << laptopList[i].price << "|";
		cout.width(scale);
		cout << laptopList[i].brand << "|";
		cout.width(scale);
		cout << laptopList[i].type << "|";
		cout.width(scale);
		cout << laptopList[i].displaySize << "|";
		cout.width(scale);
		cout << laptopList[i].displayType << "|";
		cout.width(scale);
		cout << laptopList[i].resolution << "|";
		cout.width(scale);
		cout << laptopList[i].chipset << "|";
		cout.width(scale);
		cout << laptopList[i].coresCount << "|";
		cout.width(scale);
		cout << laptopList[i].RAM << "|";
		cout.width(scale);
		cout << laptopList[i].videocardSeries << "|";
		cout.width(scale);
		cout << laptopList[i].storageMemory << "|";
		cout.width(scale);
		cout << laptopList[i].operatingSystem << "|";
		cout.width(scale);
		cout << laptopList[i].color << "|";
		cout.width(scale);
		cout << laptopList[i].weight;
	}
	cout << "\n";
	file.close();
}

void Laptop::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> displaySize;
		file >> displayType;
		file >> resolution;
		file >> chipset;
		file >> coresCount;
		file >> RAM;
		file >> videocardSeries;
		file >> storageMemory;
		file >> operatingSystem;
		file >> color;
		file >> weight;
	}
}

bool Laptop::updateProductList(int id, int amount)
{
	if (laptopList[id - 1].isAvailable() && laptopList[id - 1].getAvailable() >= amount)
	{
		laptopList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("LaptopsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << laptopList[i].ID << ' ';
			outFile << laptopList[i].available << ' ';
			outFile << laptopList[i].price << ' ';
			outFile << laptopList[i].brand << ' ';
			outFile << laptopList[i].type << ' ';

			outFile << laptopList[i].displaySize << ' ';
			outFile << laptopList[i].displayType << ' ';
			outFile << laptopList[i].resolution << ' ';
			outFile << laptopList[i].chipset << ' ';
			outFile << laptopList[i].coresCount << ' ';
			outFile << laptopList[i].RAM << ' ';
			outFile << laptopList[i].videocardSeries << ' ';
			outFile << laptopList[i].storageMemory << ' ';
			outFile << laptopList[i].operatingSystem << ' ';
			outFile << laptopList[i].color << ' ';
			outFile << laptopList[i].weight << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
