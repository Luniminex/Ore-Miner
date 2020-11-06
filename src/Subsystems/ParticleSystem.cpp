#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(size_t count) :
	m_emitter(0, 0),
	m_particles(count),
	m_vertices(sf::Quads, count * 4),
	m_lifetime(sf::seconds(3.f))
{
	static int noInst;
	noInst++;
	img.loadFromFile("content/Items/items.png");
	tex.loadFromImage(img);
	tex.setRepeated(true);
}

void ParticleSystem::resetParticle(std::size_t index) {
	sf::Vector2f gravityF = setGravityForce(2.5f, 2.5f);
	float angle = setAngle(180);
	float speed = setSpeed(50, 100.f);
	sf::Vector2f velocity = setVelocity(angle, -1.2f, speed);
	sf::Time lifetime = setLifetime(3000, 1);

	setStartingParticles(velocity, lifetime, gravityF, index);
	setStartingVertices(m_emitter, sf::Vector2f(8.f, 8.f), index, sf::Vector2f(32.f, 32.f));
}

void ParticleSystem::generateParticlesByID(std::size_t count, sf::Vector2f pos, int ID) {
	m_emitter = pos;
	setUVrect(32 * ID, 0);
	tex.loadFromImage(img, UVrect);
	for (size_t i = 0; i < m_particles.size(); i++) {
		if (m_particles[i].active == false && count > 0) {
			resetParticle(i);
			count--;
		}
		else {

		}
	}
}

void ParticleSystem::updateParticles(sf::Time elapsed, float deltaTime) {
	for (size_t i = 0; i < m_particles.size() * 4; i++) {
		int x = i / 4;
		Particle& p = m_particles[x];
		p.lifetime -= elapsed;
		if (p.lifetime <= sf::Time::Zero)
			p.active = false;
		if (p.active) {
			p.lifetime -= elapsed;


			p.velocity -= p.gravityForce;
			m_vertices[i].position += p.velocity * deltaTime;

			//float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
			//m_vertices[i].color.a = static_cast<sf::Uint8>(310 + (255 * ratio));
			m_vertices[i].color.a = static_cast<sf::Uint8>(255);
		}
		else {
			m_vertices[i].color.a = static_cast<sf::Uint8>(0);
		}
	}
}

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	states.texture = &tex;
	target.draw(m_vertices, states);
}

void ParticleSystem::setUVrect(int top, int left) {
	UVrect.top = top;
	UVrect.left = left;
	UVrect.height = 32;
	UVrect.width = 32;
}

void ParticleSystem::setStartingVertices(sf::Vector2f startingPos, sf::Vector2f quadSize, size_t index, sf::Vector2f quadTexSize) {
	if ((index * 4) % 4 == 0) {
		int i = index * 4;
		m_vertices[i].position = startingPos;
		m_vertices[i + 1].position = startingPos + sf::Vector2f(0.f, quadSize.y);
		m_vertices[i + 2].position = startingPos +quadSize;
		m_vertices[i + 3].position = startingPos + sf::Vector2f(quadSize.x, 0.f);
		m_vertices[i].texCoords =  sf::Vector2f(quadTexSize.x, 0.f);
		m_vertices[i + 1].texCoords =  quadTexSize;
		m_vertices[i + 2].texCoords =  sf::Vector2f(0.f, quadTexSize.y);
		m_vertices[i + 3].texCoords = sf::Vector2f(0.f, 0.f);
	}
}

void ParticleSystem::setStartingParticles(sf::Vector2f velocity, sf::Time lifetime, sf::Vector2f gravityForce, size_t index) {
	m_particles[index].active = true;
	m_particles[index].velocity = velocity;
	m_particles[index].lifetime = lifetime;
	m_particles[index].gravityForce = gravityForce;
}

sf::Vector2f ParticleSystem::setGravityForce(float MINF, float MAXF) {
	return sf::Vector2f(0, (((float)rand() / RAND_MAX) * (MAXF - MINF) + MINF)) * (-1.f);
}

float ParticleSystem::setSpeed(int varySpeed, float baseSpeed) {
	return (std::rand() % varySpeed) + baseSpeed;
}

sf::Time ParticleSystem::setLifetime(int base, int varyTime) {
	return sf::milliseconds((std::rand() % varyTime) + base);
}

float ParticleSystem::setAngle(int varyAngle) {
	return (std::rand() % varyAngle) * 3.14 / 180.f;
}

sf::Vector2f ParticleSystem::setVelocity(float angle, float cone, float speed) {
	return sf::Vector2f(std::cos(angle) * speed, (cone - std::sin(angle)) * speed);
}

void ParticleSystem::resizeParticlesArrays(size_t count){ // made for quads
	m_particles.resize(count);
	m_vertices.resize(count * 4);
}

void ParticleSystem::clearParticles() {
	m_vertices.clear();
	m_particles.clear();
}