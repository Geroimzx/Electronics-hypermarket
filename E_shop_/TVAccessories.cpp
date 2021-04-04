#include "TVAccessories.h"

TVAccessories TVAccessories::getTVAccessoriesByID(int id)
{
    return tvAccessoriesList[id - 1];
}

int TVAccessories::listSizeCheck()
{
	int i = 0;
	ifstream base("TVAccessoriesList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void TVAccessories::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(19) << "Наявність" << "|";
	cout << setw(14) << "Ціна" << "|";
	cout << setw(19) << "Бренд" << "|";
	cout << setw(17) << "Тип" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		tvAccessoriesList = new TVAccessories[listSize];
		for (int i = 0; i < listSize; i++)
		{
			tvAccessoriesList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << tvAccessoriesList[i].getID() << "|";
			cout.width(scale);
			cout << tvAccessoriesList[i].getAvailable() << "|";
			cout.width(scale);
			cout << tvAccessoriesList[i].getPrice() << "|";
			cout.width(14);
			cout << tvAccessoriesList[i].getBrand() << "|";
			cout.width(20);
			cout << tvAccessoriesList[i].getType() << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void TVAccessories::initProduct(std::ifstream& file)
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

bool TVAccessories::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (tvAccessoriesList[id - 1].isAvailable() && tvAccessoriesList[id - 1].getAvailable() >= amount)
	{
		tvAccessoriesList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("TVAccessoriesList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << tvAccessoriesList[i].ID << ' ';
			outFile << tvAccessoriesList[i].available << ' ';
			outFile << tvAccessoriesList[i].price << ' ';
			outFile << tvAccessoriesList[i].brand << ' ';
			outFile << tvAccessoriesList[i].type << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
