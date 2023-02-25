#include "Femto/System/App.h"
#include "Femto/Core/Debug.h"

class DemoGame : public Femto::App
{
protected:
	void Initialize() override
	{
		FEMTO_INFO("Hi!");
	}
	void Update() override
	{

	}
	void Render() override
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