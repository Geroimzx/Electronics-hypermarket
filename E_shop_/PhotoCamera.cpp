#include "PhotoCamera.h"

PhotoCamera PhotoCamera::getPhotoCameraByID(int id)
{
    return photoCameraList[id - 1];
}

int PhotoCamera::listSizeCheck()
{
	int i = 0;
	ifstream base("PhotoCamerasList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void PhotoCamera::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "Роздільна здатність" << "|";
	cout << setw(scale) << "Розмір матриці" << "|";
	cout << setw(scale) << "Оптичний зум" << "|";
	cout << setw(scale) << "Тип живлення" << "|";
	cout << setw(scale) << "Колір" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		photoCameraList = new PhotoCamera[listSize];
		for (int i = 0; i < listSize; i++)
		{
			photoCameraList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << photoCameraList[i].getID() << "|";
			cout.width(scale);
			cout << photoCameraList[i].getAvailable() << "|";
			cout.width(scale);
			cout << photoCameraList[i].getPrice() << "|";
			cout.width(scale);
			cout << photoCameraList[i].getBrand() << "|";
			cout.width(scale);
			cout << photoCameraList[i].getType() << "|";

			cout.width(scale);
			cout << photoCameraList[i].resolution << "|";
			cout.width(scale);
			cout << photoCameraList[i].sizeMatrix << "|";
			cout.width(scale);
			cout << photoCameraList[i].opticZoom << "|";
			cout.width(scale);
			cout << photoCameraList[i].powerType << "|";
			cout.width(scale);
			cout << photoCameraList[i].color << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void PhotoCamera::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> resolution;
		file >> sizeMatrix;
		file >> opticZoom;
		file >> powerType;
		file >> color;
	}
}

bool PhotoCamera::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (photoCameraList[id - 1].isAvailable() && photoCameraList[id - 1].getAvailable() >= amount)
	{
		photoCameraList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("PhotoCamerasList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << photoCameraList[i].ID << ' ';
			outFile << photoCameraList[i].available << ' ';
			outFile << photoCameraList[i].price << ' ';
			outFile << photoCameraList[i].brand << ' ';
			outFile << photoCameraList[i].type << ' ';

			outFile << photoCameraList[i].resolution << ' ';
			outFile << photoCameraList[i].sizeMatrix << ' ';
			outFile << photoCameraList[i].opticZoom << ' ';
			outFile << photoCameraList[i].powerType << ' ';
			outFile << photoCameraList[i].color << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
