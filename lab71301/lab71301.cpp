#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <functional>
#include <utility>

#pragma warning(disable : 4996)

using namespace std;

class Subscriber {
public:
	string Name;
	string country;
	string year;
	string clas;
	string mesto;


	// конструктор по умолчанию
	Subscriber() { }

	// конструктор с параметрами
	Subscriber(string lName, string pNumber, int y, string cl, string m) {
		Name = lName;
		country = pNumber;
		year = y;
		clas = cl;
		mesto = m;

	}

	// конструктор копирования
	
	Subscriber(const Subscriber& obj) {
		Name = obj.Name;
		country = obj.country;
		year = obj.year;
		clas = obj.clas;
		mesto = obj.mesto;
	}

	// перегрузка оператора =
	// позволяет выполнить операцию присваивания между двумя объектами Subscriber
	
	Subscriber& operator =(const Subscriber& obj) {
		if (&obj != this) {
			Name = obj.Name;
			country = obj.country;
			year = obj.year;
			clas = obj.clas;
			mesto = obj.mesto;
		}
		return *this;
	}

	/* дружественные методы
	 * не являются членами класса, но имеют к классу дружественное отношение,
	 * то есть такие методы могут работать с приватной частью класса
	 */
	friend bool operator <=(const Subscriber& a, const Subscriber& b);
	friend bool operator <(const Subscriber& a, const Subscriber& b);
	friend bool operator >=(const Subscriber& a, const Subscriber& b);

	friend bool com(const Subscriber& a, const Subscriber& b);

	friend ostream& operator << (ostream& out, const Subscriber& obj);
	friend istream& operator >>(istream& in, Subscriber& obj);
};

/*
 * перегрузка оператора <
 * позволяет сравнить два объекта Subscriber между собой
 */
bool operator <(const Subscriber& a, const Subscriber& b)
{
	// тернарный оператор
	
	return a.Name[0] < b.Name[0] ? true : false;
}

/*
 * перегрузка оператора <=
 * позволяет сравнить два объекта Subscriber между собой
 * сравнивает значение Name
 */
bool operator <=(const Subscriber& a, const Subscriber& b)
{
	return a.Name[0] <= b.Name[0] ? true : false;
}

/*
 * перегрузка оператора >=
 * позволяет сравнить два объекта Subscriber между собой
 */
bool operator >=(const Subscriber& a, const Subscriber& b)
{
	return a.Name[0] >= b.Name[0] ? true : false;
}

// функция компаратор

bool compareYear(const Subscriber& a, const Subscriber& b) {
	return (a.year < b.year);
}


bool compareCountry(const Subscriber& a, const Subscriber& b) {
	return (a.country < b.country);
}

bool compareClas(const Subscriber& a, const Subscriber& b) {
	return (a.clas < b.clas);
}

bool compareMesto(const Subscriber& a, const Subscriber& b) {
	return (a.mesto < b.mesto);
}

template<class T>
class Algorithm {
	vector<T> subscriber; // используем готовый класс (стандартный контейнерт из библиотеки STL) vector, в котором будем хранить наши объекты класса Subscriber

public:
	void PushBack(T); // добавление элемента в конец вектора
	void Insert(vector<Subscriber>::iterator, T); // вставляет элемент T на позицию, на которую указывает итератор pos
	void ShowList(); // показ всех эл-тов вектора на экране
	void PopBack(); // удаление последнего элемента вектора

	T CompareCollection(Algorithm<T> lst); // сравнение двух векторов между собой
	void FindElement(string); // поиск элемента
	void DeleteElement(string); // удаление  элемента
	void Rename(string, T);

	void quicksort(vector<Subscriber>::iterator beg, vector<Subscriber>::iterator end);
	void quickSort();

	// сортировка
	// используем готовый метод sort для сортировки объектов
	/*
	
	 */
	void SortYear() { sort(subscriber.begin(), subscriber.end(), compareYear); }
	void SortCountry() { sort(subscriber.begin(), subscriber.end(), compareCountry); }
	void SortClas() { sort(subscriber.begin(), subscriber.end(), compareClas); }
	void SortMesto() { sort(subscriber.begin(), subscriber.end(), compareMesto); }

