#include "DDR.h"

DDR DDR::getDDRByID(int id)
{
    return ddrList[id - 1];
}

int DDR::listSizeCheck()
{
	int i = 0;
	ifstream base("DDRsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void DDR::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "Кількість модулів" << "|";
	cout << setw(scale) << "Ємність" << "|";
	cout << setw(scale) << "Форм-фактор" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		ddrList = new DDR[listSize];
		for (int i = 0; i < listSize; i++)
		{
			ddrList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << ddrList[i].getID() << "|";
			cout.width(scale);
			cout << ddrList[i].getAvailable() << "|";
			cout.width(scale);
			cout << ddrList[i].getPrice() << "|";
			cout.width(scale);
			cout << ddrList[i].getBrand() << "|";
			cout.width(scale);
			cout << ddrList[i].getType() << "|";

			cout.width(scale);
			cout << ddrList[i].modulesCount << "|";
			cout.width(scale);
			cout << ddrList[i].memoryCapacity << "|";
			cout.width(scale);
			cout << ddrList[i].frequency << "|";
			cout.width(scale);
			cout << ddrList[i].timings << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void DDR::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> modulesCount;
		file >> memoryCapacity;
		file >> frequency;
		file >> timings;
	}
}

bool DDR::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (ddrList[id - 1].isAvailable() && ddrList[id - 1].getAvailable() >= amount)
	{
		ddrList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("DDRsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << ddrList[i].ID << ' ';
			outFile << ddrList[i].available << ' ';
			outFile << ddrList[i].price << ' ';
			outFile << ddrList[i].brand << ' ';
			outFile << ddrList[i].type << ' ';

			outFile << ddrList[i].modulesCount << ' ';
			outFile << ddrList[i].memoryCapacity << ' ';
			outFile << ddrList[i].frequency << ' ';
			outFile << ddrList[i].timings << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
