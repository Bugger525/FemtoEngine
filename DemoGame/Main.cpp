#include "Femto/System/App.h"
#include "Femto/Core/Debug.h"

class DemoGame : public Femto::App
{
protected:
	void Initialize() override
	{
	}
	void Update(float dt) override
	{
	}
	void Render(float dt) override
	{
		m_GraphicsDevice.Clear(Femto::Color::Cyan);
	}
	void Cleanup() override
	{

	}
};
int main()
{
	DemoGame().Run();
}