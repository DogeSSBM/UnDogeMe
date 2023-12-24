#include "DogeLib/Includes.h"
#include "UnDogeMe.h"

int main(void)
{
    init();
    Board board = {0};
    board.square[0][0] = CAR_A;
    board.square[1][0] = CAR_A;
    board.square[3][3] = CAR_X;
    board.square[0][4] = CAR_B;
    board.square[0][5] = CAR_B;
    board.square[0][3] = CAR_B;
    while(1){
        const uint fs = frameStart();

        boardRescale(&board);
        if(keyPressed(SC_ESCAPE))
            exit(0);

        if(mouseBtnReleased(MOUSE_L))
            board.selected = CAR_NULL;

        if(mouseBtnPressed(MOUSE_L) && coordInWindow(mouse.pos)){
            const Coord bp = boardPos(&board, mouse.pos);
            board.selected = board.square[bp.x][bp.y];
        }

        // if(board.selected != CAR_NULL){
        //     if()
        // }

        boardDraw(&board);

        frameEnd(fs);
    }

    return 0;
}
