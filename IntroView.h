#ifndef INTROVIEW_H
#define INTROVIEW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

class IntroView {
	sf::Font arial;
	sf::Font harington;

	sf::Text title;
	sf::Text name;
	sf::Text index;
	sf::Text group;

public:
	sf::RectangleShape background;

	Button small;
	Button medium;
	Button big;
	Button easy;
	Button normal;
	Button hard;
	Button start;


	IntroView();

	void draw(sf::RenderWindow &win);
};


#endif // INTROVIEW_H
