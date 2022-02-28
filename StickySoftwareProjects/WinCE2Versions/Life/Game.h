// Header file

void DrawGrid(CDC* pDC);
void DrawEverything(CDC* pDC);
void UpdateAllCells(CDC* pDC);
void InitGame(CDC* pDC);
void RandomGrid(CDC* pDC);
void Generate();
void SwapCell(CDC* pDC,int sx, int sy);
void UpdateText(CDC* pDC);
void CopyToTemp();
void CopyFromTemp();
extern int total;
extern int generation;
extern int speed;
void LoadData();
void SaveData();