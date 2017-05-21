#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
public:
	Animation();
	~Animation();

	void update(const sf::Time& deltatime);

	void setFrameTime(const sf::Time& time);
	
	void addFrame(const sf::IntRect& frame);
	unsigned int getNumberOfFrames() const;

	void setCurrentFrame(unsigned int index);
	unsigned int getCurrentFrameIndex() const;

	sf::IntRect getCurrentFrame() const;

	void play();
	void pause();
	void stop();

	void next();
	void prev();

	bool isPlaying() const;

	void setRepeat(bool repeat);

private:
	static const sf::Time DEFAULT_FRAME_TIME;

	std::vector<sf::IntRect> frames;
	unsigned int currentFrame;

	sf::Time frameTime;
	sf::Time currentFrameTime;

	bool playing;
	bool repeating;
};

#endif