#ifndef REAL_H
#define REAL_H

#include <NativeElement.h>
#include <IVisitor.h>

namespace AWS
{
    class Real : public NativeElement<double>
    {
        public:
            /** Default constructor */
            Real(const std::string& name);
            /** Default destructor */
            virtual ~Real();

            virtual void visit(IVisitor& visitor);

            virtual std::string valueAsString() const;
            virtual void setStringValue(const std::string& value);

            virtual double getDefaultValue() const;
        protected:

        private:
    };
}

#endif // REAL_H
