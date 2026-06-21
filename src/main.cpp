#include "humangl.h"


int main() {
	initialize();

	vertexSpecification();
	createGraphicsPipeline();

	loop();

	cleanup();
}
