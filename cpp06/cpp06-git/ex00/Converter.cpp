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

    double d_value = std::atof(_str.c_str());
    float f_value = std::atof(_str.c_str());
    int i_value = static_cast<int>(f_value);
    std::cout << "int: " << i_value << std::endl;
    std::cout << "double: " << d_value << std::endl;
    std::cout << "float: " << f_value << "f\n" << std::endl;

    if (_str == "nan" || _str == "nanf" || _str == "+inf"
        || _str == "-inf" || _str == "+inff" || _str == "-inff")
        specialConversion();
    else if (size > 1)
    {
        for (int i = 0; i < size - 1; i++)
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
        else if (dots == 0)
            this->convertFromInt();
        else
            this->convertFromDouble();
    }
    else if (std::isdigit(_str[0]) == false)
        this->convertFromChar();
}

void Converter::convertFromFloat()
{
    float value = std::atof(_str.c_str());
    std::cout << "char: " << static_cast<char>(value) << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void Converter::convertFromDouble()
{
    double value = std::atof(_str.c_str());
    std::cout << "char: " << static_cast<char>(value) << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void Converter::convertFromChar()
{
    char value = _str[0];
    std::cout << "char: " << value << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;

}

void Converter::convertFromInt()
{
    int value = std::atoi(_str.c_str());
    if (value < 40 || value > 176)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void Converter::specialConversion()
{
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << _str << "f" << std::endl;
    std::cout << "double: " << _str << std::endl;
}

std::string Converter::getStr() const
{
    return(this->_str);
}