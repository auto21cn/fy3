// Room: /d/heimuya/xiaolu
inherit ROOM;

void create()
{
  set ("short", "荒山小路");
  set ("long", @LONG
这是条连接黑目崖也成都的小路，据说这儿常有野兽出没，不可久
留。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "northwest":"/d/heimuya/to_cd",
  "southeast":__DIR__"sl1",
]));
  set("outdoors", "/d/heimuya");
  setup();
  replace_program(ROOM);
}
