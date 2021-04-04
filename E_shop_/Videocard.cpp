#include "Videocard.h"

Videocard Videocard::getVideocardByID(int id)
{
    return videocardList[id - 1];
}

int Videocard::listSizeCheck()
{
	int i = 0;
	ifstream base("VideocardsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Videocard::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(19) << "Наявність" << "|";
	cout << setw(14) << "Ціна" << "|";
	cout << setw(15) << "Бренд" << "|";
	cout << setw(13) << "Тип" << "|";
	cout << setw(scale) << "Виробник чипа" << "|";
	cout << setw(15) << "Серія" << "|";
	cout << setw(scale) << "Об. пам'яті" << "|";
	cout << setw(scale) << "Тип пам'яті" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		videocardList = new Videocard[listSize];
		for (int i = 0; i < listSize; i++)
		{
			videocardList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << videocardList[i].getID() << "|";
			cout.width(scale);
			cout << videocardList[i].getAvailable() << "|";
			cout.width(scale);
			cout << videocardList[i].getPrice() << "|";
			cout.width(scale);
			cout << videocardList[i].getBrand() << "|";
			cout.width(7);
			cout << videocardList[i].getType() << "|";

			cout.width(13);
			cout << videocardList[i].chipmaker << "|";
			cout.width(scale);
			cout << videocardList[i].chipSerie << "|";
			cout.width(11);
			cout << videocardList[i].videoMemory << "|";
			cout.width(11);
			cout << videocardList[i].memoryType << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Videocard::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> chipmaker;
		file >> chipSerie;
		file >> videoMemory;
		file >> memoryType;
	}
}

bool Videocard::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (videocardList[id - 1].isAvailable() && videocardList[id - 1].getAvailable() >= amount)
	{
		videocardList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("VideocardsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << videocardList[i].ID << ' ';
			outFile << videocardList[i].available << ' ';
			outFile << videocardList[i].price << ' ';
			outFile << videocardList[i].brand << ' ';
			outFile << videocardList[i].type << ' ';

			outFile << videocardList[i].chipmaker << ' ';
			outFile << videocardList[i].chipSerie << ' ';
			outFile << videocardList[i].videoMemory << ' ';
			outFile << videocardList[i].memoryType << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
