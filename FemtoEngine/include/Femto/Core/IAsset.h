#pragma once

namespace Femto
{
	class IAsset
	{
	public:
		virtual bool IsValid() const = 0;
	};
}