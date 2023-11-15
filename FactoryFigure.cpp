#include "Lib.h"

Figure* FactoryFigure::getFigure(string name) {
	if(name == "rect")
		return new Rectangle();
	if(name == "circle")
		return new Circle();
	if(name == "ellipse")
		return new Ellipse();
	if(name == "line")
		return new Line();
	if(name == "polyline")
		return new Polyline();
	if(name == "polygon")
		return new Polygon();
	if(name == "text")
		return new Text();
	return NULL;
}
