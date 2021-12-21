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

std::tuple<int, int> countWords(const std::filesystem::directory_entry &i, std::ifstream &file)
{
    file.close();
    file.open(i.path());
    return amountOfwords(file);
}

int countCharacter(std::ifstream &file)
{
    char c;
    int amountOfchar;
    while (file.get(c))
        amountOfchar++;
    return amountOfchar;
}

void countFiles(int &count)
{
    count++;
}

void printFilesDetails(const std::filesystem::directory_entry &i, const std::vector<int> &details)
{
    std::cout << " File: " << i.path() << std::endl;
    std::cout << " Size of file: " << i.file_size() << " KB" << std::endl;
    std::cout << " characters: " << details[0] << std::endl;
    std::cout << " words: " << details[1] << std::endl;
    std::cout << " lines: " << details[2] << std::endl;
}

void printFoldersDetails()
{
}

std::vector<int> hanlerForNonEmptyFile(const std::filesystem::directory_entry &i)
{
    char c;
    int amountOfchar = 0;
    std::vector<int> folders;
    std::ifstream file;

    file.open(i.path());
    if (!file){
        std::cout << "Problemws with opening file" << std::endl;
        return {};
    }
    else
    {
        if (file.peek() == std::ifstream::traits_type::eof())
        {
            std::cout << "File: " << i.path() << " is empty" << std::endl;
        }
        else
        {

            auto tuple_lines_words = countWords(i, file);
            file.close();

            folders.push_back(amountOfchar);                   //character
            folders.push_back(std::get<0>(tuple_lines_words)); //words
            folders.push_back(std::get<1>(tuple_lines_words)); //lines

            //print 
            printFilesDetails(i, folders);
        }
    }
    return folders;
}

std::tuple<int, int> numbersOfFilesAndFolders(const std::string &path)
{
    int counter_files = 0, counter_folders = 0;

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
            countFiles(counter_files);
            hanlerForNonEmptyFile(i);
        }
    }

    std::cout << "Liczba folderów: " << counter_folders << std::endl;
    std::cout << "Liczba plików: " << counter_files << std::endl;
    return {1, 2};
}