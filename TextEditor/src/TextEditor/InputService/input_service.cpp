#include "input_service.h"

#include <windows.h>

namespace Editor {
	InputService::InputService()
	{
	}

	InputService::~InputService()
	{
	}

	InputService::Event InputService::getKeyEvent()
	{
		INT16 state = GetAsyncKeyState('A');
		return Event::NONE;
	}
}