//https://benbcompsci.wordpress.com/2019/04/11/c-sfml-textbox-and-button-classes/

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
	sf::RectangleShape button;
	sf::Text text;
	sf::Font font;

public:
	Button() {};

	Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor, float outThickness, sf::Color outColor);

	void setBackColor(sf::Color color);
	void setTextColor(sf::Color color);
	void setPosition(sf::Vector2f pos);
	void drawTo(sf::RenderWindow &win);
	bool isMouseOver(sf::RenderWindow &win);
	void setFont(sf::Font &fonts);
	void setTextPosition(sf::Vector2f pos);
	void setOutline(int thickness, sf::Color color);
	void sizeSet(const sf::Vector2f size);
	void setTextString(std::string txt, int size);
};

#endif // BUTTON_H