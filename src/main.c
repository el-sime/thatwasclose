#include "raylib.h"
#include "screens.h"
#include "types.h"


#include <stdio.h>


#if defined(PLATFORM_WEB)
	#include <emscripten/emscripten.h>
#endif

int screenWidth = 800;
int screenHeight = 480;
char title[] = "That was close";

GameScreen currentScreen = 0;
Font font = {0};

void UpdateDrawFrame(void);


int main(void)
{
	InitWindow(screenWidth, screenHeight, title);
	InitAudioDevice();
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
	float deltaTime = GetFrameTime();
	printf("Time: %f\n", deltaTime);
}
