#include "Projectors.h"

Projectors Projectors::getProjectorByID(int id)
{
    return projectorsList[id - 1];
}

int Projectors::listSizeCheck()
{
	int i = 0;
	ifstream base("ProjectorsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Projectors::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(19) << "Наявність" << "|";
	cout << setw(14) << "Ціна" << "|";
	cout << setw(15) << "Бренд" << "|";
	cout << setw(11) << "Тип" << "|";
	cout << setw(scale) << "Роздільна здатність" << "|";
	cout << setw(scale) << "Інтерфейс" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		projectorsList = new Projectors[listSize];
		for (int i = 0; i < listSize; i++)
		{
			projectorsList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << projectorsList[i].getID() << "|";
			cout.width(scale);
			cout << projectorsList[i].getAvailable() << "|";
			cout.width(scale);
			cout << projectorsList[i].getPrice() << "|";
			cout.width(scale);
			cout << projectorsList[i].getBrand() << "|";
			cout.width(scale);
			cout << projectorsList[i].getType() << "|";

			cout.width(19);
			cout << projectorsList[i].resolution << "|";
			cout.width(9);
			cout << projectorsList[i].connectionInterface << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Projectors::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> resolution;
		file >> connectionInterface;
	}
}

bool Projectors::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (projectorsList[id - 1].isAvailable() && projectorsList[id - 1].getAvailable() >= amount)
	{
		projectorsList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("ProjectorsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << projectorsList[i].ID << ' ';
			outFile << projectorsList[i].available << ' ';
			outFile << projectorsList[i].price << ' ';
			outFile << projectorsList[i].brand << ' ';
			outFile << projectorsList[i].type << ' ';

			outFile << projectorsList[i].resolution << ' ';
			outFile << projectorsList[i].connectionInterface << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
