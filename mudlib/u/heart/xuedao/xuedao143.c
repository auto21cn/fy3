//This xuedao143 room file by mapmaker

inherit ROOM;

void create()
{
  set("short", "ɳ����");
  set("long",@LONG
����һ��տյ����ķ��䡣
LONG
  );
  set("exits", ([ /* sizeof() == 4 */ 
      "west" : __DIR__"xuedao141",
      "north" : __DIR__"xuedao142",
      "east" : __DIR__"xuedao146",
      "south" : __DIR__"xuedao144",
      ]));
  set("no_clean_up", 0);
  set("outdoors","xuedaomen/1");
  setup();
  replace_program(ROOM);//���û��init�����벻Ҫɾ����仰

}