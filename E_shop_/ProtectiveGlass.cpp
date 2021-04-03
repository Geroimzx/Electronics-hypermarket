#include "ProtectiveGlass.h"

string ProtectiveGlass::getCompatible()
{
    return compatible;
}

string ProtectiveGlass::getCoatingType()
{
    return coatingType;
}

ProtectiveGlass ProtectiveGlass::getProtectiveGlassByID(int id)
{
    return protectiveGlassList[id - 1];
}

int ProtectiveGlass::listSizeCheck()
{
	int i = 0;
	ifstream base("ProtectiveGlassList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void ProtectiveGlass::viewProducts(string filePath)
{
	int scale = 16;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(25) << "Наявність" << "|";
	cout << setw(20) << "Ціна" << "|";
	cout << setw(21) << "Бренд" << "|";
	cout << setw(14) << "Тип" << "|";
	cout << setw(26) << "Сумісність" << "|";
	cout << setw(24) << "Тип покриття" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		protectiveGlassList = new ProtectiveGlass[listSize];
		for (int i = 0; i < listSize; i++)
		{
			protectiveGlassList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << protectiveGlassList[i].getID() << "|";
			cout.width(scale);
			cout << protectiveGlassList[i].getAvailable() << "|";
			cout.width(scale);
			cout << protectiveGlassList[i].getPrice() << "|";
			cout.width(scale);
			cout << protectiveGlassList[i].getBrand() << "|";
			cout.width(scale);
			cout << protectiveGlassList[i].getType() << "|";
			cout.width(scale);
			cout << protectiveGlassList[i].getCompatible() << "|";
			cout.width(22);
			cout << protectiveGlassList[i].getCoatingType() << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void ProtectiveGlass::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> compatible;
		file >> coatingType;
	}
}

bool ProtectiveGlass::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (protectiveGlassList[id - 1].isAvailable() && protectiveGlassList[id - 1].getAvailable() >= amount)
	{
		protectiveGlassList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("ProtectiveGlassList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << protectiveGlassList[i].ID << ' ';
			outFile << protectiveGlassList[i].available << ' ';
			outFile << protectiveGlassList[i].price << ' ';
			outFile << protectiveGlassList[i].brand << ' ';
			outFile << protectiveGlassList[i].type << ' ';
			outFile << protectiveGlassList[i].compatible << ' ';
			outFile << protectiveGlassList[i].coatingType << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
