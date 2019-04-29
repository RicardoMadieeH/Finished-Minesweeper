#include "Button.h"

Button::Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor, float outThickness, sf::Color outColor) {
	text.setString(t);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);

	button.setSize(size);
	button.setFillColor(bgColor);
	button.setOutlineThickness(outThickness);
	button.setOutlineColor(outColor);

}

void Button::setBackColor(sf::Color color) {
	button.setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
	text.setFillColor(color);
}

void Button::setPosition(sf::Vector2f pos) {
	button.setPosition(pos);
}

void Button::drawTo(sf::RenderWindow &win) {
	win.draw(button);
	win.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow &win) {
	float mouseX = sf::Mouse::getPosition(win).x;
	float mouseY = sf::Mouse::getPosition(win).y;

	float buttonxPos = button.getPosition().x;
	float buttonyPos = button.getPosition().y;

	float buttonxPosWidth = button.getPosition().x + button.getLocalBounds().width;
	float buttonyPosHeight = button.getPosition().y + button.getLocalBounds().height;

	if (mouseX < buttonxPosWidth && mouseX > buttonxPos && mouseY < buttonyPosHeight && mouseY > buttonyPos) {
		return true;
	}
	return false;

}

void Button::setFont(sf::Font &fonts) {
	text.setFont(fonts);
}

void Button::setTextPosition(sf::Vector2f pos) {
	text.setPosition(pos);
}

void Button::setOutline(int thickness, sf::Color color) {
	button.setOutlineThickness(thickness);
	button.setOutlineColor(color);
}

void Button::sizeSet(const sf::Vector2f size) {
	button.setSize(size);
}

void Button::setTextString(std::string txt, int size) {
	text.setString(txt);
	text.setCharacterSize(size);
}