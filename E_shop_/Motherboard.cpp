#include "Motherboard.h"

Motherboard Motherboard::getMotherboardByID(int id)
{
    return motherboardList[id - 1];
}

int Motherboard::listSizeCheck()
{
	int i = 0;
	ifstream base("MotherboardsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Motherboard::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "Сокет" << "|";
	cout << setw(scale) << "Тип ОЗУ" << "|";
	cout << setw(scale) << "Форм-фактор" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		motherboardList = new Motherboard[listSize];
		for (int i = 0; i < listSize; i++)
		{
			motherboardList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << motherboardList[i].getID() << "|";
			cout.width(scale);
			cout << motherboardList[i].getAvailable() << "|";
			cout.width(scale);
			cout << motherboardList[i].getPrice() << "|";
			cout.width(scale);
			cout << motherboardList[i].getBrand() << "|";
			cout.width(scale);
			cout << motherboardList[i].getType() << "|";

			cout.width(scale);
			cout << motherboardList[i].socket << "|";
			cout.width(scale);
			cout << motherboardList[i].RAMType << "|";
			cout.width(scale);
			cout << motherboardList[i].formFactor << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Motherboard::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> socket;
		file >> RAMType;
		file >> formFactor;
	}
}

bool Motherboard::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (motherboardList[id - 1].isAvailable() && motherboardList[id - 1].getAvailable() >= amount)
	{
		motherboardList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("MotherboardsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << motherboardList[i].ID << ' ';
			outFile << motherboardList[i].available << ' ';
			outFile << motherboardList[i].price << ' ';
			outFile << motherboardList[i].brand << ' ';
			outFile << motherboardList[i].type << ' ';

			outFile << motherboardList[i].socket << ' ';
			outFile << motherboardList[i].RAMType << ' ';
			outFile << motherboardList[i].formFactor << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
