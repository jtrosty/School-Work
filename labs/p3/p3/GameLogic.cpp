#include "GameLogic.h"

GameLogic::TileInfo* tileInfo;


GameLogic::GameLogic() {
    loadGameData();
    cout << "success" << endl;
}

GameLogic::~GameLogic() {
    if (tileInfo == nullptr) {}
    else {
        delete[] tileInfo;
    }
}


void GameLogic::loadTestBoard(TileInfo tiles[], string testBoardString)
{
    // If chosen to load test board. 
    for (int i = 0; i < gameData.numOfTiles; i++) {
        if (testBoardString[i] == '0') {
            tiles[i].mine = 0;
        }
        else tiles[i].mine = 1;
    }
}

void GameLogic::zeroBoard(TileInfo tileInfo[])
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < gameData.numOfTiles; i++) {
        x = i % gameData.columns;
        y = i / gameData.columns;
        tileInfo[i].xPos = (x * gameData.lengthOfTile);
        tileInfo[i].yPos = (y * gameData.lengthOfTile);
        tileInfo[i].revealed = 0;
        tileInfo[i].numOfMines = 0;
        tileInfo[i].flag = 0;
        tileInfo[i].mine = 0;
    }
}

void GameLogic::leftClick(int x, int y)
{
	int columnClicked = x / gameData.lengthOfTile;
	int rowClicked = y / gameData.lengthOfTile;
	cout << "Column is: " << columnClicked << " Row is: " << rowClicked << endl;
	int cellClicked = (rowClicked * gameData.columns) + columnClicked;
	if (tileInfo[cellClicked].revealed == 0) {
        if (tileInfo[cellClicked].numOfMines == 0 && tileInfo[cellClicked].mine == 0) {
            // Open up all ties that don't ahve mines that touch one another
            emptyTileAutoOpen(tileInfo[cellClicked]);
        }
        tileInfo[cellClicked].revealed = 1;
	}
	else {
        // You cannot undo reveal
               // cout << "Index " << i << " " << tileInfo[i].adjacentTiles.size() << endl;
	}
}

void GameLogic::emptyTileAutoOpen(TileInfo& tile) {
    if (tile.xPos == 0 && tile.yPos == 448) {
        cout << "here" << endl;
    }
    if (tile.revealed == 1) return;
    if (tile.numOfMines != 0) {
        tile.revealed = 1;
        return;
    }
    int size = tile.adjacentTiles.size();
    for (int i = 0; i < size; i++) {
        tile.revealed = 1;
        if (tile.adjacentTiles.at(i) == nullptr) continue;
        emptyTileAutoOpen(*tile.adjacentTiles.at(i));
    }
}

void GameLogic::rightClick(int x, int y)
{
	int columnClicked = x / gameData.lengthOfTile;
	int rowClicked = y / gameData.lengthOfTile;
	int cellClicked = (rowClicked * gameData.columns) + columnClicked;
	cout << "Column is: " << columnClicked << " Row is: " << rowClicked << endl;
	if (tileInfo[cellClicked].flag == 0) {
		tileInfo[cellClicked].flag = 1;
        gameData.numOfFlags++;
		cout << "Num Of mines aroud: " << (short)tileInfo[cellClicked].numOfMines << endl;
	}
	else {
		tileInfo[cellClicked].flag = 0;
        gameData.numOfFlags--;
	}
}

void GameLogic::loadGameData()
{
    FileLoading fileLoader;
    fileLoader.loadFileHelper("config", fileLoader.config);
    gameData.rows = fileLoader.configData->rows;
    gameData.columns = fileLoader.configData->column;
    gameData.numOfMines = fileLoader.configData->numOfMines;
    gameData.numOfTiles = (gameData.rows * gameData.columns);
    gameData.showMines = 0;
    gameData.smileyFace = 0;
    gameData.numOfFlags = 0;

    tileInfo = new TileInfo[gameData.numOfTiles];
    zeroBoard(tileInfo);
    randomMines(tileInfo, gameData);
    setUpAdjacentTiles(tileInfo);
}

void GameLogic::randomMines(TileInfo tileInfo[], GameData& gameData) {
    Random random;
    int counter = gameData.numOfMines;
    while (counter > 0) {
        int x = random.Int(0, gameData.numOfTiles);
        if (tileInfo[x].mine == 0) {
            tileInfo[x].mine = 1;
            counter--;
        }
    }
}


void GameLogic::setUpAdjacentTiles(TileInfo tileInfo[])
{
    int x = 0;
    int y = 0;
    // Setup pointers and count Mines $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    for (int i = 0; i < gameData.numOfTiles; i++) {
        x = i % gameData.columns;
        y = i / gameData.columns;
        // Set up pointers to adjacent tiles

        // Most common case
        if (x != 0 && x != gameData.columns - 1 && y != 0 && y!= gameData.rows- 1) {
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns + 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns + 1]);
        }
        // Top Left Corner
        else if (x == 0 && y == 0) {
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns + 1]);
        }
        // Top Right Corner
        else if (x == gameData.columns - 1 && y == 0) {
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns]);
        }
        // Bottom Left Corner
        else if (x == 0 && y == gameData.rows - 1) {
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns + 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + 1]);
        }
        // Bottom Right Corner
        else if (x == gameData.columns - 1 && y == gameData.rows - 1) {
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - 1]);
        }
        // Left Edge
        else if (x == 0) {
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns + 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns + 1]);
        }
        // Rigth Edge
        else if (x == gameData.columns - 1) {
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns]);
        }
        // Top Edge
        else if (y == 0) {
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + gameData.columns + 1]);
        }
        // Bottom Edge
        else if (y == gameData.rows - 1) {
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - gameData.columns + 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i - 1]);
            tileInfo[i].adjacentTiles.push_back(&tileInfo[i + 1]);
        }

        int size = tileInfo[i].adjacentTiles.size();
        for (int j = 0; j < size; j++) {
            if (tileInfo[i].adjacentTiles.at(j)->mine == 1) {
                tileInfo[i].numOfMines++;
            }
        }
    }
}
