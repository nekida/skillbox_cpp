#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

int main ()
{
    auto recursiveGetFileNamesByExtension = [](std::filesystem::path path, const std::string extension) {
        std::vector<std::string> filesList;
        for (auto& p : std::filesystem::recursive_directory_iterator(path))
            if (p.is_regular_file() && p.path().string().find(extension) != std::string::npos)
                filesList.push_back(p.path().string());
        return filesList;
    };

    std::string path, extension;
    std::cout << "Enter the path to the directory and the file extension to search for:" << std::endl;
    std::cin >> path >> extension;

    auto v = recursiveGetFileNamesByExtension(path, extension);

    for (const auto& fileName : v)
        std::cout << fileName << " ";

    return 0;
}
