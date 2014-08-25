#include "Application.h"

int main(int argc, char** argv){
	Application app;
	if(!app.init())
		return 1;

	while(app.update()){
		app.draw();
	}

	return 0;
}