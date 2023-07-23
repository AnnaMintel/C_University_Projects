#include <SFML/Graphics.hpp> // библиотека добавлена при конфигурации проекта
#include <random>

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;
const int PARTICLE_RADIUS = 2;
const int PARTICLE_COUNT = 100;
const float MOVEMENT_SPEED = 2.0;

class Particle {

public:
	Particle (float x, float y) : x(x), y(y) {}

	// функция обновления позиции точек с учетом случайных смещений и скорости
	void updatePosition(float dx, float dy) {
		x += dx * MOVEMENT_SPEED; 
		y += dy * MOVEMENT_SPEED;
	}

	// возвращение координат точек по осям X и Y
	float getX() const { return x; }
	float getY() const { return y; }

private:
	float x, y;
};

int main() {
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "brownian movement"); // создание окна для отрисовки
	std::vector<Particle> particles; // создание вектора для хранения частиц

	// инициализация частиц случайными позициями
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<float> distribution(0.0, 1.0);

	// частицы со случайными координатами заполняют экран 
	for (int i = 0; i < PARTICLE_COUNT; ++i) {
		float x = distribution(generator) * WINDOW_WIDTH;
		float y = distribution(generator) * WINDOW_HEIGHT;
		particles.emplace_back(x, y);
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// за счет случайного смещения происходит обновление положения частиц
		for (auto& particle : particles) {
			float dx = distribution(generator) - 0.5;
			float dy = distribution(generator) - 0.5;
			particle.updatePosition(dx, dy);
		}

		window.clear(sf::Color::White);

		// отрисовка частиц
		for (const auto& particle : particles) {
			sf::CircleShape shape(PARTICLE_RADIUS);
			shape.setPosition(particle.getX(), particle.getY());
			shape.setFillColor(sf::Color::Black);
			window.draw(shape);
		}

		window.display();
	}

	return 0;
}
