#include "Quadrocopter.h"

Quadrocopter Quadrocopter::getQuadrocopterByID(int id)
{
    return quadrocopterList[id - 1];
}

int Quadrocopter::listSizeCheck()
{
	int i = 0;
	ifstream base("QuadrocoptersList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Quadrocopter::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "Камера" << "|";
	cout << setw(scale) << "Час польоту" << "|";
	cout << setw(scale) << "Максимальна відстань польоту" << "|";
	cout << setw(scale) << "Частота" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		quadrocopterList = new Quadrocopter[listSize];
		for (int i = 0; i < listSize; i++)
		{
			quadrocopterList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << quadrocopterList[i].getID() << "|";
			cout.width(scale);
			cout << quadrocopterList[i].getAvailable() << "|";
			cout.width(scale);
			cout << quadrocopterList[i].getPrice() << "|";
			cout.width(scale);
			cout << quadrocopterList[i].getBrand() << "|";
			cout.width(scale);
			cout << quadrocopterList[i].getType() << "|";
			cout.width(scale);
			cout << quadrocopterList[i].camera << "|";
			cout.width(scale);
			cout << quadrocopterList[i].flyTime << "|";
			cout.width(scale);
			cout << quadrocopterList[i].maxDistance << "|";
			cout.width(scale);
			cout << quadrocopterList[i].frequency << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Quadrocopter::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> camera;
		file >> flyTime;
		file >> maxDistance;
		file >> frequency;
	}
}

bool Quadrocopter::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (quadrocopterList[id - 1].isAvailable() && quadrocopterList[id - 1].getAvailable() >= amount)
	{
		quadrocopterList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("QuadrocoptersList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << quadrocopterList[i].ID << ' ';
			outFile << quadrocopterList[i].available << ' ';
			outFile << quadrocopterList[i].price << ' ';
			outFile << quadrocopterList[i].brand << ' ';
			outFile << quadrocopterList[i].type << ' ';

			outFile << quadrocopterList[i].camera << ' ';
			outFile << quadrocopterList[i].flyTime << ' ';
			outFile << quadrocopterList[i].maxDistance << ' ';
			outFile << quadrocopterList[i].frequency << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
