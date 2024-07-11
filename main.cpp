#include <iostream>
using namespace std;

class Car
{
private:    // доступ только в классе // состояние объекта - РЕАЛИЗАЦИЯ
    char engine[10];
    char model[10];

    double price;
    int year;

public:    // доступ везде // смена состояния - ИНТЕРФЕЙС
    // Конструктор по умолчанию, для инициализации
    // 1. Первый пример
    //Car() : price(0), year(0) {}

    // 2. Второй пример конструктора по умолчанию
    Car()
    {
        cout << "Constructor by default:\n";
        year = 0;
        price = 0;
    }

    // 3. Пример конструктора с параметрами
    Car(int y, double pr)
    {
        cout << "Constructor with 2 parameters:\n";
        year = y;
        price = pr;
    }

    void Start()
    {
        cout << "Engine started\n";
    }
    void Stop()
    {
        cout << "Engine stopped\n";
    }

    // Пример инициализации года и цены
    void Init (int a, double b)
    {
        year = a;
        price = b;
    }

    // Вывод года и цены
    void Print()
    {
        cout << "Year: " << year << "\t" << "Price: " << price << endl;
    }

    // через метод можно контроллировать закрытый участок класса
    // методы аксессоры getter setter
    void setYear (int y)
    {
        if (y > 2000)
        {
            year = y;
        }
    }

    void setPrice (double pr)
    {
        if (pr > 15000)
        {
            price = pr;
        }
    }

    int getYear()
    {
        return year;
    }

    double getPrice()
    {
        return price;
    }

};


int main()
{
    Car a; // Вызов конструктора по умолчанию
    //a.Init(2023, 23000);
    a.Print();

    cout << endl;

    Car b (12, 1200.4); // Вызов конструктора с параметрами
    b.Print();

    cout << "----------------------" << endl;
    ////////
    a.Start();

    // Устанавливаем год и цену
    a.setYear(2022);
    a.setPrice(25000);

    // Получаем год и цену
    cout << "Year: " << a.getYear() << endl;
    cout << "Price: " << a.getPrice() << endl;

    return 0;
}