#include "Television.h"

Television Television::getTVByID(int id)
{
    return televisionList[id - 1];
}

int Television::listSizeCheck()
{
	int i = 0;
	ifstream base("TVsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Television::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "Діагональ" << "|";
	cout << setw(scale) << "Роздільна здатність" << "|";
	cout << setw(scale) << "Технології" << "|";
	cout << setw(scale) << "ОС" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		televisionList = new Television[listSize];
		for (int i = 0; i < listSize; i++)
		{
			televisionList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << televisionList[i].getID() << "|";
			cout.width(scale);
			cout << televisionList[i].getAvailable() << "|";
			cout.width(scale);
			cout << televisionList[i].getPrice() << "|";
			cout.width(scale);
			cout << televisionList[i].getBrand() << "|";
			cout.width(scale);
			cout << televisionList[i].getType() << "|";

			cout.width(scale);
			cout << televisionList[i].diagonal << "|";
			cout.width(scale);
			cout << televisionList[i].resolution << "|";
			cout.width(scale);
			cout << televisionList[i].technology << "|";
			cout.width(scale);
			cout << televisionList[i].operatingSystem << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Television::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> diagonal;
		file >> resolution;
		file >> technology;
		file >> operatingSystem;
	}
}

bool Television::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (televisionList[id - 1].isAvailable() && televisionList[id - 1].getAvailable() >= amount)
	{
		televisionList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("TVsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << televisionList[i].ID << ' ';
			outFile << televisionList[i].available << ' ';
			outFile << televisionList[i].price << ' ';
			outFile << televisionList[i].brand << ' ';
			outFile << televisionList[i].type << ' ';

			outFile << televisionList[i].diagonal << ' ';
			outFile << televisionList[i].resolution << ' ';
			outFile << televisionList[i].technology << ' ';
			outFile << televisionList[i].operatingSystem << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
