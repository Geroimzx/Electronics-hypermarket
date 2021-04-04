#include "SmartWatches.h"

SmartWatches SmartWatches::getSmartWatchesByID(int id)
{
    return smartWatchesList[id - 1];
}

int SmartWatches::listSizeCheck()
{
	int i = 0;
	ifstream base("SmartWatchesList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void SmartWatches::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << " Наявність" << "|";
	cout << setw(14) << "Ціна" << "|";
	cout << setw(15) << "Бренд" << "|";
	cout << setw(17) << "Тип" << "|";
	cout << setw(scale) << "Призначення" << "|";
	cout << setw(scale) << "Форма дисплею" << "|";
	cout << setw(scale) << "Розмір дисплею" << "|";
	cout << setw(scale) << "Матеріал корпусу" << "|";
	cout << setw(scale) << "Час роботи" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		smartWatchesList = new SmartWatches[listSize];
		for (int i = 0; i < listSize; i++)
		{
			smartWatchesList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << smartWatchesList[i].getID() << "|";
			cout.width(scale);
			cout << smartWatchesList[i].getAvailable() << "|";
			cout.width(scale);
			cout << smartWatchesList[i].getPrice() << "|";
			cout.width(scale);
			cout << smartWatchesList[i].getBrand() << "|";
			cout.width(scale);
			cout << smartWatchesList[i].getType() << "|";
			cout.width(scale);
			cout << smartWatchesList[i].appointment << "|";
			cout.width(23);
			cout << smartWatchesList[i].displayForm << "|";
			cout.width(14);
			cout << smartWatchesList[i].displaySize << "|";
			cout.width(21);
			cout << smartWatchesList[i].material << "|";
			cout.width(scale);
			cout << smartWatchesList[i].workTime << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void SmartWatches::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> appointment;
		file >> displayForm;
		file >> displaySize;
		file >> material;
		file >> workTime;
	}
}

bool SmartWatches::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (smartWatchesList[id - 1].isAvailable() && smartWatchesList[id - 1].getAvailable() >= amount)
	{
		smartWatchesList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("SmartWatchesList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << smartWatchesList[i].ID << ' ';
			outFile << smartWatchesList[i].available << ' ';
			outFile << smartWatchesList[i].price << ' ';
			outFile << smartWatchesList[i].brand << ' ';
			outFile << smartWatchesList[i].type << ' ';

			outFile << smartWatchesList[i].appointment << ' ';
			outFile << smartWatchesList[i].displayForm << ' ';
			outFile << smartWatchesList[i].displaySize << ' ';
			outFile << smartWatchesList[i].material << ' ';
			outFile << smartWatchesList[i].workTime << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