	// возвращает итератор на первый элемент
	vector<Subscriber>::iterator left()
	{
		return subscriber.begin();
	}
	// возвращает итератор на последний элемент
	vector<Subscriber>::iterator right()
	{
		auto it = subscriber.end();
		return --it;
	}
};

template<class T>
void Algorithm<T>::PushBack(T data)
{
	subscriber.push_back(data);
}

template<class T>
void Algorithm<T>::Insert(vector<Subscriber>::iterator pos, T value)
{
	subscriber.insert(pos, value);
}

template<class T>
void Algorithm<T>::ShowList()
{
	try {
		if (subscriber.empty())
			throw "The list is empty";

		cout << endl << setw(40) << "List of available ispolnitel" << endl;
		cout << endl;
		cout << setw(15) << "Surname" << setw(15) << "Country" << setw(15) << "Year" <<  setw(15) << "Clas" << setw(15) << "Mesto" << endl;

		
		for (auto it = subscriber.begin(); it != subscriber.end(); it++) {
			cout << *it << endl; // *it - разыменование итератора - возвращает значение, расположенное в контейнере
		}
	}
	catch (char* str) {
		cout << str << endl;
	}
}

template<class T>
void Algorithm<T>::PopBack()
{
	if (subscriber.size() == 0)
		cout << "\nThe list is empty" << endl;
	else
		subscriber.pop_back();
}

template<class T>
void Algorithm<T>::FindElement(string props)
{
	if (subscriber.size() != 0) {
		bool result = false;

		for (auto it = subscriber.begin(); it != subscriber.end(); it++) {
			if (it->Name == props || it->country == props || it->year == props || it->clas == props || it->mesto == props) {
				cout << endl << setw(15) << "Surname" << setw(15) << "Country" << setw(15) << "Year" << setw(15) << "Clas" << setw(15) << "Mesto";
				cout << endl << *it << endl;
				cout << endl;
				result = true;
				break;
			}
		}

		if (result == false)
			cout << "\nThere is no such ispolnitel" << endl;
	}
	else
		cout << endl << "The list if empty" << endl;
}

template<class T>
void Algorithm<T>::DeleteElement(string props)
{
	if (subscriber.size() != 0) {
		for (int i = 0; i < subscriber.size(); i++) {
			if (subscriber[i].Name == props || subscriber[i].country == props || subscriber[i].year == props || subscriber[i].clas == props || subscriber[i].mesto == props) {
				subscriber.erase(subscriber.begin() + i);
			}
		}
	}
	else
		cout << endl << "The list if empty" << endl;
}

template<class T>
T Algorithm<T>::CompareCollection(Algorithm<T> vct)
{
	auto it = subscriber.begin(); // итератор, который указывает на начало первого списка
	auto it1 = vct.subscriber.begin(); // итератор, который указывает на начало второго списка для сравнения
	while (it != subscriber.end() && it1 != vct.subscriber.end()) // пока не достигнем конца первого или второго списка
	{
		if (it->Name != it1->Name)
			return *it; 
		it++;
		it1++;

	}
	return *it1; // если два списка равны, то возращает итератор на последний объект
}


template<class T>
void Algorithm<T>::Rename(string props, T newdata)
{
	for (int i = 0; i < subscriber.size(); i++) {
		if (subscriber[i].Name == props || subscriber[i].country == props || subscriber[i].year == props || subscriber[i].clas == props || subscriber[i].mesto == props) {
			subscriber.emplace(subscriber.begin() + i, newdata); // subscriber.begin() + i - итератор, subscriber.begin() - итератор на 1-ый элемент, + i - смещаем итератор на нужный нам эл-т
			auto it = subscriber.begin() + i;
			subscriber.erase(++it); // ++it - итератор
		}
	}
}

template <class Itr>
vector<Subscriber>::iterator partition(Itr left, Itr right)
{
	Itr i = left++;

	Itr it = left;

	while (it != right)
	{
		if (*it <= *right)
		{
			++i;
			swap(*i, *it);
		}
		++it;
	}

	swap(*(i++), *right);
	return ++i;
}

