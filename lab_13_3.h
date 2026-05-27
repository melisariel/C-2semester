// Имя файла Herbivore.h

#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "Animal.h"

class Herbivore : public Animal
{
private:
    double m_weight;

public:
    Herbivore(int id, string name, double weight)
        : Animal(id, name)
    {
        m_weight = weight;
    }

    double getFoodAmount() const override
    {
        return m_weight * 0.3;
    }

    string getFoodType() const override
    {
        return "Grass";
    }
};

#endif