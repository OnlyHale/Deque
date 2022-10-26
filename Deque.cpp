/***************************************************************************************
*Project Name : Deque                                                                  *
*File Name    : Deque.cpp                                                              *
*Language     : CPP,MSVS ver 2015 and above                                            *
*Programmers : Ратников Роман Олегович,группа:М3О-210Б-20                              *
*Modified By  :                                                                        *
*Created      : 03/12/2021                                                             *
*Last Revision: 03/12/2021                                                             *
*Comment      : Дек  	                                                               *
***************************************************************************************/

#define N 6          // Изначальный размер списка
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;


// Функция создания списка
void Create_Deque(const int& count);

// Функция печати списка
void Print_Deque();

// Функция удаления списка
void Delete_Deque();

// Функция добавления элемента
void Insert_Data(const double& value);

// Функция удаления хвоста
void Delete_Tail();

// Элемент списка
struct list
{
	double data;       // Данные
	list* next;       // Указатель на следующий элемент
	list* prev;       // Указатель на предыдущий элемент
};

list* head = NULL;    // Указатель на начало списка
list* tail = NULL;    // Указатель на конец списка

int Count = N;        // Количество элементов в списке



int main()
{
	setlocale(LC_ALL, "Rus");
	

	double value;     // Значение вводимого элемента
	

	int number = 1;   //Для первого вывода
	while (number)
	{

		cout << "\t\tМеню: " << endl;
		cout << " 0) Выйти из программы" << endl;
		cout << " 1) Создать дек" << endl;
		cout << " 2) Вывести дек" << endl;
		cout << " 3) Удалить дек" << endl;
		cout << " 4) Добавить элемент в начало" << endl;
		cout << " 5) Выбор элемента из конца" << endl;
		cout << "\n\n Введите номер команды :";
		cin >> number;

		switch (number)
		{
		case 0:
		{
			cout << "\n Завершение программы " << endl;
			Delete_Deque(); //Удаление списка
			return 0;
		}
		case 1:
		{
			Create_Deque(N);
			break;
		}
		case 2:
		{
			Print_Deque();
			break;
		}
		case 3:
		{
			Delete_Deque();
			break;
		}
		case 4:
		{
			if (head == NULL)
			{
				cout << " Дек не создан" << endl;
				break;
			}

			cout << " Введите значение элемента: ";
			cin >> value;
			
			Insert_Data(value);
			Print_Deque();
			break;
		}
		case 5:
		{
			Delete_Tail();
			Print_Deque();
			break;
		}
		
		default:
		{
			cout << "\n Введите значение ещё раз :" << endl;
			break;
		}
		}
		system("pause");
		system("cls");
	}



}


void Create_Deque(const int& count)
{
	if (head != NULL)
	{
		cout << "  Дек уже создан" << endl;
		return;
	}
	srand(time(0));
	for (int i = 0;i < count;++i)
	{

		list* temp = new list;      // Новый элемент


		if (i == 0)
		{
			head = temp;       // Начало - голова

		}
		else
		{

			tail->next = temp;  //Связь с предыдущим элементом


		}
		temp->prev = tail;     // Связь с предыдущим элементом
		tail = temp;		   // Текущий элемент - хвост
		temp->next = NULL;	   // Следующего элемента пока что нет

		setprecision(1);
		temp->data = rand() % 20 + double(rand() % 9 + 1) / 10;;  // Заполнение данных



	}
	cout << "  \n Дек создан" << endl;
	Count = N;
}


void Print_Deque()
{
	if (head == NULL)
	{
		cout << " Дек не создан" << endl;
		return;
	}
	list* actual = head;

	int i = 0;
	while (actual != NULL)       // Пока не достигнем конца списка
	{
		cout << " " << i << "\t" << actual->data << endl;
		actual = actual->next;
		i++;
	}
}

void Delete_Deque()
{
	if (head == NULL)
	{
		cout << " \n Память свободна" << endl;
		return;
	}

	while (head != NULL)   // Удаление головы, пока список не пуст
	{
		list* actual = head;     // Актуальный элемент - голова
		head = actual->next;   // Следующий элемент - голова
		actual->prev = NULL;
		actual->next = NULL;
		delete actual;

	}

	head = NULL;
	tail = NULL;

	cout << " Дек удалён " << endl;


	Count = 0;
}


void Insert_Data(const double& value)
{
	

	list* actual = head;
	
	list* temp = new list;
	temp->prev = NULL;

	head = temp;
	
	actual->prev = temp;           // Соединяем с актуальным
	temp->next = actual;
	temp->data = value;            // Записываем значение

	cout << " Элемент добавлен" << endl;
	Count++;
}

void Delete_Tail()
{
	if (head == NULL)
	{
		cout << " \nДек не создан " << endl;
		return;
	}
	list* actual = tail;      //Начинаем с хвоста
	tail = actual->prev;      // Меняем хвост на пред

	if (Count == 1)
	{
		head = NULL;
	}
	else
	{

		tail->next = NULL;  // Рвём связи с последним эл.
	}
	cout << " Значение последнего элемента:" << endl;
	cout << "\t" << actual->data << endl;
	delete actual;

	Count--;
	cout << " \n Хвост удалён " << endl;
}
