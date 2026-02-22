#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

const int CELL = 25;
const int ROWS = 24;
const int COLS = 24;
const int WIDTH = COLS * CELL;
const int HEIGHT = ROWS * CELL;

struct Segment {
    int x, y;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake Game - C++");
    window.setFramerateLimit(12); 

    std::vector<Segment> snake;
    snake.push_back({ COLS / 2, ROWS / 2 });

    int foodX = rand() % COLS;
    int foodY = rand() % ROWS;

    int dx = 1, dy = 0; 
    bool gameOver = false;
    int score = 0;

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arial.ttf");

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(22);
    scoreText.setFillColor(sf::Color::White);

    srand(time(nullptr));

    auto resetGame = [&]() {
        snake.clear();
        snake.push_back({ COLS / 2, ROWS / 2 });
        dx = 1; dy = 0;
        score = 0;
        foodX = rand() % COLS;
        foodY = rand() % ROWS;
        gameOver = false;
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        if (!gameOver) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dy != 1) { dx = 0; dy = -1; }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dy != -1) { dx = 0; dy = 1; }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dx != 1) { dx = -1; dy = 0; }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dx != -1) { dx = 1; dy = 0; }
        } else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                resetGame();
            }
        }

        if (!gameOver) {
            
            for (int i = snake.size() - 1; i > 0; i--)
                snake[i] = snake[i - 1];

            
            snake[0].x += dx;
            snake[0].y += dy;

            
            if (snake[0].x < 0 || snake[0].x >= COLS || snake[0].y < 0 || snake[0].y >= ROWS)
                gameOver = true;

            
            for (int i = 1; i < snake.size(); i++)
                if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
                    gameOver = true;

            
            if (snake[0].x == foodX && snake[0].y == foodY) {
                snake.push_back(snake.back()); 
                score++;
                foodX = rand() % COLS;
                foodY = rand() % ROWS;
            }
        }

        
        window.clear(sf::Color::Black);

        
        for (auto &s : snake) {
            sf::RectangleShape rect(sf::Vector2f(CELL - 1, CELL - 1));
            rect.setFillColor(sf::Color::Green);
            rect.setPosition(s.x * CELL, s.y * CELL);
            window.draw(rect);
        }

        
        sf::RectangleShape food(sf::Vector2f(CELL - 1, CELL - 1));
        food.setFillColor(sf::Color::Red);
        food.setPosition(foodX * CELL, foodY * CELL);
        window.draw(food);
        

        
        scoreText.setString("Score: " + std::to_string(score));
        scoreText.setPosition(5, 5);
        window.draw(scoreText);

        
        if (gameOver) {
            sf::Text msg;
            msg.setFont(font);
            msg.setCharacterSize(38);
            msg.setFillColor(sf::Color::Yellow);
            msg.setString("GAME OVER\nPress Space to Restart");
            msg.setPosition(35, HEIGHT / 2 - 60);
            window.draw(msg);
        }

        window.display();
    }

    return 0;
}
