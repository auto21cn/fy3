// Room: /d/quanzhen/houshan
inherit ROOM;

void create()
{
  set ("short", "后山");
  set ("long", @LONG
这儿是全真教的后山，平时全真弟子无事时，便偷偷溜到这儿来玩
上一玩。
LONG);

  set("outdoors", "/d/quanzhen");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jingxiushi",
  "northeast":__DIR__"xiaolu1",
]));
  setup();
set("outdoors","/d/quanzhen");
  replace_program(ROOM);
}
