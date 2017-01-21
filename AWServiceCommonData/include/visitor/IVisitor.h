#ifndef IVISITOR_H
#define IVISITOR_H

namespace AWS {
    class ArrayElement;
    class ClassElement;
    class Integer;
    class Boolean;
    class Real;
    class String;
    class DateTime;
    class Raw;
}

namespace AWS
{
    class IVisitor
    {
        public:
            virtual void visitArray(const ArrayElement& array) = 0;
            virtual void visitClass(const ClassElement& element) = 0;
            virtual void visitInteger(const Integer& integer) = 0;
            virtual void visitBoolean(const Boolean& boolean) = 0;
            virtual void visitReal(const Real& real) = 0;
            virtual void visitString(const String& element) = 0;
            virtual void visitDateTime(const DateTime& dateTime) = 0;
            virtual void visitRaw(const Raw& raw) = 0;

        protected:
            /** Default constructor */
            IVisitor();
            /** Default destructor */
            virtual ~IVisitor();

        private:
    };
}

#endif // IVISITOR_H
