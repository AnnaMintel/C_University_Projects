#include <SFML/Graphics.hpp> // ���������� ��������� ��� ������������ �������
#include <random>

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;
const int PARTICLE_RADIUS = 2;
const int PARTICLE_COUNT = 100;
const float MOVEMENT_SPEED = 2.0;

class Particle {

public:
	Particle (float x, float y) : x(x), y(y) {}

	// ������� ��������� ������� ����� � ������ ��������� �������� � ��������
	void updatePosition(float dx, float dy) {
		x += dx * MOVEMENT_SPEED; 
		y += dy * MOVEMENT_SPEED;
	}

	// ����������� ��������� ����� �� ���� X � Y
	float getX() const { return x; }
	float getY() const { return y; }

private:
	float x, y;
};

int main() {
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "brownian movement"); // �������� ���� ��� ���������
	std::vector<Particle> particles; // �������� ������� ��� �������� ������

	// ������������� ������ ���������� ���������
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<float> distribution(0.0, 1.0);

	// ������� �� ���������� ������������ ��������� ����� 
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

		// �� ���� ���������� �������� ���������� ���������� ��������� ������
		for (auto& particle : particles) {
			float dx = distribution(generator) - 0.5;
			float dy = distribution(generator) - 0.5;
			particle.updatePosition(dx, dy);
		}

		window.clear(sf::Color::White);

		// ��������� ������
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
