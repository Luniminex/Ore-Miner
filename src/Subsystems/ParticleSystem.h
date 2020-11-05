#pragma once

struct Particle {
	sf::Time lifetime;
	sf::Vector2f velocity;
	sf::Vector2f gravityForce;
	bool active = true;
};

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
private:
	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;
	sf::Texture tex;
	sf::Image img;
	sf::IntRect UVrect;
private:
	void setUVrect(int top, int left);
	void setStartingVertices(sf::Vector2f startingPos, sf::Vector2f quadSize, size_t index, sf::Vector2f quadTexSize);
	void setStartingParticles(sf::Vector2f velocity, sf::Time lifetime, sf::Vector2f gravityForce, size_t index);
	sf::Vector2f setGravityForce(float MINF, float MAXF);
	float setSpeed(int varySpeed, float baseSpeed);
	sf::Time setLifetime(int base, int varyTime);
	float setAngle(int varyAngle);
	sf::Vector2f setVelocity(float angle, float cone, float speed);
	void resizeParticlesArrays(size_t count);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

	ParticleSystem(size_t count);

	void clearParticles();

	void generateParticlesByID(size_t count, sf::Vector2f pos, int ID);

	void setPosEmitter(sf::Vector2f pos) { m_emitter = pos; }; //idk

	void setPosEmitter(float x, float y) { m_emitter = { x,y }; };

	void resetParticle(std::size_t index);

	void updateParticles(sf::Time elapsed, float deltaTime);



};