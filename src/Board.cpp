
//-----------------------
void Board::loadLevel()
{
	m_board.clear();
	auto line = std::string();
	std::string currFileName = std::string("Level") + std::to_string(currStage) + ".txt";
	std::ifstream file(currFileName);

	if (!file)
	{
		std::cout << "You are the best! You beat me!" << std::endl;
		return END_GAME;
	}

	while (std::getline(file, line))
	{
		m_level.push_back(line);
	}

	sizeRow = static_cast<int>(m_board.size()) - 1;
	sizeCol = static_cast<int>(m_board[sizeRow].size()) - 1;

	return currStage;
}
//-------------------------
void Board::LoadBoard(const std::vector <sf::Sprite>& textures, int index[])
{
	const float TILE_SIZE_X = float((WIDTH - BOARD_STARTING_X - WIDTH / 20) / m_cols);
	const float TILE_SIZE_Y = float((HEIGHT - BOARD_STARTING_Y - HEIGHT / 20) / m_rows);

	m_board.clear();
	m_board.reserve(m_rows);

	for (int row = 0; row < m_rows; row++)
	{
		m_board.emplace_back(m_cols);
		for (int col = 0; col < m_cols; col++)
		{
			m_board[row][col].setLocation(col, row, TILE_SIZE_X, TILE_SIZE_Y);

			if (m_isBoardExist)
			{
				switch (m_level[row][col])
				{
				case 'D':
					m_board[row][col].setTexture(&textures[index[DOOR]]);
					break;
				case '/':
					m_board[row][col].setTexture(&textures[index[PLAYER]]);
					break;
				case '#':
					m_board[row][col].setTexture(&textures[index[WALL]]);
					break;
				case '@':
					m_board[row][col].setTexture(&textures[index[ROCK]]);
					break;
				case '!':
					m_board[row][col].setTexture(&textures[index[GUARD]]);
					break;
				}
			}
		}
	}
}