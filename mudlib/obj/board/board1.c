inherit BULLETIN_BOARD;
void create()
{
        set_name("巫师留言板", ({ "board" }) );
        set("location", "/d/wiz/meeting");
        set("board_id", "wizboard");
        set("long",
                "这是给巫师们留言记事的小黑板。\n" );
        setup();
          set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}
