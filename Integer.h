#pragma once
#include "Object.h"
class Integer : public Object {
public:
    int element;

    // Constructor
    Integer(int x = 0);

    // Getter
    int getElement();

    // Setter
    void setElement(int);
    
    // Metodo tostring
    virtual string toString() override;

    // Metodo para verificar elementos iguales
    virtual bool equals(Object*) override;

    // Metodo "copy"
    virtual Object* copy() override;
};