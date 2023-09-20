#include "game.h"

Game::Game() {}

Game::~Game() {}

void Game::Init() {
    // Initialisierung der Kamera
    camera = { 0 };
    camera.position = Vector3{ 0.0f, 1.0f, 10.0f };
    camera.target = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    enemy1 = Enemy({ 2.0f, 1.0f, 0.0f });

    DisableCursor(); // For the cursor not to move out of the window

    //SetCameraMode(camera, CAMERA_FREE);

    // Initialisierung anderer Spielkomponenten hier
}

//old
/*
void Game::Update() {
    float offsetThisFrame = 10.0f * GetFrameTime();
    float moveX = 0.0f;
    float moveZ = 0.0f;

    // Handle input for both axes
    if (IsKeyDown(KEY_W)) {
        moveZ -= offsetThisFrame;
    }
    if (IsKeyDown(KEY_S)) {
        moveZ += offsetThisFrame;
    }
    if (IsKeyDown(KEY_A)) {
        moveX -= offsetThisFrame;
    }
    if (IsKeyDown(KEY_D)) {
        moveX += offsetThisFrame;
    }

    // Update the camera position and target
    camera.position.x += moveX;
    camera.position.z += moveZ;
    camera.target.x += moveX;
    camera.target.z += moveZ;


    UpdateCamera(&camera, cameraMode); // Update camera
}
*/

//new
void Game::Update() {
    float offsetThisFrame = 10.0f * GetFrameTime();
    float moveX = 0.0f;
    float moveZ = 0.0f;

    Vector3 front = { camera.target.x - camera.position.x, camera.target.y - camera.position.y, camera.target.z - camera.position.z };
    float length = sqrt(front.x * front.x + front.y * front.y + front.z * front.z);
    front.x /= length;
    front.y /= length;
    front.z /= length;

    Vector3 right = { front.z, 0, -front.x };
    length = sqrt(right.x * right.x + right.y * right.y + right.z * right.z);
    right.x /= length;
    right.y /= length;
    right.z /= length;

    if (IsKeyDown(KEY_W)) {
        moveZ += offsetThisFrame;
    }
    if (IsKeyDown(KEY_S)) {
        moveZ -= offsetThisFrame;
    }
    if (IsKeyDown(KEY_D)) {  
        moveX -= offsetThisFrame;
    }
    if (IsKeyDown(KEY_A)) {  
        moveX += offsetThisFrame;
    }

    Vector3 movement = { right.x * moveX + front.x * moveZ, right.y * moveX + front.y * moveZ, right.z * moveX + front.z * moveZ };

    camera.position.x += movement.x;
    camera.position.y += movement.y;
    camera.position.z += movement.z;

    camera.target.x += movement.x;
    camera.target.y += movement.y;
    camera.target.z += movement.z;

    enemy1.Update();

    UpdateCamera(&camera, cameraMode);
}


// used for drawing a cube to test
void Game::drawTestCube(Vector3 cubePosition, float width, float height, float length) {
    
    //this is in case i need it
    //Vector3 cubePosition{ 0 };

    DrawCube(cubePosition, width, height, length, RED);
}


void Game::Draw() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(camera);

    enemy1.Draw(); // Draw the enemy

    //cube for testing
    Vector3 cubePosition{ 0 };
    drawTestCube(cubePosition, 1.0f, 3.0f, 1.0f); //standart: drawTestCube(cubePosition, 1.0f, 1.0f, 1.0f);

    EndMode3D();

    EndDrawing();
}

void Game::Shutdown() {
    // Aufräumarbeiten hier
}
