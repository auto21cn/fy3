//This xuedao173 room file by mapmaker

inherit ROOM;

void create()
{
  set("short", "血魔洞");
  set("long",@LONG
上一代血刀门主正在此秘修血魔神功。
怎么也得是.百十来岁的人吧.
LONG
  );
  set("exits", ([ /* sizeof() == 2 */ 
      "out" : __DIR__"xuedao172",
      "south" : __DIR__"xuedao174",
      ]));
  set("no_clean_up", 0);
  set("outdoors","xuedaomen/2");
  setup();
  replace_program(ROOM);//如果没有init函数请不要删除这句话

}
