#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

class BMoney {

private:

	double Dollars;

public:

	BMoney(double Dollars){

		this->Dollars = Dollars;

	}

	void Set() {

		double value;
		cin >> value;
		this->Dollars = value;

	}

	double Get() {

		return Dollars;

	}

	friend BMoney operator*(int value, BMoney& d);
	friend BMoney operator/(int value, BMoney& d);
	friend BMoney operator+(int value, BMoney& d);
	friend BMoney operator-(int value, BMoney& d);
	friend BMoney operator^(int value, BMoney& d);
	friend BMoney operator++(BMoney& d);
	friend BMoney operator--(BMoney& d);


 };

BMoney operator*(int value, BMoney& d) {

	return(value * d.Dollars);

}

BMoney operator/(int value, BMoney& d) {

	return(value / d.Dollars);

}

BMoney operator+(int value, BMoney& d) {

	return(value + d.Dollars);

}

BMoney operator-(int value, BMoney& d) {

	return(value - d.Dollars);

}

BMoney operator^(int value, BMoney& d) {

	return(pow(d.Dollars, value));

}

BMoney operator++(BMoney& d) {

	return(d.Dollars++);

}

BMoney operator--(BMoney& d) {

	return(d.Dollars--);

}

int main() {

	setlocale(LC_ALL, "ru");
	
	int value;
	BMoney value_of_dollars(0);

	int choice;
	bool flag = false;
	while (!flag) {

		cout << "Введите константу: ";
		cin >> value;
		cout << "\nВведите денежную сумму: ";
		value_of_dollars.Set();

		cout << "\n1.Сложение\n2.Вычитание\n3.Умножение\n4.Деление\n5.Возведение в степень\n6.Инкремент\n7.Декремент\n0.Выход\n";

		cin >> choice;
		switch (choice) {

		case 1: {
			BMoney result = value + value_of_dollars;
			cout << endl << result.Get() << endl;
			break;
		}

		case 2: {
			BMoney result = value - value_of_dollars;
			cout << endl << result.Get() << endl;
			break;
		}

		case 3: {
			BMoney result = value * value_of_dollars;
			cout << endl << result.Get() << endl;
			break;
		}

		case 4: {
			BMoney result = value / value_of_dollars;
			cout << endl << result.Get() << endl;
			break;
		}

		/*case 5: {
			BMoney result = pow(value_of_dollars, value);
			cout << endl << result.Get() << endl;
			break;
		}

		case 6: {
			BMoney result = value_of_dollars++;
			cout << endl << result.Get() << endl;
			break;
		}

		case 7: {
			BMoney result = (value_of_dollars--);
			cout << endl << result.Get() << endl;
			break;
		}*/

		case 0: flag = true;
		}
		
	}

	return 0;
}