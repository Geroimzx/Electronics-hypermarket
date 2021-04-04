#include "Printer3D.h"

Printer3D Printer3D::getPrinter3DByID(int id)
{
    return printer3DList[id - 1];
}

int Printer3D::listSizeCheck()
{
	int i = 0;
	ifstream base("Printer3DList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Printer3D::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << " Наявність" << "|";
	cout << setw(14) << "Ціна" << "|";
	cout << setw(16) << "Бренд" << "|";
	cout << setw(13) << "Тип" << "|";
	cout << setw(scale) << "Технологія друку" << "|";
	cout << setw(scale) << "Матеріал нитки" << "|";
	cout << setw(scale) << "Кількість сопел" << "|";
	cout << setw(scale) << "Макс. шв. друку" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		printer3DList = new Printer3D[listSize];
		for (int i = 0; i < listSize; i++)
		{
			printer3DList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << printer3DList[i].getID() << "|";
			cout.width(scale);
			cout << printer3DList[i].getAvailable() << "|";
			cout.width(scale);
			cout << printer3DList[i].getPrice() << "|";
			cout.width(scale);
			cout << printer3DList[i].getBrand() << "|";
			cout.width(scale);
			cout << printer3DList[i].getType() << "|";
			cout.width(16);
			cout << printer3DList[i].technology << "|";
			cout.width(14);
			cout << printer3DList[i].material << "|";
			cout.width(15);
			cout << printer3DList[i].nozzlesCount << "|";
			cout.width(15);
			cout << printer3DList[i].maxSpeed << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Printer3D::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> technology;
		file >> material;
		file >> nozzlesCount;
		file >> maxSpeed;
	}
}

bool Printer3D::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (printer3DList[id - 1].isAvailable() && printer3DList[id - 1].getAvailable() >= amount)
	{
		printer3DList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("Printer3DList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << printer3DList[i].ID << ' ';
			outFile << printer3DList[i].available << ' ';
			outFile << printer3DList[i].price << ' ';
			outFile << printer3DList[i].brand << ' ';
			outFile << printer3DList[i].type << ' ';

			outFile << printer3DList[i].technology << ' ';
			outFile << printer3DList[i].material << ' ';
			outFile << printer3DList[i].nozzlesCount << ' ';
			outFile << printer3DList[i].maxSpeed << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
