// music 到扬州的路

inherit ROOM;

void create()
{
  set ("short", "官道");
  set ("long", @LONG
      你走在尘土飞扬的官道上。

LONG);

  set("objects", ([ /* sizeof() == 1 */
    //       __DIR__"npc/xiaofan" : 1,
                 ]));
  set("outdoors", "/d/taishan");

  set("exits", ([ /* sizeof() == 3 */
                  "north" : __DIR__"to_yz1",
                  "south" : __DIR__"to_yz3",

              ]));
  setup();
}
