#include "animation.hpp"

const sf::Time Animation::DEFAULT_FRAME_TIME = sf::seconds(0.5f);

Animation::Animation() {
	currentFrame = 0;

	frameTime = Animation::DEFAULT_FRAME_TIME;
	currentFrameTime = sf::Time::Zero;

	playing = true;
	repeating = true;
}

Animation::~Animation() {
	frames.clear();
}

void Animation::update(const sf::Time& deltatime) {
	if (isPlaying()) {
		currentFrameTime += deltatime;

		if (currentFrameTime > frameTime) {
			next();
			currentFrameTime -= frameTime;
		}
	}
}

void Animation::setFrameTime(const sf::Time& time) {
	frameTime = time;
	currentFrameTime = sf::Time::Zero;
}

void Animation::addFrame(const sf::IntRect& frame) {
	frames.push_back(frame);
}

unsigned int Animation::getNumberOfFrames() const {
	return frames.size();
}

void Animation::setCurrentFrame(unsigned int index) {
	if (index < getNumberOfFrames())
		currentFrame = index;
}

unsigned int Animation::getCurrentFrameIndex() const {
	return currentFrame;
}

sf::IntRect Animation::getCurrentFrame() const {
	if (frames.empty()) {
		return sf::IntRect(0, 0, 0, 0);
	}

	return frames[getCurrentFrameIndex()];
}

void Animation::play()  { playing = true;  }
void Animation::pause() { playing = false; }

void Animation::stop() {
	playing = false;
	setCurrentFrame(0);
}

void Animation::next() {
	if (!frames.empty()) {
		currentFrame = (currentFrame + 1) % getNumberOfFrames();
	}
}

void Animation::prev() {
	if (!frames.empty()) {
		if (currentFrame == 0) {
			currentFrame = getNumberOfFrames() - 1;
		} else {
			currentFrame = currentFrame - 1;
		}
	}
}

bool Animation::isPlaying() const { return playing; }

void Animation::setRepeat(bool repeat) { repeating = repeat; }