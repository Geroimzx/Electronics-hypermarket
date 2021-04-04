#include "EBook.h"

EBook EBook::getEBookByID(int id)
{
    return ebookList[id - 1];
}

int EBook::listSizeCheck()
{
	int i = 0;
	ifstream base("EBooksList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void EBook::viewProducts(string filePath)
{
	ifstream file;
	file.open(filePath);
	if (!file)
		cout << "Cannot open file" << endl;
	listSizeCheck();
	ebookList = new EBook[listSize];
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << " Наявність" << "|";
	cout << setw(14) << "Ціна" << "|";
	cout << setw(15) << "Бренд" << "|";
	cout << setw(11) << "Тип" << "|";
	cout << setw(scale) << "ROM" << "|";
	cout << setw(scale) << "RAM" << "|";
	cout << setw(19) << "Формати" << "|";
	cout << setw(12) << "ОС" << "|";
	cout << setw(scale) << "Діагональ екрану" << "|";
	cout << setw(22) << "Тип екрану" << "|";
	cout << setw(11) << "Колір" << "|";
	cout << setw(scale) << "Ємність акумулятора" << "|";
	for (int i = 0; i < listSize; i++)
	{
		ebookList[i].initProduct(file);
		cout << "\n|";
		cout.width(scale);
		cout << ebookList[i].ID << "|";
		cout.width(scale);
		cout << ebookList[i].available << "|";
		cout.width(scale);
		cout << ebookList[i].price << "|";
		cout.width(scale);
		cout << ebookList[i].brand << "|";
		cout.width(scale);
		cout << ebookList[i].type << "|";
		cout.width(scale);
		cout << ebookList[i].storageMemory << "|";
		cout.width(scale);
		cout << ebookList[i].RAM << "|";
		cout.width(15);
		cout << ebookList[i].formatSupport << "|";
		cout.width(scale);
		cout << ebookList[i].operatingSystem << "|";
		cout.width(16);
		cout << ebookList[i].displaySize << "|";
		cout.width(13);
		cout << ebookList[i].displayType << "|";
		cout.width(scale);
		cout << ebookList[i].color << "|";
		cout.width(19);
		cout << ebookList[i].batteryCapacity << "|";
	}
	cout << "\n";
	file.close();
}

void EBook::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> storageMemory;
		file >> RAM;
		file >> formatSupport;
		file >> operatingSystem;
		file >> displaySize;
		file >> displayType;
		file >> color;
		file >> batteryCapacity;
	}
}

bool EBook::updateProductList(int id, int amount)
{
	if (ebookList[id - 1].isAvailable() && ebookList[id - 1].getAvailable() >= amount)
	{
		ebookList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("EBooksList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << ebookList[i].ID << ' ';
			outFile << ebookList[i].available << ' ';
			outFile << ebookList[i].price << ' ';
			outFile << ebookList[i].brand << ' ';
			outFile << ebookList[i].type << ' ';
			outFile << ebookList[i].storageMemory << ' ';
			outFile << ebookList[i].RAM << ' ';
			outFile << ebookList[i].formatSupport << ' ';
			outFile << ebookList[i].operatingSystem << ' ';
			outFile << ebookList[i].displaySize << ' ';
			outFile << ebookList[i].displayType << ' ';
			outFile << ebookList[i].color << ' ';
			outFile << ebookList[i].batteryCapacity << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
