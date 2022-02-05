#ifndef UIFUNCTIONS_H
#define UIFUNCTIONS_H

#include "raylib.h"

// generic functions to draw UI elements

// ------------------------------------------
// General constants / parameters declaration
// ------------------------------------------

extern Texture2D t_window;

extern int offsetX;
extern int offsetY;

void InitUI(void);

/**
 * This should just draw the border and background (if background needs to be drawn)
 **/
void DrawMainWindow(void);
#endif

