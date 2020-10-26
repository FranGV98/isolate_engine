#ifndef __MODULE_GUI_H__
#define __MODULE_GUI_H__

#include "Module.h"
#include "Globals.h"
#include "glmath.h"
#include "imgui/imgui.h"

class ModuleGUI : public Module
{
public:
	ModuleGUI(bool start_enabled = true);
	~ModuleGUI();

	bool Init();
	update_status PreUpdate(float dt);
	update_status PostUpdate(float dt);
	bool CleanUp();
	void RequestBrowser(const char*);

	void ConsoleLog(char* log);
	void ClearConsole();
	void ShortKeys();

public:
	ImGuiIO io;
	bool show_demo_window = false;
	bool show_about_window = false;
	bool show_config_window = false;
	bool show_console_window = false;

	ImVec4 clear_color;

	char label[25];
	char title[25];

	char values[25];
	char format[10];
	float bright_float = 1.0f;
	int  width_int, height_int;
	std::vector<float> fps_log, ms_log;
	Timer frame_time;
	int fps;

	bool fullscreen = false;
	bool wireframe = false;
	bool gl_depth = true;
	bool gl_cull_face = false;
	bool gl_light = true;
	bool gl_color_mat = true;

	const char* resolution[5] = { "3840 x 2160","2560 x 1440","1920 x 1080", "1290 x 720", "720 x 480" };
	int current_resolution = 3;

	std::vector<char*> logs;
	bool update_scroll;
	
};

#endif // !__MODULE_GUI_H__