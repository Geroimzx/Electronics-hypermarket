#include "Accessories.h"

Accessories Accessories::getAccessoriesByID(int id)
{
    return accessoriesList[id - 1];
}

int Accessories::listSizeCheck()
{
	int i = 0;
	ifstream base("AccessoriesList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Accessories::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		accessoriesList = new Accessories[listSize];
		for (int i = 0; i < listSize; i++)
		{
			accessoriesList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << accessoriesList[i].getID() << "|";
			cout.width(scale);
			cout << accessoriesList[i].getAvailable() << "|";
			cout.width(scale);
			cout << accessoriesList[i].getPrice() << "|";
			cout.width(scale);
			cout << accessoriesList[i].getBrand() << "|";
			cout.width(scale);
			cout << accessoriesList[i].getType() << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Accessories::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
	}
}

bool Accessories::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (accessoriesList[id - 1].isAvailable() && accessoriesList[id - 1].getAvailable() >= amount)
	{
		accessoriesList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("AccessoriesList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << accessoriesList[i].ID << ' ';
			outFile << accessoriesList[i].available << ' ';
			outFile << accessoriesList[i].price << ' ';
			outFile << accessoriesList[i].brand << ' ';
			outFile << accessoriesList[i].type << ' ';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
