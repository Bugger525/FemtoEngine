#include "System/App.h"
#include "System/Timer.h"

namespace Femto
{
	void App::Run()
	{
		std::string_view vertexShaderCode = R"(
#version 330 core
layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;

void main()
{
    TexCoords = vertex.zw;
    gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);
}
			)";
		std::string_view fragmentShaderCode = R"(
#version 330 core
in vec2 TexCoords;
out vec4 color;

uniform sampler2D image;
uniform bool useTex;
uniform vec3 spriteColor;

void main()
{   
    if (useTex)
    {
        color = texture(image, TexCoords);
    }
    else
    {
        color = vec4(spriteColor, 1.0);
    }
}  
)";
		m_DefaultShader.Attach(vertexShaderCode, ShaderType::Vertex);
		m_DefaultShader.Attach(fragmentShaderCode, ShaderType::Fragment);

		m_GraphicsDevice = GraphicsDevice{ &m_Window };

		Initialize();

		Timer timer{};
		while (m_Window.IsRunning())
		{
			timer.Tick();

			Update(timer.GetDeltaTime());
			Render(timer.GetDeltaTime());

			timer.Reset();

			m_Window.Update();
		}
		Cleanup();
	}
}