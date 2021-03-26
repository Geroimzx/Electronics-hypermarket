#include "MemoryCard.h"

int MemoryCard::getStorageMemory()
{
    return storageMemory;
}

string MemoryCard::getSpeedClass()
{
    return speedClass;
}

MemoryCard MemoryCard::getMemoryCardByID(int id)
{
    return memoryCardList[id - 1];
}

int MemoryCard::listSizeCheck()
{
	int i = 0;
	ifstream base("MemoryCardList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів в корзині
	base.close();
	return i;
}

void MemoryCard::viewProducts(string filePath)
{
	int scale = 14;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "Об'єм" << "|";
	cout << setw(scale) << "Клас" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		memoryCardList = new MemoryCard[listSize];
		for (int i = 0; i < listSize; i++)
		{
			memoryCardList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << memoryCardList[i].getID() << "|";
			cout.width(scale);
			cout << memoryCardList[i].getAvailable() << "|";
			cout.width(scale);
			cout << memoryCardList[i].getPrice() << "|";
			cout.width(scale);
			cout << memoryCardList[i].getBrand() << "|";
			cout.width(scale);
			cout << memoryCardList[i].getType() << "|";
			cout.width(scale);
			cout << memoryCardList[i].getStorageMemory() << "|";
			cout.width(scale);
			cout << memoryCardList[i].getSpeedClass() << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void MemoryCard::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> storageMemory;
		file >> speedClass;
	}
}

bool MemoryCard::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (memoryCardList[id - 1].isAvailable() && memoryCardList[id - 1].getAvailable() >= amount)
	{
		memoryCardList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("MemoryCardList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << memoryCardList[i].ID << ' ';
			outFile << memoryCardList[i].available << ' ';
			outFile << memoryCardList[i].price << ' ';
			outFile << memoryCardList[i].brand << ' ';
			outFile << memoryCardList[i].type << ' ';
			outFile << memoryCardList[i].storageMemory << ' ';
			outFile << memoryCardList[i].speedClass << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
