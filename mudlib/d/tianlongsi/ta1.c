inherit ROOM;

void create()
{
        set("short", "舍利塔");
        set("long",@LONG
这是天龙三塔中最高的一座，高约三百余尺，共有十六级。相传塔顶
原本供奉着一颗前代高僧的舍利子，但在当年奸臣杨义贞弑上德帝篡位以
至天下大乱时，舍利子不知何因而失踪了，这也成为天龙寺历代主持的心
腹大事。这个传言也不知是真是假。
LONG
        );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"baodian",
		"east" : __DIR__"wuwoge",
		"west" : __DIR__"wujingge",
                "north" : __DIR__"talin",
//		"up" :__DIR__"floor1",
        ]));
	set("objects",([
                __DIR__"npc/hutaseng1" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}
void init()
{
        add_action("do_jump","jump");
}
int do_jump()
{
        object me;
        me=this_player();
        if(living(me)==0)       return 0;
        if(me->query_skill("dodge",1)<10)       {
                tell_object(me,"你的基本轻功还没练到家吧。\n");
                return 1;
        }
        message_vision("只见$N一个“旱地拔葱”，飞身直窜塔顶。\n",me);
        tell_room("/d/tianlongsi/tading",me->query("name")+"从塔下跃了上来。\n");
        me->move("/d/tianlongsi/tading");
        me->start_busy(3);
        return 1;
}
