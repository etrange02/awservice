/***************************************************************
 * Name:      People.cpp
 * Purpose:   Code for AWServiceCommonDataTest
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-01-18
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "People.h"
#include "element/ClassElement.h"
#include "model/ElementFactory.h"

People::People() : AWS::IUserModel("People")
{
    //ctor
}

People::~People()
{
    //dtor
}

AWS::Element* People::toElement(const std::string& name)
{
    AWS::ClassElement* classElement = new AWS::ClassElement(name.empty() ? getName() : name);

    WRITERN(classElement, "name", this->name);

    return classElement;
}

void People::fromElement(AWS::Element& element)
{
    AWS::ClassElement& classElement = dynamic_cast<AWS::ClassElement&>(element);
    READ(classElement, name,       NULL);
}

