#pragma once

namespace Sudou
{
    enum class RendererAPI
    {
        None = 0, OpenGL = 1
    };

    class Renderer
    {
    public:
        inline static RendererAPI GetAPI() { return s_RenderAPI; }
    private:
        static RendererAPI s_RenderAPI;
    };
}