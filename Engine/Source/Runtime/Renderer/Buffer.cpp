#include "Runtime/Core/stdafx.h"

#include "Buffer.h"
#include "Renderer.h"

#include "Runtime/Platform/OpenGL/OpenGLBuffer.h"

namespace Sudou
{
    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None: SD_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::OpenGL: return new OpenGLVertexBuffer(vertices, size);
        }

        SD_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None: SD_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices, size);
        }

        SD_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}