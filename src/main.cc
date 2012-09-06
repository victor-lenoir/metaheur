#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "problem.hh"

int main ()
{
  int p_size = 5;
  Problem p(p_size);
  double lcost = p.cost();
  sf::RenderWindow App(sf::VideoMode(p_size * 100,
				     p_size * 100, 32), "Metaheuristique");

  while (App.IsOpened())
  {
    sf::Event Event;
    while (App.GetEvent(Event))
    {
      if (Event.Type == sf::Event::Closed)
        App.Close();
    }
    App.Clear();
    p.draw(App);
    App.Display();
    p.random_permutation();
    if (p.cost() > lcost)
      p.undo();
    lcost = p.cost();
    std::cout << p.cost() << std::endl;
  }
  return 0;
}