//sudo aptitude install libsfml-dev

#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;

int main() {
	bool b = true;
	while (b) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
			cout << "Right-Left" << endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			cout << "Right" << endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			cout << "Left" << endl;
		}
			
	}

	return 0;
}