auto part(vector<Subscriber>::iterator beg, vector<Subscriber>::iterator end, vector<Subscriber>::iterator::value_type& pivot)
{
	auto head = beg;
	auto tail = prev(end);
	while (head != tail) {
		while (*head < pivot) {
			if (++head == tail) {
				return head;
			}
		}
		while (*tail >= pivot) {
			if (--tail == head) {
				return head;
			}
		}

		iter_swap(head, tail);
		if (++head == tail--) {
			return head;
		}
	}
	return head;
}

template<typename T>
void Algorithm<T>::quicksort(vector<Subscriber>::iterator beg, vector<Subscriber>::iterator end) {

	if (beg == end) {
		return;
	}

	auto pivot = *beg;
	auto split = part(beg, end, pivot);

	// sort left
	quicksort(beg, split);
	// sort right
	auto new_middle = beg;
	quicksort(++new_middle, end);
}

template<class T>
void Algorithm<T>::quickSort()
{
	quicksort(this->subscriber.begin(), this->subscriber.end());
}

ostream& operator<<(ostream& out, const Subscriber& obj)
{
	out << setw(15) << obj.Name << setw(15) << obj.country << setw(15) << obj.year << setw(15) << obj.clas << setw(15) << obj.mesto;
	return out;
}

istream& operator >>(istream& in, Subscriber& obj)
{
	flushall();
	cout << "\nSurname: ";
	in >> obj.Name;

	cout << "Country: ";
	in >> obj.country;

	cout << "Year: ";
	in >> obj.year;

	cout << "Clas: ";
	in >> obj.clas;

	cout << "Mesto: ";
	in >> obj.mesto;

	return in;
}

int main()
{
	Subscriber subsctiber;
	Algorithm<Subscriber> vector;

	int choice = 1;
	cout << "1 - push_back; \n2 - insert; \n3 - pop_back; \n4 - Show; \n5 - Search; \n6 - Sort by Name; \n7 - Sort by country; \n8 - Sort by year; \n9 - Removal; \n10 - Rename; \n11 - Compare Collection; \n12 - Sort by clas; \n13 - Sort by mesto" << endl;
	cout << "\nYour choice: ";
	cin >> choice;

	while (choice >= 1 & choice <= 13)
	{
		switch (choice)
		{
		case 1: {
			cin >> subsctiber;
			vector.PushBack(subsctiber);

			break;
		}
		case 2: {
			cout << "\nEntering the pos for insert: ";
			int pos = 0;
			cin >> pos;
			cout << "\nEntering the value for insert: ";
			cin >> subsctiber;
			auto it = vector.left();
			vector.Insert(it + pos, subsctiber);
			vector.ShowList();
			break;
		}
		case 3: {
			vector.PopBack();
			vector.ShowList();
			break;
		}
		case 4: {
			vector.ShowList();

			break;
		}
		case 5: {
			string data;

			cout << "\nEntering the data: ";
			cin >> data;

			vector.FindElement(data);

			break;
		}
		case 6: {
			vector.quickSort();

			break;
		}
		case 7: {
			vector.SortCountry();

			break;
		}
		case 8: {
			vector.SortYear();

			break;
		}
		case 9: {
			string data;

			cout << "\nEntering the data: ";
			cin >> data;

			vector.DeleteElement(data);

			cout << "The result of the removal" << endl;
			vector.ShowList();

			break;
		}
		case 10: {
			string data;
			cout << "\nEntering the data: ";
			cin >> data;
			cin >> subsctiber;
			vector.Rename(data, subsctiber);
			cout << "The result of the rename" << endl;
			vector.ShowList();

			break;
		}
		case 11:
		{
			Algorithm<Subscriber> vct;
			for (int i = 0; i < 2; i++)
			{
				cin >> subsctiber;
				vct.PushBack(subsctiber);
			}
			cout << vector.CompareCollection(vct) << endl;

			break;
		}
		case 12: {
			vector.SortClas();

			break;
		}
		case 13: {
			vector.SortMesto();

			break;
		}
		}
		cout << "\nYour choice: ";
		cin >> choice;
	}
}
