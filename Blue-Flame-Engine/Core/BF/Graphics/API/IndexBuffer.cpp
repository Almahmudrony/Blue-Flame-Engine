#include "IndexBuffer.h"
#include "BF/Graphics/API/Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			IndexBuffer::IndexBuffer()
			{
			}

			IndexBuffer::~IndexBuffer()
			{
			}

			void IndexBuffer::Create(const unsigned int* indices, unsigned int count)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxIndexBuffer.Create(indices, count);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glIndexBuffer.Create(indices, count);
#endif	
			}

			void IndexBuffer::Bind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxIndexBuffer.Bind();
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glIndexBuffer.Bind();
#endif	
			}

			void IndexBuffer::Unbind() const
			{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glIndexBuffer.Unbind();
#endif	
			}

			unsigned int IndexBuffer::GetIndicesCount() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					return dxIndexBuffer.GetIndicesCount();
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					return glIndexBuffer.GetIndicesCount();
#endif
				return 0;
			}
		}
	}
}