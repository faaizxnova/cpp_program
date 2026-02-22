#include <SFML/Graphics.hpp>
#include <cmath>

struct Planet {
    sf::CircleShape body;
    float distance;
    float angle;
    float speed;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1100, 800), "Solar System Animation");
    window.setFramerateLimit(60);

    // Sun
    sf::CircleShape sun(60);
    sun.setFillColor(sf::Color::Yellow);
    sun.setOrigin(60, 60);
    sun.setPosition(550, 400);

    // Planets
    Planet planets[5];

    planets[0] = { sf::CircleShape(10), 90, 0, 0.03f };   // Mercury
    planets[1] = { sf::CircleShape(14), 150, 0, 0.02f };  // Venus
    planets[2] = { sf::CircleShape(16), 230, 0, 0.015f }; // Earth
    planets[3] = { sf::CircleShape(13), 300, 0, 0.010f }; // Mars
    planets[4] = { sf::CircleShape(30), 420, 0, 0.006f }; // Jupiter

    // Colors
    planets[0].body.setFillColor(sf::Color(180, 180, 180));
    planets[1].body.setFillColor(sf::Color(245, 197, 66));
    planets[2].body.setFillColor(sf::Color(50, 120, 255));
    planets[3].body.setFillColor(sf::Color(255, 60, 60));
    planets[4].body.setFillColor(sf::Color(200, 120, 20));

    for (auto &p : planets) {
        p.body.setOrigin(p.body.getRadius(), p.body.getRadius());
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(sun);

        // Update planet positions
        for (auto &p : planets) {
            p.angle += p.speed;
            float x = 550 + p.distance * std::cos(p.angle);
            float y = 400 + p.distance * std::sin(p.angle);
            p.body.setPosition(x, y);
            window.draw(p.body);
        }

        window.display();
    }

    return 0;
}
