#include "Bureaucrat.hpp"
#include "colours.hpp"

int main()
{
    Bureaucrat *lol = new Bureaucrat("Lol", 150);
    Bureaucrat *kek = new Bureaucrat("Kek", 1);
    Bureaucrat wowow("Wow", 75);
    Bureaucrat & wow = wowow;
    Bureaucrat lowestBureaucrat("LowestBureaucrat", 151);
    Bureaucrat highestBureaucrat("HighestBureaucrat", 0);

    lol->decrement();
    lol->decrement();

    kek->increment();
    kek->increment();

    wow.increment();
    wow.decrement();

    lowestBureaucrat.increment();
    highestBureaucrat.decrement();

    delete (lol);
    delete kek;
    return 0;
}