#include "Processor.h"

Processor Processor::getProcessorByID(int id)
{
	return processorList[id - 1];
}

int Processor::listSizeCheck()
{
	int i = 0;
	ifstream base("ProcessorsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Processor::viewProducts(string filePath)
{
	const int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(19) << "Наявність" << "|";
	cout << setw(14) << "Ціна" << "|";
	cout << setw(15) << "Бренд" << "|";
	cout << setw(11) << "Тип" << "|";
	cout << setw(20) << "Серія" << "|";
	cout << setw(15) << "Сокет" << "|";
	cout << setw(scale) << "Ядра" << "|";
	cout << setw(scale) << "Частота" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		processorList = new Processor[listSize];
		for (int i = 0; i < listSize; i++)
		{
			processorList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << processorList[i].getID() << "|";
			cout.width(scale);
			cout << processorList[i].getAvailable() << "|";
			cout.width(scale);
			cout << processorList[i].getPrice() << "|";
			cout.width(scale);
			cout << processorList[i].getBrand() << "|";
			cout.width(16);
			cout << processorList[i].getType() << "|";

			cout.width(15);
			cout << processorList[i].chipSerie << "|";
			cout.width(scale);
			cout << processorList[i].socket << "|";
			cout.width(6);
			cout << processorList[i].coresCount << "|";
			cout.width(7);
			cout << processorList[i].frequency << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Processor::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> chipSerie;
		file >> socket;
		file >> coresCount;
		file >> frequency;
	}
}

bool Processor::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (processorList[id - 1].isAvailable() && processorList[id - 1].getAvailable() >= amount)
	{
		processorList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("ProcessorsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << processorList[i].ID << ' ';
			outFile << processorList[i].available << ' ';
			outFile << processorList[i].price << ' ';
			outFile << processorList[i].brand << ' ';
			outFile << processorList[i].type << ' ';

			outFile << processorList[i].chipSerie << ' ';
			outFile << processorList[i].socket << ' ';
			outFile << processorList[i].coresCount << ' ';
			outFile << processorList[i].frequency << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
