#ifndef CONVERTER_HPP
# define CONVERTER_HPP
# include <iostream>

class Converter
{
private:
    std::string _str;
public:
    Converter();
    Converter(std::string value);
    ~Converter();
    Converter(Converter const &);
    Converter &operator=(Converter const &);

    void convert();
    void convertFromFloat();
    void convertFromDouble();
    void convertFromChar();
    void convertFromInt();
    void specialConversion();

    std::string getStr() const;

    class WrongStringException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Impossible to convert this: long string with not only numbers, one dot and f at the end!");
        }
    };
};

#endif