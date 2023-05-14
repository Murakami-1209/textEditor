#pragma once

namespace Editor {
	class InputService
	{
		enum class Event {
			NONE,
			ASCII,
			BACK_SPACE,
			DELETE,
			LEFT,
			RIGHT,
			UP,
			DOWN,
			HOME,
			END,
			UNDO,
			REDO,
			SAVE,
			LOAD,
		};
	public:
		InputService();
		~InputService();
		Event getKeyEvent();

	private:
		bool isPress();
	};



}