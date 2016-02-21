// Room: /d/mingjiao/road1
inherit ROOM;

void create()
{
  set ("short", "山路");
  set ("long", @LONG
这是条群山环抱中的一条曲折山路，一直通向山的深处。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road2",
  "north" : __DIR__"shanjiao",
]));
  set("outdoors", "/d/mingjiao");
  setup();
  replace_program(ROOM);
}
