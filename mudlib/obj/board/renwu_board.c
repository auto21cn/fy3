inherit BULLETIN_BOARD;

void create()
{
set_name("任务BUG专用",({"board"}));
set("location","/d/zhongzhou/shizhongxin");
set("board_id","renwu_board");
           set("long",
                "任务BUG专用。(help board)。\n");
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);

}

