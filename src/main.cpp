#include "humangl.h"

int main() {
	initialize();

	human.upload();
	createGraphicsPipeline();

	loop();

	cleanup();
}
