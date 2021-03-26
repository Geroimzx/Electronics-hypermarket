#include "Cover.h"

string Cover::getCompatible()
{
    return compatible;
}

string Cover::getColor()
{
    return color;
}

Cover Cover::getCoverByID(int id)
{
    return �overList[id - 1];
}

int Cover::listSizeCheck()
{
	int i = 0;
	ifstream base("CoverList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//��������� ������
	base.close();
	return i;
}

void Cover::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "��������" << "|";
	cout << setw(scale) << "ֳ��" << "|";
	cout << setw(scale) << "�����" << "|";
	cout << setw(scale) << "���" << "|";
	cout << setw(scale) << "��������" << "|";
	cout << setw(scale) << "����" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		�overList = new Cover[listSize];
		for (int i = 0; i < listSize; i++)
		{
			�overList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << �overList[i].getID() << "|";
			cout.width(scale);
			cout << �overList[i].getAvailable() << "|";
			cout.width(scale);
			cout << �overList[i].getPrice() << "|";
			cout.width(scale);
			cout << �overList[i].getBrand() << "|";
			cout.width(scale);
			cout << �overList[i].getType() << "|";
			cout.width(scale);
			cout << �overList[i].getCompatible() << "|";
			cout.width(scale);
			cout << �overList[i].getColor() << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Cover::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> compatible;
		file >> color;
	}
}

bool Cover::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (�overList[id - 1].isAvailable() && �overList[id - 1].getAvailable() >= amount)
	{
		�overList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("CoverList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << �overList[i].ID << ' ';
			outFile << �overList[i].available << ' ';
			outFile << �overList[i].price << ' ';
			outFile << �overList[i].brand << ' ';
			outFile << �overList[i].type << ' ';
			outFile << �overList[i].compatible << ' ';
			outFile << �overList[i].color << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "������ ���� � ������� ������� ���� ����� ����� �����\n";
		return false;
	}
}
