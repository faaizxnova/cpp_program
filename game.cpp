#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main() {
    const int windowWidth = 1000;
    const int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "C++ Pong Game");
    window.setFramerateLimit(60);

    // Paddles
    sf::RectangleShape leftPaddle(sf::Vector2f(20, 120));
    leftPaddle.setFillColor(sf::Color::White);
    leftPaddle.setPosition(50, windowHeight / 2.f - 60);

    sf::RectangleShape rightPaddle(sf::Vector2f(20, 120));
    rightPaddle.setFillColor(sf::Color::White);
    rightPaddle.setPosition(windowWidth - 70, windowHeight / 2.f - 60);

    // Ball
    sf::CircleShape ball(12);
    ball.setFillColor(sf::Color::White);
    ball.setOrigin(12, 12);
    ball.setPosition(windowWidth / 2.f, windowHeight / 2.f);

    sf::Vector2f ballVelocity(-6.f, -4.f);

    // Speeds
    float paddleSpeed = 7.f;

    int scoreLeft = 0;
    int scoreRight = 0;

    auto updateTitle = [&]() {
        std::string title = "C++ Pong | Left: " + std::to_string(scoreLeft)
                          + "  Right: " + std::to_string(scoreRight);
        window.setTitle(title);
    };

    updateTitle();

    while (window.isOpen()) {
        // ===== Events =====
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ===== Input (Left player: W/S) =====
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            leftPaddle.move(0, -paddleSpeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            leftPaddle.move(0, paddleSpeed);
        }

        // Keep left paddle inside window
        if (leftPaddle.getPosition().y < 0)
            leftPaddle.setPosition(leftPaddle.getPosition().x, 0);
        if (leftPaddle.getPosition().y + leftPaddle.getSize().y > windowHeight)
            leftPaddle.setPosition(leftPaddle.getPosition().x, windowHeight - leftPaddle.getSize().y);

        // ===== Simple AI for Right Paddle =====
        float rightCenter = rightPaddle.getPosition().y + rightPaddle.getSize().y / 2.f;
        if (ball.getPosition().y < rightCenter - 10) {
            rightPaddle.move(0, -paddleSpeed * 0.9f);
        } else if (ball.getPosition().y > rightCenter + 10) {
            rightPaddle.move(0, paddleSpeed * 0.9f);
        }

        // Keep right paddle inside window
        if (rightPaddle.getPosition().y < 0)
            rightPaddle.setPosition(rightPaddle.getPosition().x, 0);
        if (rightPaddle.getPosition().y + rightPaddle.getSize().y > windowHeight)
            rightPaddle.setPosition(rightPaddle.getPosition().x, windowHeight - rightPaddle.getSize().y);

        // ===== Move Ball =====
        ball.move(ballVelocity);

        // Top / bottom bounce
        if (ball.getPosition().y - ball.getRadius() <= 0 ||
            ball.getPosition().y + ball.getRadius() >= windowHeight) {
            ballVelocity.y = -ballVelocity.y;
        }

        // Left paddle collision
        if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds())) {
            ballVelocity.x = std::abs(ballVelocity.x); // ensure moving right
            // small tweak based on where it hits paddle
            float offset = (ball.getPosition().y - (leftPaddle.getPosition().y + leftPaddle.getSize().y / 2.f)) / 30.f;
            ballVelocity.y = offset * 5.f;
        }

        // Right paddle collision
        if (ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds())) {
            ballVelocity.x = -std::abs(ballVelocity.x); // ensure moving left
            float offset = (ball.getPosition().y - (rightPaddle.getPosition().y + rightPaddle.getSize().y / 2.f)) / 30.f;
            ballVelocity.y = offset * 5.f;
        }

        // ===== Scoring =====
        // Ball goes off left side → right scores
        if (ball.getPosition().x + ball.getRadius() < 0) {
            scoreRight++;
            updateTitle();
            ball.setPosition(windowWidth / 2.f, windowHeight / 2.f);
            ballVelocity = sf::Vector2f(-6.f, -4.f);
        }

        // Ball goes off right side → left scores
        if (ball.getPosition().x - ball.getRadius() > windowWidth) {
            scoreLeft++;
            updateTitle();
            ball.setPosition(windowWidth / 2.f, windowHeight / 2.f);
            ballVelocity = sf::Vector2f(6.f, -4.f);
        }

        // ===== Draw =====
        window.clear(sf::Color::Black);
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(ball);
        window.display();
    }

    return 0;
}
