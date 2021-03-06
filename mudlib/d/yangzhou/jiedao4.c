// Room: /u/swordman/yangzhou/jiedao4.c

inherit ROOM;

void create ()
{
  set ("short", "二十四桥");
  set ("long", @LONG
        “二十四桥明月夜，玉人何处教吹萧”
    二十四桥又名红药桥，旧日曾集二十四美人于此，故得名。
桥头石刻“烟花夜月”，不知是谁的书笔。桥西有一酒肆，匾曰：
“听萧园”。向北就是大明寺，远远就可见寺院的栖陵塔了。
LONG);

  set("outdoors", "/u/swordman");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youke" : 2,
]));
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"jiedao3",
  "west" : __DIR__"tingxiao",
  "north" : __DIR__"damingshi",
]));

  setup();
}
