//room: 
inherit ROOM;

void create()
{
  set("short","长廊");
  set("long", @LONG
这是条明洁的长廊，两端空荡荡的，脚下的地板不时发出吱吱扭扭的声
音。南边就是青龙堂大厅。
LONG  );

  set("exits",([
      "north" : __DIR__"chlang1",
      "south" : __DIR__"qing",
  ]));			   
  set("objects",([
      __DIR__"npc/shinu1"   :1,
  ]));
  set("no_fight",0);
  set("no_steal",0);
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

