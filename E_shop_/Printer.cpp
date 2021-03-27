#include "Printer.h"

Printer Printer::getPrinterByID(int id)
{
    return printerList[id - 1];
}

int Printer::listSizeCheck()
{
	int i = 0;
	ifstream base("PrintersList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Printer::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "Технологія друку" << "|";
	cout << setw(scale) << "Формат паперу" << "|";
	cout << setw(scale) << "Колір друку" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		printerList = new Printer[listSize];
		for (int i = 0; i < listSize; i++)
		{
			printerList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << printerList[i].getID() << "|";
			cout.width(scale);
			cout << printerList[i].getAvailable() << "|";
			cout.width(scale);
			cout << printerList[i].getPrice() << "|";
			cout.width(scale);
			cout << printerList[i].getBrand() << "|";
			cout.width(scale);
			cout << printerList[i].getType() << "|";
			cout.width(scale);
			cout << printerList[i].printingTechnology << "|";
			cout.width(scale);
			cout << printerList[i].paperFormat << "|";
			cout.width(scale);
			cout << printerList[i].printingColor << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Printer::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> printingTechnology;
		file >> paperFormat;
		file >> printingColor;
	}
}

bool Printer::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (printerList[id - 1].isAvailable() && printerList[id - 1].getAvailable() >= amount)
	{
		printerList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("PrintersList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << printerList[i].ID << ' ';
			outFile << printerList[i].available << ' ';
			outFile << printerList[i].price << ' ';
			outFile << printerList[i].brand << ' ';
			outFile << printerList[i].type << ' ';
			outFile << printerList[i].printingTechnology << ' ';
			outFile << printerList[i].paperFormat << ' ';
			outFile << printerList[i].printingColor << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
