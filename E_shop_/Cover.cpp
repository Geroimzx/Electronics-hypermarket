#include "Cover.h"

string Cover::getCompatible()
{
    return compatible;
}

string Cover::getColor()
{
    return color;
}

Cover Cover::getCoverByID(int id)
{
    return сoverList[id - 1];
}

int Cover::listSizeCheck()
{
	int i = 0;
	ifstream base("CoverList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Cover::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << " Наявність" << "|";
	cout << setw(14) << "Ціна" << "|";
	cout << setw(15) << "Бренд" << "|";
	cout << setw(8) << "Тип" << "|";
	cout << setw(scale) << "Сумісність" << "|";
	cout << setw(scale) << "Колір";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		сoverList = new Cover[listSize];
		for (int i = 0; i < listSize; i++)
		{
			сoverList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << сoverList[i].getID() << "|";
			cout.width(scale);
			cout << сoverList[i].getAvailable() << "|";
			cout.width(scale);
			cout << сoverList[i].getPrice() << "|";
			cout.width(scale);
			cout << сoverList[i].getBrand() << "|";
			cout.width(scale);
			cout << сoverList[i].getType() << "|";
			cout.width(scale);
			cout << сoverList[i].getCompatible() << "|";
			cout.width(scale);
			cout << сoverList[i].getColor();
		}
		cout << "\n";
		inFile.close();
	}
}

void Cover::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> compatible;
		file >> color;
	}
}

bool Cover::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (сoverList[id - 1].isAvailable() && сoverList[id - 1].getAvailable() >= amount)
	{
		сoverList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("CoverList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << сoverList[i].ID << ' ';
			outFile << сoverList[i].available << ' ';
			outFile << сoverList[i].price << ' ';
			outFile << сoverList[i].brand << ' ';
			outFile << сoverList[i].type << ' ';
			outFile << сoverList[i].compatible << ' ';
			outFile << сoverList[i].color << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
