// Имя файла Animal.h

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    int m_id;
    string m_name;

public:
    Animal(int id, string name)
    {
        m_id = id;
        m_name = name;
    }

    virtual double getFoodAmount() const = 0;

    virtual string getFoodType() const = 0;

    int getId() const
    {
        return m_id;
    }

    string getName() const
    {
        return m_name;
    }

    virtual void print() const
    {
        cout << "ID: " << m_id
             << " Name: " << m_name
             << " Food type: " << getFoodType()
             << " Food amount: " << getFoodAmount()
             << endl;
    }

    virtual ~Animal() {}
};

#endif
