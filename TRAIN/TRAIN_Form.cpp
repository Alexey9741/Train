#include "TRAIN_Form.h"
#include <Windows.h>
using namespace TRAIN;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew TRAIN_Form);
	return 0;
}

