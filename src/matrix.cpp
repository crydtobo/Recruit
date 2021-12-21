#include "my_stack.h"

//define filename
#define nameFileToSaveData "foldersDetails.txt"


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
    file.open(i.path());
    return amountOfwords(file);
}

int countCharacter(std::ifstream &file)
{
    char c;
    int amountOfchar;
    while (file.get(c))
        amountOfchar++;
    file.close();
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

void openFile(std::ofstream &file, const std::string &file_name){
    file.open(file_name);
    if (!file) // file couldn't be opened
    { 
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }
}

void writeDatatoFile(const std::string &file_name, std::ofstream &fileToSave, const std::vector<int> &in)
{
    std::vector<std::string> strings;
    int c = 0;

    strings.push_back("SizeOfFile");
    strings.push_back("characters:");
    strings.push_back("words:");
    strings.push_back("lines:");

    fileToSave << "File name: " << file_name << std::endl;

    for (auto i : in)
    {
        fileToSave << strings[c] << i << std::endl;
        c++;
    }
}

std::vector<int> hanlerForNonEmptyFile(std::ofstream &fileToSave, const std::filesystem::directory_entry &i)
{
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
            int countChar = countCharacter(file);
            auto tuple_lines_words = countWords(i, file);

            folders.push_back(i.file_size());
            folders.push_back(countChar);                   //character
            folders.push_back(std::get<0>(tuple_lines_words)); //words
            folders.push_back(std::get<1>(tuple_lines_words)); //lines
            writeDatatoFile(i.path(), fileToSave, folders);
            //printFilesDetails(i, folders);
            file.close();
        }
    }
    return folders;
}

std::tuple<int, int> numbersOfFilesAndFolders(const std::string &path)
{
    int counter_files = 0, counter_folders = 0;
    std::ofstream writeDataTofile;
    openFile(writeDataTofile, nameFileToSaveData);
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
            hanlerForNonEmptyFile(writeDataTofile, i);
        }
    }

    std::cout << "Liczba folderów: " << counter_folders << std::endl;
    std::cout << "Liczba plików: " << counter_files << std::endl;
    writeDataTofile.close();
    return {1, 2};
}