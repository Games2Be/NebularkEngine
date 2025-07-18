#pragma once
#include "iostream"
#include <string>
#include <vector>

namespace Nebulark
{
	class RenderPipeline
	{
	public:

		RenderPipeline(const std::string& vertFilePath, const std::string& fragFilePath);

	private:
		static std::vector<char> readFile(const std::string& filePath);
		void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);

	};
}