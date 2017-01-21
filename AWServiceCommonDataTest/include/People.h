#ifndef PEOPLE_H
#define PEOPLE_H

#include "model/IUserModel.h"
#include "element/Element.h"

class People : public AWS::IUserModel
{
    public:
        /** Default constructor */
        People();
        /** Default destructor */
        virtual ~People();

        virtual AWS::Element* toElement(const std::string& name);
        virtual void fromElement(AWS::Element& element);

        std::string name;

    protected:

    private:
};

#endif // PEOPLE_H
