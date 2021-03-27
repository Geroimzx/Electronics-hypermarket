#include "Storage.h"

Storage Storage::getStorageByID(int id)
{
    return storageList[id - 1];
}

int Storage::listSizeCheck()
{
	int i = 0;
	ifstream base("StoragesList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Storage::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "Ємність" << "|";
	cout << setw(scale) << "Форм-фактор" << "|";
	cout << setw(scale) << "Інтерфейс" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		storageList = new Storage[listSize];
		for (int i = 0; i < listSize; i++)
		{
			storageList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << storageList[i].getID() << "|";
			cout.width(scale);
			cout << storageList[i].getAvailable() << "|";
			cout.width(scale);
			cout << storageList[i].getPrice() << "|";
			cout.width(scale);
			cout << storageList[i].getBrand() << "|";
			cout.width(scale);
			cout << storageList[i].getType() << "|";

			cout.width(scale);
			cout << storageList[i].memoryCapacity << "|";
			cout.width(scale);
			cout << storageList[i].formFactor << "|";
			cout.width(scale);
			cout << storageList[i].connectionInterface << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Storage::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> memoryCapacity;
		file >> formFactor;
		file >> connectionInterface;
	}
}

bool Storage::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (storageList[id - 1].isAvailable() && storageList[id - 1].getAvailable() >= amount)
	{
		storageList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("StoragesList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << storageList[i].ID << ' ';
			outFile << storageList[i].available << ' ';
			outFile << storageList[i].price << ' ';
			outFile << storageList[i].brand << ' ';
			outFile << storageList[i].type << ' ';

			outFile << storageList[i].memoryCapacity << ' ';
			outFile << storageList[i].formFactor << ' ';
			outFile << storageList[i].connectionInterface << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
