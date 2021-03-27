#include "Multimedia.h"

Multimedia Multimedia::getMultimediaByID(int id)
{
    return multimediaList[id - 1];
}

int Multimedia::listSizeCheck()
{
	int i = 0;
	ifstream base("MultimediasList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Multimedia::viewProducts(string filePath)
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

		multimediaList = new Multimedia[listSize];
		for (int i = 0; i < listSize; i++)
		{
			multimediaList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << multimediaList[i].getID() << "|";
			cout.width(scale);
			cout << multimediaList[i].getAvailable() << "|";
			cout.width(scale);
			cout << multimediaList[i].getPrice() << "|";
			cout.width(scale);
			cout << multimediaList[i].getBrand() << "|";
			cout.width(scale);
			cout << multimediaList[i].getType() << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Multimedia::initProduct(std::ifstream& file)
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

bool Multimedia::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (multimediaList[id - 1].isAvailable() && multimediaList[id - 1].getAvailable() >= amount)
	{
		multimediaList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("MultimediasList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << multimediaList[i].ID << ' ';
			outFile << multimediaList[i].available << ' ';
			outFile << multimediaList[i].price << ' ';
			outFile << multimediaList[i].brand << ' ';
			outFile << multimediaList[i].type << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
