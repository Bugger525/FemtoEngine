#include "Femto/System/App.h"
#include "Femto/Core/Debug.h"
#include <Windows.h>

class DemoGame : public Femto::App
{
protected:
	void Initialize() override
	{
		FEMTO_INFO("{}", m_GraphicsDevice == nullptr);
	}
	void Update(float dt) override
	{
	}
	void Render(float dt) override
	{
	}
	void Cleanup() override
	{

	}
};
int main()
{
	DemoGame().Run();
}