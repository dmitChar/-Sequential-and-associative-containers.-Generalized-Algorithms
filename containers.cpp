
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iomanip>
#include <numeric>

using namespace std;


class A
{
private:
	vector <int> arr;
	const int N = 10;

public:
	void gen(); 
	void gen_2();
	void Show(); 
	int Sred(); 
	void SumVec(const A v1, const A v2); 
	void Poisk(); 
};

void A::gen()
{
	arr.resize(N);
	generate(arr.begin(), arr.end(), []() {return rand() % 11; }); 
}

void A::gen_2() 
{
	arr.resize(N);
	generate(arr.begin(), arr.end(), []() {return rand() % 21-10; });
}

void A::Show() 
{
	for (auto element : arr)
	{
		cout << setw(4) << element;
	}
	cout << endl;
}

int A::Sred()
{
	return accumulate(arr.begin(), arr.end(), 0) / this->arr.size();
}

void A::SumVec(const A v1, const A v2) 
{
	transform(v1.arr.begin(), v1.arr.end(), v2.arr.begin(), back_inserter(arr), [](const int a, const int b) { return a + b; });
}

bool Check( int a) {
	return a == 5;
}

void A::Poisk()
{
	int res = count_if(arr.begin(), arr.end(), Check);
	cout << "Количество чисел равных 5: " << res;
}


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	cout << "Содержимое вектора 1:" << endl;
	A obj;
	obj.gen();
	obj.Show();

	cout << "Содержимое вектора 2:" << endl;
	A obj2;
	obj2.gen_2();
	obj2.Show();

	cout << "Сумма векторов:" << endl;
	A obj3;
	obj3.SumVec(obj, obj2);
	obj3.Show();

	cout << endl << "Среднее значение элементов первого массива = " << obj.Sred() << endl;

	obj.Poisk(); cout << endl;
 
}

