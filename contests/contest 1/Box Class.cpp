#include<bits/stdc++.h>

using namespace std;

class Box {
	int l, b, h;

public: 
	Box() : l(0), b(0), h(0)
	{
	}
	Box(int l , int b , int h) : l(l), b(b), h(h)
	{
		if (l <= 0 || b <= 0 || h <= 0) 
			throw "Box dimentions must be greater than 0!";
	}
	Box(const Box& box) : l(box.getLength()), b(box.getBreadth() ), h(box.getHeight())
	{
	}
	int getLength() const {
		return l; 
	}
	int getBreadth() const {
		return b; 
	}
	int getHeight() const {
		return h;
	}
	long CalculateVolume() const {
		return l * h * b;
	}

};
bool operator<(Box b , Box box) {

	if (b.getLength() != box.getLength())
		return b.getLength() < box.getLength();

	if (b.getBreadth() != box.getBreadth())
		return b.getBreadth() < box.getBreadth();

	if ( b.getHeight() != box.getHeight())
		return b.getHeight() < box.getHeight();

	return false;

}
ostream& operator<< (ostream& os, const Box& box) {

	os << endl << box.getLength() << " " << box.getBreadth() << " " << box.getHeight() << endl;
	return os;
}

void check2()
{
	int n;
	cout << "Enter n : ";
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cout << endl << "Enter type : ";

		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cout << endl << "Enter a Box : ";

			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cout << endl << "Enter a Box : ";

			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}