// Room: /u/xxy/room/xiaojing3
inherit ROOM;

void create()
{
  set ("short", "万壑谷");
  set ("long", @LONG
这是群山环绕中的一个山谷,与其他山谷不同的是,这地方有许多
丘壑,稍不小心掉了下去,就是万劫不复之势.引颈而望,则如坐井观天
白云片片,形势险峻之极.有一条小路向西蜿蜒而去.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yixiant",
  "east" : __DIR__"shuitan",
]));
set("outdoors","/d/emei");
  setup();
}
