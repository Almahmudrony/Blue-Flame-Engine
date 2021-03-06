#include "GLConstantBuffer.h"
#include "BF/Platform/API/OpenGL/GLError.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				GLConstantBuffer::GLConstantBuffer() :
					buffer(0)
				{
				}

				GLConstantBuffer::~GLConstantBuffer()
				{
					GLCall(glDeleteBuffers(1, &buffer));
				}

				void GLConstantBuffer::Create(unsigned int size, unsigned int bindingIndex)
				{
					GLCall(glGenBuffers(1, &buffer));
					GLCall(glBindBuffer(GL_UNIFORM_BUFFER, buffer));
					GLCall(glBufferData(GL_UNIFORM_BUFFER, size, 0, GL_DYNAMIC_DRAW));

					GLCall(glBindBufferRange(GL_UNIFORM_BUFFER, bindingIndex, buffer, 0, size));
					GLCall(glBindBuffer(GL_UNIFORM_BUFFER, 0));
				}

				void GLConstantBuffer::Update(const void* data, unsigned int size)
				{
					GLCall(glBindBuffer(GL_UNIFORM_BUFFER, buffer));
					GLCall(glBufferSubData(GL_UNIFORM_BUFFER, 0, size, data));
					GLCall(glBindBuffer(GL_UNIFORM_BUFFER, 0));
				}
			}
		}
	}
}