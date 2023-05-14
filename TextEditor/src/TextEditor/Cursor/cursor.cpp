#include "cursor.h"

Editor::Cursor::Cursor()
{
	m_position = { 0,0 };
}

Editor::Cursor::Cursor(const unsigned int x, const unsigned int y)
{
	m_position = { x,y };
}

Editor::Cursor::~Cursor()
{
}
