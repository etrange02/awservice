#ifndef DATETIME_H
#define DATETIME_H

#include <NativeElement.h>

namespace AWS
{
    class DateTime : public NativeElement<std::string>
    {
        public:
            /** Default constructor */
            DateTime(const std::string& name);
            /** Default destructor */
            virtual ~DateTime();

            virtual void visit(IVisitor& visitor);

            virtual std::string valueAsString() const;
            virtual void setStringValue(const std::string& value);

            virtual std::string getDefaultValue() const;

        protected:

        private:
    };
}

#endif // DATETIME_H
