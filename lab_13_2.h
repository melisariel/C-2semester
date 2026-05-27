// Имя файла Predator.h

#ifndef PREDATOR_H
#define PREDATOR_H

#include "Animal.h"

class Predator : public Animal
{
private:
    double m_weight;

public:
    Predator(int id, string name, double weight)
        : Animal(id, name)
    {
        m_weight = weight;
    }

    double getFoodAmount() const override
    {
        return m_weight * 0.1;
    }

    string getFoodType() const override
    {
        return "Meat";
    }
};

#endif