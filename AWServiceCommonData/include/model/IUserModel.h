#ifndef IUSERMODEL_H
#define IUSERMODEL_H

#include <string>

namespace AWS {
    class Element;
}

namespace AWS
{
    /** \brief Each class of the user model must inherit from this interface.
     */
    class IUserModel
    {
        public:
            IUserModel(const std::string& name);
            virtual ~IUserModel();

            virtual Element* toElement(const std::string& name) = 0;
            virtual void fromElement(Element& element) = 0;

            const std::string& getName() const;

        private:
            IUserModel();

            std::string m_name;
    };
}

#endif // IUSERMODEL_H
