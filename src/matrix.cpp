#include "my_stack.h"

std::tuple<int, int> amountOfwords(std::ifstream &file)
{
    std::string line;
    int words = 0;
    int lines = 0;
    while (getline(file, line))
    {
        lines++;
        std::stringstream line_stream(line);
        while (getline(line_stream, line, ' '))
            words++;
    }
    return std::make_tuple(words, lines);
}

std::map<std::string, std::vector<int>> open_file(const std::string &path)
{
    int counter_files = 0;
    int counter_folders = 0;
    std::string line;
    std::map<std::string, std::vector<int>> result;

    std::map<std::string, int> amountOfSubFolders;
    
    //listing directories ad files in this path
    std::cout << " Recursive " << std::endl;
    for (const auto &i : std::filesystem::recursive_directory_iterator(path))
    {
        if (i.is_directory())
        {
            counter_folders++;
        }
        else
        {
            char c;
            int amountOfchar = 0;
            std::vector<int> folders;
            std::ifstream file_x;

            file_x.open(i.path());
            if (!file_x)
                std::cout << "Problemws with opening file" << std::endl;
            else
            {
                if (file_x.peek() == std::ifstream::traits_type::eof())
                {
                    counter_files++;
                    std::cout << "File: " << i.path() << " is empty" << std::endl;
                }
                else
                {
                    counter_files++;
                    while (file_x.get(c))
                        amountOfchar++;
                    file_x.close();

                    //counting words
                    file_x.open(i.path());
                    //std::thread(amountOfwords, file_x);
                    auto [lines, words] = amountOfwords(file_x);

                    folders.push_back(amountOfchar);
                    folders.push_back(words);
                    folders.push_back(lines);

                    std::cout << "File: " << i.path() << std::endl;
                    std::cout << " Size of file: " << i.file_size() << " KB" << std::endl;
                    std::cout << " lines: " << lines << std::endl;
                    std::cout << " words: " << words << std::endl;
                    std::cout << " characters: " << amountOfchar << std::endl;
                    file_x.close();
                    result[i.path()] = folders;
                }
            }
        }
    }

    std::cout << "Liczba folderów: " << counter_folders << std::endl;
    std::cout << "Liczba plików: " << counter_files << std::endl;
    return result;
}