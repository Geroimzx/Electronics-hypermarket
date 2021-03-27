#include "PowerSupplies.h"

PowerSupplies PowerSupplies::getPowerSuppliesByID(int id)
{
    return powerSuppliesList[id - 1];
}

int PowerSupplies::listSizeCheck()
{
	int i = 0;
	ifstream base("PowerSuppliesList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void PowerSupplies::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "Форм-фактор" << "|";
	cout << setw(scale) << "Потужність" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		powerSuppliesList = new PowerSupplies[listSize];
		for (int i = 0; i < listSize; i++)
		{
			powerSuppliesList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << powerSuppliesList[i].getID() << "|";
			cout.width(scale);
			cout << powerSuppliesList[i].getAvailable() << "|";
			cout.width(scale);
			cout << powerSuppliesList[i].getPrice() << "|";
			cout.width(scale);
			cout << powerSuppliesList[i].getBrand() << "|";
			cout.width(scale);
			cout << powerSuppliesList[i].getType() << "|";

			cout.width(scale);
			cout << powerSuppliesList[i].formFactor << "|";
			cout.width(scale);
			cout << powerSuppliesList[i].outPower << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void PowerSupplies::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> formFactor;
		file >> outPower;
	}
}

bool PowerSupplies::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (powerSuppliesList[id - 1].isAvailable() && powerSuppliesList[id - 1].getAvailable() >= amount)
	{
		powerSuppliesList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("PowerSuppliesList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << powerSuppliesList[i].ID << ' ';
			outFile << powerSuppliesList[i].available << ' ';
			outFile << powerSuppliesList[i].price << ' ';
			outFile << powerSuppliesList[i].brand << ' ';
			outFile << powerSuppliesList[i].type << ' ';

			outFile << powerSuppliesList[i].formFactor << ' ';
			outFile << powerSuppliesList[i].outPower << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
