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
    return ñoverList[id - 1];
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
	this->listSize = i - 1;//ï³äğàõóíîê òîâàğ³â
	base.close();
	return i;
}

void Cover::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Íàÿâí³ñòü" << "|";
	cout << setw(scale) << "Ö³íà" << "|";
	cout << setw(scale) << "Áğåíä" << "|";
	cout << setw(scale) << "Òèï" << "|";
	cout << setw(scale) << "Ñóì³ñí³ñòü" << "|";
	cout << setw(scale) << "Êîë³ğ" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		ñoverList = new Cover[listSize];
		for (int i = 0; i < listSize; i++)
		{
			ñoverList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << ñoverList[i].getID() << "|";
			cout.width(scale);
			cout << ñoverList[i].getAvailable() << "|";
			cout.width(scale);
			cout << ñoverList[i].getPrice() << "|";
			cout.width(scale);
			cout << ñoverList[i].getBrand() << "|";
			cout.width(scale);
			cout << ñoverList[i].getType() << "|";
			cout.width(scale);
			cout << ñoverList[i].getCompatible() << "|";
			cout.width(scale);
			cout << ñoverList[i].getColor() << "|";
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
	if (ñoverList[id - 1].isAvailable() && ñoverList[id - 1].getAvailable() >= amount)
	{
		ñoverList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("CoverList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << ñoverList[i].ID << ' ';
			outFile << ñoverList[i].available << ' ';
			outFile << ñoverList[i].price << ' ';
			outFile << ñoverList[i].brand << ' ';
			outFile << ñoverList[i].type << ' ';
			outFile << ñoverList[i].compatible << ' ';
			outFile << ñoverList[i].color << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Òîâàğó íåìàº â íàÿíîñò³ âèáåğ³òü áóäü ëàñêà ³íøèé òîâàğ\n";
		return false;
	}
}
