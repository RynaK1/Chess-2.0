#include <SFML/Graphics.hpp>
#include <iostream>

char MAX_UNICODE = 128;

int main() {
    sf::RenderWindow window(sf::VideoMode(512, 512), "Chess", sf::Style::Close | sf::Style::Resize); //Window size, name, style
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    player.setFillColor(sf::Color::Cyan);
    player.setOrigin(50.0f, 50.0f);
    //sf::Texture playerTexture;
    //playerTexture.loadFromFile("name.png");
    //player.setTexture(&playerTexture);

    while (window.isOpen()) { //keep window open
        sf::Event evnt;
        while (window.pollEvent(evnt)) { // move window
            switch (evnt.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                printf("Width: %i Height: %i\n", evnt.size.width, evnt.size.height);
                break;
            case sf::Event::TextEntered:
                if (evnt.text.unicode < MAX_UNICODE) {
                    printf("%c", evnt.text.unicode);
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            player.move(-0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            player.move(0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            player.move(0.0f, -0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            player.move(0.0f, 0.1f);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); //get mouse position relative to window
            player.setPosition((float)mousePos.x, (float)mousePos.y);
        }

        window.clear();
        window.draw(player);
        window.display();
    }
    
    return 0;
}