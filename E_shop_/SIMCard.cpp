#include "SIMCard.h"

string SIMCard::getVipNumber()
{
    return vipNumber;
}

SIMCard SIMCard::getSIMCardByID(int id)
{
    return simCardList[id - 1];
}

int SIMCard::listSizeCheck()
{
	int i = 0;
	ifstream base("SIMCardList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void SIMCard::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "VIP номер" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		simCardList = new SIMCard[listSize];
		for (int i = 0; i < listSize; i++)
		{
			simCardList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << simCardList[i].getID() << "|";
			cout.width(scale);
			cout << simCardList[i].getAvailable() << "|";
			cout.width(scale);
			cout << simCardList[i].getPrice() << "|";
			cout.width(scale);
			cout << simCardList[i].getBrand() << "|";
			cout.width(scale);
			cout << simCardList[i].getType() << "|";
			cout.width(scale);
			cout << simCardList[i].getVipNumber() << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void SIMCard::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> vipNumber;
	}
}

bool SIMCard::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (simCardList[id - 1].isAvailable() && simCardList[id - 1].getAvailable() >= amount)
	{
		simCardList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("SIMCardList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << simCardList[i].ID << ' ';
			outFile << simCardList[i].available << ' ';
			outFile << simCardList[i].price << ' ';
			outFile << simCardList[i].brand << ' ';
			outFile << simCardList[i].type << ' ';
			outFile << simCardList[i].vipNumber << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
