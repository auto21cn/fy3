// Room: /d/japan/qingzhou
inherit ROOM;

void create()
{
    set ("short", "清州城");
  set ("long", @LONG
暂时开放 !
LONG);

  set("exits", ([ /* sizeof() == 1 */
   "down" : "/d/japan/zhongxin",
 ]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
  replace_program(ROOM);
}
