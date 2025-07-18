#include "RenderPipeline.h"
#include <fstream>
#include "../Log.h"

namespace Nebulark
{
	RenderPipeline::RenderPipeline(const std::string& vertFilePath, const std::string& fragFilePath)
	{
		NBL_CORE_TRACE("Creating LvePipeline with vertex shader: {0} and fragment shader: {1}", vertFilePath, fragFilePath);
		createGraphicsPipeline(vertFilePath, fragFilePath);
	}
	std::vector<char> RenderPipeline::readFile(const std::string& filePath)
	{
		std::ifstream file(filePath, std::ios::ate | std::ios::binary);

		if (!file.is_open())
		{
			NBL_CORE_ERROR("Failed to open file: {0}", filePath);
			throw std::runtime_error("Shader file could not be opened: " + filePath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		if (fileSize <= 0)
		{
			NBL_CORE_ERROR("Shader file is empty or unreadable: {0}", filePath);
			throw std::runtime_error("Invalid shader file size.");
		}

		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);
		file.close();

		return buffer;
	}

	void RenderPipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath)
	{
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilePath);
		NBL_CORE_TRACE("Vertex shader code size: {0} bytes", vertCode.size());
		NBL_CORE_TRACE("Fragment shader code size: {0} bytes", fragCode.size());
		// Here you would typically create the graphics pipeline using the shader code.
		// This is a placeholder for the actual Vulkan pipeline creation logic.
	}
}