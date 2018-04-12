#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif


#include <fstream>
#include <iostream>
#include <sstream>

#include <vector>

#include <memory>


#include "../lib/glew/glew.h"
#include "../lib/glfw3/glfw3.h"
#include "common.h"
#include "Shader.h"
#include "Vertex.h"
#include "Buffer.h"
#include "Mesh.h"
#include "Entity.h"
#include "Model.h"
#include "Camera.h"
#include "World.h"
#include "Texture.h"

#include "State.h"


#define FULLSCREEN false

const float ROTATION_SPEED = 64.0f;
//const float ROTATION_SPEED_RADS = glm::radians(ROTATION_SPEED);

std::string readString(const char* filename) {
	std::ifstream f(filename, std::ios_base::binary);
	std::stringstream ss;
	ss << f.rdbuf();
	return ss.str();
}


int init() {
	
	// init glew
	if (glewInit()) {
		std::cout << "could not initialize glew" << std::endl;
		return -1;
	}

	// enable gl states
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_SCISSOR_TEST);
	return 0;

}


// This method creates all the models and add them to the world
int createModelsInWorld(World & world)
{
	// Crear el Buffer que contiene los datos de un triángulo
	vector<Vertex> vertices;
	vector<uint16_t> indices;
	vector<Vertex> vertices2;
	vector<uint16_t> indices2;


	/*Vertex v1{ glm::vec3(0.0f, 0.5f, 0.0f) };
	Vertex v2{ glm::vec3(-0.5f, -0.5f, 0.0f) };
	Vertex v3{ glm::vec3(0.5f, -0.5f, 0.0f) };*/


	Vertex v0{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0, 0) };
	Vertex v1{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1, 0) };
	Vertex v2{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1, 1) };
	Vertex v3{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0, 1) };

	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(2);
	indices.push_back(3);
	indices.push_back(0);



	Vertex v4{ glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec2(0, 0) };
	Vertex v5{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1, 0) };
	Vertex v6{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1, 1) };
	Vertex v7{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(0, 1) };

	vertices.push_back(v4);
	vertices.push_back(v5);
	vertices.push_back(v6);
	vertices.push_back(v7);


	indices.push_back(4);
	indices.push_back(5);
	indices.push_back(6);
	indices.push_back(6);
	indices.push_back(7);
	indices.push_back(4);


	Vertex v8{ glm::vec3(0.5f, -0.5f, 0.5f),  glm::vec2(0, 0) };
	Vertex v9{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(1, 0) };
	Vertex v10{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1, 1) };
	Vertex v11{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(0, 1) };

	vertices.push_back(v8);
	vertices.push_back(v9);
	vertices.push_back(v10);
	vertices.push_back(v11);

	indices.push_back(8);
	indices.push_back(9);
	indices.push_back(10);
	indices.push_back(10);
	indices.push_back(11);
	indices.push_back(8);


	
	Vertex v12{ glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec2(0, 0) };
	Vertex v13{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(1, 0) };
	Vertex v14{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(1, 1) };
	Vertex v15{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0, 1) };

	vertices.push_back(v12);
	vertices.push_back(v13);
	vertices.push_back(v14);
	vertices.push_back(v15);

	indices.push_back(12);
	indices.push_back(13);
	indices.push_back(14);
	indices.push_back(14);
	indices.push_back(15);
	indices.push_back(12);

	//Insert indexes for the top and bottom sides of the cube
	Vertex v20{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0, 0) };
	Vertex v21{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1, 0) };
	Vertex v22{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1, 1) };
	Vertex v23{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0, 1) };

	vertices2.push_back(v20);
	vertices2.push_back(v21);
	vertices2.push_back(v22);
	vertices2.push_back(v23);

	indices2.push_back(0);
	indices2.push_back(1);
	indices2.push_back(2);
	indices2.push_back(2);
	indices2.push_back(3);
	indices2.push_back(0);

	Vertex v24{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0, 0) };
	Vertex v25{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1, 0) };
	Vertex v26{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1, 1) };
	Vertex v27{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0, 1) };

	vertices2.push_back(v24);
	vertices2.push_back(v25);
	vertices2.push_back(v26);
	vertices2.push_back(v27);

	indices2.push_back(4);
	indices2.push_back(5);
	indices2.push_back(6);
	indices2.push_back(6);
	indices2.push_back(7);
	indices2.push_back(4);

	shared_ptr<Buffer> bufferDatosLaterales = Buffer::create(vertices, indices);
	if (strcmp(bufferDatosLaterales->getError(), "") != 0)
	{
		cout << bufferDatosLaterales->getError() << endl;
		return 0;
	}

	shared_ptr<Buffer> bufferDatosTapas = Buffer::create(vertices2, indices2);
	if (strcmp(bufferDatosTapas->getError(), "") != 0)
	{
		cout << bufferDatosTapas->getError() << endl;
		return 0;
	}

	Material materialFront = Material::Material(Texture::load("../data/front.png"), nullptr);

	shared_ptr<Mesh> cubeMesh = make_shared<Mesh>();
	Model cubeModel(cubeMesh);
	cubeMesh->addBuffer(bufferDatosLaterales, materialFront);


	Material materialTop = Material::Material(Texture::load("../data/top.png"), nullptr);
	cubeMesh->addBuffer(bufferDatosTapas, materialTop);

	glm::vec3 scaleVector(1.0f, 1.0f, 1.0f);
	glm::vec3 rotationVector(0.0f, 0.0f, 0.0f);

	// Load textures





	// create the triangles in the scene
	//for (int x = -3; x <= 3; x += 3) {
	//	for (int z = 0; z >= -6; z -= 3) {

			shared_ptr<Model> cube = make_shared<Model>(cubeMesh);
			cube->setScale(scaleVector);
			cube->setRotation(rotationVector);
			cube->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));

			//Add them to the world object
			world.addEntity(cube);
	//	}
	//}

	return 1;
}


