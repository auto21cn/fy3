// Room: /u/oldsix/room1/taihu_1.c

inherit ROOM;

void create()
{
	set("short", "太湖");
	set("long", @LONG
到得邻近，只见一座松树枝架成的木梯，垂下来通向水面。遥遥望见远处
绿柳丛中，露出一角飞檐。也不知到了什么地方。你想了想不知要不要上岸。
LONG
	);
	set("exits",([
		"southup" :"/d/suzhou/huan",
]));
	set("no_clean_up", 0);
	set("outdoors","room1");
	setup();
}
void init()
{
	object me;
	me=this_player();
	remove_call_out("greeting");
	call_out("greeting",1,me);
	add_action("do_hua","hua");
}
void greeting(object me)
{
	if(!me||environment(me)!=this_object()) return;
	message_vision("$N划着小船过来了。\n",me);
}
int do_hua(string str)
{
	object me;
	me=this_player();
	if(!str) 	{
		write("你要往哪划？\n");
		return 1;
			}
	if(str=="s"||str=="south")	{
		write("南面是陆地，没办法划上去。\n");
		return 1;
					}
	if(str=="w"||str=="west"||str=="e"||str=="east")	{
		me->move(__DIR__"shuilu2");
		return 1;
				}
	if(str=="n"||str=="north")	{
		me->move(__DIR__"s2");
		return 1;
					}
	write("没有这个方向。\n");
	return 1;
}
