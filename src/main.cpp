#include <iostream>
#include <raylib.h>

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "window name");
	
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText("My first window!", 190, 200, 20, 
			{255,0,200,255}
			);

		EndDrawing();
	
	}

	CloseWindow();

	return 0;
}