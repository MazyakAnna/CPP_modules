#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "colours.hpp"

int main()
{
    Form wrongForm1("Wrong Form1", 0, 50);
    Form wrongForm2("Wrong Form2", 151, 50);
    Form wrongForm3("Wrong Form3", 50, 0);
    Form wrongForm4("Wrong Form4", 50, 151);

    Bureaucrat *rookie = new Bureaucrat("Rookie", 150);
    Bureaucrat *boss = new Bureaucrat("Boss", 1);
    Form *lol = new Form("lol", 50, 100);

    rookie->signForm(*lol);
    boss->signForm(*lol);

    delete (rookie);
    delete boss;
    delete lol;
    return 0;
}