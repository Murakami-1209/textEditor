#pragma once

#include <string>
#include <vector>

namespace Editor {
	class Text
	{
	public:
		Text();
		Text(const std::vector<std::string>& text);
		Text(const std::vector<std::string>&& text);
		~Text();
		const std::vector<std::string> getText() { return m_text; }
	private:
		std::vector<std::string> m_text;
	};
}