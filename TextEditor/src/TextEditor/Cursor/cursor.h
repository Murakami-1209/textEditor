#pragma once

#include <array>
namespace Editor {
	class Cursor
	{
	public:
		Cursor();
		Cursor(const unsigned int x, const unsigned int y);
		~Cursor();

	private:
		std::array<unsigned int, 2> m_position;
	};

}