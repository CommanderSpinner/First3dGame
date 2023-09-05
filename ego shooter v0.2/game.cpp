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

    //SetCameraMode(camera, CAMERA_FREE);

    // Initialisierung anderer Spielkomponenten hier
}


void Game::Update() {

    float offsetThisFrame = 10.0f * GetFrameTime();

    // Spiellogik und Aktualisierungen hier
    if (IsKeyDown(KEY_S)) {
        camera.position.z += offsetThisFrame;
        camera.target.z += offsetThisFrame;
    }
    else if (IsKeyDown(KEY_W)) {
        camera.position.z -= offsetThisFrame;
        camera.target.z -= offsetThisFrame;
    }else if (IsKeyDown(KEY_D)) {
        camera.position.x += offsetThisFrame;
        camera.target.x += offsetThisFrame;
    }
    else if (IsKeyDown(KEY_A)) {
        camera.position.x -= offsetThisFrame;
        camera.target.x -= offsetThisFrame;
    }
}

void Game::Draw() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(camera);

    //cube for testing
    Vector3 cubePosition{ 0 };
    DrawCube(cubePosition, 1.0f, 1.0f, 1.0f, RED);

    EndMode3D();

    EndDrawing();
}

void Game::Shutdown() {
    // Aufräumarbeiten hier
}
