#include "animatedsprite.hpp"

AnimatedSprite::AnimatedSprite(const sf::Texture& texture,
						       Animation* animation) 
	: sf::Sprite(texture) {
	
	this->animation = animation;
}

void AnimatedSprite::setAnimation(Animation* animation) {
	this->animation = animation;
}

void AnimatedSprite::update(const sf::Time& deltatime) {
	animation->update(deltatime);

	sf::IntRect frame = animation->getCurrentFrame();
	setTextureRect(frame);
}