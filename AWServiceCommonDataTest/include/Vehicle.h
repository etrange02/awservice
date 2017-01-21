#ifndef VEHICLE_H
#define VEHICLE_H

#include "model/IUserModel.h"
#include <vector>

class People;
namespace AWS {
    class Element;
}

class Vehicle : public AWS::IUserModel
{
    public:
        /** Default constructor */
        Vehicle();
        /** Default destructor */
        virtual ~Vehicle();

        virtual AWS::Element* toElement(const std::string& name);
        virtual void fromElement(AWS::Element& element);

        bool isMotorized;
        int wheels;
        std::string brand;
        std::vector<People*> people;

    protected:

    private:
};

#endif // VEHICLE_H
