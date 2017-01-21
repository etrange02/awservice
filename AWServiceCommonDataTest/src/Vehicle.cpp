/***************************************************************
 * Name:      Vehicle.cpp
 * Purpose:   Code for AWServiceCommonDataTest
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-01-05
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "Vehicle.h"
#include "People.h"
#include "element/ClassElement.h"
#include "element/Element.h"
#include "model/ElementFactory.h"

Vehicle::Vehicle() : AWS::IUserModel("Vehicle")
{
    //ctor
}

Vehicle::~Vehicle()
{
    //dtor
}

AWS::Element* Vehicle::toElement(const std::string& name)
{
    AWS::ClassElement* classElement = new AWS::ClassElement(name.empty() ? getName() : name);

    WRITE(classElement, isMotorized);
    WRITE(classElement, wheels);
    WRITE(classElement, brand);
    WRITE(classElement, people);

    return classElement;
}

void* createPeople() { return new People; }
void Vehicle::fromElement(AWS::Element& element)
{
    //if (element.getName() != getName())
    //    throw new exception();
    AWS::ClassElement& classElement = dynamic_cast<AWS::ClassElement&>(element);
    READ(classElement, isMotorized, NULL);
    READ(classElement, wheels,      NULL);
    READ(classElement, brand,       NULL);
    READ(classElement, people,      createPeople);
}

