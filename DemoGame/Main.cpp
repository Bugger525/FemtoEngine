#include "Femto/System/App.h"
#include "Femto/Core/Debug.h"
#include <Windows.h>

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
		FEMTO_WARN("{}", dt);
	}
	void Cleanup() override
	{

	}
};
int main()
{
	DemoGame().Run();
}