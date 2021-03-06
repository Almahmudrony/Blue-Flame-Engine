#include "GLVertexBuffer.h"
#include "BF/Platform/API/OpenGL/GLError.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				using namespace BF::Graphics::API;

				GLVertexBuffer::GLVertexBuffer() :
					VBO(0), VAO(0)
				{
				}

				GLVertexBuffer::~GLVertexBuffer()
				{
					GLCall(glDeleteBuffers(1, &VBO));
					GLCall(glDeleteVertexArrays(1, &VAO));
				}

				void GLVertexBuffer::Create(const void* data, unsigned int size)
				{
					this->size = size;

					GLCall(glGenVertexArrays(1, &VAO));
					GLCall(glBindVertexArray(0));

					GLCall(glGenBuffers(1, &VBO));
					GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));
					GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
					GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
				}

				void* GLVertexBuffer::Map() const
				{
					GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));

#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
					GLCall(return glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
					GLCall(return glMapBufferRange(GL_ARRAY_BUFFER, 0, size, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT));
#endif
				}

				void GLVertexBuffer::Unmap() const
				{
					GLCall(glUnmapBuffer(GL_ARRAY_BUFFER));
					GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
				}

				void GLVertexBuffer::Bind() const
				{
					GLCall(glBindVertexArray(VAO));
				}

				void GLVertexBuffer::Unbind() const
				{
					GLCall(glBindVertexArray(0));
				}

				void GLVertexBuffer::SetLayout(const VertexBufferLayout& vertexBufferLayout)
				{
					GLCall(glBindVertexArray(VAO));
					GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));

					for (size_t i = 0; i < vertexBufferLayout.GetBufferElement().size(); i++)
					{
						GLCall(glEnableVertexAttribArray(vertexBufferLayout.GetBufferElement()[i].index));
						GLCall(glVertexAttribPointer(vertexBufferLayout.GetBufferElement()[i].index, GetComponentCount(vertexBufferLayout.GetBufferElement()[i].dataType),
							GetGLDataType(vertexBufferLayout.GetBufferElement()[i].dataType), GL_FALSE, vertexBufferLayout.GetBufferElement()[i].stride, (GLvoid*)vertexBufferLayout.GetBufferElement()[i].offset));
					}

					GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
					GLCall(glBindVertexArray(0));
				}

				GLenum GLVertexBuffer::GetGLDataType(VertexBufferLayout::DataType dataType)
				{
					switch (dataType)
					{
						case VertexBufferLayout::DataType::Float:
						{
							return GL_FLOAT;
							break;
						}
						case VertexBufferLayout::DataType::Float2:
						{
							return GL_FLOAT;
							break;
						}
						case VertexBufferLayout::DataType::Float3:
						{
							return GL_FLOAT;
							break;
						}
						case VertexBufferLayout::DataType::Float4:
						{
							return GL_FLOAT;
							break;
						}
						default:
							return -1;
							break;
					}
				}

				unsigned int GLVertexBuffer::GetComponentCount(VertexBufferLayout::DataType dataType)
				{
					switch (dataType)
					{
						case VertexBufferLayout::DataType::Float:
						{
							return 1;
							break;
						}
						case VertexBufferLayout::DataType::Float2:
						{
							return 2;
							break;
						}
						case VertexBufferLayout::DataType::Float3:
						{
							return 3;
							break;
						}
						case VertexBufferLayout::DataType::Float4:
						{
							return 4;
							break;
						}
						default:
							return -1;
							break;
					}
				}
			}
		}
	}
}