#include "Runtime/Core/stdafx.h"

#include "VertexArray.h"

#include "Runtime/Renderer/Renderer.h"

#include "Runtime/Platform/OpenGL/OpenGLVertexArray.h"

namespace Sudou
{
    VertexArray* VertexArray::Create() 
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None: SD_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return  nullptr;
        case RendererAPI::OpenGL: return new OpenGLVertexArray();       
        }

        SD_CORE_ASSERT(false, "Unknow RendererAPI!");
        return nullptr;
    }
}