#include "Core/Assets.h"

namespace Femto
{
	bool Assets::Exists(std::string_view name)
	{
		return m_Assets.find(std::string(name)) != m_Assets.end();
	}
	void Assets::Clear()
	{
		m_Assets.clear();
	}
}