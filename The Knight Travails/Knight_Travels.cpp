#include <iostream>
using namespace std;

bool validbox(int x, int y, int n, int **chessboard)
{
    if (x >= 0 && y >= 0 && x < n && y < n && chessboard[x][y] == -1)
        return true;
    return false;
}
bool knight_Travails(int **chessboard, int x, int y, int mv, int *dx, int *dy, int n)
{
    if (mv == n * n)
    {
        return true;
    }
    for (int i = 0; i < 8; i++)

    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (validbox(nx, ny, n, chessboard))
        {
            chessboard[nx][ny] = mv;
            if (knight_Travails(chessboard, nx, ny, mv + 1, dx, dy, n))
                return true;
            chessboard[nx][ny] = -1;
        }
    }
    return false;
}
int main()
{
    int n, x, y;
    cout << "\t.........KNIGHT TRAVAILS........\n"
         << endl;
    cout << ".........FILLS THE CHESSBOARD WITH THE STEPS OF KNIGHT......\n"
         << endl;
    cout << "ENTER DIMENSIONS OF THE CHESS BOARD : ";
    cin >> n;
    int **chessboard = new int *[n];
    for (int i = 0; i < n; i++)
    {
        chessboard[i] = new int[n];

        Page | 10

            for (int j = 0; j < n; j++)
                chessboard[i][j] = -1;
    }

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    cout << "ENTER START POSITION(BEGINNING FROM 0 TO n-1) : ";
    cin >> x >> y;
    chessboard[x][y] = 0;
    int mv = 1;
    if (knight_Travails(chessboard, x, y, mv, dx, dy, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << chessboard[i][j] << " ";
            cout << "\n";
        }
    }
    else
        cout << "There is NO SOLUTION AVAILABLE !!";
    return 0;
}