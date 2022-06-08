#include "Converter.hpp"

Converter::Converter(): _str(0)
{
}

Converter::Converter(std::string value): _str(value)
{
}

Converter::~Converter()
{
}

Converter::Converter(Converter const &src)
{
    this->_str = src.getStr();
}

Converter &Converter::operator=(Converter const &rv)
{
    this->_str = rv.getStr();
    return (*this);
}

void Converter::convert()
{
    int size = _str.size();
    int dots = 0;

    std::cout.precision(9);
    if (_str == "nan" || _str == "nanf" || _str == "+inf"
        || _str == "-inf" || _str == "+inff" || _str == "-inff")
        specialConversion();
    else if (size > 1)
    {
        int start = 0;
        if (_str[0] == '-' || _str[0] == '+')
            start = 1;
        for (int i = start; i < size - 1; i++)
            if (_str[i] == '.')
            {
                dots++;
                if (dots > 1)
                    throw Converter::WrongStringException();
            }
            else if (std::isdigit(_str[i]) == false)
                throw Converter::WrongStringException();
        if (_str[size - 1] == 'f')
            this->convertFromFloat();
        else if (std::isdigit(_str[size-1]) == false)
            throw Converter::WrongStringException();
        else if (dots == 0 && atof(_str.c_str()) < INT_MAX && atof(_str.c_str()) > INT_MIN)
            this->convertFromInt();
        else
            this->convertFromDouble();
    }
    else if (std::isdigit(_str[0]) == false)
        this->convertFromChar();
    else
        this->convertFromInt();
}

void Converter::convertFromFloat()
{
    float value = std::atof(_str.c_str());
    int i = static_cast<int>(value);
    if (value < INT_MIN || value > INT_MAX || i < 0 || i > 256)
        std::cout << "char: Impossible" << std::endl;
    else if (i < 40 || i > 176)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    if (value < INT_MIN || value > INT_MAX)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    if (i != value)
    {
        std::cout << "float: " << value << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
    else
    {
        std::cout << "float: " << value << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
    }
}

void Converter::convertFromDouble()
{
    double value = std::atof(_str.c_str());
    int i = static_cast<int>(value);
    if (value < INT_MIN || value > INT_MAX || i < 0 || i > 256)
        std::cout << "char: Impossible" << std::endl;
    else if (i < 40 || i > 176)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    if (value < INT_MIN || value > INT_MAX)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    if (i != value)
    {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
        std::cout << "double: " << value << ".0" << std::endl;
    }
}

void Converter::convertFromChar()
{
    char value = _str[0];
    std::cout << "char: " << value << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0"  << std::endl;

}

void Converter::convertFromInt()
{
    int value = std::atoi(_str.c_str());
    if (value < 0 || value > 256)
        std::cout << "char: Impossible" << std::endl;
    else if (value < 40 || value > 176)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void Converter::specialConversion()
{
    std::string tmp = _str;
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    if (_str == "+inff" || _str == "-inff" || _str == "nanf")
        tmp.pop_back();
    std::cout << "float: " << tmp << "f" << std::endl;
    std::cout << "double: " << tmp << std::endl;
}

std::string Converter::getStr() const
{
    return(this->_str);
}

const char* Converter::WrongStringException::what() const throw()
{
    return ("Impossible to convert this: long string with not only numbers, one dot and f at the end!");
}