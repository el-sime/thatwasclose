#include "raylib.h"
#include "types.h"


#include <stdio.h>


#if defined(PLATFORM_WEB)
	#include <emscripten/emscripten.h>
#endif


typedef enum GameScreen { LOGO = 0, TITLE, OPTIONS, GAMEPLAY, ENDING } GameScreen;

//-------------------------------------------------------
// General globals
//-------------------------------------------------------

int screenWidth = 800;
int screenHeight = 600;
char title[] = "That was close";




GameScreen currentScreen = 0;
Font font = {0};

void GameInit(void);
void UpdateDrawFrame(void);

//-------------------------------------------------------
// Game global state
//-------------------------------------------------------

Manager manager = {
	"Manager",
	"default_portrait.png"
};



int main(void)
{
	InitWindow(screenWidth, screenHeight, title);
	//InitAudioDevice();
	font = LoadFont("resources/mecha.png");
	currentScreen = LOGO;
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

void UpdateDrawFrame(void)
{
	float deltaTime = GetTime();
	char pastTime[100];
	sprintf(pastTime, "Time:%lf", deltaTime);
	//printf("Time: %f\n", deltaTime);

	//---------------------------------------------------
	// Actual drawing
	//--------------------------------------------------
	if (currentScreen == LOGO) {	
		BeginDrawing();
		ClearBackground(WHITE);
		DrawText(pastTime, 10,10,36,BLACK);
		EndDrawing();
	}
	else 
	{
		BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();
	}
}
