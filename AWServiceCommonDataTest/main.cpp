#include <iostream>
#include <stdexcept>
//#include "element/Element.h"
#include "element/NativeElement.h"
#include "element/Boolean.h"
#include "element/Integer.h"
#include "element/ArrayElement.h"
#include "element/ClassElement.h"
#include "element/String.h"
#include "element/Real.h"

#include "Vehicle.h"
#include "People.h"

using namespace std;

int main()
{
    cout << endl << "Boolean test" << endl;
    AWS::Boolean boolean("boolean");

    boolean.setValue(true);
    cout << boolean.valueAsString() << endl;
    cout << (boolean.value() == true ? "T" : "F") << endl;

    boolean.setStringValue("FaLsE");
    cout << boolean.valueAsString() << endl;
    cout << (boolean.value() == true ? "T" : "F") << endl;

    boolean.setStringValue("trUE");
    cout << boolean.valueAsString() << endl;
    cout << (boolean.value() == true ? "T" : "F") << endl;

    cout << endl << "Integer test" << endl;
    AWS::Integer integer("integer");

    integer.setStringValue("35");
    cout << integer.value() << endl;
    cout << integer.valueAsString() << endl;
    cout << "is 35: " << (integer.value() == 35 ? "T" : "F") << endl;

    integer.setStringValue("-5");
    cout << integer.value() << endl;
    cout << integer.valueAsString() << endl;
    cout << "is -5: " << (integer.value() == -5 ? "T" : "F") << endl;

    integer.setValue(10);
    cout << integer.value() << endl;
    cout << integer.valueAsString() << endl;
    cout << "is 10: " << (integer.value() == 10 ? "T" : "F") << endl;

    try
    {
        integer.setStringValue("684654851684654681680468406840165416149");
        cout << integer.value() << endl;
        cout << integer.valueAsString() << endl;
        cout << "is -5: " << (integer.value() == -5 ? "T" : "F") << endl;
    }
    catch (const out_of_range& e)
    {
        cout << "exception" << endl;
    }

    cout << endl << "Array of int test" << endl;
    AWS::ArrayElement arrayElement("array");
    AWS::Integer* integ1 = new AWS::Integer("integ1"); integ1->setValue(1);
    AWS::Integer* integ2 = new AWS::Integer("integ2"); integ2->setValue(2147483647); // long int
    AWS::Integer* integ3 = new AWS::Integer("integ3"); integ3->setValue(4294967295); // -1
    AWS::Integer* integ4 = new AWS::Integer("integ4"); integ4->setValue(92233720368547758074294967295); // -1

    arrayElement.add(integ1);
    arrayElement.add(integ2);
    arrayElement.add(integ3);
    arrayElement.add(integ4);

    std::vector<int> vect;
    arrayElement.fill(&vect, NULL);

    for (std::vector<int>::iterator iter = vect.begin(); iter != vect.end(); ++iter)
        cout << *iter << endl;

    cout << endl << "Array of real test" << endl;
    AWS::ArrayElement realArrayElement("array");
    AWS::Real* real1 = new AWS::Real("real1"); real1->setValue(1.0);
    AWS::Real* real2 = new AWS::Real("real2"); real2->setValue(2147483647.0); // long int
    AWS::Real* real3 = new AWS::Real("real3"); real3->setValue(4294967295); // -1
    AWS::Real* real4 = new AWS::Real("real4"); real4->setValue(2); // -1

    realArrayElement.add(real1);
    realArrayElement.add(real2);
    realArrayElement.add(real3);
    realArrayElement.add(real4);

    std::vector<double> realVect;
    realArrayElement.fill(&realVect, NULL);

    for (std::vector<double>::iterator iter = realVect.begin(); iter != realVect.end(); ++iter)
        cout << *iter << endl;

    cout << endl << "Array of string test" << endl;
    AWS::ArrayElement arrayStringElement("array");
    AWS::String* string1 = new AWS::String("integ1"); string1->setValue("a");
    AWS::String* string2 = new AWS::String("integ2"); string2->setValue("b");
    AWS::String* string3 = new AWS::String("integ3"); string3->setValue("c");
    AWS::String* string4 = new AWS::String("integ4"); string4->setValue("d");

    arrayStringElement.add(string1);
    arrayStringElement.add(string2);
    arrayStringElement.add(string3);
    arrayStringElement.add(string4);

    std::vector<std::string> vectString;
    arrayStringElement.fill(&vectString, NULL);

    for (std::vector<std::string>::iterator iter = vectString.begin(); iter != vectString.end(); ++iter)
        cout << *iter << endl;

    cout << endl << "Class test" << endl;
    AWS::ClassElement classVehicle("vehicle");
    AWS::Boolean* isMotorized  = new AWS::Boolean("isMotorized"); isMotorized->setValue(true);
    AWS::Integer* wheels       = new AWS::Integer("wheels");      wheels->setValue(4);
    AWS::String*  brand        = new AWS::String("brand");        brand->setValue("Renault");
    AWS::String*  david        = new AWS::String("name");         david->setValue("David");
    AWS::ClassElement* people  = new AWS::ClassElement(""); people->add(david);// Class name not necessary because it is in an array.
    AWS::ArrayElement* peoples = new AWS::ArrayElement("people"); peoples->add(people);

    classVehicle.add(isMotorized);
    classVehicle.add(wheels     );
    classVehicle.add(brand      );
    classVehicle.add(peoples    );

    Vehicle vehicle;
    classVehicle.fill(&vehicle, NULL);

    cout << "isMotorized: " << vehicle.isMotorized    << endl;
    cout << "wheels     : " << vehicle.wheels         << endl;
    cout << "brand      : " << vehicle.brand          << endl;
    cout << "people     : " << vehicle.people[0]->name << endl;

    cout << endl << "Element test" << endl;
    AWS::ClassElement* classElement = (AWS::ClassElement*)vehicle.toElement("");
    cout << "isMotorized: " << ((AWS::Boolean*)classElement->get("isMotorized"))->value()    << endl;
    cout << "brand      : " << ((AWS::String*)classElement->get("brand")       )->value()    << endl;
    cout << "wheels     : " << ((AWS::Integer*)classElement->get("wheels")     )->value()    << endl;
    cout << "people     : " << ((AWS::String*)((AWS::ClassElement*)((AWS::ArrayElement*)classElement->get("people"))->m_elements[0])->get("name"))->value()    << endl;

    return 0;
}

