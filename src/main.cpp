#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "window name");
	
	rlImGuiSetup(true);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
				
		rlImGuiBegin();
		
		DrawRectangle(50, 50, 100, 100, {0, 255, 0, 127});
		DrawRectangle(75, 75, 100, 100, { 255, 0, 0, 127 });

		ImGui::Begin("test");

		ImGui::Text("hello");
		ImGui::Button("button");

		ImGui::End();


		rlImGuiEnd();

		EndDrawing();
		
		
	}
	rlImGuiShutdown();

	CloseWindow();
	

	return 0;
}