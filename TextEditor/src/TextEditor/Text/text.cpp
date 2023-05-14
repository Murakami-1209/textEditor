#include "text.h"

Editor::Text::Text()
{
	m_text = std::vector<std::string>();
}

Editor::Text::Text(const std::vector<std::string>& text)
{
	// 引数で渡されたテキストの列数分、vector配列を確保
	size_t column_size = text.size();
	m_text = std::vector<std::string>(column_size);

	for (size_t i = 0; i < column_size; i++) {
		// 列ごとに引数で渡された文字列をコピー
		m_text[i] = text[i];
	}
}

Editor::Text::Text(const std::vector<std::string>&& text)
{
	// 引数で渡されたテキストの列数分、vector配列を確保
	size_t column_size = text.size();
	m_text = std::vector<std::string>(column_size);

	for (size_t i = 0; i < column_size; i++) {
		// 列ごとに引数で渡された文字列をムープ
		m_text[i] = std::move(text[i]);
	}
}

Editor::Text::~Text()
{
}
