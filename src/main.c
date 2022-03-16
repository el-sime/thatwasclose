#include "raylib.h"
#include "types.h"
#include "uifunctions.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

#if defined(PLATFORM_WEB)
	#include <emscripten/emscripten.h>
#endif


typedef enum GameScreen { LOGO = 0, TITLE, OPTIONS, GAMEPLAY, ENDING } GameScreen;

//-------------------------------------------------------
// General globals
//-------------------------------------------------------

int screenWidth = 800;
int screenHeight = 640;
char title[] = "Adventurer Manager";

float lastFrameTime = 0.0f;

GameScreen currentScreen = 0;

void GameInit(void);
void UpdateDrawFrame(void);

//-------------------------------------------------------
// Game global state
//-------------------------------------------------------

unsigned int level = 1;
float XPRate = 0.6f;
float XP = 0.0f;


Manager manager = {
	"Manager",
	"default_portrait.png"
};

//-------------------------------------------------------
// UI Functions
//-------------------------------------------------------

Font font = {0};
Texture2D t_window;

void InitUI(void)
{
	// Load sprites
	//t_window = LoadTexture("");
	//Vector2 position{0.0f, 0.0f};
	//Rectangle window_topleftcorner {}
}

void DrawGameplay(void);
GameScreen UpdateGameplay(float dt);
void InitGameplay(void);

GameScreen UpdateGameplay(float dt)
{
	XP += XPRate * dt;

	DrawGameplay();
	return GAMEPLAY;
}

void DrawGameplay(void)
{
	char XPLabel[] = "XP: 0.00000000";
	char levelLabel[] = "Level: XXXX";
	sprintf(XPLabel, "XP: %3.2lf", XP);
	sprintf(levelLabel, "Level: %d", level);
	BeginDrawing();
	ClearBackground(LIGHTGRAY);
	DrawText(levelLabel, 10, 10, 36, BLACK);
	DrawText(XPLabel, strlen(levelLabel) + 100, 10, 36, BLACK);
	EndDrawing();
}



void UpdateDrawFrame(void)
{
	// DeltaTime
	float currentTime = GetTime();
	float deltaTime = currentTime - lastFrameTime;
	lastFrameTime = currentTime;

	emscripten_log(0, "current screen: %d\n", currentScreen);
	emscripten_log(0, "GAMEPLAY screen: %d\n", GAMEPLAY);

	//---------------------------------------------------
	// Actual drawing
	//--------------------------------------------------
	if (currentScreen == GAMEPLAY) {
		UpdateGameplay(deltaTime);
	}
	else
	{
		BeginDrawing();
		ClearBackground(DARKGREEN);
		EndDrawing();
	}
}

int main(void)
{
	InitWindow(screenWidth, screenHeight, title);
	//InitAudioDevice();
	font = LoadFont("resources/mecha.png");
	currentScreen = GAMEPLAY;
#if defined(PLATFORM_WEB)
	emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		UpdateDrawFrame();
	}
#endif

	UnloadFont(font);
	CloseWindow();
	return 0;
}

