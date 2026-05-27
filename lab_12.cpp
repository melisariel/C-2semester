/* Разработать систему «Автобаза». Диспетчер распределяет заявки на Рейсы между Водителями и назначает для этого Автомобиль. Водитель может сделать заявку на ремонт. Диспетчер может отстранить Водителя от работы. Водитель делает отметку о выполнении Рейса и состоянии Автомобиля.  */

#include <iostream>
#include <string>

using namespace std;

class Driver;
class Car;
class Trip;

class Car // Автомобиль
{
private:
    string m_model; // Модель
    bool m_isBroken; // Состояние

public:

    // Конструктор по умолчанию
    Car()
    {
        m_model = "Unknown";
        m_isBroken = false;

        cout << "Car default" << endl;
    }

    // Конструктор с параметрами
    Car(string model)
    {
        m_model = model;
        m_isBroken = false;

        cout << "Car parameters" << endl;
    }

    // Деструктор
    ~Car()
    {
        cout << "Car destructor" << endl;
    }

    void setBroken(bool state)
    {
        m_isBroken = state;
    }

    bool isBroken() const
    {
        return m_isBroken;
    }

    string getModel() const
    {
        return m_model;
    }
};

class Trip
{
private:
    string m_route;
    bool m_completed;

public:

    // Конструктор по умолчанию
    Trip()
    {
        m_route = "Unknown";
        m_completed = false;

        cout << "Trip default" << endl;
    }

    // Конструктор с параметрами
    Trip(string route)
    {
        m_route = route;
        m_completed = false;

        cout << "Trip parameters" << endl;
    }

    // Деструктор
    ~Trip()
    {
        cout << "Trip destructor" << endl;
    }

    void completeTrip()
    {
        m_completed = true;
    }

    string getRoute() const
    {
        return m_route;
    }
};

class Driver
{
private:
    string m_name;
    bool m_isSuspended;

    Trip* m_trip;
    Car* m_car;

public:

    // Конструктор по умолчанию
    Driver()
    {
        m_name = "Unknown";

        m_isSuspended = false;

        m_trip = nullptr;
        m_car = nullptr;

        cout << "Driver default" << endl;
    }

    // Конструктор с параметрами
    Driver(string name)
    {
        m_name = name;

        m_isSuspended = false;

        m_trip = nullptr;
        m_car = nullptr;

        cout << "Driver parameters" << endl;
    }

    // Деструктор
    ~Driver()
    {
        cout << "Driver destructor" << endl;
    }

    void setTrip(Trip* trip)
    {
        m_trip = trip;
    }

    void setCar(Car* car)
    {
        m_car = car;
    }

    void suspend()
    {
        m_isSuspended = true;
    }

    bool isSuspended() const
    {
        return m_isSuspended;
    }

    void completeTrip()
    {
        if (m_trip != nullptr)
        {
            m_trip->completeTrip();

            cout << m_name
                 << " completed trip: "
                 << m_trip->getRoute()
                 << endl;
        }
    }

    void requestRepair()
    {
        if (m_car != nullptr)
        {
            m_car->setBroken(true);

            cout << m_name
                 << " requested repair for "
                 << m_car->getModel()
                 << endl;
        }
    }

    void reportCarStatus()
    {
        if (m_car != nullptr)
        {
            cout << "Car "
                 << m_car->getModel()
                 << " status: ";

            if (m_car->isBroken())
                cout << "broken";
            else
                cout << "working";

            cout << endl;
        }
    }

    string getName() const
    {
        return m_name;
    }
};

class Dispatcher
{
private:
    string m_name;

public:

    // Конструктор по умолчанию
    Dispatcher()
    {
        m_name = "Unknown";

        cout << "Dispatcher default" << endl;
    }

    // Конструктор с параметрами
    Dispatcher(string name)
    {
        m_name = name;

        cout << "Dispatcher parameters" << endl;
    }

    // Деструктор
    ~Dispatcher()
    {
        cout << "Dispatcher destructor" << endl;
    }

    void assignTrip(Driver* driver, Trip* trip, Car* car)
    {
        if (driver->isSuspended())
        {
            cout << "Driver suspended" << endl;
            return;
        }

        if (car->isBroken())
        {
            cout << "Car is broken" << endl;
            return;
        }

        driver->setTrip(trip);
        driver->setCar(car);

        cout << "Trip assigned to "
             << driver->getName()
             << endl;
    }

    void suspendDriver(Driver* driver)
    {
        driver->suspend();

        cout << driver->getName()
             << " suspended from work"
             << endl;
    }
};

int main()
{
    Driver* driver = new Driver("Ivan");

    Car* car = new Car("Volvo");

    Trip* trip = new Trip("A - B");

    Dispatcher* dispatcher = new Dispatcher("Oleg");

    dispatcher->assignTrip(driver, trip, car);

    driver->completeTrip();

    driver->requestRepair();

    driver->reportCarStatus();

    delete driver;
    delete car;
    delete trip;
    delete dispatcher;

    return 0;
}