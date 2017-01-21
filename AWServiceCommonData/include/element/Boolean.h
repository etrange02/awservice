#ifndef BOOLEAN_H
#define BOOLEAN_H

#include <element/NativeElement.h>
#include <string>

namespace AWS
{
    class Boolean : public NativeElement<bool>
    {
        public:
            /** Default constructor */
            Boolean(const std::string& name);
            /** Default destructor */
            virtual ~Boolean();

            virtual void visit(IVisitor& visitor);

            virtual std::string valueAsString() const;
            virtual void setStringValue(const std::string& value);

            virtual bool getDefaultValue() const;

        protected:

        private:
    };
}

#endif // BOOLEAN_H
