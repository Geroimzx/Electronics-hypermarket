#include "Telephone.h"

Telephone Telephone::getTelephoneByID(int id)
{
	return telephoneList[id - 1];
}

int Telephone::listSizeCheck()
{
	int i = 0;
	ifstream base("TelephoneList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Telephone::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << " Наявність" << "|";
	cout << setw(scale) << "      Ціна" << "|";
	cout << setw(scale) << "     Бренд" << "|";
	cout << setw(scale) << "   Тип" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		telephoneList = new Telephone[listSize];
		for (int i = 0; i < listSize; i++)
		{
			telephoneList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << telephoneList[i].getID() << "|";
			cout.width(scale);
			cout << telephoneList[i].getAvailable() << "|";
			cout.width(scale);
			cout << telephoneList[i].getPrice() << "|";
			cout.width(scale);
			cout << telephoneList[i].getBrand() << "|";
			cout.width(scale);
			cout << telephoneList[i].getType() << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

bool Telephone::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (telephoneList[id - 1].isAvailable() && telephoneList[id - 1].getAvailable() >= amount)
	{
		telephoneList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("TelephoneList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << telephoneList[i].ID << ' ';
			outFile << telephoneList[i].available << ' ';
			outFile << telephoneList[i].price << ' ';
			outFile << telephoneList[i].brand << ' ';
			outFile << telephoneList[i].type << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