int main(int, char**) {


	if (glfwInit() != GLFW_TRUE) {
		std::cout << "could not initalize glfw" << std::endl;
		return -1;
	}
	atexit(glfwTerminate);

	// create window
	//glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "U-gine", FULLSCREEN ? glfwGetPrimaryMonitor() : nullptr, nullptr);
	if (!window) {
		std::cout << "could not create glfw window" << std::endl;
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (init())
		return -1;


	// Store the Shader in the global object State
	State::defaultShader = Shader::create(readString("../data/shader.vert"), readString("../data/shader.frag"));

	// If there  was any error on the generation of the sharder, raise an error
	if (strcmp(State::defaultShader->getError(), "") != 0)
	{
		cout << State::defaultShader->getError() << endl;
		return -1;
	}

	// Generate the world
	World world;

	// Generate a camera and store it in the world
	shared_ptr<Camera> camera = make_shared<Camera>();
	camera->setPosition(glm::vec3(0.0f, 1.0f, 3.0f));
	camera->setClearColor(glm::vec3(0, 0, 0));
	glm::vec3 cameraRotation = camera->getRotation();
	cameraRotation.x = -20.0f;
	camera->setRotation(cameraRotation);
	world.addEntity(camera);

	// Generate the objects in the world
	if (!createModelsInWorld(world))
	{
		cout << "Error creating the Model objects in the world" << endl;
		return -1;
	}

	// create a cuaternion with the  
	glm::quat rotationQuat = angleAxis(ROTATION_SPEED,
		glm::vec3(0.0f, 1.0f, 0.0f));

	// Bucle principal
	float lastTime = static_cast<float>(glfwGetTime());
	while ( !glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE) ) {
		// update delta time
		float newTime = static_cast<float>(glfwGetTime());
		float deltaTime = newTime - lastTime;
		lastTime = newTime;

		// get updated screen size
		int screenWidth, screenHeight;
		glfwGetWindowSize(window, &screenWidth, &screenHeight);

		// report screen size
		std::stringstream ss;
		ss << screenWidth << "x" << screenHeight;
		glfwSetWindowTitle(window, ss.str().c_str());

		// Update viewport in case the screen has been resized
		camera->setViewport(glm::ivec4(0, 0, screenWidth, screenHeight));

		// Set projection matrix in case the screen has been resized
		glm::mat4 projectionMatrix = glm::perspective(45.0f, 
			static_cast<float>(screenWidth) / static_cast<float>(screenHeight), 0.1f, 100.0f);
		camera->setProjection(projectionMatrix);

		
		// Update the objects in the world
		for (int i = 0; i < world.getNumEntities(); ++i) {

			std::shared_ptr<Entity> currentEntity = world.getEntity(i);

			//Only Model objects must be displayed
			std::shared_ptr<Model> currentModel = std::dynamic_pointer_cast<Model>(currentEntity);
			if (currentModel != nullptr)
			{
				// get the current quaternion of the object
				glm::quat rotationQuaternion = currentModel->getRotationQuat();

				// Calculate the new quaternion
				currentModel->setRotationQuat(glm::slerp(rotationQuaternion, 
					rotationQuat * rotationQuaternion, deltaTime));
				
			}
		}

		// Draw the objects
		world.update(deltaTime);
		world.draw();

		// update swap chain & process events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	return 0;
}