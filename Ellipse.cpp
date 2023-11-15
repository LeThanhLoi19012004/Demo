#include "Lib.h"

Ellipse::Ellipse() :Figure() {
	rx = ry = 0;
	center.setX(0);
	center.setY(0);
}

Ellipse::~Ellipse() {
	rx = ry = 0;
	center.setX(0);
	center.setY(0);
}

void Ellipse::updateDiffElement() {
	stringstream ss(line);
	string property, value;

	while (ss >> property >> value) {
		if (property == "rx")
			this->rx = stof(value);
		if (property == "ry")
			this->ry = stof(value);
		if (property == "cx")
			this->center.setX(stof(value));
		if (property == "cy")
			this->center.setY(stof(value));
	}
}

Point Ellipse::getCenter() {
	return this->center;
}

float Ellipse::getRx() {
	return this->rx;
}

float Ellipse::getRy() {
	return this->ry;
}

void Ellipse::setCenter(float x, float y) {
	this->center.setX(x);
	this->center.setY(y);
}

void Ellipse::setRx(float rx) {
	this->rx = rx;
}

void Ellipse::setRy(float ry) {
	this->ry = ry;
}

void Ellipse::Draw(sf::RenderWindow& window) {
	unsigned short pointNum = 72; //72 is the golden distribution of points to form ellipse

	sf::ConvexShape ellipse;
	ellipse.setPointCount(pointNum);

	for (unsigned short i = 0; i < pointNum; i++) {
		float radian = (360 / pointNum * i) / (180 / Pi);
		float x = cos(radian) * rx;
		float y = sin(radian) * ry;

		ellipse.setPoint(i, sf::Vector2f(x, y));
	}


	if (fill.r != -1) {
		ellipse.setFillColor(sf::Color(fill.r, fill.g, fill.b));
		if (fill.opacity >= 0)
			ellipse.setFillColor(sf::Color(fill.r, fill.g, fill.b, fill.opacity * MAX));
	}
	else ellipse.setFillColor(sf::Color::Transparent);

	if (stroke.getStrokeColor().r != -1) {
		ellipse.setOutlineColor(sf::Color(stroke.getStrokeColor().r, stroke.getStrokeColor().g, stroke.getStrokeColor().b));
		ellipse.setOutlineThickness(stroke.getStrokeWidth());
		if (stroke.getStrokeColor().opacity >= 0)
			ellipse.setOutlineColor(sf::Color(stroke.getStrokeColor().r, stroke.getStrokeColor().g, stroke.getStrokeColor().b, stroke.getStrokeColor().opacity * MAX));
	}
	else ellipse.setOutlineColor(sf::Color::Transparent);

	if (this->getName() == "ellipse")
		ellipse.setPosition(center.getX(), center.getY() - 10);
	else ellipse.setPosition(center.getX() - 10, center.getY());

	window.draw(ellipse);
}