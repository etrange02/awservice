#ifndef INTEGER_H
#define INTEGER_H

#include <NativeElement.h>

namespace AWS {
    class IVisitor;
}

namespace AWS
{
    class Integer : public NativeElement<long>
    {
        public:
            /** Default constructor */
            Integer(const std::string& name);
            /** Default destructor */
            virtual ~Integer();
            /** Copy constructor
             *  \param other Object to copy from
             */

            virtual void visit(IVisitor& visitor);

            virtual std::string valueAsString() const;
            virtual void setStringValue(const std::string& value);

            virtual long getDefaultValue() const;

        protected:

        private:
    };
}

#endif // INTEGER_H
