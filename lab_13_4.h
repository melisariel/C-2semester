// Имя файла Omnivore.h

#ifndef OMNIVORE_H
#define OMNIVORE_H

#include "Animal.h"

class Omnivore : public Animal
{
private:
    double m_weight;

public:
    Omnivore(int id, string name, double weight)
        : Animal(id, name)
    {
        m_weight = weight;
    }

    double getFoodAmount() const override
    {
        return m_weight * 0.2;
    }

    string getFoodType() const override
    {
        return "Mixed";
    }
};

#endif