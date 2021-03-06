#pragma once

#include <windows.h>
#include <unordered_map>
using std::unordered_map;
#include <iostream>
#include <string.h>
using namespace std;
using std::string;
using std::endl;
using std::cout;

class FileLoader {

    public:
    // Data types
	struct FileReadInData {
		LPVOID data;
		DWORD size;
	};

	struct ConfigData {
		int column;
		int rows;
		int numOfMines;
	};

    struct TextureData {
        int width;
        int height;
        int n;
        unsigned char* pixelData;
        BITMAPINFO bitMapInfo; 
    };
    static char* convertToChar;
	static std::string testBoardString;
    ConfigData configData;

    FileLoader::FileLoader(); 
    FileLoader::~FileLoader();
    // ENUM
	enum fileTypeToLoad {config, board};

    // ALL TEXTURES FOR THE GAME
    static unordered_map< string, TextureData& > textures;


    // Functionst in Support of loading and getting textures
    static TextureData& getTextureChar(char* name);
    static TextureData& getTextureString(string name);
    static void loadAllTextures();
    TextureData& getTextureBMP(string name);

    static const unordered_map< string, TextureData& > getTextureMap();

    // Functiosn in support of configuring and test boards
	string getTestBoardString();
	void deleteTestBoardString();
	void loadFileHelper(string fileName, fileTypeToLoad type);

    private:
    // char* for file names to be used in strToChar this is to prevent leaks

    // Helper functions for loading textures
    static FileReadInData readEntireFile(char* path);
    static TextureData& loadTextureData32Bit(FileReadInData& data);

    // Helper fucntion to load in board
	void loadConfig(string fileName);
	void loadBoard(string fileName);
    static char* stringToChar(string str);


    // Helper function, implemented my own stoi
    int stoi(string input);
};