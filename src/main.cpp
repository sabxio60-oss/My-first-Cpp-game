#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "window name");
	
	#pragma region imgui
	rlImGuiSetup(true);

	//Making the font bigger
	ImGuiIO &io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_DockingEnable;
	io.FontGlobalScale = 2.5;
	#pragma endregion

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		
	#pragma region imgui
		rlImGuiBegin();
		//Docking settings
		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);
	#pragma endregion	


		DrawRectangle(50, 50, 100, 100, {0, 255, 0, 127});
		DrawRectangle(75, 75, 100, 100, { 255, 0, 0, 127 });

	#pragma region imgui windows
		ImGui::Begin("test");

		ImGui::Text("hello");

		if(ImGui::Button("button")) 
		{
			std::cout << "Text\n";
		}
		ImGui::SameLine();
		if (ImGui::Button("button##2"))
		{
			std::cout << "Second button\n";
		}

		ImGui::PushID(2);

		if (ImGui::Button("button##2"))
		{
			std::cout << "Thrid button\n";
		}
		ImGui::PopID();
		

		ImGui::End();

		ImGui::Begin("second window");

		ImGui::Text("hello");
		ImGui::Separator();
		ImGui::NewLine();
		static float a = 0;
		ImGui::SliderFloat("slider", &a, 0, 1);

		ImGui::End();


		rlImGuiEnd();
	#pragma endregion
		EndDrawing();
		
		
	}
	#pragma region imgui
	rlImGuiShutdown();
	#pragma endregion

	CloseWindow();
	

	return 0;
}